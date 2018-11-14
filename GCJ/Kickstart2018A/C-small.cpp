#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Word {
    char s, e;
    int count[26], len;
};
char tmpstr[100000 + 1];
char sentence[1000000 + 1];
int psum[1000000 + 1][26];
int main() {
    int T, L, N, A, B, C, D;
    scanf("%d", &T);
    vector<Word> words;
    for (int TT = 1; TT <= T; TT++) {
        scanf("%d", &L);
        words.resize(L);
        // read dictionary
        for (int i = 0; i < L; i++) {
            scanf("%s", tmpstr);
            int len = 1;
            fill(words[i].count, words[i].count + 26, 0);
            for (; tmpstr[len]; len++) {
                words[i].count[tmpstr[len] - 'a'] ++;
            }
            words[i].s = tmpstr[0] - 'a';
            words[i].count[tmpstr[len - 1] - 'a'] --;
            words[i].e = tmpstr[len - 1] - 'a';
            words[i].len = len;
        }
        //read sentence
        scanf("%s", sentence + 1);
        scanf("%s", sentence + 2);
        scanf("%d%d%d%d%d", &N, &A, &B, &C, &D);
        {
            long long a = sentence[1];
            long long b = sentence[2];
            sentence[1] -= 'a';
            sentence[2] -= 'a';
            int c;
            for (int i = 3; i <= N; i++) {
                c =  ( A * b + B * a + C ) % D;
                sentence[i] = c % 26;
                a = b;
                b = c;
            }
        }
        memset(psum[0], 0, sizeof(psum));
        for (int i = 1; i <= N; i++) {
            // printf("%c", sentence[i] + 'a');
            for (int j = 0; j < 26; j++) {
                psum[i][j] = psum[i - 1][j];
            }
            psum[i][int(sentence[i])] ++;
        }
        // printf("\n");
        // scan
        vector<bool> exist(L, 0);
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < L; j++) {
                Word &w = words[j];
                if (exist[j] || w.len > i || w.e != sentence[i] || w.s != sentence[i - w.len + 1]) {
                    continue;
                }
                bool ex = true;
                for (int k = 0; k < 26; k++) {
                    if (psum[i - 1][k] - psum[i - w.len + 1][k] != w.count[k]) {
                        ex = false;
                        break;
                    }
                }
                exist[j] = ex | exist[j];
            }
        }
        int ans = 0;
        for (size_t i = 0; i < exist.size(); i++) {
            ans += exist[i];
        }
        printf("Case #%d: %d\n", TT, ans);
    }
    return 0;
}
