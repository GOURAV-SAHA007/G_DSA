#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char *argv[]){
	if(argc < 2){
		printf("Many Arguments : %s\n", argv[0]);
		exit(0);
	}
	
	int n = atoi(argv[1]);
	if(n <= 0){
		printf("Enter a valid size of the array");
		exit(0);
	}
	
	int *arr = (int *)malloc(n * sizeof(int));
	//if(arr == NULL){
	//	printf("Memory Allocation Failed");
	//	exit(0);
	//}
	
	srand(time(NULL));
	
	
	for(int i=0; i<n; i++){
		arr[i]=rand();
		printf("%d\n", arr[i]);
	}
	
	free(arr);
	
	return 0;
}
