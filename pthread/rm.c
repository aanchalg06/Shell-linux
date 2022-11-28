#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <stdbool.h>


int main(int argc, char const *argv[])
{
    int file_rmv = remove(argv[1]);
    if(file_rmv == 0){
        printf("File Removed successfully" );
        printf("\n");
            }

    else{
        printf("File removal failed");
        printf("\n");
            }
	
	return 0;
}