#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <libgen.h> 
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>
#include <dirent.h>
#include <stddef.h>
#include <pthread.h>
#include <stdbool.h>

const char* run_command;

void *fnc(void* arg){
    system(run_command);
}

int main(char** argv,int argc){
    printf("Shell in C!! Assignment 1 || OS");
    printf("\n");

	char cwd_folder[1024];
    char *directory=getcwd(cwd_folder, sizeof(cwd_folder));
    if ((directory) != NULL){
		printf("Present directory(cwd string): %s", cwd_folder);
        printf("\n");
    }
	else {
    	printf("getcwd failed\n");
        printf("\n");
    }
	
	char commands_input[1024];
    // printf("%s ",commands_input);
    printf("\n");

    bool t= true;
    while(t){
    printf("Input commands!!");
        printf("\n");
		fgets(commands_input,1024,stdin);

    if(commands_input==NULL){
            printf("no inputs are there hence breaking the loop");
            printf("\n");
			
		}

    int size= strlen(commands_input);
    commands_input[size-1]='\0';
    // printf("%s..hello",commands_input);


    // char commands_input[] ="abc/qwe/ccd";
    int i = 0;
    char *p = strtok (commands_input, " ");
    char *array[80];
    while (p != NULL)
    {
        array[i++] = p;
        p = strtok (NULL, " ");
    }
    array[i]=NULL;

    // for (i = 0; i < 1; i++) 
    //     printf("%s\n", array[i]);

    char command[200]="";
    
    if(strcmp(array[0],"&t")==0){
        pthread_t thread;
        int x=1;
        while(array[x]!=NULL){
            strcat(command,array[x]);
            strcat(command," ");
            x++;
        }

        run_command=command;

        // printf("%s",command);
        // printf("hello");

        pthread_create(&thread,NULL,fnc,(void*)&thread);
        pthread_join(thread,NULL);
    }
// ls -m
    else{
        int x=0;
        // printf("hello2");
        while(array[x]!=NULL){
            strcat(command,array[x]);
            strcat(command," ");
            x++;
        }
        // printf("%s",command);
        // printf("debug");
        system(command);
        // printf("%s",command);
        
    }
    
    }

    return 0;
}