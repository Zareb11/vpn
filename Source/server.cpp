#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

using namespace std;

const int BUFSIZE = 65536;

int main() {
    int server_sock, client_sock;
    sockaddr_in server_addr, client_addr;
    int client_addr_size;

    // Create a socket for the server
    server_sock = socket(AF_INET, SOCK_STREAM, 0);

    // Bind the socket to an IP address and port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    //server_addr.sin_port = htons(1194);
    server_addr.sin_port = htons(1194);
    //12345
    bind(server_sock, (sockaddr*)&server_addr, sizeof(server_addr));

    // Listen for incoming connections
    listen(server_sock, 5);

    while (true) {
        // Accept an incoming connection
        client_addr_size = sizeof(client_addr);
        client_sock = accept(server_sock, (sockaddr*)&client_addr, (socklen_t*)&client_addr_size);

        // Send a message to the client
        char buffer[BUFSIZE];
        char recv_buffer_data[BUFSIZE];

        strcpy(buffer, "Welcome to the VPN!\n");
        send(client_sock, buffer, strlen(buffer), 0);

        // Receive data from the client
        recv(client_sock, recv_buffer_data, BUFSIZE, 0);
        cout << "Received: " << recv_buffer_data << endl;

        // Close the client socket
        close(client_sock);
    }

    // Close the server socket
    close(server_sock);

    return 0;
}
