//
// Created by Orange on 3/31/21.
//

#ifndef C_TEST_HELPER_H
#define C_TEST_HELPER_H

#endif //C_TEST_HELPER_H

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <assert.h>
#include <time.h>
#include <math.h>

// Creates an array of random numbers. Each number has a value from 0-1
float* create_rand_nums(int num_elements) {
    float* rand_nums = (float*)malloc(sizeof(float) * num_elements);
    assert(rand_nums != NULL);
    for (int i = 0; i < num_elements; i++) {
        rand_nums[i] = (rand() / (float)RAND_MAX);
    }
    return rand_nums;
}