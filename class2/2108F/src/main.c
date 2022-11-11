#include <stdio.h>
#include <math.h>


a,b,c[500001],d[8001],big,f,g,count,i;
double total;
int compare(const void * A,const void * B){
    int * a = (int *)A; int * b = (int *)B;
    return (*a < *b) - (*a > *b);
}
int main(){
    scanf("%d",&a);
    for(int i = 0; i < a; i++){
        scanf("%d",&c[i]);
        total+=c[i];
        d[c[i] + 4000]++;
    }
    qsort(c,a,4,compare);
    big = c[a - 1] + 4000;
    for(i = big; i <= c[0] + 4000; i++){
        if(d[i] > d[big]) {
            big = i;
            count = 0;
        }
        else if(d[i] == d[big]) count++;
        if(count == 2) break;
    }

    printf("%d\n%d\n%d\n%d\n",
        (int)round(total/a),
        c[a/2],
        i - 4000,
        c[0] - c[a - 1]);
}