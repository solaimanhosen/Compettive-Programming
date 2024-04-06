#include <stdio.h>
#include <omp.h>

// Recursive function to calculate Fibonacci numbers
int fib(int n)
{
  int x, y;
  if (n < 2)
    return n;

  #pragma omp task shared(x) // Create a new task for the first recursive call
  x = fib(n - 1);

  #pragma omp task shared(y) // Create a new task for the second recursive call
  y = fib(n - 2);

  #pragma omp taskwait // Wait for all tasks created within this function to complete
  return x + y;
}

int main()
{
  int n, fibonacci;
  double starttime;

  printf("Please insert n, to calculate fib(n): \n");
  scanf("%d", &n);

  starttime = omp_get_wtime();

  // Set the number of threads to 16 using OpenMP
  omp_set_num_threads(16);

  #pragma omp parallel // Start the parallel region
  {
    #pragma omp single // Ensure the fib function is called only once
    fibonacci = fib(n);
  }

  printf("fib(%d)=%d \n", n, fibonacci);
  printf("calculation took %lf sec\n", omp_get_wtime() - starttime);
  return 0;
}
