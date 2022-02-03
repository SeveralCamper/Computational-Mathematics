#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <fstream>

void print_matrix(float (*matrix)[4], int equations_num, int variables_num) {
    for (int i = 0; i < equations_num; i++) {
        for (int j = 0; j < variables_num; j++) {
            if (j == variables_num - 1) {
                std::cout << "|" << std::setw(3) << matrix[i][j];
            } else {
                std::cout << std::setw(3) << matrix[i][j] << std::setw(3);
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    int equations_num = 3, variables_num = 4;
    float matrix[3][4] = {2, 1, -1, 1, -3, 1, 1, -2, 2, -3, 2, 4};
 
    std::string path = "src/CM/conf_file.txt";

    std::ifstream fin;
    fin.open(path);

    /* if (!fin.is_open()) {
        std::cout << "File open error" << std::endl;
    } else {
        std::cout << "file opened successfully" << std::endl;
        char ch;
        int i, j;
        while(fin.get(ch)) {
            matrix_dumb[i] = ch;
            i++;
        }

        for (int i = 0; i < 10; i++) {
            if (matrix_dumb[i] != '\n') {
                std::cout << matrix_dumb[i] << std::endl;
            }
        }
    }

    for (int i = 0; i < equations_num; i++) {
        for (int j = 0; j < variables_num; j++) {
            matrix[i][j] = matrix_dumb[i];
            if (matrix_dumb[i] == '-') {

            }
        }
    } */

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
  

    fin.close();

    return 0;
}
