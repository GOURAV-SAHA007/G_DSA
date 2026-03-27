#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// Function to fill the array with random numbers
void populate_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;
    }
}

// Bubble Sort implementation with comparison counting
void bubble_sort(int *arr, int size, long *comp_count) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            (*comp_count)++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to measure sorting time and comparisons
void measure_time(int *arr, int size, long *comp_count, long *exec_time) {
    struct timeval start, end;
    gettimeofday(&start, NULL);
    bubble_sort(arr, size, comp_count);
    gettimeofday(&end, NULL);
    *exec_time = (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);
}

// Function to write results to a CSV file
void write_to_csv(const char *filename, int *sizes, long *exec_times, long *comp_counts, int num_sizes) {
    FILE *file = fopen(filename, "w");
    fprintf(file, "Input Size,Execution Time (us),Comparison Time\n");
    for (int i = 0; i < num_sizes; i++) {
        fprintf(file, "%d,%ld,%ld\n", sizes[i], exec_times[i], comp_counts[i]);
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    int num_sizes = atoi(argv[1]);
    int sizes[num_sizes];
    long exec_times[num_sizes], comp_counts[num_sizes];

    // Parse input sizes from command line arguments
    for (int i = 0; i < num_sizes; i++) {
        sizes[i] = atoi(argv[i + 2]);
    }

    for (int i = 0; i < num_sizes; i++) {
        int *arr = (int *)malloc(sizes[i] * sizeof(int));
        populate_array(arr, sizes[i]);

        long comp_count = 0, exec_time = 0;
        measure_time(arr, sizes[i], &comp_count, &exec_time);

        exec_times[i] = exec_time;
        comp_counts[i] = comp_count;

        free(arr);
    }

    write_to_csv("bubble_sort_results.csv", sizes, exec_times, comp_counts, num_sizes);
    return 0;
}