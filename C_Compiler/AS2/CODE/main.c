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
		case TERROR : errorcount++; printf("**Error**\t"); break;//에러면 에러합계를 하나 증가시킴 
		case NEWLINE : break;
	}
}//token형식에 따라 인식 결과를 print해주는 함수

void main()
{
	enum tokentypes tn;
	strcpy(errorstring,"\n");//에러 초기화
	errorcount=0;
	nextid=0;
	nextfree=0;
	newcount=1;

	printf("==========================================================\n");
	printf("Line number\tToken type\tST-index\tToken\n");
	printf("==========================================================\n");
	
	while( ( tn = yylex() ) != TEOF ){
		if(tn!=NEWLINE){
			printf("%d\t\t",newcount);//라인number
			printtoken(tn);//Token type 출력
			if(tn==TIDENT){//IDENT일 때만
				if(!found)
					printf("%d\t\t", nextid);//새로운 identifier의 ST-index 출력 
				else
					printf("%d\t\t", originalid);//중복된 identifier의 ST-index 출력 
			}
			printf("%s\t", yytext);//토큰 출력
			printf("%s",errorstring);//에러 처리
			strcpy(errorstring,"\n");//에러 초기화
		}
		else
			newcount++;//newline이면 라인수 하나 증가
	}//input 파일이 끝날때까지 while문 돈다
}


int yywrap()
{
	printf("\n\n\t%d number of errors are detected! \n",errorcount);//에러수 세기
	printf("==========================================================");
	printf("\nmade by. ki-yeon\n");
	return 1;
}//맨 끝에 호출되는 yywrap함수
