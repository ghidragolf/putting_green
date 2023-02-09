// decompiler

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h> // for close

#define PORT 25

int main(int argc, char *argv[])
{
    int sockfd, port;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];

    if (argc < 2) {
        fprintf(stderr,"usage %s hostname\n", argv[0]);
        exit(0);
    }

    port = PORT;
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    // create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        perror("ERROR opening socket");

    // set up the server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // connect to the server
    if (connect(sockfd, (const struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
        perror("ERROR connecting");

    // send the SMTP request
    memset(buffer, 0, 1024);
    strcpy(buffer, "HELO smtp.example.com\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0)
        perror("ERROR writing to socket");

    // get the response
    memset(buffer, 0, 1024);
    if (recv(sockfd, buffer, 1023, 0) < 0)
        perror("ERROR reading from socket");

    printf("Received response: %s\n", buffer);

    close(sockfd);
    return 0;
}