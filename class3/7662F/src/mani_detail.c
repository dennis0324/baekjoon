#include <stdio.h>
#include <stdbool.h>
#define MAX 1000000 + 10000
int k,c,a,l;
char flag;

typedef struct{
    long long value; // 이거 곱하면서 오버플로우 난다. 반드시 확인해야한다.
    int index;
}HE;

typedef struct {
    int n;
    HE * d;
}H;

HE max[MAX];
HE min[MAX];
int f[MAX] = {0}; 

void insert(H * h,HE e,int type){
    int index = ++h->n;
    while(index != 1){
        if(h->d[index / 2].value * type<= e.value * type) break;
        h->d[index] = h->d[index /2];
        index /= 2;
    }
    h->d[index] = e;
}

void delete_(H * h, int type){
    if(!h->n) return;
    HE result = h->d[1];
    int parent = 1,child = 2;
    HE temp = h->d[h->n--];
    while(child <= h->n){
        if(child < h->n && (h->d[child].value * type > h->d[child + 1].value * type))
            child++;
        if(temp.value * type <= h->d[child].value * type) break;
        h->d[parent] = h->d[child];
        parent = child;
        child *=2;
    }
    h->d[parent] = temp;
    f[result.index] = 1;
}

int main(){
    H min_heap;
    H max_heap;
    min_heap.d = min;
    max_heap.d = max;
    int dataCount = 0;
    int currentIndex = 0;
    scanf(" %d",&c);
    while(c--){
        min_heap.n = 0;
        max_heap.n = 0;
        currentIndex = 0;
        dataCount = 0;
        scanf(" %d",&l);
        for(int i = 0; i <l;i++){
            scanf(" %c %d",&flag,&a);
            if(flag == 'D'){
                if(a > 0){
                    while (f[max_heap.d[1].index] && max_heap.n) delete_(&max_heap,-1);
                    delete_(&max_heap,-1);
                }
                else{
                    while (f[min_heap.d[1].index] && min_heap.n) delete_(&min_heap,1);
                    delete_(&min_heap,1);
                }
            }
            else if(flag == 'I'){
                f[currentIndex] = 0;
                insert(&min_heap,(HE){a,currentIndex},1);
                insert(&max_heap,(HE){a,currentIndex},-1);
                currentIndex++;
            }
        }

        while (f[max_heap.d[1].index] && max_heap.n) delete_(&max_heap,-1);
        while (f[min_heap.d[1].index] && min_heap.n) delete_(&min_heap,1);

        !(min_heap.n || max_heap.n) ? printf("EMPTY\n") : printf("%d %d\n",max_heap.d[1].value,min_heap.d[1].value);
    }
}
