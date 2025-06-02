#include <stdio.h>

int sum(int num) {
    int result = 0;
    int i;
    for (i = 1; i <= num; i++) {
        result += i;
    }
    return result;
}

int main() {
    printf("%d ", sum(55));
    printf("%d ", sum(45));
    printf("%d ", sum(50));
    return 0;
}

