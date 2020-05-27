#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
int main(int argc, char** argv){

int pid;
int fifoA, fifoB;
int a,b;
scanf("%d %d", &a, &b);

pid = fork();
if(pid == 0)
{
 fifoA=open("fifo1", O_RDONLY);
 fifoB=open("fifo2", O_WRONLY);
 read(fifoA, &a, sizeof(int));
 read(fifoA, &b, sizeof(int));
 a = a + b;
 write(fifoB, &a, sizeof(int));
 close(fifoA);
 close(fifoB);
 exit(0);
}
fifoA=open("fifo1", O_WRONLY);
fifoB=open("fifo2", O_RDONLY);
write(fifoA, &a, sizeof(int));
write(fifoA, &b, sizeof(int));
read(fifoB, &a, sizeof(int));
printf("The sum is: %d \n", a);
close(fifoA);
close(fifoB);
return 0;
}
