#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NON_ZEROS 20
#define SIZE 20

void generate_sparse_matrix(int matrix[SIZE][SIZE]){
    int count = 0;
    srand(time(0));

    while(count < NON_ZEROS){
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
            printf("%3d", matrix[i][j]);
        }
        printf("\n");
    }
}

void convert_csr(int matrix[SIZE][SIZE],int value[], int row_ptr[], int col_index[]){
    int k = 0;
    row_ptr[0] = 0;

   for(int i=0; i<SIZE; i++){
      for(int j=0; j<SIZE; j++){
        if(matrix[i][j] != 0){
            value[k] = matrix[i][j];
            col_index[k] = j;
            k++;
        }
      }
      row_ptr[i+1] = k;
   }
}

void print_csr(int value[], int row_ptr[], int col_index[]){
    
    printf("\nNon-Zero values are :");
    for(int i=0; i<NON_ZEROS; i++){
        printf("%d ", value[i]);
    }

    printf("\nColumn index are :");
    for(int i=0; i<NON_ZEROS; i++){
        printf("%d ", col_index[i]);
    }

    printf("\nRow index are :");
    for(int i=0; i<SIZE; i++){
        printf("%d ", row_ptr[i]);
    }

    printf("\n");
}

int main(){
    int matrix[SIZE][SIZE] = {0};
    int value[NON_ZEROS], column[NON_ZEROS], row[SIZE];

    generate_sparse_matrix(matrix);

    printf("Generated sparse matrix is :\n");
    print_sparse_matrix(matrix);

    convert_csr(matrix, value, row, column);

    printf("Sparse matrix in CSR form is :\n");
    print_csr(value, row, column);

    return 0;
}