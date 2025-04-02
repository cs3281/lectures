#include <sys/types.h>		// Definition of data types used in syscalls
#include <sys/socket.h>		// Structures needed for sockets
#include <netinet/in.h>		// Constant and structures needed for internet domain addresses
#include <stdio.h>			// For I/O
#include <unistd.h>			// For close
#include <assert.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/******************************
 * Example of socket (client) *
 *****************************/

int main(int argc, char *argv[]) {
	// Create socket
	int fd = socket (AF_INET, SOCK_STREAM, 0);
	assert (fd >= 0);

	// Configure settings of the server address struct
	struct sockaddr_in serv_addr;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_addr.sin_port = htons(8080);

	// Connect to server
	int retVal = connect (fd, (struct sockaddr *) &serv_addr, sizeof (serv_addr));
	assert (retVal != -1);	
	
	// Receive data from server
	char buffer [256];
	retVal = read (fd, buffer, sizeof (buffer));
	assert (retVal != 0);

	// Display server's response.
	printf ("Response status = %d Server reply: %s\n", retVal, buffer);

	// Done. Close connection socket
	close (fd);

	return 0; 
}
