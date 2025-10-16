#ifndef PART3_H_
#define PART3_H_

void part3()
{
	int input = 0, procedToCheckout = 0, daysUntilExpiry = 0;
	int products[3] = { 0, 0, 0 }; // { discounted pies, non expired pies, chips}
	double total = 0;

	printf("Part 3:\n");

	while(!procedToCheckout)
	{
		part3_basket(total, products);
		input = part3_menu();

		if(input == 1)
		{
			daysUntilExpiry = date_generator();

			if( daysUntilExpiry < 0)
				printf("\nPie can't be sold due to expired date! %d days past", daysUntilExpiry);
			else if(daysUntilExpiry == 0)
			{
				products[0]++;
				printf("\n50%(expiry date)discounted Pie added!");
			}
			else
			{
				products[1]++;
				printf("\nPie added!");
			}
		}
		else if(input == 2)
		{
			products[2]++;
			printf("\nPortion of chips added!");
		}
		else if(input == 0)
			procedToCheckout = 1;
		else
			printf("\nWrong input!");

		total = total_calculator(products);
		printf("\n\n\n\n");
	}

	part3_checkout(total, products);
}

void part3_basket(double total, int products[])
{
	printf("\nTotal charge: £%.2f\n", total );
	printf("Basket: \n");
	if(products[0] > 0) printf("\t%d x 50%(expiry date)discount x'Pie'\n", products[0]);
	if(products[1] > 0) printf("\t%d x 'Pie'\n", products[1]);
	if(products[2] > 0) printf("\t%d x 'Portion of chips'\n", products[2]);
	if(products[1] > 0 && products[2] > 0)
	{
		if(products[1] < products[2])
			printf("\t(Of witch: %d x Meal deals)\n", products[1]);
		else
			printf("\t(Of witch: %d x Meal deals)\n", products[2]);
	}
}

int part3_menu()
{
	int input = 0;

	printf("\nMenu(select a number):\n");
	printf("(1) Add 'Pie' -- £3.20\n");
	printf("(2) Add 'Portion of chips' -- £1.80\n");
	printf("(0) Go to checkout!\n");
	printf("Input: ");
	scanf("%d", &input);

	return input;
}

void part3_checkout(double total, int products[])
{
	printf("\nCheckout!\nBasket: \n");
	if(products[0]) printf("\t%d x 50%(expiry date)discount x 'Pie' -- £1.60\n", products[0]);
	if(products[1] > 0 && products[2] > 0)
	{
		if(products[1] < products[2])
		{
			printf("\t%d x 'Meal deal' -- £4.00\n", products[1]);
			products[2] -= products[1];
			products[1] = 0;
		}
		else
		{
			printf("\t%d x 'Meal deal'-- £4.00\n", products[2]);
			products[1] -= products[2];
			products[2] = 0;
		}
	}
	if(products[1]) printf("\t%d x 'Pie' -- £3.20\n", products[1]);
	if(products[2]) printf("\t%d x 'Portion of chips' -- £1.80\n", products[2]);
	printf("\n\t Total Charge: £%.2f\n",  total );

}

double total_calculator(int products[])
{
	double total = 0;

	total += products[0] * 3.20 * 0.5;
	if(products[1] >= products[2])
	{
		total+= (products[2] * 4.00);
		total+=(products[1] - products[2]) * 3.20;
	}
	if(products[1] < products[2])
	{
		total+= products[1] * 4.00;
		total+=(products[2] - products[1]) * 1.80;
	}

	return total;
}

#endif /* PART3_H_ */
