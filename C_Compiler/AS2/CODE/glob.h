/*
glob.h - global variable for the project
date - 2015. 04. 23
made by. ki-yeon
*/

#define STsize 1000 //string table ������
#define HTsize 100 //hash table ������

typedef struct HTentry *HTpointer; //hash table entry ����Ű�� ������
typedef struct HTentry{
	int index;// string table �ε���
	HTpointer next;//���� entry�� ����Ű�� ������
}HTentry;//hash table ��ü

HTpointer HT[HTsize];//hash table
char ST[STsize];//string table

int newcount;//line�� ���� ���� ����
int nextid;
int nextfree;//identifier�� ó���� ���� ����Ʈ �ϱ����� String table�� index��
int originalid;//�ߺ�üũ�� id�� ������ ���� id�� �ε��� ��ȯ�ϱ� ���� ����

int hashcode;//hash code
int found;//�ߺ�üũ flag

int errorcount;//���� ��
char errorstring[30];//������ ����Ʈ�� ��Ʈ��