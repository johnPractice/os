

#ifndef Server_h
#define Server_h

#include <sys/socket.h>
#include <netinet/in.h>

// MARK: DATA TYPES

struct Server
{
    /* PUBLIC MEMBER VARIABLES */
    int domain;
    int service;
    int protocol;
    u_long interface;
    int port;
    int backlog;
    struct sockaddr_in address;
    int socket;

    void (*launch)(struct Server *server);
};

// MARK: CONSTRUCTORS

struct Server server_constructor(int domain, int service, int protocol, u_long interface, int port, int backlog, void (*launch)());

#endif /* Server_h */
