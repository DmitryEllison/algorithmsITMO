#include <cstdio>
#include <algorithm>

void ma_test() {
    size_t n;
    scanf("%zu", &n);
    int sum = 0;
    int max = 0;
    int i = 0;
    while (n--) {
        scanf("%d", &i);
        sum += i;
        sum < 0 ? sum = 0 : max = std::max(sum, max);
    }
    printf("%d", max);
}

int main() {
    ma_test();
}
