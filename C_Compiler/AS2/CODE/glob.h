/*
glob.h - global variable for the project
date - 2015. 04. 23
made by. ki-yeon
*/

#define STsize 1000 //string table 사이즈
#define HTsize 100 //hash table 사이즈

typedef struct HTentry *HTpointer; //hash table entry 가리키는 포인터
typedef struct HTentry{
	int index;// string table 인덱스
	HTpointer next;//다음 entry를 가리키는 포인터
}HTentry;//hash table 개체

HTpointer HT[HTsize];//hash table
char ST[STsize];//string table

int newcount;//line수 세기 위한 변수
int nextid;
int nextfree;//identifier의 처음과 끝을 포인트 하기위한 String table의 index들
int originalid;//중복체크시 id가 같으면 기존 id의 인덱스 반환하기 위한 변수

int hashcode;//hash code
int found;//중복체크 flag

int errorcount;//에러 수
char errorstring[30];//에러시 프린트할 스트링