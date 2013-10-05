#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
const ll M = 9901;

ll Mul(ll a,ll b,ll p) {
    a%=p;
    ll res=0;
    while(b) {
        if(b&1) {
            res+=a;
            if(res>p) res-=p;
        }
        a*=2,b/=2;
        if(a>p) a-=p;
    }
    return res;
}

ll Pow(ll a,ll b,ll p) {
    if(b==0) return 1;
    ll t=Pow(a,b/2,p);
    t=Mul(t,t,p);
    if(b&1) t=Mul(t,a,p);
    return t;
}

int main()
{
    ll a,b;
    while(~scanf("%lld%lld",&a,&b)) {
//        if(b==0) {
//            puts("1");
//            continue;
//        }
//        if(a==0) {
//            puts("0");
//            continue;
//        }
        ll ans=1;
        for(ll i=2;i*i<=a;i++) if(a%i==0) {
            ll e=0;
            while(a%i==0) {
                e++;
                a/=i;
            }
            e*=b;
            ans=Mul(ans,(Pow(i,e+1,(i-1)*M)-1)/(i-1),M);
        }
        if(a>1) {
            ll e=b;
            ans=Mul(ans,(Pow(a,e+1,(a-1)*M)-1)/(a-1),M);
        }
        printf("%lld\n",ans);
    }

    return 0;
}