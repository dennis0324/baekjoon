#include <stdio.h>
#include <math.h>

void hanoRecursion(int n, int from, int help, int to) {
    int total = 0;
    if (n == 1) {
        printf("%d %d\n", from, to);
        return ;
    }

    hanoRecursion(n - 1, from, to, help);
    printf("%d %d\n", from, to);
    hanoRecursion(n - 1, help, from, to);
}

int main() {
    int input;
    scanf("%d", &input);
    printf("%d\n",(int)pow(2,input) - 1);
    hanoRecursion(input, 1, 2, 3);
}