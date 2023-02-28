#include <iostream>

int ma_comparator(int a, int b) {
    return a - b;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * O(N*logN)
 * @param array
 * @param left
 * @param right
 * @param comparator - функция сравнения
 */
void quickSort(int* array,
               int left,
               int right,
               int (comparator)(int, int)) {

    int i = left, j = right;
    int pivot = array[(left + right)/2];

    while ( i <= j) {
        while (comparator(array[i], pivot) < 0) ++i;
        while (comparator(array[j], pivot) > 0) --j;
        if (i > j) break;
        swap(&array[i], &array[j]);
        ++i;
        --j;
    }

    if (left < j) quickSort(array, left, j, comparator);
    if (right > i) quickSort(array, i, right, comparator);
}

int main() {
    long long n, sum = 0;
    std::cin >> n;
    int xCoords[n];
    int yCoords[n];
    for (long long i = 0; i < n; ++i) std::cin >> xCoords[i] >> yCoords[i];

    quickSort(xCoords, 0, n - 1, ma_comparator);
    quickSort(yCoords, 0, n - 1, ma_comparator);

    for (long long i = 1; i < n; i++)
        sum += ((xCoords[i] - xCoords[i - 1]) + (yCoords[i] - yCoords[i - 1])) * (i) * (n - i) * 2;
    sum = sum / (n * (n - 1)) ;
    std::cout << sum << std::endl;
    return 0;
}