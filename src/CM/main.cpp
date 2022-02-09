#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <fstream>

void print_matrix(float **matrix, int equations_num, int variables_num) {
    for (int i = 0; i < equations_num; i++) {
        for (int j = 0; j < variables_num; j++) {
            if (j == variables_num - 1) {
                std::cout << "|" << std::setw(4) << matrix[i][j];
            } else {
                std::cout << std::setw(4) << matrix[i][j] << std::setw(3);
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    int equations_num, variables_num, alloc_err = 0;
    float **matrix;

    std::cout << "Please enter the number of lines" << std::endl;
    std::cin >> equations_num;
    std::cout << "Please enter the number of cloumns" << std::endl;
    std::cin >> variables_num;

    if ((matrix = (float**)malloc(equations_num * sizeof(float*))) != NULL) {
        for (int i = 0; i < equations_num; i++) {
            if ((matrix[i] = (float*)malloc(variables_num * sizeof(float))) != NULL) {

            } else {
                std::cout << "Memory allocation error!" << std::endl;
                alloc_err = 1;
                break;
            }
        }
    } else {
        std::cout << "Memory allocation error!" << std::endl;
    }

    for (int i = 0; i < equations_num; i++) {
        for (int j = 0; j < variables_num; j++) {
            matrix[i][j] = 0;
        }
    }

    print_matrix(matrix, equations_num, variables_num);

    if (alloc_err != 1) {
        std::cout << "The memory has been allocated successfully!" << std::endl;

        std::ifstream file("src/CM/conf_file.txt");

        for (int i = 0; i < equations_num; i++){
            for (int j = 0; j< variables_num; j++) {
                file >> matrix[i][j];
            }
        }

        print_matrix(matrix, equations_num, variables_num);

        for (int i = 0; i < equations_num; i++) {
                float divide = matrix[i][i];
                for (int j = i; j < variables_num; j++)
                {
                matrix[i][j] = matrix[i][j]/divide;
                }

                for (int l = 0; l < equations_num; l++)
                {
                if (l != i){
                    float subtract = matrix[l][i];
                    matrix[l][i] = 0;
                    for (int m = i+1; m < variables_num; m++)
                    {
                    matrix[l][m] =  matrix[l][m] - subtract*matrix[i][m];
                    }
                }
            }
        }

        print_matrix(matrix, equations_num, variables_num);
    }
    return 0;
}
