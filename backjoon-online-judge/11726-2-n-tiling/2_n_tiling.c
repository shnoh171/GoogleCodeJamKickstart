#include <stdio.h>
#define MAX_SIZE 1001

// d[n] = d[n-2] + d[n-1] (n >= 3)

/*
int main() {
    int d[MAX_SIZE];
    int i, num;
    scanf("%d", &num);

    d[1] = 1;
    d[2] = 2;
    for (i = 3; i <= num; ++i) {
        d[i] = (d[i-2] + d[i-1]) % 10007;
    }
    
    printf("%d\n", d[num]);

    return 0;
}
*/

int tiling(int n, int *d) {
    if (n == 1) {
        return d[1] = 1;
    } else if (n == 2) {
        return d[2] = 2;
    } else {
        if (d[n] > 0) return d[n];
        return d[n] = (tiling(n-2, d) + tiling(n-1, d)) % 10007;
    }
}

int main() {
    int d[MAX_SIZE] = {};
    int i, num;
    scanf("%d", &num);

    printf("%d\n", tiling(num, d));

    return 0;
}
