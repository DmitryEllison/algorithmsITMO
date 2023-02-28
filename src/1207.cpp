
/**
 * Решение не сколько на быстроту но на использование функций высшего поярдка
 */

#include <iostream>
#include <valarray>

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
    if (b->x == a->x) return (b->y >= a->y) ? PI_2 : 3 * PI_2;
    else if (b->y == a->y ) return 0;
    return atan2((double )(b->y - a->y) , (double )(b->x - a->x));
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
               int left,
               int right,
               double (comparator)(Point*, Point*, Point*)) {

    int i = left, j = right;
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

int main() {
    int n;
    int base = 0;
    std::cin >> n;
    Point points[n];

    for (int i = 0; i < n; ++i) {
        std::cin >> points[i].x >> points[i].y;
        points[i].num = i;
        if (points[i].y < points[base].y ||
        points[i].y == points[base].y && points[i].x < points[base].x) base = i;
    }
    swap(&points[0], &points[base]);

    quickSort(points, 1, n-1, ma_comparator);

    printf("%d %d", points[0].num + 1, points[n/2].num + 1);
}