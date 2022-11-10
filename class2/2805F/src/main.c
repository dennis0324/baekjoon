#include <stdio.h>

int n,m,s,e;
long long compare,b1,b2,t,a[1000001];
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i++){
        scanf("%lld",&a[i]);
        if(a[b1] < a[i])
            b1 = i;
    }
    e = a[b1];
    while(s <= e){
        t = (s + e) / 2;
        compare = 0;
        for(int i = 0; i < n; i++){
            if(a[i] > t)
                compare += (a[i] - t);
        }
        if(m > compare) e = t - 1;
        else if(m <= compare) {
            s = t + 1;
            if(b2 < t)
                b2 = t;
        }
    }
    printf("%lld\n",b2);
}