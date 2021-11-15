#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    // the size of memory shared in bytes
    const int SIZE = 4096;
    const char *name = "OS";
    /* strings written to shared memory */
    const char *message_0 = "Hello";
    const char *message_1 = "World!";
    /* shared memory file descriptor */
    int fd;
    /* pointer to shared memory obect */
    char *ptr;

    // create the share memory object
    fd = shm_open(name, O_RDONLY, 0666);

    // mamp memory object
    ptr = (char *)mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    printf("%s", (char *)ptr);
    /* remove the shared memory object */
    // shm_unlink(name);
    return 0;
}
