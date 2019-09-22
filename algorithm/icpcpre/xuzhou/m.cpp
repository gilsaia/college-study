#include <cstdio>
#include<queue>
#include<algorithm>
#include<iostream>

using namespace std;
char s[1000200], t[1000200];
int n, m;

queue<int> C[26];

int main() {
    scanf("%d%d", &n, &m);
    scanf("%s%s", s, t);
    for (int i = 0; i < n; i++) {
        C[s[i] - 'a'].push(i);
    }
    int now = 0;
    int ans = 0;
    for (int f = 0; f < m; f++) {
        int l, v;
        v = n + 1;
        l = 0;
        int flag = 0;
        for (int i = t[f] - 'a' + 1; i < 26; i++) {
            while (!C[i].empty() && C[i].front() < now) C[i].pop();
            if (C[i].empty()) continue;
            if (v > C[i].front()) {
                v = C[i].front();
                l = i;
            }
            flag = 1;
        }

        if (l > t[f] - 'a') {
            ans = max(ans, f + n - v);
        }
        while (!C[s[f] - 'a'].empty() && now > C[s[f] - 'a'].front()) C[s[f] - 'a'].pop();
        if (C[s[f] - 'a'].empty() && flag == 0) {
            cout << "-1" << endl;
            exit(0);
        }
        now = C[s[f] - 'a'].front();
    }
    ans = max(ans, m + n - 1 - now);
    if (ans == m&&now==(n-1)) cout << "-1" << endl;
    else cout << ans << endl;

    return 0;
}