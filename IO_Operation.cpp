#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define FILE_SIZE (1024 * 1024 * 2) // 2 MB
#define ITERATIONS 100

int main() {
    char *testfile = "file_test.dat";
    FILE *fp;
    char *buffer = (char *)malloc(FILE_SIZE);
    srand(time(NULL));

    // Populate the buffer with random data
    for (int i = 0; i < FILE_SIZE; ++i) {
        buffer[i] = rand() % 256;
    }

    double total_time = 0.0;

    for (int i = 0; i < ITERATIONS; ++i) {
        // Write the buffer to the file
        clock_t start = clock();
        fp = fopen(testfile, "wb");
        if (fp == NULL) {
            perror("fopen");
            exit(1);
        }
        fwrite(buffer, 1, FILE_SIZE, fp);
        fclose(fp);
        clock_t end = clock();

        double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
        total_time += elapsed_time;

        // Read the file back into the buffer
        start = clock();
        fp = fopen(testfile, "rb");
        if (fp == NULL) {
            perror("fopen");
            exit(1);
        }
        fread(buffer, 1, FILE_SIZE, fp);
        fclose(fp);
        end = clock();

        elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
        total_time += elapsed_time;
    }

    printf("Average I/O time per iteration: %.3f seconds\n", total_time / (ITERATIONS * 2));

    free(buffer);
    remove(testfile);
	
	// We need this to keep nanos up and running.
    while(1){}

    return 0;
}
