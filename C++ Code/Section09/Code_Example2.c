#include <cstdio>
#include <cstdlib>
#include <mpi.h>
#include <cstddef>

struct car {
       int shifts;
       int topSpeed;
};

int main(int argc, char **argv) {
         const int tag = 13;
         int size, rank;
         MPI_Init(&argc, &argv);

         MPI_Comm_size(MPI_COMM_WORLD, &size);

         if (size < 2) {
               fprintf(stderr,"Requires at least two processes.\n");
               MPI_Abort(MPI_COMM_WORLD, 1);
 }

         const int nitems = 2;
         int blocklengths[2] = {1,1};
   MPI_Datatype types[2] = {MPI_INT, MPI_INT};
         MPI_Datatype mpi_car_type;
         MPI_Aint offsets[2];

         offsets[0] = offsetof(car, shifts);
         offsets[1] = offsetof(car, topSpeed);

         MPI_Type_create_struct(nitems, blocklengths, offsets, types,
&mpi_car_type);
         MPI_Type_commit(&mpi_car_type);

         MPI_Comm_rank(MPI_COMM_WORLD, &rank);
         if (rank == 0) {
               car send;
               send.shifts = 4;
               send.topSpeed = 100;

               const int dest = 1;
         MPI_Send(&send, 1, mpi_car_type, dest, tag, MPI_COMM_WORLD);

               printf("Rank %d: sent structure car\n", rank);
 }
 if (rank == 1) {
             MPI_Status status;
             const int src = 0;

       car recv;

       MPI_Recv(&recv, 1, mpi_car_type, src, tag, MPI_COMM_WORLD,
&status);
       printf("Rank %d: Received: shifts = %d topSpeed = %d\n", rank,
recv.shifts, recv.topSpeed);
 }

 MPI_Type_free(&mpi_car_type);
 MPI_Finalize();
 return 0;
}
