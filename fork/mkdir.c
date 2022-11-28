#include<stdio.h>
#include<sys/stat.h>

int main(int agrc,char* argv[]){
    int n;
    n=mkdir(argv[1],0777);
    if (!n){
        printf("Process Completed\n");
    }
    else{
        printf("Process Failed...error\n");
    }
}