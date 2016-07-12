/*
������>
Hashtable�� ���ο� entry�߰��ҽ� list�� ���� ó���� �ִ´�.
+ �˰������ ���� ������ IDENTIFIER���� ����ϰ� �״����� INDEX����Ͽ��� 
����� �̻����� �ʽ��ϴ�. �����ϰ� ���� �ֽø� �����ϰڽ��ϴ�.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define FILE_NAME "testdata.txt"//�Է� ����
#define STsize 1000 //string table ������
#define HTsize 100 //hash table ������

typedef struct HTentry *HTpointer; //hash table entry ����Ű�� ������
typedef struct HTentry{
	int index;// string table �ε���
	HTpointer next;//���� entry�� ����Ű�� ������
}HTentry;//hash table ��ü

enum errorTypes {noerror, illsp,illid, overst};//���� ���� {��������, �߸��� seperator, �߸��� id, overflow}
typedef enum errorTypes ERRORtypes;//���� Ÿ��
ERRORtypes err;//���� ����

char seperators[] =".,;:?!\t\n ";//delimeter
char alphabet[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";//���ĺ�
char number[]="0123456789";//number
int snum,anum,nnum;//seperator,alphabet,���� ����

HTpointer HT[HTsize];//hash table
char ST[STsize];//string table

int nextid=0,nextfree=0;//identifier�� ó���� ���� ����Ʈ �ϱ����� String table�� index��
int originalid;//�ߺ�üũ�� id�� ������ ���� id�� �ε��� ��ȯ�ϱ� ���� ����
int hashcode;//hash code
int found;//�ߺ�üũ flag

FILE *fp;//���� ������
char input;//�Է� ����



void initialize(){
	snum= strlen(seperators);//seperator ����
	anum= strlen(alphabet);//alphabet ����
	nnum= strlen(number);//���� ����
	fp=fopen(FILE_NAME,"r");//���� �б���� ����
	input=fgetc(fp);//���� �Է� �ޱ�
}//���� ���� �� �ʱ�ȭ

void printHeading(){
	printf("------------\t------------\n");
	printf("identifier\tIndex in ST\n");
	printf("------------\t------------\n");
}//list head ���


void printHStable(){
   int i;//for�� ����
   int temp;//�ε����� ������ ����
   HTpointer tempentry;//entry pointer
   printf("[[ HASH TABLE ]]\n");
   
   for(i=0;i<HTsize;i++){//Hash table ������ ����
      if(HT[i]!='\0'){//hash table[i]�� ���� �ƴϸ� ����Ʈ �ϰ� �Ѵ�. 
         printf("Hash Code %d : ",i);
         for(tempentry=HT[i];tempentry!='\0';tempentry=tempentry->next){//HT[i]�� ����Ǿ� �ִ� ��� entry�� ����Ѵ�
			for(temp=tempentry->index;ST[temp]!='\0'; temp++){//���� entry�� �ִ� identifier����Ѵ�
               printf("%c",ST[temp]);
            }//id ���
            printf("\t");
         }
         printf("\n");
      }
   }
   printf("\n< %d characters are used in the string table >\n",nextfree-1);//String table�� ��ŭ �������� �����ش�
}//hash table ���

void printError(ERRORtypes err){		
	int i=0;
	switch(err){
	case 0://��������
		break;
	case 1://�̻��� seperator
		printf("**Error**\t illegar seperator!\n");
		break;
	case 2://�̻��� id
		printf("**Error**\t ");
		while(input!=EOF){//���� loop
			for(i=0;i<snum;i++){
				if(input==seperators[i]){//delimeter�� ������ for�� ��������
					break;
				}
			}
			if(i==snum){//delimeter�� �ƴϾ���
				printf("%c", input);
				input=fgetc(fp);//�״��� ���� �Է� �ޱ�
			}
			else{//delimeter����
				break;//while�� ����������
			}
		}		
		printf(" start with digits\n");
		break;
	case 3://overflow
		printf("\n**Error** OVERFLOW!\n");
		printHStable();//�ؽ����̺� ����Ʈ
		abort();//abort
		break;
	}
}//���� ���


void skipSeperators(){
	int i,j,k;//���� ����
	while(1){//���� loop
		for(i=0;i<snum;i++){
			while(input==seperators[i]){//delimeter�� �ϳ���
				input=fgetc(fp);//�״��� ���� �Է� �ޱ�
				i=0;//i ����
				break;//while loop ����������
			}
		}
		for(j=0;j<anum;j++){
			while(input==alphabet[j]){//alphabet�� �ϳ���			
				return;
			}
		}
		for(k=0;k<nnum;k++){
			while(input==number[k]){//number�� �ϳ���
				return;
			}
		}
		if(input==EOF){//���ϳ��̸�
			printHStable();//�ؽ����̺� ����Ʈ
			exit(1);//����
		}//���ϳ��� seperator�� �����ÿ� ���� �����ϱ� ���� ���� if��
		
		err=illsp;//seperator,����,���� �� �ƴϸ� illsp
		printError(err);//���� ���
		err=noerror;//error �ʱ�ȭ
		input=fgetc(fp);//�� ���� ���� �Է� �ޱ�
	}
}//delimeter�� skip�ϴ� �Լ�

void readID(){
   int i;//���� ����
   nextid=nextfree;//nextid�ε����� ���� free�������� ����
   for(i=0;i<nnum;i++){
		if(input==number[i]){//ù ���ڰ� number�� �ϳ���
			err=illid;//�̻��� identifier 
			printError(err);//���� ���
			return;
		}
	}//ù ���ڰ� number�� �̻��� identifier
   while((input>=48&&input<58)||(input>=65&&input<=90)||(input>=97&&input<=122)){//��ҹ��� Ȥ�� ���ڸ� while loop ���� 
	   if(nextfree<STsize){//stack�� overflow���� �Ź� Ȯ��
		   if(nextfree-nextid<10){//10���� ������ �߶� ST�� ����ִ´�
			   if(input>=65&&input<=90){ //�빮�ڶ�� 
				   ST[nextfree++]=(char)(input+32);//�ҹ��ڷ� ��ȯ�� ST�� ����ְ�
			   }
			   else //�ҹ��� Ȥ�� ���ڶ��
			   {
				   ST[nextfree++]=input; //�׳� ����ִ´�
			   }
		   }
		   printf("%c",input);//�ֿܼ� ���
		   input=fgetc(fp);//�״��� ���� �Է� �ޱ�
	   }
	   else{//stack�� overflow 
		   err=overst;//stack ����
		   printError(err);
	   }
   }
}

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


int main(){
	printHeading();//list ��� ���
	initialize();//�ʱ�ȭ
	while(input != EOF){
		err=noerror;//�ʱ���´� ���� ����
		skipSeperators();//seperator�� skip
		readID();//id�ν�
		if(err!=illid){//�Է��� �̻��� identifier�� �ƴҰ��
			if(nextfree==STsize){
				err=overst;//stack ����
				printError(err);//���� ���
			}
			ST[nextfree++]='\0';//identifier���� null���� �߰�
		
			computeHS(nextid,nextfree);//hashcode ���
			lookupHS(nextid,hashcode);//�ߺ� Ȯ��	
			
			if(!found){//��ã�Ҵٸ�
				ADDHT(hashcode);//�ؽ����̺� �߰�
				printf("%15d",nextid);//identifier�� ù��°index print
				printf("\t(entered)\n");
			}
			else{
				printf("%15d",originalid);//�̹� ������ identifier�� index print
				printf("\t(already existed)\n");//�̹� ����
				nextfree=nextid;//������ ���󺹱�
			}
		}
	}//���� ������ ������ ����
	
	printHStable();//�ؽ����̺� ����Ʈ
}


