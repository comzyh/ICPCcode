#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unsigned count_hash(int count[26]) {
    unsigned res = 0;
    for (int i = 0; i < 26; i++) {
        res = res * 43 + count[i];
    }
    return res << 10;
}
struct Word {
    int count[26], index;
};
char tmpstr[100000 + 1];
char sentence[1000000 + 1];
int main() {
    int T, L, N, A, B, C, D;
    scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        scanf("%d", &L);
        unordered_map<int, unordered_multimap<unsigned, Word> > wordmap; // [length][hash + s * 26 + e]
        // read dictionary
        for (int i = 0; i < L; i++) {
            scanf("%s", tmpstr);
            Word word;
            word.index = i;
            int len = 1;
            fill(word.count, word.count + 26, 0);
            for (; tmpstr[len]; len++) {
                word.count[tmpstr[len] - 'a'] ++;
            }
            word.count[tmpstr[len - 1] - 'a'] --;
            unsigned s = tmpstr[0] - 'a', e = tmpstr[len - 1] - 'a';
            wordmap[len].insert(make_pair(count_hash(word.count) + s * 26 + e, word));
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
        // scan
        vector<bool> exist(L, 0);
        for (auto lit = wordmap.begin(); lit != wordmap.end(); lit ++) {
            int len = lit->first;
            // printf("len = %d\n", len);
            auto &hashtable = lit->second;
            int count[26];
            fill(count, count + 26, 0);
            for (int i = 1; i < len; i++) {
                count[int(sentence[i])] ++;
            }
            for (int i = 1; i + len - 1 <= N; i++ ) {
                count[int(sentence[i])] --;
                unsigned hash = count_hash(count) + sentence[i] * 26 + sentence[i + len - 1];
                auto range = hashtable.equal_range(hash);
                for (auto it = range.first; it != range.second; it ++) {
                    if (exist[it->second.index]) {
                        continue;
                    }
                    bool ex = true;
                    for (int j = 0; j < 26; j++) {
                        if (it->second.count[j] != count[j]) {
                            ex = false;
                            break;
                        }
                    }
                    if (ex) {
                        // printf("index = %d\n", it->second.index);
                        exist[it->second.index] = true;
                    }
                }
                count[int(sentence[i + len - 1])] ++;
            }
        }
        // result
        int ans = 0;
        for (size_t i = 0; i < exist.size(); i++) {
            ans += exist[i];
        }
        printf("Case #%d: %d\n", TT, ans);
    }
    return 0;
}
