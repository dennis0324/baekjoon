long long h[100000],temp;
int size,n;
void insert(long long n){
    int index;
    for(index = ++size; index != 1;index /=2){
        if(h[index / 2] <= n) break;
        h[index] = h[index / 2];
    }
    h[index] = n;
}

long long delete(){
    if(!size) return 0;
    int parent = 1;
    int child = 2;
    long long result = h[1],temp = h[size--];
    while(child <= size){
        if(child < size && h[child] > h[child +1]) child++;
        if(h[child] >= temp) break; //아래 위
        h[parent] = h[child];
        parent = child;
        child *=2;
    }
    h[parent] = temp;
    return result;
}
int main(){
    scanf("%d",&n);
    for(int i = 0 ; i < n;i++){
        scanf("%lld",&temp);
        if(!temp){
            long long ex = delete();
            printf("%lld\n",ex);
        }
        else
            insert(temp);
        
    }
    return 0;
}