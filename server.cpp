// Server side code
/* The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h> // Include this header file for using socket feature in the code
#include <netinet/in.h>
#include <arpa/inet.h>  // Library having inet_ntoa
#include <string>
#include <ctime>
#include <iostream>

/*
NOTE: For socket programming in Linux/UNIX based compilers, usage of ‘sys/socket.h’ is recommended. 
To run it on Windows OS, usage of WinShock.h is mandatory. 
Also, you can use Cygwin to run these programs on Windows OS
https://www.educba.com/socket-programming-in-c-plus-plus/
*/

using namespace std;

void error(const char *msg){
    // Funtion to print the error messages
    perror(msg);
    exit(1);
}

int main(){
    int port_no = 5555;
    int master_sock, new_sock; // declare variables for file descriptor(socket), new socket formed and port number.
    socklen_t cli_addr_len; // create an object for connecting client address length.
    char buffer[256]; // What for?
    char * out_msg = "FROM SERVER: How are you?";
    // string msg_to_client;
    struct sockaddr_in server_addr,client_addr; // What is the story?
    int n; // variable to take incoming transmission from client

   
    // STEP 1 : Creating socket file descriptor using socket() function. This is the Master socket
    // int socket ( int domain, int type, int protocol );
    // Returns a file descriptor for the socket or -1 on error.

    if ((master_sock = socket(AF_INET, SOCK_STREAM,0)) < 0){
      // Beautiful way of saying, if this returns a 0, then it fails, else, it worked!
       perror("ERROR opening socket");
       exit(EXIT_FAILURE);
       }

    else {
        printf("SUCCESS opening socket");
    }


    // STEP 2 : Bind created socket to the server IP address and port number.
    /*
     bind(int fd, struct sockaddr *local_addr, socklen_t addr_length)
     Returns 0 on success and -1 on error.
     bind() passes:
       - file descriptor
       - the address structure 
       - and the length of the address structure
     This bind() call will bind  the socket to the current IP address on port, portno
     
    */
    
    /*
    We can use Setsockopted if we need to reuse the address and port. It is optional.
    */

    server_addr.sin_family = AF_INET; // server byte order
    server_addr.sin_addr.s_addr = INADDR_ANY; // automatically be filled with current host's IP address. I don't have to edit anything.
    server_addr.sin_port = htons(port_no); // convert short integer value for port must be converted into network byte order

    /*
    - sin_family = specifies the address family, usually the constant AF_INET
    - sin_addr = holds the IP address returned by inet_addr() to be used in the socket connection.
    - sin_port = specifies the port number and must be used with htons() function that converts the host byte order to 
      network byte order so that it can be transmitted and routed properly when opening the socket connection. 
      The reason for this is that computers and network protocols order their bytes in a non-compatible fashion.
    */

    if (bind(master_sock, (struct sockaddr*)&server_addr, sizeof(server_addr))< 0){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    else{
        printf("\nSuccessfull bind of socket to port 5555 and address = server IP");
    }

    int i = 0;
    while (i<1){
        
        // STEP 3 : Get into Listening process
        /*
        int listen(int fd, int backlog_queue_size)
        Returns 0 on success and -1 on error.
         - This listen() call tells the socket to listen to the incoming connections, and a subsequent accept() call actually accepts an incoming connection.
         - The listen() function places all incoming connection into a backlog queue until accept() call accepts the connection.
         - We set the maximum size for the backlog queue to 5.
        The listen method is used to keep socket inactive when it waits for the client-server connection to establish.
        */
       
        if (listen(master_sock, 5) < 0) {
            perror("listen failed");
            exit(EXIT_FAILURE);
        }
    
        else{
            printf("\nNow in listening state.....\n");
        }
        
        // STEP 4 : Accepting incoming connections.
        /*
        new_sock = accept(master_sock , struct sockaddr *remote_host, socklen_t addr_length)

        Accept method will have the very first connection request on the pending connection list in the socket. 
        As it will create a new socket that is already connected and return a new file descriptor. 
        This is the point of contact between server and client where your socket is ready for transferring data.

        The accept() returns a new socket file descriptor for the accepted connection.So, the original socket file 
        descriptor can continue to be used for accepting new connections while the new socker file descriptor is used 
        for communicating with the connected client.
        */

        cli_addr_len = sizeof(client_addr);

        if ((new_sock = accept(master_sock, (struct sockaddr *)&client_addr, &cli_addr_len))< 0) {
            perror("ERROR on accept");
            exit(EXIT_FAILURE);
        }

        else{
            // current date/time based on current system
            time_t now = time(0);
            // convert now to string form
            char* dt = ctime(&now);
            cout<<"\nTIME : " << dt << endl;
            printf("Connection from %s port %d\n",inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        }
      
        /*
        $ man inet_ntoa  ... for more details.

        The inet_ntoa() function converts the Internet host address in, given  in  net‐
        work  byte  order,  to a string in IPv4 dotted-decimal notation.
        */
        bzero(buffer,256);
        n = read(new_sock, buffer, 1024);
        printf("%s\n", buffer);

        send(new_sock, out_msg, strlen(out_msg), 0);
        printf("Return message sent\n");

        // closing the connected socket
        close(new_sock);

        // closing the listening socket. If I don't want it to be constantly up??
        // shutdown(master_sock, SHUT_RDWR);

    }
    
    return 0;
}