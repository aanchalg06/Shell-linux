#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    // printf("good");
    DIR *directory;
	struct dirent *allFilesname;
	directory = opendir(".");


	if(argc==1){
		if(directory!= NULL){
			while((allFilesname= readdir(directory)) != NULL){
				if(!(strcmp(allFilesname->d_name,".")==0))
					printf("%s\n",allFilesname->d_name );
			}
		}
        printf("\n");
		closedir(directory);
	}

	if(strcmp(argv[1],"-m\n")==0){
		if(directory!= NULL){
			while((allFilesname= readdir(directory)) != NULL){
				if(!(strcmp(allFilesname->d_name,".")==0 || strcmp(allFilesname->d_name,"..")==0))
					printf("%s,\t",allFilesname->d_name );
			}
			printf(", ");
		}
        printf("\n");
		closedir(directory);
	}

    else{
        printf("Some error occured\n");
    }

	return 0;
}