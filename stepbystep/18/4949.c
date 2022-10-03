#include <stdio.h>

int main(){
  char input;
  int stack[100];
  int index = 0;
  int start = 0;
  while(1){
    index = 0;
    start = 0;
    while(1){
      scanf("%c",&input);
      if(input == '.')
        break;
      if(input == '['){
        stack[index++] = 2;
      }
      else if(input == ']'){
        stack[index++] = 0;
        if(index == 0 || stack[index - 1] != 2){
          printf("NO");
          break;
        }
      }
      else if(input == '('){
        stack[index++] = 1;
      }
      else if(input == ')'|| stack[index - 1] != 1){
        if(index == 0){
          printf("NO");
          break;
        }
        stack[--index] = 0;
      }
      start = 1;
    }
    if(input == '.' && start == 0){ 
      break;
    }
  }
  return 0;
}