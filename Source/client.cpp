#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;

int main(int argc, char *argv[])
{
    int client_fd;
    struct sockaddr_in server_addr;
    char buffer[1024];
    int n;

    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(1194);

    connect(client_fd, (struct sockaddr *) &server_addr, sizeof(server_addr));

    while (1)
    {
        cout << "Client: ";
        cin.getline(buffer, 1024);
        write(client_fd, buffer, strlen(buffer));
        n = read(client_fd, buffer, 1024);
        buffer[n] = '\0';
        cout << "Server: " << buffer << endl;
    }
}
