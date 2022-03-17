#include <stdio.h>

int main(){
    int inputCount;
    char input;
    int count = 0;
    char stack[50];
    int result = 0;
    scanf("%d",&inputCount);
    while(fgetc(stdin) != '\n');
    while(inputCount--){
        result = 0;
        count = 0;
        while(1){
            scanf("%c",&input);
            if(input == '\n') break;
            if(input == '(') stack[count++] = input;
            else {
                if(count == 0 ) {
                    result = 1;
                    while(fgetc(stdin) != '\n');
                    break;
                }
                stack[--count] = ' ';
            }
        }
            if(count > 0) result = 1;
            if(result == 1) printf("NO\n");
            else printf("YES\n");
    }

    return 0;
}