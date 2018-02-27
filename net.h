#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/select.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

/* Stores a connection between two sockets */
struct conn_t {
	int local_socket;
	sockaddr_in remote_addr; 
	socklen_t addr_len;
};

int send_data(conn_t & conn, char * buffer, int buffer_len);

int recv_data(conn_t & conn, char * buffer, int buffer_len, int time_out, bool get_all = false);

int start_server(conn_t & conn, int port);

int start_client(conn_t & conn, char * server_addr, int port);

void close_conn(conn_t & conn);

