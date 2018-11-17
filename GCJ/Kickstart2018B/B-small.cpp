#include <cstdio>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
typedef pair<pair<int, int>, int> constrain_T;
int main() {
    int T, N, K;
    scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        long long P;
        scanf("%d%d%lld", &N, &K, &P);
        vector<int> occpy(N, 0);
        vector<bool> bits(N, 0);
        for (int i = 0; i < K; i++) {
            constrain_T constrain;
            scanf("%d%d%d", &constrain.first.first, &constrain.first.second, &constrain.second);
            occpy[N -constrain.first.first] = 1;
            bits[N - constrain.first.first] = constrain.second == 1;
        }
        long long p = P - 1;
        for (int i = 0; p > 0 && i < N; i++) {
            if (!occpy[i]) {
                bits[i] = p & 1;
                p >>= 1;
            }
        }
        printf("Case #%d: ", TT);
        for (int i = N - 1; i >= 0; i--) {
            printf("%d", int(bits[i]));
        }
        printf("\n");
    }
    return 0;
}
