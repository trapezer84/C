/*
유의점>
Hashtable에 새로운 entry추가할시 list의 제일 처음에 넣는다.
+ 알고리즘상의 이유 때문에 IDENTIFIER먼저 출력하고 그다음에 INDEX출력하여서 
출력이 이쁘지가 않습니다. 감안하고 보아 주시면 감사하겠습니다.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define FILE_NAME "testdata.txt"//입력 파일
#define STsize 1000 //string table 사이즈
#define HTsize 100 //hash table 사이즈

typedef struct HTentry *HTpointer; //hash table entry 가리키는 포인터
typedef struct HTentry{
	int index;// string table 인덱스
	HTpointer next;//다음 entry를 가리키는 포인터
}HTentry;//hash table 개체

enum errorTypes {noerror, illsp,illid, overst};//에러 종류 {에러없음, 잘못된 seperator, 잘못된 id, overflow}
typedef enum errorTypes ERRORtypes;//에러 타입
ERRORtypes err;//에러 변수

char seperators[] =".,;:?!\t\n ";//delimeter
char alphabet[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";//알파벳
char number[]="0123456789";//number
int snum,anum,nnum;//seperator,alphabet,숫자 개수

HTpointer HT[HTsize];//hash table
char ST[STsize];//string table

int nextid=0,nextfree=0;//identifier의 처음과 끝을 포인트 하기위한 String table의 index들
int originalid;//중복체크시 id가 같으면 기존 id의 인덱스 반환하기 위한 변수
int hashcode;//hash code
int found;//중복체크 flag

FILE *fp;//파일 포인터
char input;//입력 문자



void initialize(){
	snum= strlen(seperators);//seperator 개수
	anum= strlen(alphabet);//alphabet 개수
	nnum= strlen(number);//숫자 개수
	fp=fopen(FILE_NAME,"r");//파일 읽기모드로 열기
	input=fgetc(fp);//문자 입력 받기
}//파일 연결 및 초기화

void printHeading(){
	printf("------------\t------------\n");
	printf("identifier\tIndex in ST\n");
	printf("------------\t------------\n");
}//list head 출력


void printHStable(){
   int i;//for문 변수
   int temp;//인덱스를 저장할 변수
   HTpointer tempentry;//entry pointer
   printf("[[ HASH TABLE ]]\n");
   
   for(i=0;i<HTsize;i++){//Hash table 끝까지 돈다
      if(HT[i]!='\0'){//hash table[i]가 널이 아니면 프린트 하게 한다. 
         printf("Hash Code %d : ",i);
         for(tempentry=HT[i];tempentry!='\0';tempentry=tempentry->next){//HT[i]에 연결되어 있는 모든 entry를 출력한다
			for(temp=tempentry->index;ST[temp]!='\0'; temp++){//현재 entry에 있는 identifier출력한다
               printf("%c",ST[temp]);
            }//id 출력
            printf("\t");
         }
         printf("\n");
      }
   }
   printf("\n< %d characters are used in the string table >\n",nextfree-1);//String table이 얼만큼 쓰였는지 보여준다
}//hash table 출력

void printError(ERRORtypes err){		
	int i=0;
	switch(err){
	case 0://오류없음
		break;
	case 1://이상한 seperator
		printf("**Error**\t illegar seperator!\n");
		break;
	case 2://이상한 id
		printf("**Error**\t ");
		while(input!=EOF){//무한 loop
			for(i=0;i<snum;i++){
				if(input==seperators[i]){//delimeter를 만나면 for문 빠져나옴
					break;
				}
			}
			if(i==snum){//delimeter가 아니었음
				printf("%c", input);
				input=fgetc(fp);//그다음 문자 입력 받기
			}
			else{//delimeter였음
				break;//while문 빠져나오기
			}
		}		
		printf(" start with digits\n");
		break;
	case 3://overflow
		printf("\n**Error** OVERFLOW!\n");
		printHStable();//해시테이블 프린트
		abort();//abort
		break;
	}
}//에러 출력


void skipSeperators(){
	int i,j,k;//변수 설정
	while(1){//무한 loop
		for(i=0;i<snum;i++){
			while(input==seperators[i]){//delimeter중 하나면
				input=fgetc(fp);//그다음 문자 입력 받기
				i=0;//i 리셋
				break;//while loop 빠져나오기
			}
		}
		for(j=0;j<anum;j++){
			while(input==alphabet[j]){//alphabet중 하나면			
				return;
			}
		}
		for(k=0;k<nnum;k++){
			while(input==number[k]){//number중 하나면
				return;
			}
		}
		if(input==EOF){//파일끝이면
			printHStable();//해시테이블 프린트
			exit(1);//종료
		}//파일끝이 seperator로 끝날시에 오류 방지하기 위해 넣은 if문
		
		err=illsp;//seperator,숫자,문자 다 아니면 illsp
		printError(err);//에러 출력
		err=noerror;//error 초기화
		input=fgetc(fp);//그 다음 문자 입력 받기
	}
}//delimeter를 skip하는 함수

void readID(){
   int i;//변수 설정
   nextid=nextfree;//nextid인덱스를 다음 free공간으로 설정
   for(i=0;i<nnum;i++){
		if(input==number[i]){//첫 글자가 number중 하나면
			err=illid;//이상한 identifier 
			printError(err);//오류 출력
			return;
		}
	}//첫 문자가 number면 이상한 identifier
   while((input>=48&&input<58)||(input>=65&&input<=90)||(input>=97&&input<=122)){//대소문자 혹은 숫자면 while loop 돌기 
	   if(nextfree<STsize){//stack이 overflow인지 매번 확인
		   if(nextfree-nextid<10){//10글자 까지만 잘라 ST에 집어넣는다
			   if(input>=65&&input<=90){ //대문자라면 
				   ST[nextfree++]=(char)(input+32);//소문자로 변환해 ST에 집어넣고
			   }
			   else //소문자 혹은 숫자라면
			   {
				   ST[nextfree++]=input; //그냥 집어넣는다
			   }
		   }
		   printf("%c",input);//콘솔에 출력
		   input=fgetc(fp);//그다음 문자 입력 받기
	   }
	   else{//stack이 overflow 
		   err=overst;//stack 꽉참
		   printError(err);
	   }
   }
}

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


int main(){
	printHeading();//list 헤더 출력
	initialize();//초기화
	while(input != EOF){
		err=noerror;//초기상태는 오류 없음
		skipSeperators();//seperator를 skip
		readID();//id인식
		if(err!=illid){//입력이 이상한 identifier가 아닐경우
			if(nextfree==STsize){
				err=overst;//stack 꽉참
				printError(err);//오류 출력
			}
			ST[nextfree++]='\0';//identifier끝에 null문자 추가
		
			computeHS(nextid,nextfree);//hashcode 계산
			lookupHS(nextid,hashcode);//중복 확인	
			
			if(!found){//못찾았다면
				ADDHT(hashcode);//해시테이블에 추가
				printf("%15d",nextid);//identifier의 첫번째index print
				printf("\t(entered)\n");
			}
			else{
				printf("%15d",originalid);//이미 존재한 identifier의 index print
				printf("\t(already existed)\n");//이미 존재
				nextfree=nextid;//포인터 원상복귀
			}
		}
	}//파일 끝까지 갔으면 종료
	
	printHStable();//해시테이블 프린트
}


