#include <WinSock2.h>

/**
 * Creats a windows socket, output to the socket_out ptr.
 * Returns non-zero when there is an error.
*/
int create_socket(int port, SOCKET* socket_out);