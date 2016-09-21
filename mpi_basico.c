#include <stdio.h>
#include <mpi.h>

int main( int argc, char *argv[] )
{
  int size,myrank;
  MPI_Init(&argc, &argv);

  MPI_Status sts;

  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
  // printf( "[%d] Hello, parallel world!\n", myrank );
double a[2], b[2];
  if(myrank == 0){
    a[0] = 0.3;   a[1] = 0.5;
    MPI_Send(a,2,MPI_DOUBLE,1,17,MPI_COMM_WORLD);

  }else if(myrank == 1){

    MPI_Recv(b,2,MPI_DOUBLE,0,17,MPI_COMM_WORLD,&sts);
    printf("[%d] b=%f,%f\n",myrank,b[0],b[1]);
  }

  MPI_Finalize();
  return 0;
}