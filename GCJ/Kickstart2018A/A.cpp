#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int T;
long long N;
int main() {
    scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        cin >> N;
        long long n;

        long long up = 0;
        n = N;
        for (long long i = 1; i <= n; i *= 10) {
            if ((n / i) % 2 == 1) {
                long long d = ((n / i) + 1) * i - n;
                n += d;
                up += d;
            }
        }
        long long down = 0;
        n = N;
        long long head = 1;
        for (;head * 10 <= n; head *= 10);
        for (long long i = head; i >= 1; i /= 10) {
            if ((n / i) % 2 == 1) {
                down += n % i + 1;
                n -=  n % i + 1;
            }
        }
        printf("Case #%d: %lld\n", TT, min(up, down));
    }
    return 0;

}
