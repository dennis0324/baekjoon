#define T 100001
i,n,m,a,b,c,d,l,u,*o,r[T],v[T],e[T],x[T],*g[T];main(){scanf("%d%d",&n,&m);for(;i<m;i++){scanf("%d%d",&a,&b);g[a]=realloc(g[a],4*e[a]+4);g[a][e[a]++]=b;r[b]++;}for(;;){l=0;for(i=1;i<=n;i++){if(!r[i]&&!v[i]){if(c^d)break;x[d++]=i;v[i]=1;l++;}}if(!l)break;u=x[c++];printf("%d ",u);for(i=0;i<e[u];i++)r[g[u][i]]--;}}