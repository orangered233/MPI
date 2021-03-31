//
// Created by Orange on 3/31/21.
//

#include "helper.h"

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: avg num_elements_per_proc\n");
        exit(1);
    }

    int num_elements_per_proc = atoi(argv[1]);

    MPI_Init(NULL, NULL);
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Create a random array of elements on all process.
    srand(time(NULL)*world_rank);
    float* rand_nums = NULL;
    rand_nums = create_rand_nums(num_elements_per_proc);

    // Sum the numbers locally
    float local_sum = 0;
    for (int i = 0; i < num_elements_per_proc; i++)
        local_sum += rand_nums[i];

    // Reduce all of the local sums into the global sum
    float global_sum;
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD);

    // Print the result
    if (world_rank == 0) {
        printf("Total sum = %f, avg = %f\n", global_sum, global_sum / (world_size * num_elements_per_proc));
    }

    // Clean up
    free(rand_nums);
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize();
}


