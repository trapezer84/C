#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mpi.h>

int main(void)
{
	int my_rank; //Rank of process //현재 프로세스를 결정 짓는 고유 번호 
	int comm_sz; //전체 프로세스 
	int A; //message , 즉 전달 할 정수
	
	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);

	if(my_rank == 0) { //프로세스0 인 경우 1로 보내주고 n-1로부터 받아와야한다. 
		A=0;
		if(comm_sz > 1) { //전체 프로세서의 수가 1일 수도 있으므로 구분해주기 위해 if문을 써준다. 
			MPI_Send(&A,1,MPI_INT,my_rank+1,0,MPI_COMM_WORLD);
			MPI_Recv(&A,1,MPI_INT,comm_sz-1,0,MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		}
		printf("%d\n", A);

	} else { //프로세스가 0이 아닌 경우 
		MPI_Recv(&A,1,MPI_INT,my_rank-1,0,MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		if( my_rank == comm_sz-1 ) {
			A+=my_rank;
			MPI_Send(&A,1,MPI_INT,0,0,MPI_COMM_WORLD);
		} else {
			A+=my_rank;		
			MPI_Send(&A,1,MPI_INT,my_rank+1,0,MPI_COMM_WORLD);
		}
	}
	MPI_Finalize();
	return 0;
}