#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc,char* argv[]){
    FILE* file;
    char st;

    file=fopen(argv[1],"r");
    if (!file){
        printf("Some issue occurred");
    }

    st=fgetc(file);

    while(st!=EOF){
        
        printf("%c",st);
        st=fgetc(file);
    }
    fclose(file);
}