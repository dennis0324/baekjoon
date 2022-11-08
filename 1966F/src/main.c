typedef struct{
    int pri;
    int index;
}data;
data q[102];
int a,b,loop,findindex,r,i,p[102];
int compare(const void * A,const void *B){
    int * a = (int *)A; int * b = (int *)B;
    return (*a < *b) - (*a > *b);
}
int main(){
    scanf("%d",&a);
    while(a--){
        scanf("%d %d",&loop,&findindex);
        data d;
        for(int i = 0; i < loop; i++){
            d.index = i;
            scanf("%d",&d.pri);
            q[i] = d; p[i] = d.pri;
        }
        qsort(p,loop,4,compare);
        i=0;b=0;
        while(b != loop){ //제일 높은 숫자
            if(p[b] == q[i].pri){
                if(q[i].index == findindex) break;
                b++;
            }
            i = (i + 1) % loop;
        }
        printf("%d\n",b + 1);
    }
}