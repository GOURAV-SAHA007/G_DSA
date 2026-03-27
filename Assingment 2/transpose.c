#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 20
#define NON_ZERO 20

void generate_sparse_matrix(int matrix[SIZE][SIZE]){
	int count = 0;
	srand(time(0));
	
	while(count < NON_ZERO){
		int row = rand() % SIZE;
		int col = rand() % SIZE;
		int value = (rand() % 90) + 10;
		if(matrix[row][col] == 0){
			matrix[row][col] = value;
			count++;
		}
	}
}

void print_sparse_matrix(int matrix[SIZE][SIZE]){
	for(int i=0; i<SIZE; i++){
		for(int j=0; j<SIZE; j++){
			printf("%2d ", matrix[i][j]);
		}
		printf("\n");
	}
}

void transpose_sparse_matrix(int matrix[SIZE][SIZE], int transpose[SIZE][SIZE]){
	for(int i=0; i<SIZE; i++){
		for(int j=0; j<SIZE; j++){
		transpose[j][i] = matrix[i][j];
			printf("%2d ", matrix[i][j]);
		}
		printf("\n");
	}
}

void convert_csr(int transpose[SIZE][SIZE], int value[], int col_index[], int row_ptr[]){
	int k = 0;
	row_ptr[0] = 0;
	
	for(int i=0; i<SIZE; i++){
		for(int j=0; j<SIZE; j++){
			if(transpose[i][j] != 0){
				value[k] = transpose[i][j];
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
	int matrix[SIZE][SIZE] = {0};
	int transpose[SIZE][SIZE] = {0};
	int value[NON_ZERO], column[SIZE], row[SIZE];
	
	generate_sparse_matrix(matrix);
	
	printf("Generated Sparse Matrix : \n");
	print_sparse_matrix(matrix);
	
	printf("Generated Transpose matrix : \n");
	transpose_sparse_matrix(matrix, transpose);
	
	convert_csr(transpose, value, column, row);
	
	printf("Transpose Sparse matrix in CSR format : \n");
	print_csr(value, column, row);
	
 return 0;
} 
