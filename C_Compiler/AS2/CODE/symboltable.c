/*
symboltable.c - symfortable for the project
date - 2015. 04. 23
made by. ki-yeon


<유의점>
Hashtable에 새로운 entry추가할시 list의 제일 처음에 넣는다.
널문자까지 stringtable에 들어가야 해시테이블에 넣는 작업을 수행한다
(ex identifier는 넣었는데 꽉차서 널문자를 넣을수 없다면 해시테이블에 집어넣지 않고 overflow로 간주)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "glob.h"

extern Reporterror(int);
extern char *yytext; 
extern int yyleng; 

void stringtable(char* id){
	int i;//for문에 쓰일 i
	nextid=nextfree;//nextid인덱스를 다음 free공간으로 설정
	for(i=0;i<yyleng;i++){//identifier길이만큼 돈다
		if(nextfree<STsize){//stack이 overflow인지 매번 확인
			if(nextfree-nextid<10){//10글자 까지만 잘라 ST에 집어넣는다
				if(id[i]>=65&&id[i]<=90){ //대문자라면    
					ST[nextfree++]=(char)(id[i]+32);//소문자로 변환해 ST에 집어넣고
				}
				else //소문자 혹은 숫자라면
				{
					ST[nextfree++]=id[i]; //그냥 집어넣는다
				}
			}
		}
		else{//stack이 overflow 
			Reporterror(3);
		}
	}
}//main.c에서 identifier를 받아 stringtable에 넣는다

void computeHS(int nid,int nfree){
	int sum=0;//합 0으로 설정
	while(nid<nfree-1){
		sum+=(int)ST[nid];//string table의 문자를 아스키코드값으로 바꾸어 더한다
		nid++;//nid 하나 증가
	}
	hashcode=sum%HTsize;
}//hash code계산



void lookupHS(int nid,int hscode){
	HTpointer tempentry;//HTentry가리키는 임시 변수

	int temp1,temp2;//index가리키는 임시변수
	if(HT[hscode]==NULL){ //HT[hscode]에 아무것도 연결되어있지 않으면 그냥 return 
		found=0;//못찾음
		return;
	}
	else{//HT[hscode]에 무언가 연결되어있다면
		tempentry = HT[hscode];
		found=0;//초기값=못찾음
		while(tempentry!=NULL&&found==0){//HT[hscode]에 연결되어있는 entry들 다 검색
			temp1=nid;//새로 입력한 id의 index
			temp2=tempentry->index;//입력되어있던 id의 index
			originalid=temp2;//입력되어있던 id의 인덱스를 저장
			while(temp1<nextfree){
				if(ST[temp1]==ST[temp2]){
					temp1++;
					temp2++;
					found=1;
				}
				else {
					found=0; //찾지 못함
					return;
				}
			}
			tempentry=tempentry->next;
		}
	}
}//hash table에서 identifier검색하여 중복 체크


void ADDHT(int hscode){
	HTpointer newentry;//id정보를 저장할 새 entry
	newentry=(HTpointer)malloc(sizeof(newentry));//새 entry를 동적할당하여 만든다
	
	newentry->index=nextid;
	newentry->next=HT[hscode];//현재 identifier의 정보를 입력하고
	HT[hscode]=newentry;//HT[hscode]가 newentry를 가리키게함
}//hash table에 HTentry 추가하는 함수


void Symboltable(){
	stringtable(yytext);//id를 stringtable에 넣는다
	if(nextfree==STsize){
		Reporterror(3);//오류 출력
	}//stringtable꽉 찼으면 오류출력!
	ST[nextfree++]='\0';//identifier끝에 null문자 추가
	computeHS(nextid,nextfree);//hashcode 계산
	lookupHS(nextid,hashcode);//중복 확인	
	
	if(!found){//못찾았다면
		ADDHT(hashcode);//해시테이블에 추가
	}
	else{
		nextfree=nextid;//포인터 원상복귀
	}
}//Symboltable에 identifier를 넣어주는 함수


