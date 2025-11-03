#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 205;
vector<int> g[N];
int t[N];
int par[N];
int n, A, B;

bool bfs(int mid) {
    vector<bool> vis(n + 1, false);
    queue<int> q;
    q.push(A);
    vis[A] = true;
    par[A] = -1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (!vis[v] && abs(t[u] - t[v]) <= mid) {
                vis[v] = true;
                par[v] = u;
                q.push(v);
            }
        }
    }
    return vis[B];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("MOVE.INP", "r", stdin);
    freopen("MOVE.OUT", "w", stdout);

    cin >> n >> A >> B;
    for (int i = 1; i <= n; i++) cin >> t[i];

    int u, v;
    while (cin >> u >> v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int lo = 0, hi = 20000, ans = -1;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (bfs(mid)) {
            ans = mid;
            hi = mid - 1;
        } else lo = mid + 1;
    }

    if (ans == -1) {
        cout << -1;
        return 0;
    }

    bfs(ans);
    vector<int> path;
    for (int cur = B; cur != -1; cur = par[cur]) path.push_back(cur);
    reverse(path.begin(), path.end());

    cout << ans << '\n';
    for (int x : path) cout << x << ' ';
}
