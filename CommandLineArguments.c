#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//Adam A Dost G00703748 Lab 214 CS 262
int main ( int argc, char *argv[] )
{
	FILE *fp1, *fp2;//Create two File Pointer
	char a;
	fp1 = fopen(argv[1],"r"); //Try to open file 1
	assert(fp1 !=NULL);
	//If the input text break the program and notify the user with a print statement
	if(fp1 == NULL)
	{
		printf("%s does not exist\nClosing Program",argv[1]);
		return;//Stops the Program
	}
	fp2 = fopen(argv[2],"w");//Open File 2
	
	//If the input text break the program and notify the user with a print statement
	
	if(fp2 == NULL)
	{
		printf("%s does not exist\nClosing Program",argv[2]);
		return;//Break
	}
	
	while((a = fgetc(fp1))!=EOF)//CATCHES THE END OF THE FILE AND MAKES SURE IT DOESN'T PLACE IT INTO THE TEXT.
	{	
		#ifndef NDEBUG
			printf("%c",a);
		#endif
		putc(a,fp2);
	}
}
