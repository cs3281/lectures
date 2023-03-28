#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void exit_with_error(char* msg) {
  perror("msg");
  exit(1);  
}	

void client(int port) {
  struct sockaddr_in in_addr;
  memset(&in_addr, 0, sizeof(struct sockaddr_in));

  int fd = socket(AF_INET, SOCK_STREAM, 0);
  if(fd == -1) {
   perror("socket");
   exit(1);   
  }

  in_addr.sin_family = AF_INET; 
  in_addr.sin_port = htons(port);
  inet_pton(AF_UNIX, "127.0.0.1", &in_addr.sin_addr);

  int connect_res = connect(fd, (struct sockaddr*)&in_addr, sizeof(struct sockaddr_in));  
  if(connect_res == -1) {
   perror("connect");
   exit(1);
  }
  
  char* str = "Hello, server!";     
  int num_bytes, total = 0; 
  while(strlen(str) != total) {
    num_bytes = write(fd, str + total, strlen(str) - total);    
    if(num_bytes == -1) {
     exit_with_error("Client failed to write");	    
    }	    
    
    total += num_bytes;
  } 
}	

void server() {
  struct sockaddr_in in_addr;
  memset(&in_addr, 0, sizeof(struct sockaddr_in));

  int fd = socket(AF_INET, SOCK_STREAM, 0);
  if(fd == -1) {
   perror("socket");
   exit(1);   
  }

  in_addr.sin_family = AF_INET;
  in_addr.sin_port = htons(3000);
  in_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  

  int bind_res = bind(fd, (struct sockaddr*)&in_addr, sizeof(struct sockaddr_in));
  if(bind_res == -1) {
   perror("bind");
   exit(1);   
  }

  int lis_res = listen(fd, 1);
  if(lis_res == -1) {
   perror("listen");
   exit(1);	  
  }	  
   
  int client_fd;
  struct sockaddr_in client_addr;

  
  memset(&client_addr, 0, sizeof(struct sockaddr_in));
  socklen_t addr_size = sizeof(struct sockaddr_in);

  
  client_fd = accept(fd, (struct sockaddr*)&client_addr, &addr_size);  

  if(client_fd == -1) {
   perror("accept");
   exit(1);
  }

  char buf[100];
  int num_bytes, total = 0; 
  
  while((num_bytes = read(client_fd, buf + total, sizeof(buf) - total - 1)) > 0) {    
    if(num_bytes == -1) {
     exit_with_error("Client failed to write");     
    }

    total += num_bytes;
   
    buf[total] = '\0';
    printf("server received %d bytes for %s from %d\n", total, buf, client_addr.sin_addr.s_addr);        
  }  
}

int main(int argc, char* args[]) {
  if(argc > 1) {
   client(atoi(args[1]));	  
  } else {
      server();	  
  }	  
}	
