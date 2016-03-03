#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//Adam A Dost JAPA340 03/03/2016
void bank_problems()
{
	printf("\n----------------------------------------------------------------------------------------------\n");
	char prob1[] = "\nNote, due to the Shito family assistance Noriko starts with double the bank roll with $500\n";
	char prob2[] = "Due to Gokichi's passing Yoko has been spending quite a bit on birds and will start at $40\n";
	printf("%s%s\n",prob1,prob2);
	printf("----------------------------------------------------------------------------------------------\n");
	printf("Press enter to continue\n");
	getch();
}
double bet_func(double *bankroll)
{
	double bet;
	printf("How much would you like to bet?\n$");
	scanf("%lf",&bet);
	while(bet<5)
	{
		printf("Your bet must be above $5.00, please enter again.\n");
		printf("How much would you like to bet?\n$");
		scanf("%lf",&bet);
	}
	printf("Your current bet is %.02lf\n",bet);
	(*bankroll)-=bet;
	return bet;
}
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
int Game(double *bankroll, char *name)//Return winnings
{
	printf("Hello %s ",name);
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
						(*bankroll)=(double)(*bankroll)-bet;
						bet= (double)bet *2;
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

void results(double noriko,int winnings)
{
	int playagain;
	if(winnings!=0)//We won something that isn't bad
	{
		noriko = (double)(noriko+winnings);//Add up the bank roll and reset the winnnings
		winnings=0;
		printf("\nYour bankroll is now at $%.02lf\n\n\n",noriko);//Tell them how much skrilla they made
	}
	printf("Your current bankroll is '$%.02lf'\n",noriko);
	printf("\n\n----------------------------------------------------------------------------------------\n\n");
}
void main()
{
	char name[50];
	int choice,winnings;
	srand(time(NULL));
	char intro[] = "\t\t\tWelcome to JAPA340 Game of Craps feat various characters across different books!\n\n\nPlease enter your name so we may begin\t";
	printf("%s",intro);
	fgets(name,50,stdin);
	double bankroll=100,noriko=500,lily=100,Yoko=40;//Bankroll
	printf("Welcome %sLet's enjoy this wonderful game of Craps with Star Lily, Noriko, and Yoko. Press enter to continue:\t",name);
	getch();
	int playagain;
	bank_problems();
	fflush(stdin);
	printf("\t\t\tAre you aware of the game of craps? Press 1 for Yes or 2 for No:\t");
	scanf("%d",&choice);
	if(choice==2){
		printf("\t\t\tPlease check out the wiki page here, press enter when you understand\n");
		system("start http://www.wikihow.com/Play-Craps");
		getch();
	}
	//printf("Let us begin the game of craps! %sYou're up first!\n",name);
	while(1)
	{
        fflush(stdin);
        printf("\t\t\t\t\tSelect who you wish to be!\n\t\tPress 1 for Noriko, press 2 for Yoko, press 3 for Lily, press 4 for yourself, press 5 to quit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				winnings=0;
				winnings = Game(&noriko,"Noriko");
				if(winnings!=0)//We won something that isn't bad
				{
					bankroll = (double)(bankroll+winnings);//Add up the bank roll and reset the winnnings
					winnings=0;
					printf("\nYour bankroll is now at $%.02lf\n\n\n",bankroll);//Tell them how much skrilla they made
				}
				results(noriko,winnings);
				break;
			case 2:
				winnings=0;
				winnings = Game(&Yoko,"Yoko");
				if(winnings==0){printf("\n\n\t\t\tBecause of YOUR actions Yoko realized that her marriage was fake\n\n\n");}
				if(winnings!=0)//We won something that isn't bad
				{
					Yoko = (double)(Yoko+winnings);//Add up the bank roll and reset the winnnings
					winnings=0;
					printf("\nYour bankroll is now at $%.02lf\n\n\n",Yoko);//Tell them how much skrilla they made
				}
				results(Yoko,winnings);
				break;
			case 3:
				winnings=0;
				winnings = Game(&lily,"Lily");
				if(winnings==0){printf("\n\n\t\t\tBecause you lost at craps lily loses an eye to her father\n\n\n");}
				if(winnings!=0)//We won something that isn't bad
				{
					lily = (double)(lily+winnings);//Add up the bank roll and reset the winnnings
					winnings=0;
					printf("\nYour bankroll is now at $%.02lf\n\n\n",lily);//Tell them how much skrilla they made
				}
				results(lily,winnings);
				break;
			case 4:
				winnings = Game(&bankroll,name);//LETS PLAY THE GAME		
				results(bankroll,winnings);
				break;
			case 5:
				printf("The game will now exit, goodbye %s",name);
				exit(1);
		}
	}
}
