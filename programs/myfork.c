#include <stdio.h>
#include <sys.h>
void main1() 
{ 
    int ws=0; 
    int i,j,k,pid,ppid; 
    if(fork()) 
    {
        //2#
        sleep(4);
        for(k=1;k<6;k++) 
        {
            printf("%d,%d; ",k,getppid(k));
        }
        printf("\n");
    } 
    else
    { 
        //3#
        if(fork()) 
        { 
            if(fork()) 
            { 
                //3#
                sleep(1);   
                pid=getpid(); 
                ppid=getppid(pid); 
                for(k=0;k<ws;k++) 
                { 
                    i=wait(&j); 
                    printf("Process %d#:My child %d is finished with exit status %d\n",pid,i,j);
                } 
                printf("Process %d# finished: My father is %d\n",pid,ppid); 
                exit(ppid); 
            } 
            else
            { 
                //5#
                sleep(2);
                pid=getpid(); 
                ppid=getppid(pid); 
                printf("Process %d# finished: My father is %d\n",pid,ppid); 
                exit(ppid); 
            } 
        } 
        else
        {
            //4#
            pid=getpid(); 
            ppid=getppid(pid); 
            printf("Process %d# finished: My father is %d\n",pid,ppid); 
            exit(ppid); 
        } 
    } 
} 
