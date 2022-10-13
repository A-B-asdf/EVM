#include <stdio.h>
#include <time.h>

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
    long long N = 10000000000;
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    double pi = CountPi(N);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    printf("Time taken: %lf sec.\n",
           end.tv_sec-start.tv_sec
           + 0.000000001*(end.tv_nsec-start.tv_nsec));
    printf("%lf\n", pi);
    return 0;
}
