#include "philo.h"

#define MAX_THREADS 10

__attribute__((destructor)) static void destructor()
{
	system("leaks -q a.out");
}

void	*threadFunction(void *arg)
{
	printf("Thread number %ld is running.\n", (long)arg);
	return (NULL);
}

int	main(void)
{
	pthread_t threads[MAX_THREADS];
	int ret;
	long i;

	for (i = 0; i < MAX_THREADS; i++)
	{
		ret = pthread_create(&threads[i], NULL, threadFunction, (void *)i);
		if (ret != 0 || i == 5)
		{
			break ;
		}
	}
	return (0);
}