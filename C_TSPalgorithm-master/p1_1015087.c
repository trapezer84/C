#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define INF 1000000000

void inputs ( int **d, int n )
{
    int i, j, t;
    int *x, *y;
    
    //d : 배열
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
    
	
	while( edge < n ) { //edge가 다 들어오면 끝 
	dac_cost = dac_cost + test ( d, n, num, 0 , edge); //val은 시작점, 그리고 num은 이제 들어올 val에서 가장 가까운 노드 
	
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
    //변수선언
    int egde=1;
    int i,j;
    int *degree; //차수결정
    int *root; //root결정
    int g_cost=0;
    int min=10000;
    int a=0;
    int b=0;
    int **add; //edge가 포함되면 넣는다. 넣으면:1, 안넣으면:0

    //배열 초기화
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
    while (egde<n) { //포함된 edge의 수가 전체 n의 갯수보다 작아야 cycle이 안되므로
        
        min = 10000; //매번 min값을 찾아줘야하므로 9999로 다시 갱신해준다.
        
        for (i=1; i<n; ++i) for (j=0; j<i; ++j) {
            if( d[i][j] < min && add[i][j]!=1 && degree[i]<4 && degree[j]<4 ){
                //min보다 작을 경우 갱신한다. & 안들어간경우만 갱신 & 노드가 총 4번 이하만 포함되야 갱신
                if( root[i] != root[j] ) { //그리고 이거에 충족하는게, root가 같지 않을 경우
                    //연결된 경우 root가 같으므로, cycle이 될 일이 없다. 
                    min = d[i][j]; //min 값 갱신
                    a=i; b=j; //해당 값을 저장한다
                }
            }
        }
        
        //root 설정 해주기
        if ( root[a] > root[b] ) {  //root[b]가 더 작은 경우
            if ( root[b] < 1000) {  //root[b]에 이미 다른 root가 선언되어 있을 경우
                if ( root[b] > a ) { //root[b]보다 a가 작은 경우
                    root[b] = a; root[a] = a;
                }
                else {
                    root[a] = root[b];
                }
            }
            else {  //root[b]가 1000보다 작지 않은 경우, 작은 것이 1000보다 작지 않으므로 둘다 1000보다 크다는 의미
                if ( a > b ) {
                    root[a] = b; root[b] = b;
                }
                else {
                    root[a] = a; root[b] = a;
                }
            }
        }
        else { //root[a] 가 더 작은 경우
            if ( root[a] < 1000) {  //root[a]에 이미 다른 root가 선언되어 있을 경우
                if ( root[a] > b ) { //root[a]말고 b가 더 작은 경우, root[a]와 a를 비교할 필요 없다. 이미 작은게 input
                    root[a] = b; root[b] = b;
                }
                else { //root[a]가 b보다 저 작은 경우
                    root[b] = root[a];
                }
            }
            else {  //root[a]가 1000보다 작지 않은 경우, 작은 것이 1000보다 작지 않으므로 둘다 1000보다 크다는 의미
                if ( a > b ) {
                    root[a] = b; root[b] = b;
                }
                else {
                    root[a] = a; root[b] = a;
                }
            }
        }
        
        
        add[a][b]=1; //edge가 포함되었다는 것을 표시
        ++egde; //edge numbering
        ++degree[a]; //3개이상 포함되지 않도록
        ++degree[b];
        g_cost=g_cost+d[a][b]; //cost update
        
    }
    return g_cost;
}


int dynamicProgramming ( int **d, int n )
{
    int i, j, k, s; //loop구문에 사용할 변수 선언
    int dp_cost=0; //cost 저장해줄 변수
    int **weight; //dynamicprogramming에 사용할 배열 선언, 즉 weight 저장 배열
    
    //weight 배열 초기화
    weight = (int **)malloc(n * sizeof(int *));
    for (i=0; i<n; i++) weight[i] = (int *)malloc(n * sizeof(int));
    for (i=0; i<n; i++) for(j=0; j<n; j++) {
        weight[i][j]=9999;
    }
    
    //중간에 아무것도 거치지 않을 경우 - d(num, null) set, 이 코딩은 1부터가 아닌 0부터 시작하므로
    for (i=1; i<n; i++) {
        weight[0][i]=d[i][0]; //weight[0][i] 여기엔 0이 들어가는 이유는 subset이 없기때문이다.
    }
    
    //거치는 경우
    for (s=1; s<n-1; s++) { //들어갈 subset의 개수 측정 변수 s, 즉 1이면 subset이 1개이다.
        for (i=2; i<n; i++) {
            for (j=2; j<n; j++) {
                if(i==j) continue; //변수가 같은 경우는 일어날 수 없으므로, 다시 continue해준다.
                if(weight[s][i] > (d[i][j]+weight[s-1][j]) ) { //최소값만 갱신해주기 위해 if문
                    weight[s][i]=d[i][j]+weight[s-1][j]; //작은 경우, 갱신해준다
                }
            }
        }
    }
    
    //마지막 전체 구해주기
    for (i=1; i<n; i++) {
        if( weight[n-1][0] > (d[0][i]+weight[n-2][i]) ){ //최소값을 찾아주기 위한 if문
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