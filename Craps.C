#include <stdio.h>
#include <time.h>
int die_roll()
{
	int die_1,die_2;
	printf("Press enter to roll!\n");
	getch();
	printf("Rolling the dice!!!!\n");
	die_1 = (rand()%6) + 1;
	die_2 = (rand()%6) + 1;
	printf("Dice 1: \t%d \nDice 2: \t%d\n",die_1,die_2);	
	return (die_1 + die_2);	
}

double bet_func(double *bankroll)
{
	double bet;
	printf("How much would you like to bet?\n$");
	scanf("%lf",&bet);
	while(bet<5)
	{
		printf("Your bet must be above $5.00, please enter again\n");
		scanf("%lf",&bet);
	}
	printf("Your current bet is %.02lf\n",bet);
	(*bankroll)-=bet;
	return bet;
}

void message()
{
	char message[] = "Welcome to the game of Craps! Let's get this show on the road!";
	printf("%s\n",message);
}

int Game(double *bankroll)//Return winnings
{
	double bet = bet_func(&(*bankroll));
	double winnings = 0;
	int point,choice,double_bet;
	int result;//1 True 0 False
	printf("Would you like to bet for yourself or against?\nChoose 1 for yourself or 2 for against\t");
	scanf("%d",&choice);
	while(1)
	{
		int dice_val = die_roll();
		printf("The total value of the die roll is %d\n",dice_val);
		switch(dice_val)
		{
			case 2: case 3: case 12:
				if(choice == 1)
				{
					printf("You have lost the game.\n");
					result = 0;
				}
				break;
			case 7: case 11:
				if(choice == 1)
				{
					printf("You have won the game.\n");
					result = 1;
				}
				break;
			default:
				point = dice_val;
				printf("You will need to roll again.\n");
				if(choice ==1)
				{
					printf("Would you like to double your bet?\nYes = 1\tNo = 0\t");
					scanf("%d",&double_bet);
					if(double_bet==1)
					{
						(*bankroll)-=bet;
						bet*=2;
					}
					printf("\nThe current bet on the table is %.02lf\n\n",bet);
					dice_val=0;
					for(;;)
					{
						dice_val=die_roll();
						printf("The total value of the die roll is %d\n",dice_val);
						printf("Your point value is: %d\n",point);
						if(dice_val==7||dice_val==11||dice_val==point)
						{
							break;
						}
					}
					if(dice_val==7||dice_val==11)
					{
						result=0;
					}
					else if(dice_val==point)
					{
						result=1;
					}

				break;
				}

		}

		switch(result)
		{
			case 1:
				printf("You have won the following\t$%.2lf\n",bet);
				winnings+=(bet*2);
				return winnings;
			case 0:
				printf("You have lost the following\t$%.2lf\n",bet);
				return winnings;
		}
	}
	return winnings;
}

void main()
{
	message();
	srand(time(NULL));
	double winnings;
	double bankroll = 100;
	int d;
	while(1)
	{
		winnings = Game(&bankroll);
		if(winnings==0)
		{
			printf("The Game will now end. Goodbye!\n");
			break;
		}
		bankroll+=winnings;
		printf("Winnings = $%.02lf\t Bankroll = $%.02lf\n",winnings,bankroll);
		winnings=0;
		printf("Would you like to let it ride?\nYes = 1, No = 0\t");
		scanf("%d",&d);
		if(d==0){break;}
		printf("\nLet's play again!\n");
		message();
	}
	printf("Your game has now ended, your bankroll is the following: $%.02lf",bankroll);
}
