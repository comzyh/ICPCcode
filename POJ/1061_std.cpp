/*Accepted 164K 0MS C++ 633B 2012-10-09 23:38:48 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long long LL;

LL extgcd(LL a, LL b, LL &x, LL &y)
{
    if(b == 0) {x = 1; y = 0; return a;}
    LL d = extgcd(b, a % b, x, y);
    LL t = x;
    x = y;
    y = t - a / b * x;
    return d;
}

int main()
{
    LL x, y, m, n, L, t;
    while(scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &L) != EOF)
    {
        LL a = m - n, b = L, c = y - x;
        if(a < 0) a = -a, c = -c;
        LL d = extgcd(a, b, x, y);
        if(m == n || c % d != 0)
            puts("Impossible");
        else
        {
            b /= d, c /= d, t = c * x;
            t = (t % b + b) % b;
            printf("%I64d\n", t);
        }
    }
    return 0;
}