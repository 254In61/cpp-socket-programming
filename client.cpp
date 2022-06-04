
// Client side C/C++ program to demonstrate Socket programming
#include <arpa/inet.h> 
#include <string.h>
#include <unistd.h> 
#include <iostream> 
#include <string>
#define PORT 5555

using namespace std;

void chat_function(int client_sock){
    // Exchange of messages between client and server
    
    char* out_msg = "FROM CLIENT : Hello from client";

    send(client_sock, out_msg, strlen(out_msg), 0);
    cout << "SUCCESS. Message sent to server...."<< endl;
    

    char buffer[1024]; // Create a char array that will contain the returned message
    int returned_output = read(client_sock, buffer, 1024);

    if (returned_output < 0){
        cout<< "ERROR reading from socket" << endl;
    }

    else{
        cout<< buffer << endl;
    }

    close(client_sock); // Close socket
}
 
int main()
{   
    // Define client socket variable and create the socket using socket() function
    int client_sock; // Declare variables for client_sock file descriptor, port number
    struct sockaddr_in addr; // Create an object out of the the struct sockaddr_in


    client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sock < 0) {
        cout << "\nERROR! Socket not created "<<endl;
        return -1;
    }

    else {
        cout<<"\nSUCCESS. Socket created..."<< endl;
    }
    
    /* Create an object out of sockaddr_in struct found in netinet/in.h and use the member functions */
    addr.sin_family = AF_INET; 
    addr.sin_port = htons(PORT);  
    
    if (inet_pton(AF_INET,"192.168.1.111", &addr.sin_addr)<= 0) {
        cout<< " ERROR. IP could be invalid or not supported"<< endl;
        return -1;
    }
    
    /*
    int connect(int fd, struct sockaddr *remote_host, socklen_t addr_length)
    - Connects a socket (described by file descriptor fd) to a remote host.
    - Returns 0 on success and -1 on error. Until the return is back i.e 0 or -1 , nothing else happens, hence called 'blocking call'.
    - The connect() system call connects the socket referred to by the file descriptor to the address specified by addr. 
    - Server’s address and port is specified in addr.
    
    */

    int create_connection = connect(client_sock, (struct sockaddr*)&addr, sizeof(addr));
    if (create_connection < 0) {
        cout << "ERROR. Connection creation failed"<< endl;
        return -1;
    }
    
    else{
        cout << "SUCCESS. Connection created...."<< endl;

    }

    // = 0, valread, client_fd;
   
    chat_function(client_sock);
    
    return 0;
}