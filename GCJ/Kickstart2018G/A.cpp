#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int T, N;
int main() {
    scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        scanf("%d", &N);
        vector<int> nums(N);
        map<int, int> occur;
        for (int i = 0; i < N; i++) {
            int n;
            scanf("%d", &n);
            nums[i] = n;
            occur[n]++;
        }
        // sort(nums.begin(), nums.end());
        long long ans = 0;
        for (int i = 0; i < N; i++) {
            int y = nums[i];
            occur[y] --;
            for (int j = 0; j < i; j++) {
                // printf("i  = %d, j = %d\n", i , j);
                long long x = nums[j];
                if (x == 0 && y == 0) {
                    ans += N - i - 1;
                    continue;
                }
                set<int> s;
                if (x * y < 0x7fffffff) {
                    s.insert(x * y);
                }
                if (x != 0 && x <= y && y % x == 0) {
                    s.insert(y / x);
                }
                if (y != 0 && y <= x && x % y == 0) {
                    s.insert(x / y);
                }
                for (auto it = s.begin(); it != s.end(); it++) {
                    if (occur.count(*it)) {
                        ans += occur[*it];
                    // printf("s = %d, ans = %lld\n", *it, ans);
                    }
                }

                // printf("\n");
            }
        }
        printf("case #%d: %lld\n", TT, ans);
        cerr << TT << endl;
    }
    return 0;
}
