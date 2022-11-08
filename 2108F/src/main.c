#include <stdio.h>
#include <math.h>


a,b,c[500001],d[8001],big,f,g;
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

    for(int i = c[a - 1] + 4000; i <= c[0] + 4000; i++){
        if(d[i] > big) {
            big = d[i];
            f = i;
            g = 0;
        }
        else if(d[i] == big) {
            if(g == 0)
                g = i;
        }
    }

    printf("%d\n%d\n%d\n%d\n",
        (int)round(total/a),
        c[a/2],
        g != 0 ? g - 4000 : f - 4000,
        c[0] - c[a - 1]);
}