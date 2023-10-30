#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <pthread.h>

void thread_func(void* arg) {
  long client_fd = (long)arg;

  char buf[100];
  int num_bytes = 0;
  while((num_bytes = read(client_fd, buf, sizeof(buf) - 1)) > 0) {
      buf[num_bytes] = '\0';

      if(strcmp(buf, "quit") == 0) {
       break;       
      }

      printf("server received %d bytes for %s\n", num_bytes, buf);
 
      for(int i = 0; i < num_bytes; ++i) {
        buf[i] = toupper(buf[i]);	    
      }

      if(num_bytes == -1) {
       perror("read");
       exit(1);
      }
          
      write(client_fd, buf, num_bytes);
  }

  write(client_fd, "Done", 4);
  close(client_fd);  
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
      
  char str[100];
  int num_bytes, total = 0;  
  while((num_bytes = scanf("%s", str)) > 0) {
    num_bytes = write(fd, str, strlen(str));        
    
    if(num_bytes == -1) {
     perror("write");
     exit(1);
    }

    char buf[100];
    int size = 100;    

    num_bytes = read(fd, buf, sizeof(buf) - 1);             
   
    buf[num_bytes] = '\0';
    printf("%s\n", buf);

    if(strcmp(buf, "Done") == 0) {
     break;	    
    }	    
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
  in_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  in_addr.sin_port = htons(5050);

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
  struct sockaddr_storage client_addr;
  memset(&client_addr, 0, sizeof(struct sockaddr_storage));
  socklen_t addr_size = sizeof(struct sockaddr_storage);

  while(1) {
    client_fd = accept(fd, (struct sockaddr*)&client_addr, &addr_size);

    if(client_fd == -1) {
     perror("accept");
     exit(1);
    }

    pthread_t client_thread;
    pthread_create(&client_thread, NULL, thread_func, (void*)client_fd);    
  }  
}

int main(int argc, char* args[]) {
  if(argc > 1) {
   client(atoi(args[1]));	  
  } else {
      server();	  
  }	  
}	
