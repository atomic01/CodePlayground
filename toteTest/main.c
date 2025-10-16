#include <stdlib.h>
#include <stdio.h>
#include "declarations.h"

#include "part1.h"
#include "part2.h"
#include "part3.h"

int main()
{
	int input = 1;

	printf("The Fish and Chip Shop Problem\n\n");

	while(input != 0)
	{
		printf("\n\n(1) Part 1.\n");
		printf("(2) Part 2.\n");
		printf("(3) Part 3.\n");
		printf("(0) Exit.\n");
		printf("\tInput: ");
		scanf("%d", &input);

		if(input == 1) part1();
		if(input == 2) part2();
		if(input == 3) part3();
	}

	return 0;
}
