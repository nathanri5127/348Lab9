// 388Lab8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

template <typename T>
void print_matrix(std::vector<std::vector<T>> matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}
template <typename T>
void add_matrix(std::vector<std::vector<T>> matrix1, std::vector<std::vector<T>> matrix2) {
    for (int i = 0; i < matrix1.size(); i++) {
        for (int j = 0; j < matrix1[i].size(); j++) {
            matrix1[i][j] += matrix2[i][j];
        }
    }
    std::cout << "Sum of two matrices: " << std::endl;
    print_matrix(matrix1);
}
template <typename T>
void multiply_matrix(std::vector<std::vector<T>> matrix1, std::vector<std::vector<T>> matrix2) {
    std::vector<std::vector<T>> product;
    product.resize(matrix1.size(), std::vector<T>(matrix2.size(), 0));
    for (int i = 0; i < matrix1.size(); i++) {
        for (int j = 0; j < matrix2[i].size(); j++) {
            product[i][j] = 0;
            for (int k = 0; k < matrix1[i].size(); k++) {
                product[i][j] += (matrix1[i][k] * matrix2[k][j]);
            }
        }
    }
    std::cout << "Product matrix: " << std::endl;
    print_matrix(product);
}
template <typename T>
void calculate_diagonals(std::vector<std::vector<T>> matrix) {
    int main = 0;
    int secondary = 0;

    for (int i = 0; i < matrix.size(); i++) {
        main += matrix[i][i];
        secondary += matrix[i][matrix.size() - i - 1];
    }
    std::cout << "Main diagonal sum: " << main << std::endl;
    std::cout << "Secondary diagonal sum: " << secondary << std::endl;
}
template <typename T>
void swap_rows(int first_row, int second_row, std::vector<std::vector<T>> matrix) {
    matrix[first_row].swap(matrix[second_row]);
    std::cout << "Swaped matrix: " << std::endl;
    print_matrix(matrix);
}
template <typename T>
void swap_cols(int first_col, int second_col, std::vector<std::vector<T>> matrix) {
    int temp;
    for (int i = 0; i < matrix.size(); i++) {
        temp = matrix[i][first_col];
        matrix[i][first_col] = matrix[i][second_col];
        matrix[i][second_col] = temp;
    }
    std::cout << "Swaped matrix: " << std::endl;
    print_matrix(matrix);
}
template <typename T>
void update_matrix(int row, int col, T value, std::vector<std::vector<T>> matrix) {
    matrix[row][col] = value;
    std::cout << "Updated matrix: " << std::endl;
    print_matrix(matrix);
}

void run_double(int n, std::vector<std::vector<double>> matrix1, std::vector<std::vector<double>> matrix2) {
    std::vector<double> matrixRow;
    std::string line;
    std::cout << "Matrix 1: " << std::endl;
    print_matrix(matrix1);
    std::cout << "Matrix 2: " << std::endl;
    print_matrix(matrix2);
    add_matrix(matrix1, matrix2);
    multiply_matrix(matrix1, matrix2);
    std::cout << "Matrix 1 diagonal sum: " << std::endl;
    calculate_diagonals(matrix1);
    std::cout << "Matrix 2 diagonal sum: " << std::endl;
    calculate_diagonals(matrix2);

    int first_row, second_row, matrix_version;
    std::cout << "Enter first row to swap with: ";
    std::cin >> first_row;
    std::cout << "Enter second row to swap with: ";
    std::cin >> second_row;
    if (first_row > n - 1 || first_row < 0 || second_row > n - 1 || second_row < 0) {
        std::cout << "Rows out of bounds." << std::endl;
    }
    else {
        std::cout << "Enter which matrix to swap (1 or 2): ";
        std::cin >> matrix_version;
        if (matrix_version != 1 && matrix_version != 2) {
            std::cout << "Invalid matrix selected. " << std::endl;
        }
        else {
            switch (matrix_version) {
            case(1):
                swap_rows(first_row, second_row, matrix1);
                break;
            case(2):
                swap_rows(first_row, second_row, matrix2);
                break;
            default:
                break;
            }
        }
    }
    int first_col, second_col;
    std::cout << "Enter first column to swap with: ";
    std::cin >> first_col;
    std::cout << "Enter second column to swap with: ";
    std::cin >> second_col;
    if (first_col > n - 1 || first_col < 0 || second_col > n - 1 || second_col < 0) {
        std::cout << "Cols out of bounds." << std::endl;
    }
    else {
        std::cout << "Enter which matrix to swap (1 or 2): ";
        std::cin >> matrix_version;
        if (matrix_version != 1 && matrix_version != 2) {
            std::cout << "Invalid matrix selected. " << std::endl;
        }
        else {
            switch (matrix_version) {
            case(1):
                swap_cols(first_col, second_col, matrix1);
                break;
            case(2):
                swap_cols(first_col, second_col, matrix2);
                break;
            default:
                break;
            }
        }
    }
    double new_value;
    std::cout << "Enter new value: ";
    std::cin >> new_value;
    std::cout << "Enter row to update: ";
    std::cin >> first_row;
    std::cout << "Enter column to update: ";
    std::cin >> first_col;
    if (first_row > n - 1 || first_row < 0 || first_col > n - 1 || first_col < 0) {
        std::cout << "Row/Column out of bounds." << std::endl;
    }
    else {
        std::cout << "Enter which matrix to swap (1 or 2): ";
        std::cin >> matrix_version;
        if (matrix_version != 1 && matrix_version != 2) {
            std::cout << "Invalid matrix selected. " << std::endl;
        }
        else {
            switch (matrix_version) {
            case(1):
                update_matrix(first_row, first_col, new_value, matrix1);
                break;
            case(2):
                update_matrix(first_row, first_col, new_value, matrix2);
                break;
            default:
                break;
            }
        }
    }
}

void run_int(int n, std::vector<std::vector<int>> matrix1, std::vector<std::vector<int>> matrix2) {
    std::cout << "Matrix 1: " << std::endl;
    print_matrix(matrix1);
    std::cout << "Matrix 2: " << std::endl;
    print_matrix(matrix2);
    add_matrix(matrix1, matrix2);
    multiply_matrix(matrix1, matrix2);
    std::cout << "Matrix 1 diagonal sum: " << std::endl;
    calculate_diagonals(matrix1);
    std::cout << "Matrix 2 diagonal sum: " << std::endl;
    calculate_diagonals(matrix2);

    int first_row, second_row, matrix_version;
    std::cout << "Enter first row to swap with: ";
    std::cin >> first_row;
    std::cout << "Enter second row to swap with: ";
    std::cin >> second_row;
    if (first_row > n - 1 || first_row < 0 || second_row > n - 1 || second_row < 0) {
        std::cout << "Rows out of bounds." << std::endl;
    }
    else {
        std::cout << "Enter which matrix to swap (1 or 2): ";
        std::cin >> matrix_version;
        if (matrix_version != 1 && matrix_version != 2) {
            std::cout << "Invalid matrix selected. " << std::endl;
        }
        else {
            switch (matrix_version) {
            case(1):
                swap_rows(first_row, second_row, matrix1);
                break;
            case(2):
                swap_rows(first_row, second_row, matrix2);
                break;
            default:
                break;
            }
        }
    }
    int first_col, second_col;
    std::cout << "Enter first column to swap with: ";
    std::cin >> first_col;
    std::cout << "Enter second column to swap with: ";
    std::cin >> second_col;
    if (first_col > n - 1 || first_col < 0 || second_col > n - 1 || second_col < 0) {
        std::cout << "Cols out of bounds." << std::endl;
    }
    else {
        std::cout << "Enter which matrix to swap (1 or 2): ";
        std::cin >> matrix_version;
        if (matrix_version != 1 && matrix_version != 2) {
            std::cout << "Invalid matrix selected. " << std::endl;
        }
        else {
            switch (matrix_version) {
            case(1):
                swap_cols(first_col, second_col, matrix1);
                break;
            case(2):
                swap_cols(first_col, second_col, matrix2);
                break;
            default:
                break;
            }
        }
    }
    int new_value;
    std::cout << "Enter new value: ";
    std::cin >> new_value;
    std::cout << "Enter row to update: ";
    std::cin >> first_row;
    std::cout << "Enter column to update: ";
    std::cin >> first_col;
    if (first_row > n - 1 || first_row < 0 || first_col > n - 1 || first_col < 0) {
        std::cout << "Row/Column out of bounds." << std::endl;
    }
    else {
        std::cout << "Enter which matrix to swap (1 or 2): ";
        std::cin >> matrix_version;
        if (matrix_version != 1 && matrix_version != 2) {
            std::cout << "Invalid matrix selected. " << std::endl;
        }
        else {
            switch (matrix_version) {
            case(1):
                update_matrix(first_row, first_col, new_value, matrix1);
                break;
            case(2):
                update_matrix(first_row, first_col, new_value, matrix2);
                break;
            default:
                break;
            }
        }
    }
}

int main()
{
    
    std::string file_name;
    std::cout << "Enter the name of the input file: ";
    std::cin >> file_name;
    std::ifstream file(file_name);
    std::string matrix_data;
    int n;
    int flag;

    getline(file, matrix_data);
    n = int(matrix_data[0]-'0');
    flag = int(matrix_data[2]-'0');
    if (flag == 0) {
        std::vector<std::vector<int>> matrix1;
        std::vector<std::vector<int>> matrix2;
        std::vector<int> matrixRow;
        std::string line;
        for (int i = 0; i < n; i++) {
            getline(file, line);
            std::string num;
            for (int i = 0; i < line.length(); i++) {
                if (line[i] == ' ') {
                    matrixRow.push_back(stoi(num));
                    num.clear();
                }
                else {
                    num += line[i];
                }
            }
            if (!num.empty()) {
                matrixRow.push_back(stoi(num));
                num.clear();
            }
            matrix1.push_back(matrixRow);
            matrixRow.clear();

        }
        for (int i = 0; i < n; i++) {
            getline(file, line);
            std::string num;
            for (int i = 0; i < line.length(); i++) {
                if (line[i] == ' ') {
                    matrixRow.push_back(stoi(num));
                    num.clear();
                }
                else {
                    num += line[i];
                }
            }
            if (!num.empty()) {
                matrixRow.push_back(stoi(num));
                num.clear();
            }
            matrix2.push_back(matrixRow);
            matrixRow.clear();
        }
        run_int(n, matrix1, matrix2);
    }
    else {
        std::vector<std::vector<double>> matrix1;
        std::vector<std::vector<double>> matrix2;
        std::vector<double> matrixRow;
        std::string line;
        for (int i = 0; i < n; i++) {
            getline(file, line);
            std::string num;
            for (int i = 0; i < line.length(); i++) {
                if (line[i] == ' ') {
                    matrixRow.push_back(stod(num));
                    num.clear();
                }
                else {
                    num += line[i];
                }
            }
            if (!num.empty()) {
                matrixRow.push_back(stod(num));
                num.clear();
            }
            matrix1.push_back(matrixRow);
            matrixRow.clear();

        }
        for (int i = 0; i < n; i++) {
            getline(file, line);
            std::string num;
            for (int i = 0; i < line.length(); i++) {
                if (line[i] == ' ') {
                    matrixRow.push_back(stod(num));
                    num.clear();
                }
                else {
                    num += line[i];
                }
            }
            if (!num.empty()) {
                matrixRow.push_back(stod(num));
                num.clear();
            }
            matrix2.push_back(matrixRow);
            matrixRow.clear();
        }
        run_double(n, matrix1, matrix2);
    }
}
