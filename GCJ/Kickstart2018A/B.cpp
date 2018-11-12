#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int T, N, K;
vector<double> C;
vector<int> V;
int main() {
    scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        scanf("%d%d", &N, &K);
        V.resize(N);
        C.resize(K + 1);
        for (int i = 0; i < N; i++) {
            scanf("%d", &V[i]);
        }
        sort(V.begin(), V.end());
        vector<long long> s(N + 1);
        s[0] = 0;
        for (int i = 0; i < N; i++) {
            s[i + 1] = s[i] + V[i];
        }
        C[0] = (double)s[N] / N;
        for (int i = 1; i <= K; i++) {
            auto it = lower_bound(V.begin(), V.end(), C[i - 1]);
            int x = it - V.begin(); // pick x (index from 1 to N)
            C[i] = double(s[N] - s[x]) / N + double(x) / N * C[i - 1];
        }
        printf("Case #%d: %.7lf\n", TT, C[K]);
    }
    return 0;

}
