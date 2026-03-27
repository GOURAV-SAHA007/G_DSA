#include<stdio.h>

int main(int argc, char *argv[]){
	printf("\nPrograme name is %s", argv[0]);
	
	printf("\nNumber of argument is : %d", argc);
	for(int i=0; i<argc; i++){
		printf("\nArguments %d : %s", i, argv[i]);
		}
	if(argc == 2){
		printf("\nThe argument passed is %s", argv[1]);
		}
	if(argc < 2){
		printf("\nToo many arguments");
		}
		
return 0;
}


