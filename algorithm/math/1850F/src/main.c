long long a,b;
i;
long long gcd_recursive(long long a, long long b){
    if (b)
        return gcd_recursive(b, a % b);
    else
        return a;
}
int main(){
    scanf("%lld %lld",&a,&b);
    long long m = gcd_recursive(a,b);

    for(;i < m;i++){
        printf("1");
    }
}