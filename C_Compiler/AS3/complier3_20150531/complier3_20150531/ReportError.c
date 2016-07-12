/*
 * ReportError.c - �� ��쿡 �´� error message ���
 * programmer - �̱⿬
 * date - 2015�� 5�� 31�� �Ͽ���
 */
#include<stdio.h>
#include<stdlib.h>
#include "glob.h"
#include "tn.h"
extern char *yytext;

void yyerror(char *s){
	//printf("%s",s);
}


/* Error �� �����ϰ� ��� ����ϴ� �Լ� */
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