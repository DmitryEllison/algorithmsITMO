#include <cstdio>
#include <climits>
#include <algorithm>

int ma_min(int a, int b) {
    return a > b ? b : a;
}

void ma_test() {
    int n;
    scanf("%d", &n);
    int data[n];

    for (size_t i = 0; i < n; ++i) {
        scanf("%d", data + i);
    }

    int min_diff = INT_MAX;
    int sum_left, sum_right;
    for (int code = 0; code < (1 << (n-1)); ++code) {
        sum_left = 0;
        sum_right = 0;
        for (int i = 0; i < n; ++i) {
            if ( ((code >> i) & 1) == 0)
                sum_left += data[i];
            else
                sum_right += data[i];
        }
        min_diff = ma_min(min_diff, std::abs(sum_right - sum_left));
    }
    printf("%d", min_diff);
}

int main() {
    ma_test();
}