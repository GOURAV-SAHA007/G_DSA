#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

int main(int argc, char *argv[]){
	if(argc < 3){
		printf("Enter required arguments : %s\n", argv[0]);
		return 1;
	}
	
	struct timeval start, end;
	
	gettimeofday(&start, NULL);
	
	int num1 = atoi(argv[1]);
	int num2 = atoi(argv[2]);
	int sum = num1 + num2;
	printf("Sum of the number is : %d\n", sum);

	gettimeofday(&end, NULL);
	
	long seconds = end.tv_sec - start.tv_sec;
	long microseconds = end.tv_usec - start.tv_usec;
	long total_time = (seconds * 1000000) + microseconds;
	
	printf("Total time taken is %ld\n microseconds", total_time);
	return 0;
}
