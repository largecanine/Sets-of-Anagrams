// 8.16 Multiple Sets of Anagrams.cpp : Defines the entry point for the console application.
//
#include "stdio.h"
#include "ctype.h"
#define MAX_WORDS 10
#define MAX_LETTERS 25
void main()
{
	int numsets=0,isana=true;
	bool needsgetch=false;
	int row,col;
	const char constwords[MAX_WORDS][MAX_LETTERS]={
		{"cat"},//1
		{"bat"},//2
		{"tac"},//3
		{"tab"},//4
		{"ate"},//5
		{"aet"},//6
		{"abc"},//7
		{"bac"},//8
		{"bbc"},//9
		{"cbb"}//10
	};
	char words[MAX_WORDS][26]={0},ch;//init array and ch that is used to read the letters into the array
	for(row=0;row<MAX_WORDS;row++)
	{
		for(col=0;col<MAX_LETTERS && constwords[col]!=0;col++)//copies constwords to words
		{
			ch=constwords[row][col];
			ch=toupper(ch);
			words[numsets][ch-'A']++;
		}
		if(numsets==0)//if first word then it returns back to beginning of "while numwords doesnt exceed 10" because theres nothing to compare it to
		{
			numsets++;
			continue;
		}
		else//if there are two words or more then it starts to compare
		{
			int numsetscopy;//used to identify each already archived word before the word being compared
			for(numsetscopy=0;numsetscopy<numsets;numsetscopy++)
			{
				for(int a=0;a<26;a++)//compares the current word and whichever archived word is currently selected
				{
					if(words[numsetscopy][a]!=words[numsets][a])
					{
						isana=false;
						break;
					}
				}
				if(!isana)
				{
					if(numsets-numsetscopy!=1)//if there are more archived words that haven't been compared with the current word yet, the loop restarts
					{
						isana=true;
						continue;
					}
					else//if the current word does not match with an archived word, then it is archived and as the if paired with this else will never reach here, it breaks out of the loops
						numsets++;
				}
				else
				{
					for(int b=0;b<26;b++)//if the current word matches an archived word, the space for the current word is cleared and space is made for the next word
						words[numsets][b]=0;
				}
				break;
			}
			isana=true;//is set to true so the next time words are compared it can be set to false if they don't match
		}
	}
	printf("There are %d sets of anagrams.\n\n",numsets);
}

//with user input
	/*
	while(true)
	{
	for(int a=1,ch=getchar();a<=MAX_WORDS && ch!='\n' && ch!='0';a++)//while numwords doesnt exceed 10
	{
		for(int b=0;b<MAX_LETTERS && ch!='\n';b++)//reads the letters while ch != newline char
		{
			ch=toupper(ch);
			words[numsets][ch-'A']++;
			ch=getchar();
		}
		if(numsets==0)//if first word then it returns back to beginning of "while numwords doesnt exceed 10" because theres nothing to compare it to
		{
			numsets++;
			printf("Enter a word (No more than 10 and 0 to terminate): ");
			ch=getchar();
			continue;
		}
		else//if there are two words or more then it starts to compare
		{
			int numsetscopy=0;//used to identify each already archived word before the word being compared
			for(;numsetscopy<numsets;numsetscopy++)
			{
				for(int a=0;a<26;a++)//compares the current word and whichever archived word is currently selected
				{
					if(words[numsetscopy][a]!=words[numsets][a])
					{
						isana=false;
						break;
					}
				}
				if(isana==false)
				{
					if(numsets-numsetscopy!=1)//if there are more archived words that haven't been compared with the current word yet, the loop restarts
					{
						isana=true;
						continue;
					}
					else//if the current word does not match with an archived word, then it is archived and as the if paired with this else will never reach here, it breaks out of the loops
						numsets++;
					break;
				}
				else
				{
					for(int b=0;b<26;b++)//if the current word matches an archived word, the space for the current word is cleared and space is made for the next word
						words[numsets][b]=0;
					break;
				}
			}
			isana=true;//is set to true so the next time words are compared it can be set to false if they don't match
			if(a==10)
				break;
			printf("Enter a word (No more than 10 and 0 to terminate): ");//reads next word
			ch=getchar();
		}
				if(ch=='0')
		needsgetch=true;
	printf("\nThere are %d set(s) of anagrams\n\nThey are: ",numsets); //prints numsets of anagrams
	bool frstana=true;
	for(int row=0,col=0;row<MAX_WORDS;row++)//prints the sets of arrays
	{
		bool haf2print=false;
		for(;col<26;col++)
		{
			if(words[row][col]>0)
			{					
				if(frstana=true)
					frstana=false;
				for(int c=words[row][col],d=0;d<c;d++)
				{
					haf2print=true;
					printf("%c",col+'A');
				}
			}
		}
		if(haf2print==true)//lines up the strings of chars
		{
			printf("\n");
			if(frstana==false)
				printf("%10c",' ');//10 spaces
		}
		col=0;
	}
	printf("\n");
	if(needsgetch==true)
	{
		ch=getchar();//eliminates the newline 
	}
	else{}
		//ch=getchar();
	}
}
*/