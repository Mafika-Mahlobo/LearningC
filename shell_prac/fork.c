#include <unistd.h>
#include <stdio.h>

int main(void)
{
	pid_t  my_pid;
	pid_t pid;

	printf("before fork\n");
	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		return (1);
	}
	printf("after fork\n");
	my_pid = getpid();
	printf("My pid is %u\n", my_pid);
	return (0);
}
