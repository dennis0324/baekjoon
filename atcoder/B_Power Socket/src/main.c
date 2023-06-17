int a,b,t,i;
int main(){
  scanf("%d %d",&a,&b);
  t = 1;
  while(t <b){
    t--;
    t += a;
    i++;
  }

  printf("%d\n",i);
}

