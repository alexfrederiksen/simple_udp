#include "net.h"

#include <cstdio>
#include <cstdlib>

#define BYTE_WIDTH 8
int main(int argc, char ** argv) {
    int port = (argc >= 2) ? 
        atoi(argv[1]) : 10000;
    int buffer_size = (argc >= 3) ?
        atoi(argv[2]) : 100;

    conn_t conn;
    printf("Starting server on port %d...\n", port);
    int status = start_server(conn, port);
    if (status == -1) printf("Unable to start server...\n");
    
    char * buffer = new char[buffer_size];
    printf("Waiting for %d bytes...\n", buffer_size);
    int got = recv_data(conn, buffer, buffer_size, 10000);
    if (got > 0) {
        printf("Got %d bytes: \n", got);
        for (int i = 0, c = 1; i < got; i++, c++) {
            printf(" %3d ", (int) buffer[i]);
            if (c >= BYTE_WIDTH) {
                printf("\n");
                c = 0;
            }
        }
        printf("\n");
    } else {
        printf("Problem occured.\n");   
    }

    delete [] buffer;
    close_conn(conn);
}
