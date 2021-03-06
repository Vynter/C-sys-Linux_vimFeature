#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>



int main(int argc, char *argv[]){
    int choice;
    int fd,fsize=255,psize=255;
    char filename[255],path[255],buff[255]="",aff[255]="";
    /*filename = malloc((fsize+1)*sizeof(char));
    path = malloc((fsize+1)*sizeof(char));*/
    FILE * file;
    mkfifo("/tmp/pipe1",S_IRWXU|S_IRGRP);
    
    fd=open("/tmp/pipe1",O_WRONLY);
 
    while(1){
        printf("Veuillez choisir un des choix suivant:\n");
        printf("- 1 Envoyer un fichier \n");
        printf("- 2 Quitter\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Vous avez choisir sa\n");
                printf("Veuillez saisir le nom du fichier et le chemin du fichier \n");
                scanf(" %[^\n]",&filename);
                printf("Veuillez saisir le chemain du fichier \n");
                scanf(" %[^\n]",&path);
                printf("%s/%s",path,filename);
                file=fopen(path,"r");
                if(file==NULL){
                    printf("le nom du fichier ou le chemin sont incorrecte\n");
                    return 1;
                }else{
                    printf("ok\n");
                    while((fscanf(file,"%[^\n]\n",aff))!=EOF){
                        strcat(buff,aff);
                        strcat(buff,"\n");
                    }
                    printf("----------------\n");
                    printf(" %s",buff);
                }
                fclose(file);
                write(fd,buff,sizeof(buff));
                close(fd);
                printf("Le programme va se fermé...\n");
                return 1;
                break;
            case 2:
                printf("Le programme va se fermé...\n");
                return 1;
                break;
            default:
                printf("Choie erroné\n");
                break;
        }
    }

return 0;
}


