
int get(int k,int n){
    if(k == 0 )return n;
    if(n == 0) return 0;
    return get(k-1,n) + get(k,n-1);
}
int main(){
    int c,k,n;
    int temp;
    scanf("%d",&c);
    while(c--){
        scanf("%d %d",&k,&n);
        temp = get(k,n);

        print("%d\n",temp);
    }
}