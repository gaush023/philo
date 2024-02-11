#include "philo.h"

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (unsigned long)1000) + (time.tv_usec / 1000));
}

int	main(void)
{
	unsigned long start_time, end_time;
	start_time = get_time();
    sleep(1);
	end_time = get_time();
	printf("処理にかかった時間: %lu ミリ秒\n", end_time - start_time);
}