#include <stdio.h>
#include <stdlib.h>
#include <omp.h> // Include OpenMP header

/* Define length of dot product vectors */
#define VECLEN 100

int main (int argc, char* argv[])
{
    int i, len=VECLEN;
    double *a, *b;
    double sum;

    printf("Starting omp_dotprod_parallel\n");

    /* Assign storage for dot product vectors */
    a = (double*) malloc(len*sizeof(double));
    b = (double*) malloc(len*sizeof(double));

    /* Initialize dot product vectors */
    for (i=0; i<len; i++)
    {
        a[i]=1.0;
        b[i]=a[i];
    }

    /* Perform the dot product */
    sum = 0.0;

    omp_set_num_threads(16); // Set the number of threads to 16
    
    double  starttime = omp_get_wtime();
    #pragma omp parallel for reduction(+:sum) // Parallelize the loop with a reduction clause for sum
    for (i=0; i<len; i++)
    {
        sum += (a[i] * b[i]);
    }

    printf("Done. Parallel version: sum = %f\n", sum);
    printf("calculation took %lf sec\n",omp_get_wtime()-starttime);

    free(a); free(b);

    return 0;
}
