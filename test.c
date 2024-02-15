#include <pthread.h>
#include <stdio.h>

int				counter = 0;

pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;

void	*increment_counter(void *arg)
{
	int	i;
	(void)arg;

	i = 0;
	while (i < 10000)
	{
		pthread_mutex_lock(&mutex);
		++counter;
		pthread_mutex_unlock(&mutex);
		i++;
	}
	return NULL;
}

int main (void)
{
	pthread_t	thread1;
	pthread_t	thread2;

	pthread_create(&thread1, NULL, increment_counter, NULL);
	pthread_create(&thread2, NULL, increment_counter, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("Counter: %d\n", counter);
	pthread_mutex_destroy(&mutex);
	return (0);
}