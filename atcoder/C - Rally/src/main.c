#include <math.h>

int x[1000];
int N,t,r;
int main(){
  scanf("%d",&N);
  for(int i = 0; i < N;i++){
    scanf("%d",&x[i]);
    t+= x[i];
  }
  int avg = round(t/(double)N);
  for(int i = 0; i < N; i++){
    r += (x[i]-avg)*(x[i]-avg);    
  }
  printf("%d\n",r);
}