#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE *file;
	
	file = fopen("items.csv", "w");
	
	fprintf(file, "Fruits, Quantity, Price\n");
	
	fprintf(file, "apple, 5, 10$\n");
	fprintf(file, "banana, 15, 2$\n");
	fprintf(file, "Papaya, 1, 50$\n");
	
	fclose(file);
	
	printf("Items have been saved.");
	
	return 0;
	
}
