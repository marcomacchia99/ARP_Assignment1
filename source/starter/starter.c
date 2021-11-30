#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#define SIZE 80

int spawn(const char *program, char **arg_list)
{
    pid_t child_pid = fork();
    if (child_pid != 0)
        return child_pid;
    else
    {
        execvp(program, arg_list);

        perror("exec failed");
        return 1;
    }
}

int pid_command;
int pid_inspection;
int pid_motorX;
int pid_motorZ;
int pid_watchdog;
char buffer[SIZE];

int fd_watchdog;
int fd_inspection;

int main(int argc, char *argv[])
{

    char console[] = "/usr/bin/konsole";
    char *arg_list_1[] = {"/usr/bin/konsole", "-e", "./../command_console/commandConsole", "", (char *)NULL};
    char *arg_list_2[] = {"/usr/bin/konsole", "-e", "./../inspection_console/inspectionConsole", "", (char *)NULL};
    char *arg_list_3[] = { "./../motor_x/motorX", "", (char *)NULL};
    char *arg_list_4[] = { "./../motor_z/motorZ", "", (char *)NULL};
    char *arg_list_5[] = { "./../watchdog/watchdog", "", (char *)NULL};

    pid_motorX = spawn("./../motor_x/motorX", arg_list_3);
    pid_motorZ = spawn("./../motor_z/motorZ", arg_list_4);
    pid_command = spawn(console, arg_list_1);
    pid_inspection = spawn(console, arg_list_2);
    pid_watchdog = spawn("./../watchdog/watchdog", arg_list_5);



    return 0;
}
