/*
 * glob.h - global�������� ��Ƴ��� header ����
 * programmer - �̱⿬
 * date - 2015�� 5�� 31�� �Ͽ���
 */

#define STsize 1000 //size of string table
#define HTsize 10000 //size of hash table

typedef struct HTentry *HTpointer;

typedef struct HTentry {

int index; //index of identifier in ST
int line; // line number ����
int type3; 
int scope;

HTpointer next; //pointer to next identifier
HTpointer func_next;

} HTentry;


HTpointer HT[HTsize];

char ST[STsize];


enum ERRORtypes{noerror, wstat, wfunc, nobrace, nosemi, nobracket, overst};

enum Type1 {in,vo, de};
enum Type2 {func, scal, arra, defa};

enum ERRORtypes err;
enum Type1 T1;
enum Type2 T2;

int cErrors;
int i;
int sametype;
int func_in;

HTpointer temp;