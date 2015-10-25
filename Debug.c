#include<stdio.h>
#include<stdlib.h>
#ifndef NDEBUG
	printf("Does this actually work?\n");
#endif
int main ( int argc, char *argv[] )
{
	FILE *fp1, *fp2;
	char a;
	fp1 = fopen(argv[1],"r");
	if(fp1 == NULL){
		printf("%s does not exist\nClosing Program",argv[1]);
		return;//Stops the Program
	}
	fp2 = fopen(argv[2],"w");
	if(fp2 == NULL)
	{
		printf("%s does not exist\nClosing Program",argv[2]);
		return;
	}
	while((a = fgetc(fp1))!=EOF)
	{
		putc(a,fp2);
	}
}
