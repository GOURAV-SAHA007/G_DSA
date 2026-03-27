#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 5
#define NON_ZERO 5

void generate_sparse_matrix_1(int matrix_1[SIZE][SIZE]){
	int count = 0;
	srand(time(0));
	
	while(count < NON_ZERO){
		int row = rand() % SIZE;
		int col = rand() % SIZE;
		int value = (rand() % 90) + 10;
		if(matrix_1[row][col] == 0){
			matrix_1[row][col] = value;
			count++;
		}
	}
}

void print_sparse_matrix_1(int matrix_1[SIZE][SIZE]){
	for(int i=0; i<SIZE; i++){
		for(int j=0; j<SIZE; j++){
			printf("%2d ", matrix_1[i][j]);
		}
		printf("\n");
	}
}


void generate_sparse_matrix_2(int matrix_2[SIZE][SIZE]){
	int count = 0;
	srand(time(0));
	
	while(count < NON_ZERO){
		int row = rand() % SIZE;
		int col = rand() % SIZE;
		int value = (rand() % 90) + 10;
		if(matrix_2[row][col] == 0){
			matrix_2[row][col] = value;
			count++;
		}
	}
}

void print_sparse_matrix_2(int matrix_2[SIZE][SIZE]){
	for(int i=0; i<SIZE; i++){
		for(int j=0; j<SIZE; j++){
			printf("%2d ", matrix_2[i][j]);
		}
		printf("\n");
	}
}



void multiply_sparse_matrix(int matrix_1[SIZE][SIZE], int matrix_2[SIZE][SIZE], int result[SIZE][SIZE]){ 
	for(int i=0; i<SIZE; i++){
		for(int j=0; j<SIZE; j++){
			result[i][j] = 0;
		}
	}
	
	for(int i=0; i<SIZE; i++){
		for(int j=0; j<SIZE; j++){
			for(int k=0; k<SIZE; k++){
				result[i][j] += matrix_1[i][k]*matrix_2[k][j];
			}
		}
	}
	
}

void print_result(int result[SIZE][SIZE]){
	for(int i=0; i<SIZE; i++){
		for(int j=0; j<SIZE; j++){
			printf("%2d ", result[i][j]);
		}
		printf("\n");
	}
}



void convert_csr(int result[SIZE][SIZE], int value[], int col_index[], int row_ptr[]){
	int k = 0;
	row_ptr[0] = 0;
	
	for(int i=0; i<SIZE; i++){
		for(int j=0; j<SIZE; j++){
			if(result[i][j] != 0){
				value[k] = result[i][j];
				col_index[k] = j;
				k++;
			}
		}
		row_ptr[i+1] = k;
	}
}

void print_csr(int value[], int col_index[], int row_ptr[]){
	
	printf("\nNon-Zero values are : ");
	for(int i=0; i<NON_ZERO; i++){
		printf("%2d ", value[i]);
	}
	
	printf("\nRow Value : ");
	for(int i=0; i<SIZE; i++){
		printf("%2d ", row_ptr[i]);
	}
	
	printf("\nColumn value : ");
	for(int i=0; i<NON_ZERO; i++){
		printf("%2d ", col_index[i]);
	}
	
	printf("\n");
}

int main(){
	int matrix_1[SIZE][SIZE] = {0};
	int matrix_2[SIZE][SIZE] = {0};
	int result[SIZE][SIZE] = {0};
	int value[NON_ZERO], column[SIZE], row[SIZE];
	
	generate_sparse_matrix_1(matrix_1);
	generate_sparse_matrix_2(matrix_2);
	
	printf("Generated Sparse Matrix 1 : \n");
	print_sparse_matrix_1(matrix_1);
	
	printf("Generated Sparse Matrix 2 : \n");
	print_sparse_matrix_2(matrix_2);
	
	multiply_sparse_matrix(matrix_1, matrix_2, result);
	
	printf("Multiplication Result: \n");
	print_result(result);
	
	convert_csr(result, value, column, row);
	print_csr(value, column, row);
	
	
	
 return 0;
} 
