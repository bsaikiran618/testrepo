/*

	This program measures the execution speed of another program.

	Usage: execspeed <program_name>
	Author: boddulus
*/

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

 int main(int argc , char*argv[])
 {
 	 if(argc != 2)
	 {
	 		puts("Usage : execspeed <program_name>");
			return 1;
	 }

	 pid_t pid = fork();

	 clock_t begin = clock();

	 	if(pid == 0)
		{
			// this is the child.

			execl(argv[1],argv[1],NULL);
		}
	int pid_status;
   if(waitpid(pid ,&pid_status,0 ) == -1)
	 puts("error waiting for child process to finish\n");

	clock_t end = clock();

	puts("--------------------------------------------");
	if(WEXITSTATUS(pid_status))
	{
		printf("Process exited abnormally\n");
	}
	else
	{
		printf("Process exited succesfully\n");
	}
	printf("Execution time: %lfs\n", ((double)(end - begin)/CLOCKS_PER_SEC));

		return 0;
 }
