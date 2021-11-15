#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <libgen.h>
#include <string.h>
#include <dirent.h>

static void _mkdir(const char *dir) {
        char tmp[256];
        char *p = NULL;
        size_t len;

        snprintf(tmp, sizeof(tmp),"%s",dir);
        len = strlen(tmp);
        if(tmp[len - 1] == '/')
                tmp[len - 1] = 0;
        for(p = tmp + 1; *p; p++)
                if(*p == '/') {
                        *p = 0;
                        mkdir(tmp, S_IRWXU);
                        *p = '/';
                }
        mkdir(tmp, S_IRWXU);
}

int isExecutable(char *program){
    struct stat sb;
    return
        stat(program, &sb) == 0 &&
        sb.st_mode &
        S_IXUSR;
}

int main(int argc, char *argv[]){
    if(argc < 3)
    {
        printf("Usage: ./redirect <program> <file> <program arguments>\n"
               "* program: full path to the progtam to execute\n"
               "* file: path to the file to store the output\n"
               "* program arguments: arguments passed to program\n");
        return 1;
    }

    char *program = argv[1];
    if(!isExecutable(program)){
        printf("\"%s\" is not executable. Be sure to use full path.\n", program);
        return 1;
    }
    char *file = argv[2];

    argv[2] = program;
    char **args = & argv[2];

    int pid = fork();
    if(pid < 0)
    {
        printf("fork failed.\n");
        return 1;
    }
    else if(pid == 0)
    {
        pid = fork();
        if(pid < 0)
        {
            printf("fork failed.\n");
            return 1;
        }
        else if(pid == 0)
        {
            //child of child
            //create all directories needed
            _mkdir(dirname(file));
            return 0;
        }
        else
        {
            //child
            int rc;
            if(waitpid(pid,&rc,0) < 0 || rc < 0)
            {
                perror("directory creation failed.");
                return 1;
            }
            //all directories created by child
            int fd = open( file , O_CREAT | O_WRONLY | O_TRUNC , S_IRWXU );
            dup2(fd, STDOUT_FILENO);
            dup2(fd, STDERR_FILENO);
            close(fd);
            execv(program, args);
            perror("execution failed.\n");
            return 1;
        }
    }
    else
    {
        //parent
        int rc;
        waitpid(pid,&rc,0);
        printf("child rc: %d\n", rc);
        return 0;
    }
}