/*
symboltable.c - symfortable for the project
date - 2015. 04. 23
made by. ki-yeon


<������>
Hashtable�� ���ο� entry�߰��ҽ� list�� ���� ó���� �ִ´�.
�ι��ڱ��� stringtable�� ���� �ؽ����̺� �ִ� �۾��� �����Ѵ�
(ex identifier�� �־��µ� ������ �ι��ڸ� ������ ���ٸ� �ؽ����̺� ������� �ʰ� overflow�� ����)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "glob.h"

extern Reporterror(int);
extern char *yytext; 
extern int yyleng; 

void stringtable(char* id){
	int i;//for���� ���� i
	nextid=nextfree;//nextid�ε����� ���� free�������� ����
	for(i=0;i<yyleng;i++){//identifier���̸�ŭ ����
		if(nextfree<STsize){//stack�� overflow���� �Ź� Ȯ��
			if(nextfree-nextid<10){//10���� ������ �߶� ST�� ����ִ´�
				if(id[i]>=65&&id[i]<=90){ //�빮�ڶ��    
					ST[nextfree++]=(char)(id[i]+32);//�ҹ��ڷ� ��ȯ�� ST�� ����ְ�
				}
				else //�ҹ��� Ȥ�� ���ڶ��
				{
					ST[nextfree++]=id[i]; //�׳� ����ִ´�
				}
			}
		}
		else{//stack�� overflow 
			Reporterror(3);
		}
	}
}//main.c���� identifier�� �޾� stringtable�� �ִ´�

void computeHS(int nid,int nfree){
	int sum=0;//�� 0���� ����
	while(nid<nfree-1){
		sum+=(int)ST[nid];//string table�� ���ڸ� �ƽ�Ű�ڵ尪���� �ٲپ� ���Ѵ�
		nid++;//nid �ϳ� ����
	}
	hashcode=sum%HTsize;
}//hash code���



void lookupHS(int nid,int hscode){
	HTpointer tempentry;//HTentry����Ű�� �ӽ� ����

	int temp1,temp2;//index����Ű�� �ӽú���
	if(HT[hscode]==NULL){ //HT[hscode]�� �ƹ��͵� ����Ǿ����� ������ �׳� return 
		found=0;//��ã��
		return;
	}
	else{//HT[hscode]�� ���� ����Ǿ��ִٸ�
		tempentry = HT[hscode];
		found=0;//�ʱⰪ=��ã��
		while(tempentry!=NULL&&found==0){//HT[hscode]�� ����Ǿ��ִ� entry�� �� �˻�
			temp1=nid;//���� �Է��� id�� index
			temp2=tempentry->index;//�ԷµǾ��ִ� id�� index
			originalid=temp2;//�ԷµǾ��ִ� id�� �ε����� ����
			while(temp1<nextfree){
				if(ST[temp1]==ST[temp2]){
					temp1++;
					temp2++;
					found=1;
				}
				else {
					found=0; //ã�� ����
					return;
				}
			}
			tempentry=tempentry->next;
		}
	}
}//hash table���� identifier�˻��Ͽ� �ߺ� üũ


void ADDHT(int hscode){
	HTpointer newentry;//id������ ������ �� entry
	newentry=(HTpointer)malloc(sizeof(newentry));//�� entry�� �����Ҵ��Ͽ� �����
	
	newentry->index=nextid;
	newentry->next=HT[hscode];//���� identifier�� ������ �Է��ϰ�
	HT[hscode]=newentry;//HT[hscode]�� newentry�� ����Ű����
}//hash table�� HTentry �߰��ϴ� �Լ�


void Symboltable(){
	stringtable(yytext);//id�� stringtable�� �ִ´�
	if(nextfree==STsize){
		Reporterror(3);//���� ���
	}//stringtable�� á���� �������!
	ST[nextfree++]='\0';//identifier���� null���� �߰�
	computeHS(nextid,nextfree);//hashcode ���
	lookupHS(nextid,hashcode);//�ߺ� Ȯ��	
	
	if(!found){//��ã�Ҵٸ�
		ADDHT(hashcode);//�ؽ����̺� �߰�
	}
	else{
		nextfree=nextid;//������ ���󺹱�
	}
}//Symboltable�� identifier�� �־��ִ� �Լ�


