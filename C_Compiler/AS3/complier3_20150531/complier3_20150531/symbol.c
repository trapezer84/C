/*
 * symbol.c - Identifier 가 들어왔을때 hash table 추가 및 관리
 * programmer - 이기연
 * date - 2015년 5월 31일 일요일
 */
#include<stdio.h>
#include<stdlib.h>
#include "glob.h"
#include "tn.h"

extern void PrintError( enum ERRORtypes err);
extern char *yytext;
extern int yyleng;

int found = 0;
int nextid = 0, nextfree = 0, hashcode = 0;
int sameid = 0;

HTpointer ScopeTrace = NULL;

void funcname(int cur_scope)
{
	HTpointer cur = ScopeTrace;

	if(cur_scope == 0)
		printf("root(),	");
	else{
		while(cur_scope > 0){

			if(cur->func_next == NULL)
				break;

			cur = cur->func_next;
			cur_scope--;
		}

		printf("%s(),	",&ST[cur->index]);
	}
}

// PrintHStable - Prints the hash table.write out the hashcode and the list of identifiers
// associated with each hashcode,but only for non-empty lists.
// Print out the number of characters used up in ST.

void PrintHStable()
{
	int j = 0;
	HTpointer curr_node;

	printf("[[ HASH TABLE : Identifier Information  ]]\n");

	for(j=0; j < HTsize ; j++)
	{
		curr_node = HT[j];

		if(curr_node == NULL)
			continue;
		else{
			printf("\nHash Code %d: ", j);
			do{

				printf("(%s:	line%d,	",&ST[curr_node->index], curr_node->line);

				funcname(curr_node->scope);

				switch(curr_node->type3){
				case 0: printf("integer scalar variable )"); break;
				case 1: printf("integer array variable )"); break;
				case 2: printf("void scalar variable )"); break;
				case 3: printf("void array variable )"); break;
				case 4: printf("function name )"); break;
				default: printf("no type )"); break;
				}

				curr_node = curr_node->next;
			}while(curr_node != NULL);
		}
	}
	printf("\n\n<%d characters are used in the string table>\n\n",nextid-1);

}


// ComputeHS - Compute the hash code of identifier by summing the ordinal values of its
// characters and then taking the sum modulo the size of HT.
void ComputeHS( int nid, int nfree )
{
	int count;
	int i, a;
	int sum=0;
	
	count=nfree-nid;

	for(i=0;i<count;i++){
		a=ST[nid+i]+'0';
		sum=sum+a;
	}

	hashcode=sum%HTsize;
}

// LookupHS -For each identifier,Look it up in the hashtable for previous occurrence
// of the identifier.If find a match, set the found flag as true.
// Otherwise flase.
// If find a match, save the starting index of ST in same id.
void LookupHS(int nid, int hscode)
{
	HTpointer curr_node;
	int ST_index, nid_index;

	found = 0;
	if( HT[hscode] != NULL )
	{
		curr_node = HT[hscode];
		while(curr_node != NULL && found == 0)
		{
			found = 1;
			ST_index = curr_node->index;
			nid_index = nid;
			sameid = ST_index;

			while(ST[ST_index] != '\0' && ST[nid_index] != '\0' && found == 1)
			{
				if(ST[ST_index] != ST[nid_index])
					found = 0;
				else
				{
					ST_index++;
					nid_index++;
				}
			}
			curr_node = curr_node->next;
		}
	}
}

// ADDHT - Add a new identifier to the hash table.
// If list head ht[hashcode] is null, simply add a list element with
// starting index of the identifier in ST.
// IF list head is not a null , it adds a new identifier to the head of the chain
void ADDHT( int nid, int hscode )
{
	HTpointer curr_node = NULL;

	HTpointer new_node = (HTentry*)malloc(sizeof(HTentry)); // Make new node increased in hash table.
	new_node->index = nid;
	new_node->line = i; // line number 저장
	new_node->func_next = NULL;
	new_node->next = NULL;


	if(HT[hscode] == NULL)
		HT[hscode] = new_node;
	else{
		curr_node = HT[hscode];

		while(curr_node->next != NULL) // Find end node in list.
			curr_node = curr_node->next;

		curr_node->next = new_node;
	}

	temp = new_node;
}

// SymbolTable() - Identifier 가 들어왔을때, 기존에 있는것인지 없는것이지 걸러내고
//                 제대로 출력

int SymbolTable(){
	int k;

	if(nextfree==STsize){
		err=overst;
		PrintError(err);
	}

	for(k=0; yytext[k]!='\0';k++){
		if(nextfree==STsize){
			err=overst;
			PrintError(err);
		}
		ST[nextfree++]=yytext[k];
	}

	ST[nextfree++]='\0';

	ComputeHS(nextid, nextfree);
	LookupHS(nextid, hashcode);

	if(found)
		nextfree -= yyleng;
	else
		ADDHT(nextid, hashcode);

	nextid=nextfree;

	return 1;


}