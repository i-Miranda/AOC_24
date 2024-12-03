#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	main (int argc, char *argv[])
{
	FILE* data;
	int	i = 0;
	int	j = 0;
	int	buffersize = 14;
	int *left_nums;
	int *right_nums;
	int *diff_nums;
	long diff = 0;
	long similarity = 0;
	long total_sim = 0;

	data = fopen(argv[1], "r");

	left_nums = malloc(1000 * sizeof(int));
	right_nums = malloc(1000 * sizeof(int));
	diff_nums = malloc(1000 * sizeof(int));

	while (i < 1000)
	{
		fscanf(data, "%d %d", &left_nums[i], &right_nums[i]);
		i++;
	}
	
	while (j < 999)
	{
		i = 0;
		while (i < 999)
		{
			if (left_nums[i] > left_nums[i + 1])
			{
				left_nums[i] = left_nums[i + 1] ^ left_nums[i];	
				left_nums[i + 1] = left_nums[i] ^ left_nums[i + 1];	
				left_nums[i] = left_nums[i + 1] ^ left_nums[i];	
			}
			if (right_nums[i] > right_nums[i + 1])
			{
				right_nums[i] = right_nums[i + 1] ^ right_nums[i];	
				right_nums[i + 1] = right_nums[i] ^ right_nums[i + 1];	
				right_nums[i] = right_nums[i + 1] ^ right_nums[i];	
			}
			i++;
		}
		j++;
	}
	
	j = 0;

	while (j < 1000)
	{
		i = 0;
		similarity = 0;
		while (i < 1000)
		{
			if (left_nums[j] == right_nums[i])
				similarity++;
			i++;
		}
		total_sim += left_nums[j] * similarity;
		j++;
	}

	i = 0;

	while (i < 1000)
	{
		diff_nums[i] = left_nums[i] - right_nums[i];	
		if (diff_nums[i] < 0)
			diff_nums[i] *= -1;
		diff += diff_nums[i];
		printf("%d - %d = %d  diff = %ld\n", left_nums[i], right_nums[i], diff_nums[i], diff);	
		i++;
	}

	free(left_nums);
	free(right_nums);
	free(diff_nums);

	fclose(data);

	printf("total similarity = %ld\n", total_sim);
	return (0);
}
