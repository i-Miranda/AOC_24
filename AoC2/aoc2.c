#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

int	main (int argc, char *argv[])
{
	FILE* data;
	int	**numberStrings;
	int i;
	int j;
	int	totalSafe = 1000;
	bool isDecreasing = false;
	bool problemDamp = false;
	data = fopen(argv[1], "r");

	numberStrings = malloc(1000 * sizeof(int *));
	i = 0; 
	while (i < 1000)
	{
		j = 0;
		numberStrings[i] = malloc(9 * sizeof(int));
		while (j < 9)
		{
			fscanf(data, "%d", &numberStrings[i][j]);
			if (numberStrings[i][j] == 0)
				break;
			j++;
		}
		while (j < 9)
		{
			numberStrings[i][j] = 0;
			j++;
		}
		i++;
	}
	
	i = 0;
	while (i < 1000)
	{
		j = 0;
		while (j < 9 && numberStrings[i][j] != 0)
		{
			printf("%d ", numberStrings[i][j]);
			j++;
		}
		j = 0;
		if (numberStrings[i][j] > numberStrings[i][j + 1])
			isDecreasing = true;
		else
			isDecreasing = false;
		problemDamp = false;
		while (j < 9 && numberStrings[i][j + 1] != 0)
		{
			if (isDecreasing)
			{
				if (numberStrings[i][j] <= numberStrings[i][j + 1] ||
					numberStrings[i][j] - numberStrings[i][j + 1] > 3)
				{
					if (problemDamp)
					{
						totalSafe--;
						printf("NOT SAFE!");
						break;
					}
					else
					{
						problemDamp = true;
						printf("DAMPENED! ");
					}
				}
			} 
			else 
			{
				if (numberStrings[i][j] >= numberStrings[i][j + 1] ||
					numberStrings[i][j] - numberStrings[i][j + 1] < -3)
				{
					if (problemDamp)
					{
						totalSafe--;
						printf("NOT SAFE!");
						break;
					}
					else
					{
						problemDamp = true;
						printf("DAMPENED! ");
					}
				}
			}
			j++;
		}
		printf("\n");
		i++;
	}
	
	printf("Total safe = %d\n", totalSafe);

	i = 0;
	while (i < 1000)
	{
		free(numberStrings[i]);
		i++;
	}
	free(numberStrings);
	fclose(data);

	return (0);
}
