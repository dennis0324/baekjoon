// long long h[8<<14],s;
// main(t,i,j,x){
//     for(memset(h,1,8<<17),scanf("%*s");~scanf("%d",&x);)
//         if(x)
//             for(h[++s]=x,x=s;x>1;x/=2)
//                 h[x/2]>h[x]?t=h[x],h[x]=h[x/2],h[x/2]=t:0;

//         else 
//             printf("%d ",s?h[1]:0);
//             s?h[i=1]=h[s],h[s--]=9e9:0;
//             for(;s?h[i]>h[i*=2]||h[i/2]>h[i+1]:0;)
//                 j=h[i]<h[i+1]?i:i+1;
//                 i=h[j];
//                 h[j]=h[j/2];
//                 h[j/2]=i;
//                 i=j;
// }