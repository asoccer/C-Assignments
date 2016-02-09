//As the title suggest this is a WIP of Craps.

#include <stdio.h>
#include <stdlib.h>

void bet_path(int *choice)
{
	
	printf("-------------------------------------------\n");
	printf("Pass Line: 1\nDon't pass Line: 2\n");
	scanf("%d",&(*choice));
	printf("-------------------------------------------\n");
}

void introduction()
{
	printf("-------------------------------------------\n");
	printf("Welcome to the game of Crabs, please begin by\n");
	printf("entering a seed for the random number generator\n");
	printf("Seed\t");
}

int die_roll()
{
	char choice;
	int die_1,die_2;
	printf("Would you like to roll the dice? Y or N?: ");
	scanf(" %c",&choice);
	if(choice == 'Y' || choice == 'y')
	{
		printf("\n\nRolling the dice!!!!\n");
		die_1 = (rand()%6) + 1;
		die_2 = (rand()%6) + 1;
		printf("Dice 1: \t%d \nDice 2: \t%d\n",die_1,die_2);	
		printf("-------------------------------------------\n");
		return (die_1 + die_2);
	}
	else{
		printf("Dice will not roll\n");
		return 0;
	}
	
}

void print_sum(int sum)
{
	if (sum ==0){
		printf("No Sum available to print\n");
		return;
	}
	printf("The Sum of the dice is %d\n",sum);
}

double bet(double *bankroll)
{
	double bet_value;
	printf("How much would you like to bet? (Min of $5.00 is required\n\n$");
	scanf("%lf",&bet_value);
	printf("-------------------------------------------\n");
	return bet_value;
}

void double_question(double *current_bet)
{
	char c;
	printf("Would you like to double/press your bet? Y or N\t");
	scanf(" %c",&c);
	if(c == 'Y' ||c == 'y')
	{
		(*current_bet) = (double)((*current_bet)*2);
	}
	return;
}
void Pass_Line(int sum_die,double *bankroll,double *current_bet)
{
	int point;
	(*current_bet) = bet(&(*bankroll));
	sum_die = die_roll();
	switch(sum_die)
	{
		case 7:case 11:
			printf("Congrats!! You just won %.2f\n",*current_bet);
			(*bankroll) = (double)((*bankroll)+(*current_bet));
			break;
		case 2: case 3: case 12:
			printf("Sadly you lost %.2f\n!",*current_bet);
			(*bankroll) = (double)((*bankroll)-(*current_bet));
			break;
		//case 4:case 5:case 6:case 8:case 9:case 10:
		default:
			double_question(&(*current_bet));
			printf("Your current bet is %.2f\n",(*current_bet));
			point = sum_die;
			sum_die = 0;
			printf("Your point is %d\n",point);
			printf("Let us now continue, we shall now roll again\n");
			sum_die = die_roll();
			while(1)
			{
				if(sum_die==point)
				{
					printf("You have just won %.2f!!!!\n",(*current_bet));
					(*bankroll) = (double)((*bankroll)+(*current_bet));
					break;
				}
				else if(sum_die == 7)
				{
					printf("You've seven-out, the following will be deducted %.2f\n",(*current_bet));
					(*bankroll) = (double)((*bankroll)-(*current_bet));
					break;
				}
				else
					sum_die = die_roll();
					printf("Reminder, your point is %d\n",point);
			}
	}
}

void main()
{
	int choice,sum_die,seed;
	char c;
	introduction();
	double bankroll = 100.00,current_bet,winnings=0;
	scanf("%d",&seed);
	srand(seed);
	bet_path(&choice);
	printf("Bets have been set! Let's play some craps!!\n");
	
	while(1){
		if(choice == 1){Pass_Line(sum_die,&winnings,&current_bet);}
		printf("Would you like to continue? Your current winnings are %.2f\n",winnings);
		scanf(" %c",&c);
		if(c == 'N'||c =='n'){break;}

	}
	bankroll = (double)(bankroll+winnings);
	printf("My bankroll is %.2f",bankroll);
}
