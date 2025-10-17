#ifndef PART1_H_
#define PART1_H_

void part1()
{
	int input = 0, proced_to_checkout = 0;
	int products[1] = {0}; // [number of chips]
	double total = 0;

	printf("Part 1:\n\n");

	while(!proced_to_checkout)
	{
		part1_basket(total, products);
		input = part1_menu();

		if(input == 1)
		{
			products[0]++;
			printf("\nPortion of chips added!");
			total += 1.80;
		}
		else if(input == 0)
			proced_to_checkout = 1;
		else
			printf("\nWrong input!");

		printf("\n\n\n\n");
	}

	part1_checkout(total, products);
}

void part1_basket(double total, int products[])
{
	printf("\nTotal charge: £%.2f\n", total );
	printf("Basket: \n");
	if(products[0] > 0) printf("\t%d x 'Portion of chips'\n", products[0]);
}

int part1_menu()
{
	int input = 0;

	printf("\nMenu(select a number):\n");
	printf("(1) Add 'Portion of chips' -- £1.80\n");
	printf("(0) Go to checkout!\n");
	printf("Input: ");
	scanf("%d", &input);

	return input;
}

void part1_checkout(double total, int products[])
{
	printf("\nCheckout!\nBasket: \n");
	if(products[0]) printf("\t%d x 'Portion of chips' -- £1.80\n", products[0]);
	printf("\n\t Total Charge: £%.2f\n", total );
}


#endif /* PART1_H_ */
