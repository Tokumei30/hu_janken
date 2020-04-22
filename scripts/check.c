#include <stdio.h>
#include <math.h>
#include <omp.h>
#include <time.h>

int p(unsigned long int n, unsigned long w)
{
	return n % 3;
}

int main(void)
{
	unsigned long int i, w, n;
	int br = 0, h;
	struct timespec startTime, endTime;

	if (p(0, 0) != 0)
	{
		printf("Saisho ha gu dayo\n"); //これが出たら最初がグーじゃない
	}

	n = omp_get_max_threads();

	printf("Max thread = %lu\n", n);

	clock_gettime(CLOCK_REALTIME, &startTime);

	#pragma omp parallel for private(w) num_threads(n)
	for (i = 1; i <= 1000000; i++)
	{
		for (w = 0; w < i && w < 10000; w++)
		{
			h = p(i, w);
			if (h < 0 || h > 2)
			{
				printf("error(n=%lu w=%lu p(n, w)=%d)\n", i, w, h);
			}
		}
	}
	
	clock_gettime(CLOCK_REALTIME, &endTime);

	printf("elapsed time = ");
	if (endTime.tv_nsec < startTime.tv_nsec)
	{
		printf("%5ld.%09ld", endTime.tv_sec - startTime.tv_sec - 1,
			   endTime.tv_nsec + (long int)1.0e+9 - startTime.tv_nsec);
	}
	else
	{
		printf("%5ld.%09ld", endTime.tv_sec - startTime.tv_sec,
			   endTime.tv_nsec - startTime.tv_nsec);
	}
	printf("(sec)\n");

	printf("Finish\n");

	return 0;
}