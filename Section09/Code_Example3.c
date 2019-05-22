int MPI_Bcast(
   void *buffer,
   int count,
   MPI_Datatype datatype,
   int root,
   MPI_Comm comm)

int MPI_Scatter(
        void* send_data,
        int send_count,
        MPI_Datatype send_datatype,
        void* recv_data,
        int recv_count,
        MPI_Datatype recv_datatype,
        int root,
        MPI_Comm communicator)

int MPI_Gather(
         void* send_data,
         int send_count,
         MPI_Datatype send_datatype,
         void* recv_data,
         int recv_count,
         MPI_Datatype recv_datatype,
         int root,
         MPI_Comm communicator)

         
