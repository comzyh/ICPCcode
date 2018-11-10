#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int T, R, C;
char ground[26][27];
bool test(int l, int r, int t, int b, char c) {
    for (int i = t; i <= b; i++) {
        for (int j = l; j <= r; j++) {
            if (ground[i][j] != '?' && ground[i][j] != c) {
                return false;
            }
        }
    }
    return true;
}
void expand(int x, int y) {
    int l = y, r = y, t = x, b = x;
    for (; t > 1 && ground[t - 1][y] == ground[x][y]; t --);
    for (; b < R && ground[b + 1][y] == ground[x][y]; b ++);        
    for (; l > 1 && ground[x][l - 1] == ground[x][y]; l --);
    for (; r < C && ground[x][r + 1] == ground[x][y]; r ++);
    while (l > 1) {
        if (test(l - 1, l - 1, t, b, ground[x][y])) {
            for (int i = t; i <= b; i++) {
                ground[i][l - 1] = ground[x][y];
            }
            l--;
        }  else {
            break;
        }
    }
    while (r < C) {
        if (test(r + 1, r + 1, t, b, ground[x][y])) {
            for (int i = t; i <= b; i++) {
                ground[i][r + 1] = ground[x][y];
            }
            r++;
        }  else {
            break;
        }
    }
    while (t > 1) {
        if (test(l, r, t - 1, t - 1, ground[x][y])) {
            for (int i = l; i <= r; i++) {
                ground[t - 1][i] = ground[x][y];
            }
            t--;
        }  else {
            break;
        }
    }
    while (b < R) {
        if (test(l, r, b + 1, b + 1, ground[x][y])) {
            for (int i = l; i <= r; i++) {
                ground[b + 1][i] = ground[x][y];
            }
            b++;
        }  else {
            break;
        }
    }
}
int main() {
    scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        scanf("%d%d", &R, &C);
        for (int i = 1; i <= R; i++) {
            scanf("%s", ground[i] + 1);
        }
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                expand(i, j);
            }
        }
        // checking
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                int l = j, r = j, t = i, b = i;
                for (; t > 1 && ground[t - 1][j] == ground[i][j]; t --);
                for (; b < R && ground[b + 1][j] == ground[i][j]; b ++);
                for (; l > 1 && ground[i][l - 1] == ground[i][j]; l --);
                for (; r < C && ground[i][r + 1] == ground[i][j]; r ++);
                for (int x = t; x <= b; x++) {
                    for (int y = l; y <= r; y++) {
                        if (ground[x][y] != ground[i][j]) {
                            printf("-----------------------------------------\n");
                        }
                    }
                }    
            }
        }
        printf("Case #%d:\n", TT);
        for (int i = 1; i <= R; i++) {
            printf("%s\n", ground[i] + 1);
        }
    }
    return 0;
}
