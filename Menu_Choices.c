#include <stdio.h>
void menu_choices();
void main()
{
	//Menu Choices in the following
	char choice;
	char character;
	char number;
	char type;
	int rows;
	int boolean = 0; //True
	int i,j;
	menu_choices();
	scanf("%c", &choice);
	while(choice != 'Q')
	{	
		if (choice != '\n')
		{
			switch(choice)
			{
				case 'C':
				case 'c':
					printf("Enter your character\t\t");
					scanf(" %c",&character);
					break;
					
				case 'N':
				case 'n':
					printf("Enter your number\t\t");
					scanf("%c ",&number);
					rows = number - '0';
					break;
				case '1':
					for(i=0;i<rows;++i)
					{
						for(j=0;j<i;++j)
						{
							printf("%c ",character);
						}
						printf("\n");
					}
				case '2':
					for(i=0;i<rows;++i)
					{
						for(j=0;j<i;++j)
						{
							printf("%c ",character);
						}
						printf("\n");
					}
					printf("\n");
					break;
				case 'Q':
				case 'q':
					boolean = 1;
					choice = 'Q';
			}
		}
		menu_choices();
		scanf(" %c", &choice);
	}
}

void menu_choices()
{
	printf("Menu choice \t\t\t\t\t Valid Choices\nEnter/Change Character\t\t\t\t 'C' or 'c'\n");
	printf("Enter/Change Number \t\t\t\t 'N' or 'n'\n");
	printf("Print Triangle Type 1 (Left Justified) \t\t '1'\n");
	printf("Print Triangle Type 2 (Right Justified) \t '2'\n");
	printf("Quit program \t\t\t\t\t 'Q' or 'q'\n\nInput your choice\t\t");
}
