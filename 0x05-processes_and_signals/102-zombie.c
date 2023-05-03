#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int infinite_while(void);

/**
 * main - creates 5 zombie processes that keep running
 * indefinetely until they receive a signal to terminate
 *
 * Return: always 0 (Success)
 */
int main(void)
{
	short j;
	pid_t pid;

	for (j = 0; j < 5; j++)
	{
		pid = fork();
		if (!pid)
		{
			printf("Zombie process created, PID: %d\n", getpid());
			exit(1);
		}
	}

	return (infinite_while());
}

/**
 * infinite_while - while loop that never ends
 *
 * Return: 0
 */
int infinite_while(void)
{
	while (1)
		sleep(1);

	return (0);
}
