#include <iostream>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{
    printf("当前进程：%d\n", getpid());
    for (int i = 0; i < 2; ++i)
    {        
        pid_t pid = fork();
        if (pid < 0)
        {
            printf("异常：%d", pid);
            exit(1);
        }
        else if (pid == 0)
        {
            printf("当前进程：%d，父进程：%d，计数：%d\n",getpid(), getppid(), i);
        }
        else if (pid > 0)
        {
            printf("当前进程：%d，子进程：%d，计数：%d\n", getpid(), pid, i);
        }
        printf("当前进程：%d，计数：%d\n", getpid(), i);
    }   
    return 0;
}