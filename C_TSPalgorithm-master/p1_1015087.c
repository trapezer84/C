#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define INF 1000000000

void inputs ( int **d, int n )
{
    int i, j, t;
    int *x, *y;
    
    //d : �迭
    //x, y : random numbering 
    x = (int *)malloc(n * sizeof(int));
    y = (int *)malloc(n * sizeof(int));
    
    
    for (i=0; i<n; i++) {    // random value : 0 ~ 999
        x[i] = rand() % 1000;
        y[i] = rand() % 1000;
        d[i][i] = 0;
    }
    for (i=n-2; i>=0; i--) {
        for (j=0; j<=i; j++) {
            if (x[j] > x[j+1]) {
                t = x[j]; x[j] = x[j+1]; x[j+1] = t;
            }
        }
    }
        
     /**** For reproducing the sample ****
     x[0] = 21; x[1] = 36; x[2] = 59; x[3] = 87; x[4] = 193; x[5] = 286;
     x[6] = 561; x[7] = 737; x[8] = 821; x[9] = 856; x[10] = 958; x[11] = 962;
     y[0] = 993; y[1] = 490; y[2] = 101; y[3] = 740; y[4] = 997; y[5] = 19;
     y[6] = 131; y[7] = 100; y[8] = 614; y[9] = 246; y[10] = 136; y[11] = 967;
     /****/
    
    
    
    for (i=1; i<n; ++i) for (j=0; j<i; ++j) {  // calculate the distance
        d[i][j] = (int)sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
        d[j][i] = d[i][j];    // symmetric and undirected graph
    }
    
    
    
    free(x);
    free(y);
}

int divideAndConquer ( int **d, int n )
{
    int dac_cost = 0;
    int i, k;
    int edge = 0;
    int *num;
    int min=9999; 

    num = (int *)malloc(n * sizeof(int));
    for (i=0; i<n; i++) {
        num[i] = 0;
    }
    
	
	while( edge < n ) { //edge�� �� ������ �� 
	dac_cost = dac_cost + test ( d, n, num, 0 , edge); //val�� ������, �׸��� num�� ���� ���� val���� ���� ����� ��� 
	
	++edge;
	}
	
	//dac_cost = test( d, n, num, 0 , edge); 

	return dac_cost;
}

int test ( int **d, int n, int *num, int val, int edge ) {
    
    int dac_cost = 0;
    int i, k;
    int min=9999;

    for (i=0; i<n; i++) {
        if ( val == i && num[i] != 0 ) continue;
        if ( min > d[val][i] ) {
            k = i; 
        }
    }
    
    num[k] = 1;
	dac_cost = d[val][k];
	val=num[k];
	++edge;

	/*
	while( edge < n ) 
	{
		dac_cost =  dac_cost + test( d, n, num, val, edge);
	}
    */

    return dac_cost; //
    
}

int greedy ( int **d, int n )
{
    //��������
    int egde=1;
    int i,j;
    int *degree; //��������
    int *root; //root����
    int g_cost=0;
    int min=10000;
    int a=0;
    int b=0;
    int **add; //edge�� ���ԵǸ� �ִ´�. ������:1, �ȳ�����:0

    //�迭 �ʱ�ȭ
    add = (int **)malloc(n * sizeof(int *));
    for (i=0; i<n; i++) add[i] = (int *)malloc(n * sizeof(int));
    for (i=0; i<n; i++) for(j=0; j<n; j++) {
        add[i][j]=0;
    }
    degree = (int *)malloc(n * sizeof(int));
    for (i=0; i<n; i++) {
        degree[i]=0;
    }
    root = (int *)malloc(n * sizeof(int));
    for (i=0; i<n; i++) {
        root[i]=i+1000;
    }
    
    //greedy approach - kuskal's algorithm
    while (egde<n) { //���Ե� edge�� ���� ��ü n�� �������� �۾ƾ� cycle�� �ȵǹǷ�
        
        min = 10000; //�Ź� min���� ã������ϹǷ� 9999�� �ٽ� �������ش�.
        
        for (i=1; i<n; ++i) for (j=0; j<i; ++j) {
            if( d[i][j] < min && add[i][j]!=1 && degree[i]<4 && degree[j]<4 ){
                //min���� ���� ��� �����Ѵ�. & �ȵ���츸 ���� & ��尡 �� 4�� ���ϸ� ���ԵǾ� ����
                if( root[i] != root[j] ) { //�׸��� �̰ſ� �����ϴ°�, root�� ���� ���� ���
                    //����� ��� root�� �����Ƿ�, cycle�� �� ���� ����. 
                    min = d[i][j]; //min �� ����
                    a=i; b=j; //�ش� ���� �����Ѵ�
                }
            }
        }
        
        //root ���� ���ֱ�
        if ( root[a] > root[b] ) {  //root[b]�� �� ���� ���
            if ( root[b] < 1000) {  //root[b]�� �̹� �ٸ� root�� ����Ǿ� ���� ���
                if ( root[b] > a ) { //root[b]���� a�� ���� ���
                    root[b] = a; root[a] = a;
                }
                else {
                    root[a] = root[b];
                }
            }
            else {  //root[b]�� 1000���� ���� ���� ���, ���� ���� 1000���� ���� �����Ƿ� �Ѵ� 1000���� ũ�ٴ� �ǹ�
                if ( a > b ) {
                    root[a] = b; root[b] = b;
                }
                else {
                    root[a] = a; root[b] = a;
                }
            }
        }
        else { //root[a] �� �� ���� ���
            if ( root[a] < 1000) {  //root[a]�� �̹� �ٸ� root�� ����Ǿ� ���� ���
                if ( root[a] > b ) { //root[a]���� b�� �� ���� ���, root[a]�� a�� ���� �ʿ� ����. �̹� ������ input
                    root[a] = b; root[b] = b;
                }
                else { //root[a]�� b���� �� ���� ���
                    root[b] = root[a];
                }
            }
            else {  //root[a]�� 1000���� ���� ���� ���, ���� ���� 1000���� ���� �����Ƿ� �Ѵ� 1000���� ũ�ٴ� �ǹ�
                if ( a > b ) {
                    root[a] = b; root[b] = b;
                }
                else {
                    root[a] = a; root[b] = a;
                }
            }
        }
        
        
        add[a][b]=1; //edge�� ���ԵǾ��ٴ� ���� ǥ��
        ++egde; //edge numbering
        ++degree[a]; //3���̻� ���Ե��� �ʵ���
        ++degree[b];
        g_cost=g_cost+d[a][b]; //cost update
        
    }
    return g_cost;
}


int dynamicProgramming ( int **d, int n )
{
    int i, j, k, s; //loop������ ����� ���� ����
    int dp_cost=0; //cost �������� ����
    int **weight; //dynamicprogramming�� ����� �迭 ����, �� weight ���� �迭
    
    //weight �迭 �ʱ�ȭ
    weight = (int **)malloc(n * sizeof(int *));
    for (i=0; i<n; i++) weight[i] = (int *)malloc(n * sizeof(int));
    for (i=0; i<n; i++) for(j=0; j<n; j++) {
        weight[i][j]=9999;
    }
    
    //�߰��� �ƹ��͵� ��ġ�� ���� ��� - d(num, null) set, �� �ڵ��� 1���Ͱ� �ƴ� 0���� �����ϹǷ�
    for (i=1; i<n; i++) {
        weight[0][i]=d[i][0]; //weight[0][i] ���⿣ 0�� ���� ������ subset�� ���⶧���̴�.
    }
    
    //��ġ�� ���
    for (s=1; s<n-1; s++) { //�� subset�� ���� ���� ���� s, �� 1�̸� subset�� 1���̴�.
        for (i=2; i<n; i++) {
            for (j=2; j<n; j++) {
                if(i==j) continue; //������ ���� ���� �Ͼ �� �����Ƿ�, �ٽ� continue���ش�.
                if(weight[s][i] > (d[i][j]+weight[s-1][j]) ) { //�ּҰ��� �������ֱ� ���� if��
                    weight[s][i]=d[i][j]+weight[s-1][j]; //���� ���, �������ش�
                }
            }
        }
    }
    
    //������ ��ü �����ֱ�
    for (i=1; i<n; i++) {
        if( weight[n-1][0] > (d[0][i]+weight[n-2][i]) ){ //�ּҰ��� ã���ֱ� ���� if��
            weight[n-1][0] = d[0][i]+weight[n-2][i];
        }
    }
    
    dp_cost = weight[n-1][0];
    return dp_cost;
}


void main ( )
{
    int n, i;
    int **d;
    int cost;
    
    printf("Number of cities = ");
    scanf("%d", &n);
    
    d = (int **)malloc(n * sizeof(int *));
    for (i=0; i<n; i++) d[i] = (int *)malloc(n * sizeof(int));
    
    inputs(d,n);  // gernerate inputs
    
    printf("Divide-and-Conquer TSP : "); cost = divideAndConquer(d,n);    printf(" cost = %d\n", cost);
    printf("Dynamic programming TSP : "); cost = dynamicProgramming(d,n);     printf(" cost = %d\n", cost);
    printf("Greedy TSP : "); cost = greedy(d,n); printf(" cost = %d\n", cost);
    
    for (i=0; i<n; ++i) free(d[i]);
    free(d);
}