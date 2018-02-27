#include "net.h"

#include <cstdio>
#include <cstdlib>

int main(int argc, char ** argv) {
    int port = (argc >= 2) ?
        atoi(argv[1]) : 10000;
    int buffer_size = (argc >= 3) ?
        atoi(argv[2]) : 100;

    conn_t conn;
    printf("Starting client to port %d...\n", port);
    start_client(conn, "127.0.0.1", port);

    char * buffer = new char[buffer_size];
    for (int i = 0; i < buffer_size; i++) {
        buffer[i] = (char)(i % 256);
    }
    printf("Sending %d bytes...\n", buffer_size);
    int sent = send_data(conn, buffer, buffer_size);
    if (sent <= 0) {
        printf("Problem occured.");
    }

    delete [] buffer;
    close_conn(conn);
}
