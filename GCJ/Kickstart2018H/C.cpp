#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MOD = 1000000000 + 7;
const int MAXN = 100000;
int fact[2 * MAXN + 1], inv[2 * MAXN + 1], pow2[2 * MAXN + 1];
int combin(int N, int M) {
    return (((long long)fact[N] * inv[N - M]) % MOD * inv[M]) % MOD;
}
inline int P(int n, int m, int x) {
    long long ans = combin(2 * n - x, x);
    ans = (ans * combin(m , x)) % MOD;
    ans = (ans * fact[2 * (n - x)]) % MOD;
    ans = (ans * fact[x]) % MOD;
    ans = (ans * pow2[x]) % MOD;
    return ans;
}
int main() {
    // init
    fact[0] = 1;
    fact[1] = 1;
    inv[0] = 1;
    inv[1] = 1;
    pow2[0] = 1;
    pow2[1] = 2;
    for (int i = 2; i <= 2 * MAXN; i++) {
        fact[i] = (fact[i - 1] * (long long)i) % MOD;
        inv[i] = ((MOD - MOD / i) * (long long)inv[MOD % i]) % MOD;
        pow2[i] = (pow2[i - 1] * 2ll) % MOD;
    }
    for (int i = 1; i <= 10; i++) {
        // printf("%lld ", ((long long)i * inv[i]) % MOD);
        // printf("%d ", fact[i]);
    }
    // printf("\n");
    for (int i = 2; i <= 2 * MAXN; i++) {
        inv[i] = ((long long)inv[i] * inv[i - 1]) % MOD;
    }
    int T;
    scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        int N, M;
        scanf("%d%d", &N, &M);
        long long ans = 0;
        for (int i = 0; i <= M; i++) {
            if (i % 2 == 0) {
                ans = (ans + P(N, M , i)) % MOD;
            } else {
                ans = (ans + MOD - P(N, M, i)) % MOD;
            }
            // printf("%d ", P(N, M, i));
        }
        // printf("\n");
        printf("Case #%d: %lld\n", TT, ans);
    }
    return 0;
}
