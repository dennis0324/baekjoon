#define L 100000
n,i,b,arr[L],r[L];
int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++)
        arr[i]=i+1;
    n--;i=0;
    while(i<n/2){
        r[b] = arr[i];
        r[b + 1] = arr[n-1-i];
        b+=2;i++;
    }
    if(n%2) r[n-1]=arr[n/2];
    r[n-1] = arr[++n-1];
    for(i = 0;i < n; i++){
        printf("%d ",r[i]);
    }
}