#include <stdio.h>

int getDecomposeNum(int input) {
    int temp, decompose;
    for (int i = 1; i < input; i++) {
        temp = i;
        decompose = 0;
        while (temp > 0) {
            decompose += temp % 10;
            temp /= 10;
        }
        if (i + decompose == input)
            return i;
    }
    return 0;
}
int main(){
    int input;
    scanf("%d",&input);
    printf("%d",getDecomposeNum(input));

    return 0;
}