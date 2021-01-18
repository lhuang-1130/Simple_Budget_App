#include <stdio.h>
#include <stdlib.h>

int multiply(int** matrix, int m, int n, int* array)
{   
    int a = sizeof(array) / sizeof(int);
    if(m != a){
        return 1;
    }

    for(int j = 0; j<m; j++){
        for(int i = 0; i<n; i++){
            matrix[i][j]  *= array[j];
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            matrix[i][0] += matrix[i][j];
        }
    }
    return 0;
}

int main (int argc, char *argv[])
{
    int** matrix;
    int* array;
    int m = 2, n = 3;
    int a = 2;

    matrix = (int**)malloc(sizeof(int*) * n);
    for(int i = 0; i<n; i++){
        matrix[i] = (int*) malloc (sizeof(int) * m);
    }

    int counter = 1;
    array = (int*)malloc(sizeof(int) * a);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            matrix[i][j] = 13 * counter;
            array[j] = 7 * counter;
            counter++;
        }
        
    }

    int error = multiply(matrix, m, n, array);
    if(error){
        printf("No size");
        return 0;
    }

    for(size_t i = 0; i<n; i++){
        for(size_t j = 0; j<m; j++){
            printf("%d", matrix[i][j]);
        }
        printf("/n");
    }
    return 0;
}

 