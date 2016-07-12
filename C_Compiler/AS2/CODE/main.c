/*
main.c - main program for the project
date - 2015. 04. 23
made by. ki-yeon
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tn.h"
#include "glob.h"

extern yylex();
extern char *yytext;
extern int yyleng;


void printtoken(enum tokentypes tn) 
{
	switch(tn)
	{
		case TCONST : printf("CONST\t\t\t\t"); break;
		case TELSE : printf("ELSE\t\t\t\t"); break;
		case TIF : printf("IF\t\t\t\t"); break;
		case TINT : printf("INT\t\t\t\t"); break;
		case TRETURN : printf("RETURN\t\t\t\t"); break;
		case TVOID : printf("VOID\t\t\t\t"); break;
		case TWHILE : printf("WHILE\t\t\t\t"); break;
		case TPLUS : printf("PLUS\t\t\t\t"); break; 
		case TMINUS : printf("MINUS\t\t\t\t"); break; 
		case TSTAR : printf("STAR\t\t\t\t"); break; 
		case TSLASH :printf("SLASH\t\t\t\t"); break;
		case TNOT : printf("NOT\t\t\t\t"); break;
		case TMOD : printf("MOD\t\t\t\t"); break; 
		case TASSIGN : printf("ASSIGN\t\t\t\t"); break; 		
		case TEQUAL : printf("EQUAL\t\t\t\t"); break;
		case TNOTEQU : printf("NOT EQUAL\t\t\t"); break;
		case TLESSE : printf("LESS EQUAL\t\t\t"); break;
		case TGREATE : printf("GREAT EQUAL\t\t\t"); break;  
		case TAND : printf("AND\t\t\t\t"); break;
		case TOR : printf("OR\t\t\t\t"); break;
		case TINC : printf("INC\t\t\t\t"); break;
		case TDEC : printf("DEC\t\t\t\t"); break;
		case TADDASSIGN : printf("ADDASSIGN\t\t\t"); break;
		case TSUBASSIGN : printf("SUBASSIGN\t\t\t"); break;
		case TMULASSIGN : printf("MULASSIGN\t\t\t"); break;
		case TDIVASSIGN : printf("DIVASSIGN\t\t\t"); break;
		case TMODASSIGN : printf("MODASSIGN\t\t\t"); break;
		case TLESS : printf("LESS\t\t\t\t"); break;
		case TGREAT : printf("GREAT\t\t\t\t"); break;
		case TLPAREN : printf("LEFT PARENTHESES\t\t"); break;
		case TRPAREN : printf("RIGHT PARENTHESES\t\t"); break;
		case TLBRACKET : printf("LEFT BRACKET\t\t\t"); break;
		case TRBRACKET : printf("RIGHT BRACKET\t\t\t"); break;
		case TLBRACE : printf("LEFT BRACE\t\t\t"); break;
		case TRBRACE : printf("RIGHT BRACE\t\t\t"); break;
		case TCOMMA : printf("COMMA\t\t\t\t"); break;
		case TSEMICOLON : printf("SEMICOLON\t\t\t"); break; 
		case TIDENT : printf("<identifier>\t"); break; 
		case TNUMBER: printf("<number>\t"); break; 
		case TERROR : errorcount++; printf("**Error**\t"); break;//������ �����հ踦 �ϳ� ������Ŵ 
		case NEWLINE : break;
	}
}//token���Ŀ� ���� �ν� ����� print���ִ� �Լ�

void main()
{
	enum tokentypes tn;
	strcpy(errorstring,"\n");//���� �ʱ�ȭ
	errorcount=0;
	nextid=0;
	nextfree=0;
	newcount=1;

	printf("==========================================================\n");
	printf("Line number\tToken type\tST-index\tToken\n");
	printf("==========================================================\n");
	
	while( ( tn = yylex() ) != TEOF ){
		if(tn!=NEWLINE){
			printf("%d\t\t",newcount);//����number
			printtoken(tn);//Token type ���
			if(tn==TIDENT){//IDENT�� ����
				if(!found)
					printf("%d\t\t", nextid);//���ο� identifier�� ST-index ��� 
				else
					printf("%d\t\t", originalid);//�ߺ��� identifier�� ST-index ��� 
			}
			printf("%s\t", yytext);//��ū ���
			printf("%s",errorstring);//���� ó��
			strcpy(errorstring,"\n");//���� �ʱ�ȭ
		}
		else
			newcount++;//newline�̸� ���μ� �ϳ� ����
	}//input ������ ���������� while�� ����
}


int yywrap()
{
	printf("\n\n\t%d number of errors are detected! \n",errorcount);//������ ����
	printf("==========================================================");
	printf("\nmade by. ki-yeon\n");
	return 1;
}//�� ���� ȣ��Ǵ� yywrap�Լ�
