#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv)  {
   int a, b, pid;
   int p[2];
   scanf("%d %d", &a, &b);
   pipe(p);
   pid = fork();
   if(pid == 0){
      close(p[0]);	   
      a = a + b;
      write(p[1], &a, sizeof(int) );
      close(p[1]);
      exit(0);
   }
   close(p[1]);
   read(p[0], &a, sizeof(int));
   close(p[0]);
   wait(0);
   printf("The sum is: %d \n", a);
   return 0;
}
