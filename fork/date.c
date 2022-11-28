#include <time.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    time_t T = time(NULL);
    struct tm tm = *localtime(&T);

	if(argc==1){
	time_t T = time(NULL);
    struct tm tm = *localtime(&T);
    printf("System Date is: %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    printf("System Time is: %02d:%02d:%02d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
	}

	if(strcmp(argv[1],"-I\n")==0){
    printf("System Date is: %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	}
	else if (strcmp(argv[1],"-R\n")==0){
    printf("System Date is: %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    printf("System Time is: %02d:%02d:%02d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
	}
    else{
        printf("Some error occured\n");
    }

}