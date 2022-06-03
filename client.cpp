
// Client side C/C++ program to demonstrate Socket
/*
https://www.bogotobogo.com/cplusplus/sockets_server_client.php
Client Socket
create a socket.
bind* - this is probably be unnecessary because you're the client, not the server.
connect to a server.
send/recv - repeat until we have or receive data
shutdown to end read/write.
close to releases data.
*/
// programming
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
#define PORT 5555

using namespace std;
 
int main(int argc, char const* argv[])
{
    int sock = 0, valread, client_fd;
    struct sockaddr_in serv_addr;
    char* hello = "FROM CLIENT : Hello from client";
    char buffer[1024] = { 0 };
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error \n");
        return -1;
    }

    else {
        printf("Socket created successfully.........\n");
    }
 
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
 
    // Convert IPv4 and IPv6 addresses from text to binary

    if (inet_pton(AF_INET, "192.168.1.111", &serv_addr.sin_addr)<= 0) {
        printf("Invalid address/ Address not supported \n");
        return -1;
    }
    
    if ((client_fd = connect(sock, (struct sockaddr*)&serv_addr,sizeof(serv_addr)))< 0) {
        printf("Connection Failed \n");
        return -1;
    }
    
    else{
        printf("Connection established with server.....\n");

    }

    send(sock, hello, strlen(hello), 0);
    printf("Message sent to server...\n");
    valread = read(sock, buffer, 1024);
    printf("%s\n", buffer);
 
    // closing the connected socket
    close(client_fd);
    return 0;
}