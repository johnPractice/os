#include <stdio.h>
#include "Server.h"
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
typedef struct
{
    int new_socket;
    char *response;
} myarg_t;
void *read_write(void *arg)
{
    myarg_t *args = (myarg_t *)arg;
    int new_socket = args->new_socket;
    char *response = args->response;

    char buffer[30000];
    sleep(5);
    read(new_socket, buffer, 30000);
    printf("%s\n", buffer);
    write(new_socket, response, strlen(response));
    close(new_socket);
}
void lunch(struct Server *server)
{
    char buffer[30000];
    int address_len = sizeof(server->address);
    char *response = "<h1>Hello World</h1>";
    printf("in the lunch function\n");
    int new_socket;
    while (1)
    {
        printf("in the while");
        printf("=====Waiting For Connection======");
        new_socket = accept(server->socket, (struct sockaddr *)&server->address, (socklen_t *)&address_len);
        if (new_socket < 0)
        { //mean fail
            perror("In accept");
            exit(EXIT_FAILURE);
        }

        // read(new_socket, buffer, 30000);
        // printf("%s\n", buffer);
        // write(new_socket, response, strlen(response));
        // close(new_socket);
        // read_write(new_socket, buffer, response);
        pthread_t thread_id;
        myarg_t args = {new_socket, response};
        if (pthread_create(&thread_id, NULL, *read_write, &args) != 0)
        {
            perror("In Thread Creation");
            exit(EXIT_FAILURE);
        }
    }
}

int main()
{
    struct Server server = server_constructor(AF_INET, SOCK_STREAM, 0, INADDR_ANY, 8090, 1, lunch);
    server.launch(&server);
    fork();
}