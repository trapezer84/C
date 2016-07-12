/*
 * main.c - yyparse()를 호출한다. 
 * programmer - 이기연
 * date - 2015년 5월 31일 일요일
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "tn.h"
#include "glob.h"

extern int yylex();
extern int yyparse();
extern void PrintHStable();

int yywrap()
{
return 1;
}



void main()
{
	printf("======================================================\n");
	printf("***MiniC Parsing Begins\n");
	
	T1 = de;
	T2 = defa;

	yyparse();

	printf("\n***MiniC Parsing Ends\n");

	
	printf("\n Total %d error(s) detected.\n", cErrors);
	printf("======================================================\n\n\n");
	
	PrintHStable();
}
