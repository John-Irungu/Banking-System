#include <stdio.h>
#include <math.h>
#include <string.h>

float deposit, withdrawal, balance, comp_interest, simp_interest, dep_bal, with_bal;
char customer[20];
int input;

FILE *banking;

float Balance() {
	balance = 0.0;
	printf("Checking balance. . .\n");
	balance += dep_bal;
	balance -= with_bal;
	printf("Balance is %.2f\n", balance);
	fprintf(banking, "Balance is %.2f\n", balance);
}

float Deposit() {
	printf("Enter the amount to deposit please = ");
	scanf("%f", &deposit);
	dep_bal += deposit;
	printf("Amount deposited = %.2f\n", deposit);
	fprintf(banking, "Amount deposited = %.2f\n", deposit);
}

float Withdraw() {
	printf("Please enter the amount to withdraw = ");
	scanf("%f", &withdrawal);
	with_bal += withdrawal;
	if ((balance == 0.0) || (balance < withdrawal))
	{
		printf("Sorry! There is not enough money in account to withdraw!\n");
		fprintf(banking, "Sorry! There is not enough money in account to withdraw!\n");
	} else
	{
		printf("Amount withdrawn = %.2f\n", withdrawal);
		fprintf(banking, "Amount withdrawn = %.2f\n", withdrawal);
	}
}

float Compound() {
	if (balance > 100000.00)
	{
		printf("The interest rate is 15%. . .\n");
		fprintf(banking, "The interest rate is 15%. . .\n");
		comp_interest = balance * (pow(1.15, 10));
		printf("Compound Interest = %.2f\n", comp_interest);
		fprintf(banking, "Compound Interest = %.2f\n", comp_interest);
	} else
	{
		printf("The interest rate is 11%. . .\n");
		fprintf(banking, "The interest rate is 11%. . .\n");
		comp_interest = balance * (pow(1.11, 10));
		printf("Compound Interest = %.2f\n", comp_interest);
		fprintf(banking, "Compound Interest = %.2f\n", comp_interest);
	}
}

float Simple() {
	if (balance > 100000.00)
	{
		printf("The interest rate is 15%. . .\n");
		fprintf(banking, "The interest rate is 15%. . .\n");
		simp_interest = (balance * 15 * 10) / 100;
		simp_interest += balance;
		printf("Simple Interest = %.2f\n", simp_interest);
		fprintf(banking, "Simple Interest = %.2f\n", simp_interest);
	} else
	{
		printf("The interest rate is 11%. . .\n");
		fprintf(banking, "The interest rate is 11%. . .\n");
		simp_interest = (balance * 11 * 10) / 100;
		simp_interest += balance;
		printf("Simple Interest = %.2f\n", simp_interest);
		fprintf(banking, "Simple Interest = %.2f\n", simp_interest);
	}
}

int Display() {
	DISPLAY:
	printf("1. Deposit Amount.\n");
	printf("2. Check Balance.\n");
	printf("3. Withdraw Amount.\n");
	printf("4. Check Balance After Compound Interest.\n");
	printf("5. Check Balance After Simple Interest.\n");
	printf("6. Exit.\n");
	printf("Please choose one option below = ");
	scanf("%d", &input);

	if (input == 1)
	{
		Deposit();
		goto DISPLAY;
	} else if (input == 2)
	{
		Balance();
		goto DISPLAY;
	} else if (input == 3)
	{
		Withdraw();
		goto DISPLAY;
	} else if (input == 4)
	{
		Compound();
		goto DISPLAY;
	} else if (input == 5)
	{
		Simple();
		goto DISPLAY;
	} else if (input == 6)
	{
		printf("Thank You for choosing us.\n");
		fprintf(banking, "Thank You for choosing us.\n");
		return 0;
	}
}

void Customer() {
	banking = fopen("Banking.txt", "w");
	printf("Welcome customer, please state your name = ");
	gets(customer);
	printf("Welcome to the National Bank... %s\n", customer);
	Display();
}

int main()
{
	Customer();
	fprintf(banking, "\n");
	fprintf(banking, "\n");
	fprintf(banking, "\n");
	fprintf(banking, "\n");
	fprintf(banking, "Receipt Generated for The National Bank System Service. . .\n");
	fclose(banking);
	return 0;
}
