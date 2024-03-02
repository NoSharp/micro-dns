#include "nt_udp.h"
/**
 * Creats a windows socket, output to the socket_out ptr.
 * Returns non-zero when there is an error.
*/
int create_socket(int port, SOCKET* socket_out){

  SOCKET sock;
  WSADATA wsa;

  if(WSAStartup(MAKEWORD(2,2), &wsa) != 0){
    return 1;
  }

  sock = socket(AF_INET, SOCK_DGRAM, 0);

  if(sock == INVALID_SOCKET){
    return 2;
  }

  struct sockaddr_in server_ip;
  server_ip.sin_port = port;
  server_ip.sin_addr.S_un.S_addr = INADDR_ANY;
  server_ip.sin_family = AF_INET;

  if(bind(sock, (struct sockaddr*)&server_ip, sizeof(server_ip)) == SOCKET_ERROR){
    return 3;
  }

  *socket_out = sock;
  return 0;
}
