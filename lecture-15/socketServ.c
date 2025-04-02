#include <sys/types.h>		// Definition of data types used in syscalls
#include <sys/socket.h>		// Structures needed for sockets
#include <netinet/in.h>		// Constant and structures needed for internet domain addresses
#include <stdio.h>			// For I/O
#include <errno.h>			// For error management
#include <stdlib.h>			// For exit function
#include <string.h>			// For strerror
#include <unistd.h>	
#include <ctype.h>			// For toupper
#include <assert.h>
#include <string.h>

int main(int argc, char *argv[]) {

	int serv_fd = socket (AF_INET, SOCK_STREAM, 0);
	assert (serv_fd != -1);

	struct sockaddr_in serv_addr;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(8080);

	int retVal = bind (serv_fd, (struct sockaddr *) &serv_addr, sizeof (serv_addr));
	assert (retVal != -1);

	listen(serv_fd, 1);	// Backlog 1 request
	printf("Listening...\n");
       
        while(1) {	
	int client_fd = accept (serv_fd, (struct sockaddr*)NULL, NULL);
	assert (client_fd != -1);
	printf("Connection accepted\n");
	char msg[] = "Hello World!"; 
	retVal = write (client_fd, msg, sizeof(msg));
	assert (retVal >= 0);

	close (client_fd);
	}
	close (serv_fd);

	return 0; 
}
