#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int T, N;
char nums[100000001];
int main() {
    scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        scanf("%d", &N);
        scanf("%s", nums);
        int l = (N + 1) / 2;
        int tans = 0;
        for (int i = 0; i < l; i++) {
            tans += nums[i] - '0';
        }
        int ans = tans;
        for (int i = l; i < N; i++) {
            tans += nums[i] - '0' - (nums[i - l]  - '0');
            ans = max(ans, tans);
        }
        printf("Case #%d: %d\n", TT, ans);
    }
    return 0;
}
