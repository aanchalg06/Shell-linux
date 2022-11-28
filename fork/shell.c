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
#include <stdbool.h>

char* join_str(char* direc,char* join_s){
    size_t len = strlen(direc);
    
    int i=0;
    while(join_s[i]!='\0'){
        direc[len+i]= join_s[i];
        i++;
    }
    direc[len+i]=='\0';
    return direc;

}

int main(){
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
    printf("%s ",commands_input);
    printf("\n");
    bool flag= true;
	
	do{
        printf("Input commands!!");
        printf("\n");
		fgets(commands_input,1024,stdin);

		if(commands_input==NULL){
            printf("no inputs are there hence breaking the loop");
            printf("\n");
			break;
		}

		char *internal_command[3]={"echo","cd","pwd"};
		
		char new_cwd[1024];
        char pwd_path[1024];
		char* sep=" ";


		char **ret = malloc(20 * sizeof(char *));

    	char *startp = commands_input, *endp;
    	size_t l = strlen(sep);
    	int cnt = 0;

    while (endp = strstr(startp, sep))
    {
        ptrdiff_t diff = endp - startp;
        ret[cnt] = malloc(diff + 1);
        strncpy(ret[cnt], startp, diff);
        ret[cnt][diff] = '\0';
        cnt++;
        startp = endp + l;
    }

    if (*startp) // in case last is not a separator
    {
        ret[cnt] = malloc(strlen(startp) + 1);
        strcpy(ret[cnt], startp);
        cnt++;
    }

    ret[cnt] = NULL;

    // for(int i=0;i<cnt;i++){
    //     printf("%s ",ret[i]);
    //     printf("\n");
    // }
       
		
		if(strcmp(ret[0],internal_command[0])==0){
			flag=false;

			if(strcmp(ret[1],"-n")==0){
                printf("Echo command in process!!");
                printf("\n");
                cnt=2;
                while(ret[cnt]!=NULL){
                    printf("%s ",ret[cnt]);
                    printf("\n");
                    cnt++;
                }
                printf("\n");
			}

			else if(strcmp(ret[1],"-e")==0){
                printf("Echo command in process!!");
                printf("\n");
				cnt=2;
                while(ret[cnt]!=NULL){
                    if(ret[cnt]=="\n"){
                        printf("\n");
                    }
                    else{
                    printf("%s ",ret[cnt]);
                    printf("\n");
                    }
                    cnt++;
                }
                printf("\n");
                
			}

            else{
                printf("Some non recognised input recieved !!! try again\n");
				
			}
		}

		else if(strcmp(ret[0],internal_command[1])==0){
			
			flag=false;
			if(ret[1]==NULL){
				char cd_direc[1024];
    			char *direc=getcwd(cd_direc, sizeof(cd_direc));
				if(direc==NULL){
					printf("Error occurred");
                    printf("\n");
				}
				else{
				printf("%s",direc);
                printf("\n");
                }
			}
			else{
				char *new_dir;

				if(chdir(ret[1])==-1){
					printf("Some error occurred\n");
                    printf("\n");
				}
				else if(chdir(ret[1])==0){
					new_dir=getcwd(new_cwd,sizeof(new_cwd));
					printf("New directory is: %s",new_dir);	
                    printf("\n");				
				}
				
			}
		}

		else if(strcmp(ret[0],internal_command[2])==0){
			flag=false;
			getcwd(pwd_path,sizeof(pwd_path));
			printf("Current Directory : %s\n", pwd_path);
			printf("\n" );
		}
	
		if(fork()==0){
			
			if(strcmp(ret[0],"ls\n")==0){
                // printf("goodie");
                printf("\n");
                char* join_s="/ls_";
                // char new_cwd_folder[1024];
                // char *new_directory=getcwd(new_cwd_folder, sizeof(new_cwd_folder));
                // new_directory= join_str(new_directory,join_s);
				// execv(new_directory,ret);
                directory= join_str(directory,join_s);
				execv(directory,ret);
			}

            if(strcmp(ret[0],"ls")==0){
                // printf("1");
                // printf("\n");
                // printf("goodie");
                char* join_s="/ls_";
                char new_cwd_folder[1024];
                char *new_directory=getcwd(new_cwd_folder, sizeof(new_cwd_folder));
                new_directory= join_str(new_directory,join_s);
				execv(new_directory,ret);
                directory= join_str(directory,join_s);
				execv(directory,ret);
                printf("\n");
			}

            // else if(strcmp(ret[0],"cat")==0){

            //     if(ret[1]==NULL){
            //         printf("No file name given\n Renter command with cat filename");
            //         printf("\n");
            //     }
            //     char* join_s="/cat_";
            //     char new_cwd_folder[1024];
            //     char *new_directory=getcwd(new_cwd_folder, sizeof(new_cwd_folder));
            //     new_directory= join_str(new_directory,join_s);
			// 	// execv(new_directory,ret);
            //     directory= join_str(directory,join_s);
			// 	execv(directory,ret);
			// }

            if(strcmp(ret[0],"cat\n")==0){
                // printf("goodie");
                // printf("\n");
                // char* join_s="/cat_";
                // char new_cwd_folder[1024];
                // char *new_directory=getcwd(new_cwd_folder, sizeof(new_cwd_folder));
                // new_directory= join_str(new_directory,join_s);
				// execv(new_directory,ret);
                printf("\n");
					printf("No file given");
                    printf("Renter the command with format cat filename");
                    printf("\n");
				// }
                // directory= join_str(directory,join_s);
				// execv(directory,ret);
			}

            if(strcmp(ret[0],"cat")==0){
                // printf("1");
                // printf("\n");
                // printf("goodie");
                char* join_s="/cat_";
                char new_cwd_folder[1024];
                char *new_directory=getcwd(new_cwd_folder, sizeof(new_cwd_folder));
                new_directory= join_str(new_directory,join_s);
				// execv(new_directory,ret);
                directory= join_str(directory,join_s);
				execv(directory,ret);
                printf("\n");
			}

            else if(strcmp(ret[0],"date")==0){
                char* join_s="/date_";
                directory= join_str(directory,join_s);
				execv(directory,ret);
			}

			

			else if(strcmp(ret[0],"rm\n")==0){
				// if(ret[1]==NULL){
                    printf("\n");
					printf("Nothing to remove given");
                    printf("Renter the command with format rm filename or rm -i filename");
                    printf("\n");
				// }
				// else{
                    // char* join_s="/rm_";
                    // char new_cwd_folder[1024];
                    // char *new_directory=getcwd(new_cwd_folder, sizeof(new_cwd_folder));
                    // new_directory= join_str(new_directory,join_s);
				    // execv(new_directory,ret);
			// }
            }

            else if(strcmp(ret[0],"rm")==0){
                char* join_s="/rm_";
                    // char new_cwd_folder[1024];
                    // char *new_directory=getcwd(new_cwd_folder, sizeof(new_cwd_folder));
                    // new_directory= join_str(new_directory,join_s);
				    // execv(new_directory,ret);
                directory= join_str(directory,join_s);
				execv(directory,ret);
            }


			else if(strcmp(ret[0],"mkdir")==0){
                char* join_s="/mkdir_";
                directory= join_str(directory,join_s);
				execv(directory,ret);
			}

			else {
				if(flag==true)
					printf("Command not found\n");
                    printf("\n");
			}
			exit(0);
		}

		else{
			wait(NULL);
		}
	}
    while(true);
	return 0;
    
}