#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mpi.h>

int main(void)
{
	int my_rank; //Rank of process //���� ���μ����� ���� ���� ���� ��ȣ 
	int comm_sz; //��ü ���μ��� 
	int A; //message , �� ���� �� ����
	
	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);

	if(my_rank == 0) { //���μ���0 �� ��� 1�� �����ְ� n-1�κ��� �޾ƿ;��Ѵ�. 
		A=0;
		if(comm_sz > 1) { //��ü ���μ����� ���� 1�� ���� �����Ƿ� �������ֱ� ���� if���� ���ش�. 
			MPI_Send(&A,1,MPI_INT,my_rank+1,0,MPI_COMM_WORLD);
			MPI_Recv(&A,1,MPI_INT,comm_sz-1,0,MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		}
		printf("%d\n", A);

	} else { //���μ����� 0�� �ƴ� ��� 
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