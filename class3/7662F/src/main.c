#define MAX 1000000 + 10000
k,co,a,l;
char flag;

typedef struct{
    long long value;
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
    int i = ++h->n;
    while(i != 1){
        if(h->d[i / 2].value * type<= e.value * type) break;
        h->d[i] = h->d[i /2];
        i /= 2;
    }
    h->d[i] = e;
}

void delete_(H * h, int t){
    if(!h->n) return;
    HE result = h->d[1];
    int p = 1,c = 2;
    HE temp = h->d[h->n--];
    while(c <= h->n){
        if(c < h->n && (h->d[c].value * t > h->d[c + 1].value * t))
            c++;
        if(temp.value * t <= h->d[c].value * t) break;
        h->d[p] = h->d[c];
        p = c;
        c *=2;
    }
    h->d[p] = temp;
    f[result.index] = 1;
}

int main(){
    H miH;miH.d = min;
    H maH;maH.d = max;

    scanf(" %d",&co);
    while(co--){
        int CI = 0;
        miH.n = 0;
        maH.n = 0;
        scanf(" %d",&l);
        for(int i = 0; i <l;i++){
            scanf(" %c %d",&flag,&a);
            if(flag == 'D'){
                if(a > 0){
                    while (f[maH.d[1].index] && maH.n) delete_(&maH,-1);
                    delete_(&maH,-1);
                }
                else{
                    while (f[miH.d[1].index] && miH.n) delete_(&miH,1);
                    delete_(&miH,1);
                }
            }
            else if(flag == 'I'){
                insert(&miH,(HE){a,CI},1);
                insert(&maH,(HE){a,CI},-1);
                f[CI++] = 0;
            }
        }
        while (f[maH.d[1].index] && maH.n) delete_(&maH,-1);
        while (f[miH.d[1].index] && miH.n) delete_(&miH,1);
        !(miH.n || maH.n) ? printf("EMPTY\n") : printf("%d %d\n",maH.d[1].value,miH.d[1].value);
    }
}

