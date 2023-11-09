#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void exit_with_error(char *msg)
{
  perror(msg);
  exit(1);
}

void client(char *msg)
{
  int fd;
  if ((fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    exit_with_error(0);

  struct sockaddr_in in_addr;
  memset(&in_addr, 0, sizeof(struct sockaddr_in));
  in_addr.sin_family = AF_INET;
  in_addr.sin_port = htons(5050);
  inet_pton(AF_INET, "127.0.0.1", &in_addr.sin_addr);

  if (connect(fd, (struct sockaddr *)&in_addr, sizeof(struct sockaddr_in)))
    exit_with_error("Client error with connect");

  int ret, sent = 0;
  while (sent != strlen(msg)) {
    ret = write(fd, msg + sent, strlen(msg) - sent);
    printf("sent bytes: %d\n", ret);
    if (ret == -1)
      exit_with_error("Client error with write");
    else
      sent += ret;
    printf("sent = %d\n", sent);
  }

  close(fd);
}

void server()
{
  int fd;
  if ((fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    exit_with_error("Server error with socket");

  struct sockaddr_in in_addr;
  memset(&in_addr, 0, sizeof(struct sockaddr_in));
  in_addr.sin_family = AF_INET;
  in_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  in_addr.sin_port = htons(5050); 

  if (bind(fd, (struct sockaddr *) &in_addr, sizeof(struct sockaddr_in)))
    exit_with_error("Server error with bind");

  if (listen(fd, 10))
    exit_with_error("Server error with listen");

  int client_fd;
  struct sockaddr_storage client_info;
  memset(&client_info, 0, sizeof(struct sockaddr_storage));
  socklen_t client_size = sizeof(struct sockaddr_storage);
  
  if ((client_fd = accept(fd, (struct sockaddr *) &client_info, &client_size)) == -1)
    exit_with_error("Server error with accept");

  char buf[100];
  int ret, total = 0;
  while ((ret = read(client_fd, buf + total, sizeof(buf) - 1 - total))) {
    if (ret == -1)
      exit_with_error("Server error with read");
    total += ret;
  }

  buf[total] = 0;
  printf("Server received: %s, total = %d\n", buf, total);
}

int main(int argc, char *argv[])
{
  if (argc > 1)
      client(argv[1]);
  else
    server();
}
