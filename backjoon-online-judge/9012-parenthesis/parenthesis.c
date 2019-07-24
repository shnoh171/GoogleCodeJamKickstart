#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_vps(char *str) {
    int size = strlen(str);
    int i, count = 0;

    for (i = 0; i < size; ++i) {
        if (str[i] == '(') ++count;
        else if (str[i] == ')') --count;

        if (count < 0) return false;
    }

    if (count == 0) return true;
    else return false;
}

int main() {
    char str[51];
    int num;

    scanf("%d", &num);
    while (num--) {
        scanf("%s", str);

        if (is_vps(str)) printf("YES\n");
        else printf("NO\n");
    }
}