File Edit Options Buffers Tools C Help                                               
#include "stdlib.h"
#include "stdio.h"
#include "omp.h"
#define SIZE 100000000
double input[SIZE];

void generate_random(double *input, size_t size)
{
  for (size_t i = 0; i < size; i++) {
    input[i] = rand() / (double)(RAND_MAX);
  }
}


double serial_sum(double *x, size_t size)
{
  double sum_val = 0.0;

  for (size_t i = 0; i < size; i++) {
    sum_val += x[i];
  }

  return sum_val;
}

int main(int argc, char *argv[])
{
  double sum;

  double start_time = omp_get_wtime();

  generate_random(input, SIZE);
  sum = serial_sum(input, SIZE);

  double run_time = omp_get_wtime() - start_time;
  printf(" %f \n", run_time);
  return 0;
}
