/*#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

using namespace std;

const int BUFSIZE = 65536;

int main() {
    int sock;
    sockaddr_in server_addr;

    // Create a socket for the client
    sock = socket(AF_INET, SOCK_STREAM, 0);

    // Connect to the server
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(1194);
    //connect(sock);
    //connect(socketDescriptor,(struct sockaddr *) &socketInfo,sizeof(socketInfo));
    connect(sock,(struct sockaddr *) &server_addr,sizeof(server_addr));
}*/


#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

using namespace std;

const int BUFSIZE = 65536;

int main() {
    int sock;
    sockaddr_in server_addr;

    // Create a socket for the client
    sock = socket(AF_INET, SOCK_STREAM, 0);

    // Connect to the server
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(1194);
    //connect(sock);
    //connect(socketDescriptor,(struct sockaddr *) &socketInfo,sizeof(socketInfo));
    connect(sock,(struct sockaddr *) &server_addr,sizeof(server_addr));
    char buffer[BUFSIZE];
    char server_data_received_buffer[BUFSIZE];
    recv(sock, server_data_received_buffer, BUFSIZE, 0);
    
    strcpy(buffer, "This is the client!\n");
    cout << server_data_received_buffer << endl;
    send(sock, buffer, strlen(buffer), 0);


}