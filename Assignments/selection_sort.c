#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

void selectionSort(int *arr, int n, double *comparisonTime) {
    struct timeval compStart, compEnd;
    gettimeofday(&compStart, NULL);

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    gettimeofday(&compEnd, NULL);

    *comparisonTime = (compEnd.tv_sec - compStart.tv_sec) +
                      (compEnd.tv_usec - compStart.tv_usec) / 1000000.0;
}

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <size1> <size2> ... <sizeN>\n", argv[0]);
        return 1;
    }

    srand(time(NULL));

    FILE *csvFile = fopen("selection_sort_results.csv", "w");
    if (csvFile == NULL) {
        printf("Failed to create CSV file.\n");
        return 1;
    }

    fprintf(csvFile, "Input Size,Execution Time (seconds),Comparison Time (seconds)\n");

    for (int i = 1; i < argc; i++) {
        int n = atoi(argv[i]);
        if (n <= 0) {
            printf("Invalid input size: %s\n", argv[i]);
            continue;
        }

        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed for size %d\n", n);
            continue;
        }

        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 1000;
        }

        printf("Original array (size %d):\n", n);
        printArray(arr, n);

        double comparisonTime = 0.0;

        struct timeval start, end;
        gettimeofday(&start, NULL);
        selectionSort(arr, n, &comparisonTime);
        gettimeofday(&end, NULL);

        double executionTime = (end.tv_sec - start.tv_sec) +
                               (end.tv_usec - start.tv_usec) / 1000000.0;

        printf("Sorted array (size %d):\n", n);
        printArray(arr, n);

        printf("Execution time: %.6f seconds\n", executionTime);
        printf("Comparison time: %.6f seconds\n\n", comparisonTime);

        fprintf(csvFile, "%d,%.6f,%.6f\n", n, executionTime, comparisonTime);

        free(arr);
    }

    fclose(csvFile);
    printf("Results have been saved to 'selection_sort_results.csv'.\n");

    return 0;
}

