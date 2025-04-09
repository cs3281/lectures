#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <netdb.h>
#include <errno.h>
#include <signal.h>
#include <ctype.h>

#define BUFFER_LEN 100

void* handle_client(void* arg) {
  long client_fd = (long)arg;
  char buf[BUFFER_LEN];
  int num_bytes; 
  
  pthread_detach(pthread_self());
  while((num_bytes = read(client_fd, buf, sizeof(buf))) > 0) {  
                
       buf[num_bytes] = '\0';
     
       printf("server received %d bytes for %s", num_bytes, buf);
       write(client_fd, buf, strlen(buf));
  }
    
  close(client_fd); 
}	

void exit_with_error(char* msg) {
  perror(msg);
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
  inet_pton(AF_INET, "127.0.0.1", &in_addr.sin_addr);

  int connect_res = connect(fd, (struct sockaddr*)&in_addr, sizeof(struct sockaddr_in));
    
  if(connect_res == -1) {
   perror("connect");
   exit(1);
  }
   
  char str[BUFFER_LEN] = "Hello, from client!"; 
  int num_bytes;
  
  while((num_bytes = read(0, str, sizeof(str))) > 0) {
    str[num_bytes] = '\0';
    num_bytes = write(fd, str, strlen(str));
    num_bytes = read(fd, str, sizeof(str));
    str[num_bytes] = '\0';
    printf("client receieved %s", str); 
  }  
  close(fd); 
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
   
  long client_fd;
  struct sockaddr_in client_addr;

  
  memset(&client_addr, 0, sizeof(struct sockaddr_in));
  socklen_t addr_size = sizeof(struct sockaddr_in);

  while(1) {
    client_fd = accept(fd, (struct sockaddr*)&client_addr, &addr_size);      
    printf("accepted a client. client_fd=%ld\n", client_fd); 

    if(client_fd == -1) {
     perror("accept");
     exit(1);
    }    
    
    char buf[BUFFER_LEN];
    int num_bytes; 
     
    pthread_t t;
    pthread_create(&t, NULL, handle_client, (void*) client_fd);
    //pthread_join(t, NULL);
    /*while((num_bytes = read(client_fd, buf, sizeof(buf))) > 0) {  
                
       buf[num_bytes] = '\0';
     
       printf("server received %d bytes for %s", num_bytes, buf);
       write(client_fd, buf, strlen(buf));
    }
    close(client_fd);*/    
  }       
}

int main(int argc, char* args[]) {
  if(argc > 1) {
   client(atoi(args[1]));	  
  } else {
      server();	  
  }	  
}	
