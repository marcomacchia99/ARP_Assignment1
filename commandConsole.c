#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h>
#include <signal.h>


int fd_motX;
int fd_motZ;


int main(int argc, char * argv[])
{

    // pipe file path
    char * fifo_command_motorX = "/tmp/command_motorX";
    char * fifo_command_motorZ = "/tmp/command_motorZ";
    char * fifo_command_comm = "/tmp/command_comm";

    // Creating the named file(FIFO)
    // mkfifo(<pathname>, <permission>)
    mkfifo(fifo_command_motorX, 0666);
    mkfifo(fifo_command_motorZ, 0666);
    mkfifo(fifo_command_comm, 0666);

    // Open FIFO for Read only
    fd_motX = open(fifo_command_motorX, O_RDONLY);
    fd_motZ = open(fifo_command_motorZ, O_RDONLY);
    
    
    close(fd_motX);
    close(fd_motZ);
    
    char input_ch[80];

    while(1)
        {
            printf("AVAILABLE COMMANDS: \n");
            //fflush(stdout);
            printf("W to go UP\n");
            //fflush(stdout);
            printf("S to go DOWN\n");
            //fflush(stdout);
            printf("A to go LEFT\n");
            //fflush(stdout);
            printf("D to go RIGHT\n");
            //fflush(stdout);
            printf("Z to stop z movement\n");
            //fflush(stdout);
            printf("X to stop x movement\n");
            fflush(stdout);
            
            scanf("%s",input_ch);

        if(strlen(input_ch) > 1)
        {
            printf("Unrecognized command, press only one button at a time!\n");
            fflush(stdout);
        }

        else
        {
            char out_str[80];
            sprintf(out_str,"%d",input_ch[0]);
            
            switch(input_ch[0])
            {
                case 119:
                    printf("UP WAS PRESSED\n");
                    fflush(stdout);
                    write(fd_motZ, out_str, strlen(out_str)+1);
                    break;

                case 122:
                    printf("DOWN WAS PRESSED\n");
                    fflush(stdout);
                    write(fd_motZ, out_str, strlen(out_str)+1);
                    break;
                    
                case 97:
                    printf("LEFT WAS PRESSED\n");
                    fflush(stdout);
                    write(fd_motX, out_str, strlen(out_str)+1);
                    break;

                case 100:
                    printf("RIGHT WAS PRESSED\n");
                    fflush(stdout);
                    write(fd_motX, out_str, strlen(out_str)+1);
                    break;

                case 113:
                    printf("STOP X WAS PRESSED\n");
                    fflush(stdout);
                    write(fd_motX, out_str, strlen(out_str)+1);
                    break;

                case 101:
                    printf("STOP Z WAS PRESSED\n");
                    fflush(stdout);
                    write(fd_motZ, out_str, strlen(out_str)+1);
                    break;

                default:
                    printf("Unrecognized command, please try again: \n");
                    fflush(stdout);
                    break;
            }











        }






















}
