#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct loc
{
	char locName[35];
	char *location;
	float longitude;
	float latitude;
	struct loc *next;
}loc;
loc *AddItem(loc *ptr, char locName[],char *location, float lon, float lat)
{
	loc *lp = ptr;
	if(ptr!=NULL)
	{
		while(ptr->next!=NULL)
		{
			ptr = ptr->next;
		}
		ptr->next=(loc*)malloc(sizeof(loc));
		ptr = ptr->next;
		ptr->next=NULL;
		strcpy(ptr->locName,locName);
		strcpy(ptr->location,location);
		ptr->longitude= lon;
		ptr->latitude=lat;
		return ptr;
	}
	else
	{
		ptr = (loc*)malloc(sizeof(loc));
		ptr->next=NULL;
		return ptr;
	}
}
void menu_choice();
int main()
{
	loc l, *ptr;
	char locName[35];
	char *location,choice;
	float longitude;
	float latitude;
	ptr = NULL;
	do
	{
		menu_choice(&choice);
		switch(choice)
		{
			case 'A':
			case 'a':
				printf("YOU HIT A");
		}
	}while(choice!='Q'||choice!='q');
	

}

void menu_choice(char* choice)
{
	char local;
	printf("\nOptions are the following:
\t[A]dd an additional location to the LocationArray
\t[P]rint the current list of locations
\t[Q]uit the program\n");
	do{
		local = getchar();
		if(local!='\n')
		{
			printf("You must enter a character");
		}
	}
	*choice = local;

}
