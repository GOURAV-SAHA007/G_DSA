#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	if(argc < 2){
	printf("Insufficient argumrnts : %s", argv[0]);
	return 1;
	}
	float num1 = atof(argv[1]);
	printf("Using atof : %.2f\n", num1);

	char *endptr;
	float num2 = strtof(argv[1], &endptr);
	
	if(*endptr != '\0'){
		printf("Number is Invalid!! %s is not a float value\n ", endptr);	
	} else {
	  	printf("Using strtof : %.2f\n", num2);
	  }
}
	

	
