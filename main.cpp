#include <algorithm>
#include <iostream>
#include <iomanip>
#include <ctime>
const int SIZE = 3;
int main() {
    //Дана целочисленная квадратная матрица.
    srand(time(0));
    int array[SIZE][SIZE];
    for (int index_row = 0; index_row < SIZE; ++index_row) {
        for (int index_column = 0; index_column < SIZE; ++index_column) {
            array[index_row][index_column] = rand() % 10 - 5;
            std::cout << std::setw(3) << array[index_row][index_column];
        }
        std::endl(std::cout);
    }
    //1. Сумму элементов в тех строках, которые не содержат отрицательных элементов;
    int sum = 0;
    bool isNeg = false;
    for (int index_row = 0; index_row < SIZE; ++index_row) {
        for (int index_column = 0; index_column < SIZE; ++index_column) {
            if (array[index_row][index_column] < 0) {
                isNeg = true;
                continue;
            }
            sum += array[index_row][index_column];
        }
        if (!isNeg)
            std::cout << "The sum of the elements in row " << index_row << " is " << sum << std::endl;
        sum = 0;
        isNeg = false;
    }
    //2. Минимум среди сумм элементов диагоналей, параллельных главной диагонали матрицы.
    const int COUNT_DIAGONAL = 2 * SIZE - 1;
    int sum_array = 0;
    int min_sum = array[SIZE - 1][0];
    for (int index = 0; index < COUNT_DIAGONAL; ++index) {
        int t = SIZE - index - 1;
        int row = (t > 0) ? t : 0;
        int col = (t < 0) ? -t : 0;
        while ((row < SIZE) && (col < SIZE))
            sum_array += array[row++][col++];
        if (min_sum > sum_array)
            min_sum = sum_array;
        sum_array = 0;
    }

    std::cout << "The minimum amount on the diagonal is " << min_sum << std::endl;
}
