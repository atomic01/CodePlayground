#ifndef PART2_H_
#define PART2_H_

void part2()
{
	int input = 0, proced_to_checkout = 0, days_until_expiry = 0;
	int products[2] = { 0, 0 }; // {discounted pies, non expired pies}
	double total = 0;

	printf("Part 2:\n");

	while(!proced_to_checkout)
	{

		part2_basket(total, products);
		input = part2_menu();

		if(input == 1)
		{
			days_until_expiry = date_generator();

			if( days_until_expiry < 0)
				printf("\nPie can't be sold due to expired date! %d days past", days_until_expiry);
			else
			{
				if(days_until_expiry == 0)
				{
					products[0]++;
					total+=3.20 * 0.5;
					printf("\n50%(expiry date)discounted Pie added!");
				}
				else if(days_until_expiry > 0)
				{
					products[1]++;
					total+=3.20;
					printf("\nPie added!");
				}
			}
		}
		else if(input == 0)
			proced_to_checkout = 1;
		else
			printf("\nWrong input!");

		printf("\n\n\n\n");
	}

	part2_checkout(total, products);
}

void part2_basket(double total, int products[])
{
	printf("\nTotal charge: £%.2f\n", total );
	printf("Basket: \n");
	if(products[0] > 0) printf("\t%d x 50%(expiry date)discount x'Pie'\n", products[0]);
	if(products[1] > 0) printf("\t%d x 'Pie'\n", products[1]);
}

int part2_menu()
{
	int input = 0;

	printf("\nMenu(select a number):\n");
	printf("(1) Add 'Pie' -- £3.20\n");
	printf("(0) Go to checkout!\n");
	printf("Input: ");
	scanf("%d", &input);

	return input;
}

void part2_checkout(double total, int products[])
{
	printf("\nCheckout!\nBasket: \n");
	if(products[0]) printf("\t%d x 50%(expiry date)discount x 'Pie' -- £1.60\n", products[0]);
	if(products[1]) printf("\t%d x 'Pie' -- £3.20\n", products[1]);
	printf("\n\t Total Charge: £%.2f\n",  total );
}

int date_generator() //returns [-2, 5]... [-2,-1] -> expired, [0] -> expiry date, [1,...5] non expired
{
	int daysUntilExpiry = 0;

	daysUntilExpiry = rand() %7 - 2;
	return daysUntilExpiry;
}

#endif /* PART2_H_ */
