#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

void selectionSort(int *arr, int n) {
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
}

int binarySearch(int *arr, int n, int target, double *searchTime) {
    struct timeval start, end;
    gettimeofday(&start, NULL);

    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            gettimeofday(&end, NULL);
            *searchTime = (end.tv_sec - start.tv_sec) +
                          (end.tv_usec - start.tv_usec) / 1000000.0;
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    gettimeofday(&end, NULL);
    *searchTime = (end.tv_sec - start.tv_sec) +
                  (end.tv_usec - start.tv_usec) / 1000000.0;
    return -1;
}

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <size1> <size2> ... <target>\n", argv[0]);
        return 1;
    }

    int target = atoi(argv[argc - 1]);
    srand(time(NULL));

    FILE *csvFile = fopen("binary_search_results.csv", "w");
    if (csvFile == NULL) {
        printf("Failed to create CSV file.\n");
        return 1;
    }

    fprintf(csvFile, "Input Size,Search Target,Execution Time (seconds),Search Time (seconds),Found At Index\n");

    for (int i = 1; i < argc - 1; i++) {
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

        for (int j = 0; j < n; j++) {
            arr[j] = rand() % 1000;
        }

        printf("Original array (size %d):\n", n);
        printArray(arr, n);

        struct timeval start, end;
        gettimeofday(&start, NULL);
        selectionSort(arr, n);
        gettimeofday(&end, NULL);

        double executionTime = (end.tv_sec - start.tv_sec) +
                               (end.tv_usec - start.tv_usec) / 1000000.0;

        printf("Sorted array (size %d):\n", n);
        printArray(arr, n);

        double searchTime = 0.0;
        int foundIndex = binarySearch(arr, n, target, &searchTime);

        if (foundIndex != -1) {
            printf("Target %d found at index %d.\n", target, foundIndex);
        } else {
            printf("Target %d not found in the array.\n", target);
        }

        printf("Execution time: %.6f seconds\n", executionTime);
        printf("Search time: %.6f seconds\n\n", searchTime);

        fprintf(csvFile, "%d,%d,%.6f,%.6f,%d\n", n, target, executionTime, searchTime, foundIndex);

        free(arr);
    }

    fclose(csvFile);
    printf("Results have been saved to 'binary_search_results.csv'.\n");

    return 0;
}

