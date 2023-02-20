#include <iostream>

void ma_test() {
    int n, k, n_min;
    int count;
    std::cin >> count;
    while (count-- > 0) {
        std::cin >> n >> k;
        n_min = n/k * k;
        std::cout << n/k * n_min * (k-1)/2 + (n - n_min) * (n - n_min - 1) / 2 + (n - n_min) * (n_min - n/k) << "\n";
    }
}

int main() {
    ma_test();
    return 0;
}