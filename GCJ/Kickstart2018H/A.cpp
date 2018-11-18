#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int T, N, P;
struct Node {
    int child[2];
    bool end;
    Node() {
        child[0] = 0;
        child[1] = 0;
        end = false;
    }
};
void add(vector<Node> &nodes, char str[]) {
    int root = 0;
    for (int i = 0; str[i]; i++) {
        int c = str[i] == 'R';
        if (nodes[root].child[c] == 0) {
            nodes[root].child[c] = nodes.size();
            nodes.push_back(Node());
        }
        root = nodes[root].child[c];
    }
    nodes[root].end = true;
}
long long counting(vector<Node> &nodes, int p, int depth) {
    if (nodes[p].end == true) {
        return 1ll << (N - depth);
    }
    long long ans = 0;
    for (int i = 0; i < 2; i++) {
        if (nodes[p].child[i] != 0) {
            ans += counting(nodes, nodes[p].child[i], depth + 1);
        }
    }
    return ans;

}
int main() {
    scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++) {
        scanf("%d%d", &N, &P);
        char str[51];
        vector<Node> nodes;
        nodes.push_back(Node());
        for (int p = 0; p < P; p++) {
            scanf("%s", str);
            add(nodes, str);
        }
        long long ans = (1ll << N) - counting(nodes, 0, 0);
        printf("Case #%d: %lld\n", TT, ans);
    }
    return 0;
}
