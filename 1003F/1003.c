int febo(int * a, int * b){
    int temp = *a + *b;
    *a = *b;
    *b = temp;
}

int main() {
    int zeroA = 1;
    int oneB = 1;
    int zeroB = 0;
    int oneA = 0;
    int count = 0;
    int num = 0;
    scanf("%d",&count);
    for(int i = 0; i< count; i++){
        zeroA = oneB = 1;
        zeroB = oneA = 0;
        scanf("%d",&num);
        for(int j = 0;j < num; j++){
            febo(&zeroB,&oneB);
            febo(&zeroA,&oneA);
        }
        printf("%d %d\n",zeroA,oneA);
    }

    return 0;
}


// long a,b;
// main(i){
//     for(gets(&i);~scanf("%d",&i);printf(i<0?"1 0 ":"%ld %ld ",a,b),a=b=0)
//         for(b++;0< --i;a=b-a)
//             b+=a;
//     }


// int main(){
//     printf("%d",~-1);
//     return 0;
// }