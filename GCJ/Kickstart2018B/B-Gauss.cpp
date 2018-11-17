#include <cstdio>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;
typedef pair<pair<int, int>, int> constrain_T;
int T, N, K;
long long P;
int coeff[100][101];
vector<int> gauss(int K) {
    vector<int> free_p;
    int col = N + 1;
    for (int line = 0; line < K; line ++) {
        int swapline = -1;
        col --;
        while (col >= 1) {
            for (int i = line; i < K; i++) {
                if (coeff[i][col] != 0) {
                    swapline = i;
                    break;
                }
            }
            if (swapline == -1) {
                free_p.push_back(col);
                col --;
            } else {
                break;
            }
        }
        if (col < 1) {
            break;
        }
        for (int i = 0; i <= N; i++) {
            swap(coeff[line][i], coeff[swapline][i]);
        }
        assert(coeff[line][col] == 1 || coeff[line][col] == -1);
        if (coeff[line][col] == -1) {
            for (int i = 0; i <= N; i++) {
                coeff[line][i] *= -1;
            }
        }
        // reduce
        for (int rline = 0; rline < K; rline ++) {
            int c = coeff[rline][col];
            if (rline == line || c == 0) {
                continue;
            }
            for (int i = 0; i <= N; i++) {
                coeff[rline][i] -= coeff[line][i] * c;
            }
        }
    }
    for (int i = col - 1; i >= 1; i--) {
        free_p.push_back(i);
    }
    return free_p;
}
void print_coeff(int K) {
    printf("-----------------------------\n");
    for (int i = 0; i < K; i++) {
        for (int j = 0; j <= N; j ++) {
            printf("%4d ", coeff[i][j]);
        }
        printf("\n");
    }
}
int main() {
    scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        scanf("%d%d%lld", &N, &K, &P);
        memset(coeff, 0, sizeof(coeff));
        for (int i = 0; i < K; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            for (int j = a; j <= b; j++) {
                coeff[i][j] = 1;
            }
            coeff[i][0] = c;
        }
        // Gauss
        // print_coeff(K);
        vector<int> free_p = gauss(K);
        // print_coeff(K);

        long long p = P - 1;
        int free_base = K - (free_p.size() - (N - K));
        sort(free_p.begin(), free_p.end(), greater<int>());
        // printf("free_p: ");
        // for (size_t i = 0; i < free_p.size(); i++) {
        //     printf("%4d ", free_p[i]);
        // }
        // printf("\n");
        // printf("base  = %4d\n", free_base);
        for (size_t i = 0; i < free_p.size(); i++) {
            coeff[free_base + i][0] = p & 1;
            coeff[free_base + i][free_p[i]] = 1;
            p >>= 1;
        }
        // print_coeff(N);
        free_p = gauss(N);
        // print_coeff(N);
        printf("Case #%d: ", TT);
        for (int i = N - 1; i >= 0; i--) {
            printf("%d", int(coeff[i][0]));
        }
        printf("\n");
    }
    return 0;
}
