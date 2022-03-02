#include "lab_2.h"

double* itreator(double** matrix, double* free_members_array, int matrix_length) {
	double* res = new double[matrix_length]; // по началу хранит начальное приближение: элементы вектора свободных челнов/ на диоганальный элемент.
                                             // затем просто хранит результат
	for (int i = 0; i < matrix_length; i++) {
		res[i] = free_members_array[i] / matrix[i][i]; // делаем начальное приближение
	}

	double eps = 0.0001;
	double* Xn = new double[matrix_length]; // хранит последнее приблежение на итерации

	do {
		for (int i = 0; i < matrix_length; i++) {
			Xn[i] = free_members_array[i] / matrix[i][i]; // задаем начаольное приблежение для дальнейших вычислений
			for (int j = 0; j < matrix_length; j++) {
				if (i == j) { // пропускаем диагональные элементы общей матрицы
                    continue;
                } else {
					Xn[i] -= matrix[i][j] / matrix[i][i] * res[j]; // формула простых итераций 
				}
			}
		}

		bool flag = true;
		for (int i = 0; i < matrix_length - 1; i++) { // проверяем, явялется ли текущее приближение необходимой точности
			if (abs(Xn[i] - res[i]) > eps) {
				flag = false;
				break;
			}
		}

		for (int i = 0; i < matrix_length; i++) {
			res[i] = Xn[i];
		}

		if (flag) {
			break;
        }
	} while (1);

	return res;
}

/* int main() {
    int matrix_length, alloc_err;
	double** matrix;
	double *resualt_array, *free_members_array;
	std::ifstream file("src/CM/conf_file_2.txt");
    
    std::cout << "Please enter the matrix_length" << std::endl;
    std::cin >> matrix_length;

	free_members_array = new double[matrix_length];

    if ((matrix = (double**)malloc(matrix_length * sizeof(double*))) != NULL) {
        for (int i = 0; i < matrix_length; i++) {
		    if ((matrix[i] = (double*)malloc((matrix_length) * sizeof(double))) != NULL) {

            } else {
                std::cout << "Memory allocation error!" << std::endl;
                alloc_err = 1;
                break;  
            }
	    }
    } else {
        std::cout << "Memory allocation error!" << std::endl;
        alloc_err = 1;      
    }

    if (alloc_err != 1) {
        for (int i = 0; i < matrix_length; i++) {
            for (int j = 0; j <= matrix_length; j++) {
                if (j != matrix_length) {
                    file >> matrix[i][j];
                }
                else {
                    file >> free_members_array[i];
                }
            }
        }
        file.close();

        for (int i = 0; i < matrix_length; i++) {
            for (int j = 0; j <= matrix_length; j++) {
                if (j != matrix_length) {
                    std::cout << matrix[i][j] << "\t";
                }
                else {
                    std::cout << "| " << free_members_array[i] << "\t";
                }
            }
            std::cout << std::endl;
        }

        resualt_array = itreator(matrix, free_members_array, matrix_length);

        for (int i = 0; i < matrix_length; i++) {
            std::cout << "x" << i+1 << ": " <<resualt_array[i] << std::endl;
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < matrix_length; i++) {
        free(matrix[i]);
    }

    free(matrix);

	return 0;
} */