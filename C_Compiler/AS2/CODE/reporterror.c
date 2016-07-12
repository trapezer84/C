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
		strcpy(errorstring,"*** Illegal Identifier ***\n");//�̻��� id�϶�
		break;
	case 2:
		strcpy(errorstring,"*** Illegal Character ***\n");//�̻��� �����϶�
		break;
	case 3:
		printf("********OVERFLOW********\n");//overflow�϶�
		printf("\n\n\t%d number of errors are detected! \n",errorcount);//������ ����
		printf("==========================================================");
		printf("\nmade by. young-eun ki-yeon seong-ha\n");
		abort();//abort
		break;
	default:
		strcpy(errorstring,"\n");//������ ������
		break;
	}
}//���� ó�� �Լ�