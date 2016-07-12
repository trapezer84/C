/*
reporterror.c - error handling for the project
date - 2015. 04. 23
made by. ki-yeon
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "glob.h"

void Reporterror(int error)
{
	switch (error){
	case 1:
		strcpy(errorstring,"*** Illegal Identifier ***\n");//이상한 id일때
		break;
	case 2:
		strcpy(errorstring,"*** Illegal Character ***\n");//이상한 문자일때
		break;
	case 3:
		printf("********OVERFLOW********\n");//overflow일때
		printf("\n\n\t%d number of errors are detected! \n",errorcount);//에러수 세기
		printf("==========================================================");
		printf("\nmade by. young-eun ki-yeon seong-ha\n");
		abort();//abort
		break;
	default:
		strcpy(errorstring,"\n");//에러가 없을시
		break;
	}
}//에러 처리 함수