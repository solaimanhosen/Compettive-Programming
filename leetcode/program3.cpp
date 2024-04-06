#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define N 35
#define CHUNKSIZE 5

int main(int argc, char *argv[]) {
    int i, chunk;
    float a[N], b[N], c[N];  // Arrays a, b, and c should be shared among the threads since they are being accessed and modified by all threads.

    /* Some initializations */
    for (i=0; i < N; i++) {
        a[i] = b[i] = i * 1.0;
    }
    chunk = CHUNKSIZE;  // The variable chunk should be defined outside the parallel region

    #pragma omp parallel for \
        shared(a,b,c) \ 
        private(i) \
        schedule(static,chunk)
    for (i=0; i < N; i++) {
        int tid = omp_get_thread_num();  // The tid variable should be private as each thread will have its own thread id
        c[i] = a[i] + b[i];
        printf("tid=%d i=%d c[i]=%f\n", tid, i, c[i]);
    }
    return 0;
}

