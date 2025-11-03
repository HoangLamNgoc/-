#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 2e5 + 5;
vector<int> g[N];
long long dp[N], val[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("ARMY.INP", "r", stdin); 
    freopen("ARMY.OUT", "w", stdout); 

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    long long s;
    cin >> s;
    for (int i = 1; i <= n; ++i)
        cin >> val[i];

    fill(dp, dp + n + 1, -1);
    dp[1] = (val[1] > s ? s / 2 : s);

    priority_queue<pair<long long, int>> pq;
    pq.push({dp[1], 1});

    while (!pq.empty()) {
        auto [e, u] = pq.top();
        pq.pop();

        if (e < dp[u]) continue; 

        for (int v : g[u]) {
            long long next = (e > val[v]) ? e : e / 2;
            if (next > dp[v]) {
                dp[v] = next;
                pq.push({next, v});
            }
        }
    }

    cout << dp[n] << "\n";
}
