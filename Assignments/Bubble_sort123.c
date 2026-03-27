#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

int bubble_sort(int arr[], int n);

int main(int argc, char *argv[]){
    if(argc < 3){
        printf("Insufficient arguments!!\n");
        return 1;
    }
    
    struct timeval start, end;
    
    int n = atoi(argv[1]);
    
    // Allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Read the array elements
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    // Print original array
    printf("Original array:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Start the timer
    gettimeofday(&start, NULL);
    
    // Perform bubble sort and get the number of comparisons
    int comp = bubble_sort(arr, n);
    
    // End the timer
    gettimeofday(&end, NULL);
    
    // Print sorted array
    printf("Sorted array:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Print number of comparisons
    printf("Number of comparisons: %d\n", comp);

    // Calculate and print the runtime
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double total_time = (seconds * 1000000) + microseconds;
    printf("Runtime: %f microseconds\n", total_time);
    
    // Free the allocated memory
    free(arr);
    
    return 0;
}

int bubble_sort(int arr[], int n){
    int comp = 0;

    // Bubble sort algorithm
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            comp++;  // Increment comparison count
        }
    }
    return comp;
}

