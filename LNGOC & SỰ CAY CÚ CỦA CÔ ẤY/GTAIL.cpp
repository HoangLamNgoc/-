#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 1e5 + 5;

vector<int> g[N]; 
int n, m;
int indeg[N]; 
int cnt = 0, ans = 0; 
bool vis[N]; 

void dfs(int u, int par = 0) {
    vis[u] = 1; 

    for (int i : g[u]) {
        if (i == par) continue; 
        if (indeg[i] == 2 && !vis[i]) {
            cnt++; 
            ans = max(ans, cnt); 
            dfs(i, u);
        }
    }
}

void input() {
    cin >> n >> m; 

    while(m--) {
        int u, v; 
        cin >> u >> v; 

        g[u].emplace_back(v);
        g[v].emplace_back(u);
        ++indeg[u];
        ++indeg[v]; 
    }

    for(int i = 1; i <= n; ++i) {
        if (indeg[i] == 1) {
            fill_n(vis, N, 0);
            cnt = 1;  
            dfs(i);
        }
    }  
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    freopen("GTAIL.INP", "r", stdin); 
    freopen("GTAIL.OUT", "w", stdout); 
    
    input(); 
    cout << ans << '\n'; 
    return 0; 
}
