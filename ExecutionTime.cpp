#include <stdio.h>
#include <time.h>

int main() {
    clock_t start = clock();

    // CPU-intensive task (e.g., prime number calculation)
    for (int i = 0; i < 10000000; ++i) {
        int is_prime = 1;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }
    }

    clock_t end = clock();
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Elapsed time: %f seconds\n", elapsed_time);
	
	// We need this just to keep nanos up and running.
    while(1)
	{
	}

    return 0;
}
