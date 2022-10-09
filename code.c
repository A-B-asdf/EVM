#include <stdio.h>
#include <stdint.h>  // for uint64_t
#include <time.h>

uint64_t getCycles() {
    unsigned int lo, hi;
    __asm__ __volatile__ ("rdtscp" : "=a" (lo), "=d" (hi));
    return ((uint64_t) hi << 32) | lo;
}

double CountPi(long long N) {
    double pi = 0;
    double sign = 1;
    for (long long n = 1; n <= N; n += 2) {
        pi += sign * 4 / n;
        sign = -sign;
    }
    return pi;
}

int main()
{
    long long N = 8000000000;

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    double pi = CountPi(N);

    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("%f\n", cpu_time_used);

    return 0;
}
