
/**
 * Решение не сколько на быстроту но на использование функций высшего поярдка
 */

#include <cstddef>
#include <iostream>
#define PI_2 1.5707963267948966

struct Point {
    int x, y, num;
};

void swap(Point* a, Point* b) {
    Point t = *a;
    *a = *b;
    *b = t;
}

double angle(Point* a, Point* b) {
    // (b->y > a->y) предтикат всегда верный ибо base выбран как самый маленьким по y
    if (b->x - a->x == 0) return (b->y > a->y) ? PI_2 : 3 * PI_2;
    double result = (b->y - a->y) / (b->x - a->x);
    return result;
}

double ma_comparator(Point* base, Point* a, Point* b) {
    return angle(base, a) - angle(base, b);
}

/**
 * O(N*logN)
 * @param array
 * @param left
 * @param right
 * @param comparator - функция сравнения
 */
void quickSort(Point* array,
               size_t left,
               size_t right,
               double (comparator)(Point*, Point*, Point*)) {

    size_t i = left, j = right;
    Point pivot = array[(left + right)/2];

    while ( i <= j) {
        while (comparator(&array[0], &array[i], &pivot) < 0) ++i;
        while (comparator(&array[0], &array[j], &pivot) > 0) --j;
        if (i > j) break;
        swap(&array[i], &array[j]);
        ++i;
        --j;
    }
    if (left < j) quickSort(array, left, j, comparator);
    if (right > i) quickSort(array, i, right, comparator);
}

int ma_test() {
    size_t n;
    size_t base = 0;
    std::cin >> n;
    Point points[n];

    for (size_t i = 0; i < n; ++i) {
        std::cin >> points[i].x >> points[i].y;
        points[i].num = i;
        if (points[i].y < points[base].y) base = i;
    }

    swap(&points[0], &points[base]);
    quickSort(points, 1, n-1, ma_comparator);

    printf("%d %d", points[0].num + 1, points[n/2].num + 1);
}

int main() {
    return ma_test();
}