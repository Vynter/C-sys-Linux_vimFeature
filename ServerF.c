#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int main(){
    int fd;
    char buff[100];
    FILE * file;
    //TODO si le fichier existe pas on le crée
    
    mkfifo("/tmp/pipe1",S_IRWXU|S_IRGRP);
    
    fd=open("/tmp/pipe1",O_RDONLY);
    
    while(1){
    if(read(fd,buff,sizeof(buff))){
        file=fopen("server.txt","a");
        fputs(buff,file);
        fclose(file);
        printf("%s",buff);
        
    }
        }
    
    
    
    close(fd);
    

    return 0;
}
