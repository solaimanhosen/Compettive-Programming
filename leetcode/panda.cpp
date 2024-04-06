/*=======================================================================*/
/* Approximates pi with the n-point quadrature rule 4 / (1+x**2)         */
/* applied to the integral of x from 0 to 1, using OpenMP for parallelism*/
/*=======================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h> // Include the OpenMP header

const double M_pi = 3.14159265358979323846; /* reference value */

double calc_pi (unsigned n) {
  double h   = 1.0 / n;
  double sum = 0.0;
  double x;
  int i;

  // Parallelize this loop with OpenMP. Each thread has its own private x variable,
  // and the sum variable is reduced across all threads.
  #pragma omp parallel for private(x) reduction(+:sum)
  for (i = 0; i < n; i++) {
    x = (i + 0.5) * h;
    sum += 4.0 / (1.0 + x * x);
  }

  return h * sum;
}

int main(int argc, char* argv[]) {
  int n;

  if (argc != 2) {
    fprintf(stderr, "usage: pi <num_iterations>\n");
    return 1;
  }

  n = atoi(argv[1]);

  // Set the number of threads to 2
    double  starttime = omp_get_wtime();
  omp_set_num_threads(2);

  if (n > 0) {
    double pi = calc_pi(n);
    double err = pi - M_pi;
    printf("Calculated pi is %19.15f\n", pi);
    printf("Referenced pi is %19.15f\n", M_pi);
    printf("  Error in pi is %19.15f (%.15f%%)\n", err, err * 100 / M_pi);
    printf("calculation took %lf sec\n",omp_get_wtime()-starttime);
  }

  return 0;
}
