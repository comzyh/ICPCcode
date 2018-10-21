#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
int T, N, Q;
vector<int> generate(int n) {
    vector<int> res(n);
    long long a, b, c, m;
    scanf("%d%d", &res[0], &res[1]);
    scanf("%lld%lld%lld%lld", &a, &b, &c, &m);
    for (int i = 2; i < n; i++) {
        res[i] = (res[i - 1] * a + res[i - 2] * b + c) % m;
    }
    return res;
}
int main() {
    scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        scanf("%d%d", &N , &Q);
        vector<int> X = generate(N);
        vector<int> Y = generate(N);
        vector<int> Z = generate(Q);
        vector<pair<int, int> > chs;
        vector<pair<int, int> > slope;
        for (int i = 0; i < N; i++) {
            int l = X[i] + 1;
            int r = Y[i] + 1;
            if (r < l)  {
                swap(l, r);
            }
            // printf("%4d %4d\n", l, r);
            chs.push_back(make_pair(l, 1));
            chs.push_back(make_pair(r + 1, -1));
        }
        // printf("N = %d\n", N);
        sort(chs.begin(), chs.end());
        slope.push_back(make_pair(-1, 0));
        for (size_t i = 0; i < chs.size(); i++) {
            // printf("%d %d\n", chs[i].first, chs[i].second);
            if (chs[i].first == slope.rbegin()->first) {
                slope.rbegin()->second += chs[i].second;
            } else {
                slope.push_back(make_pair(chs[i].first, slope.rbegin()->second + chs[i].second));
            }
        }
        vector<long long> sum(1, 0);
        for (size_t i = 1; i < slope.size(); i++) {
            // printf("%5d %5d\n", slope[i].first, slope[i].second);
            sum.push_back(sum[i - 1] + (long long)slope[i - 1].second * (slope[i].first - slope[i - 1].first));
        }
        for (size_t i = 0; i < sum.size(); i++) {
            // printf("%d %d %lld\n", slope[i].first, slope[i].second, sum[i]);
        }

        long long ans = 0;
        for (int i = 0; i < Q; i++) {
            long long k = Z[i] + 1;
            if (k > *sum.rbegin()) {
                continue;
            }
            k = *sum.rbegin() - k + 1;
            // printf("k = %lld, sum = %lld\n", k, *sum.rbegin());
            int it = lower_bound(sum.begin(), sum.end(), k) - sum.begin() - 1;
            long long tans = slope[it].first + (k - (sum[it] + 1)) / slope[it].second;
            // printf("%4d %4d %4d %lld\n", slope[it].first, slope[it].second, sum[it], tans);
            ans += (i + 1) * tans;
        }
        cerr << TT << endl;
        printf("Case #%d: %lld\n", TT, ans);

    }
    return 0;
}
