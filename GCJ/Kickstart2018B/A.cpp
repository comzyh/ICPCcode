#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int T;
long long contain[19] = {0}; // [0, 10 ^ x)
long long mod[19][9] = {0};
long long contain_mod[19][9] = {0};
long long psum(long long x) {
    // res = x - contain - mod[0] + contain_mod[0]
    x++; // cause we do not process x
    long long res = 0;
    long long base = 1000000000000000000ll;
    int leadmod = 0;
    long long contain_sum = 0, contain_mod_sum = 0, mod_sum = 0;
    for (int i = 18; i >= 0; i--, base /= 10) {
        if (base > x) {
            continue;
        }
        long long lead = (x / (base * 10)) * (base * 10);
        for (int d = 0; d <= 9; d++) { // scan digital
            if (lead + d * base + base - 1 >= x) {
                break;
            }
            contain_sum += d == 9 ? base / 10 : contain[i];
            mod_sum += mod[i][(18 - (leadmod + d)) % 9]; // (9 - (leadmod + d) % 9) % 9 
            contain_mod_sum += contain_mod[i][(18 - (leadmod + d)) % 9];

        }
        leadmod = (leadmod + (x / base) % 10) % 9;
    }
    res = contain_sum + mod_sum - contain_mod_sum;
    return res;
}
int main() {
    // init mods
    {
        mod[0][0] = 1;
        long long base = 1;
        for (int p = 1; p <= 18; p++) {
            contain[p] = contain[p - 1] * 9 + base;
            for (int d = 0; d <= 9; d++) { // digital this position
                for (int m = 0; m < 9; m++) {
                    mod[p][(m + d) % 9] += mod[p - 1][m];
                }
            }
            // choose 9
            for (int m = 0; m < 9; m++) {
                contain_mod[p][m] += mod[p - 1][m];
            }
            // d choose 1-8
            for (int d = 0; d <= 8; d++) {
                for (int m = 0; m < 9; m++) {
                    contain_mod[p][(m + d) % 9] += contain_mod[p - 1][m];
                }
            }
            base *= 10;
        }
    }
    scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        long long F, L;
        scanf("%lld%lld", &F, &L);
        printf("Case #%d: %lld\n", TT, (L - F + 1) -  (psum(L) - psum(F - 1)));
    }
    return 0;
}
