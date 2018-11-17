#include <cstdio>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
const long long MAX = 1000000000000000000;
const int MASK = (1 << 15) - 1;
long long dp[101][1 << 15];
bool check(int base, vector <pair<int, int> > &constrains) {
    if (constrains.size() == 0) {
        return true;
    }
    int sum[17];
    sum[0] = 0;
    for (int i = 1; i <= 16; i++) {
        sum[i] = sum[i - 1] + int(base & 1);
        base >>= 1;
    }
    for (auto it = constrains.begin(); it != constrains.end(); it++) {
        if (sum[it->first] != it->second) {
            return false;
        }
    }
    return true;
}
int main() {
    int T, N, K;
    scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        long long P;
        scanf("%d%d%lld", &N, &K, &P);
        vector<vector<pair<int, int> > >constrain(N + 1);
        for (int i = 0; i < K; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            constrain[b].push_back(make_pair(b - a + 1, c));

        }
        // DP
        long long rest = P;
        memset(dp, 0, sizeof(dp));
        vector<bool> bits(N + 1);
        dp[0][0] = 1;
        for (int p = 1; p <= N; p++) {
            unsigned base = 0;
            for (int i = 0; i < p; i++) {
                base = base << 1;
                base = base | bits[i];
            }
            base &= MASK;
            // try 0
            if (!check(base << 1, constrain[p])) {
                bits[p] = 1;
                continue;
            }
            fill(dp[p], dp[p] + (1 << 15), 0);
            dp[p][(base << 1) & MASK] = 1;
            for (int q = p + 1; q <= N; q++) {
                fill(dp[q], dp[q] + (1 << 15), 0);
                for (int pre = 0; pre <= MASK; pre ++){
                    if (!dp[q - 1][pre]) {
                        continue;
                    }
                    int cur = pre << 1;
                    if (check(cur, constrain[q])) {
                        dp[q][cur & MASK] = min(MAX, dp[q][cur & MASK] + dp[q-1][pre]);
                    }
                    cur ++;
                    if (check(cur, constrain[q])) {
                        dp[q][cur & MASK] = min(MAX, dp[q][cur & MASK] + dp[q-1][pre]);
                    }
                }
            }
            long long tans = 0;
            for (int i = 0; i <= MASK; i++) {
                tans = min(MAX, tans + dp[N][i]);
            }
            // printf("p = %4d, rest = %lld, tans = %lld\n", p, rest, tans);
            if (tans >= rest) {
                bits[p] = 0;
            } else {
                bits[p] = 1;
                rest -= tans;
            }

        }
        cerr << TT << endl;
        printf("Case #%d: ", TT);
        for (int i = 1; i <= N; i++) {
            printf("%d", int(bits[i]));
        }
        printf("\n");
    }
    return 0;
}
