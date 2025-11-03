#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = (int)1e5 + 5;
vector<int> g[N];
long long dp[N], val[N];
bool vis[N];

void dfs(int u, int par = 0) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (v == par) continue;

        if (!vis[v]) {
            if (val[v] < dp[u]) {
                dp[v] = max(dp[v], dp[u]);
            } else {
                dp[v] = max(dp[v], dp[u] / 2);
            }
            dfs(v, u);
        } else {
            dp[v] = max(dp[v], (dp[u] > val[v]) ? dp[u] : dp[u] / 2);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    freopen("ARMY.OUT", "r", stdin); 
    freopen("ARMY.INP", "w", stdout); 
    
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    fill_n(dp, N, 0);
    cin >> dp[1];

    for (int i = 1; i <= n; ++i)
        cin >> val[i];

    if (val[1] > dp[1])
        dp[1] /= 2;

    dfs(1);

    cout << dp[n] << '\n';
}
