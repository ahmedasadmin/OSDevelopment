#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>



void copy(int , int);
char buffer[2048];
int main(int argc, char const *argv[])
{
    int fold, fnew;

    if(argc != 3){
        printf("need 2 arguments for copy program\n");
        return 1;
    }
    fold = open(argv[1],O_RDONLY);


    if(!fold){
            printf("cannot open %s file\n", argv[1]);
            return 1;
    }
    fnew =  open(argv[2],O_WRONLY);
    copy(fold, fnew);
    printf("*******OPERATION SUCCEED!!*******\n");
    return 0;
}

void copy(int fold, int fnew) 
{
        int count;

        while((count = read(fold, buffer, sizeof(buffer)))>0){
            write(fnew, buffer, count);
        }
}
