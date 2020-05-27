#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char** argv) 
 {
   int pid1, pid2;
   int nr1=0 , nr2=0;
   int p1[2], p2[2];
   char word[50];
   pipe(p1);
   pipe(p2);
   pid1= fork();
   if(pid1 == 0)
        {
	  close(p1[1]);
	  read(p1[0], &word, 50*sizeof(char));
	  while(strcmp(word, "\n") != 0){
          if (strstr(word, "oa") != NULL)
             nr1 = nr1 + strlen(word)-1;
	  read(p1[0], &word, 50*sizeof(char));
	  }
	  printf("Total number of characters with words containing <oa>: %d \n" , nr1);
          close(p1[0]);	  
          exit(0);
	}
   pid2= fork();
   if(pid2 == 0)
   {       close(p2[1]);
	   read(p2[0],&word, 50*sizeof(char));
	   while(strcmp(word, "\n") != 0){
	   if(strstr(word, "oa") == NULL)
               nr2 = nr2 + strlen(word)-1;
	   read(p2[0], &word, 50*sizeof(char));
	   }
	   printf("The rest of total characters: %d \n", nr2);
	   close(p2[0]);
	   exit(0); 
   }
   
   close(p1[0]);
   close(p2[0]);
   while(strcmp(word, "\n") != 0)
   {
      fgets(word, 20, stdin);
      write(p1[1], &word, 50*sizeof(char));
      write(p2[1], &word, 50*sizeof(char));


   }
   close(p1[1]);
   close(p2[1]);
   wait(0);
   wait(0);
   return 0;
 }
 
