/*
 * ReportError.c - 각 경우에 맞는 error message 출력
 * programmer - 이기연
 * date - 2015년 5월 31일 일요일
 */
#include<stdio.h>
#include<stdlib.h>
#include "glob.h"
#include "tn.h"
extern char *yytext;

void yyerror(char *s){
	//printf("%s",s);
}


/* Error 를 적절하게 골라내 출력하는 함수 */
void PrintError( enum ERRORtypes err )
{
	cErrors++;

	if(err == overst)
	{
		printf("\n<Error>		OVERFLOW \n");

		
		if(cErrors==0)
			printf("No errors defected\n");
		else
			printf("%d errors detected\n", cErrors);

	}

	if(err == wstat)
	{
		printf("\n%d		<Error> Wrong Statement.",i);
	}

	if(err == wfunc)
	{
		printf("\n%d		<Error> Wrong Function Definition.",i);
	}

	if(err==nobrace){
		printf("\n%d		<Error> No Brace.",i);
	}

	if(err==nobracket){
		printf("\n%d		<Error> No Bracket.",i);
	}

	if(err==nosemi){
		printf("\n%d		<Error> No Semicolon.",i);
	}

}