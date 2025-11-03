#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 
const int N = (int)1e5 + 5;
int n, m; 
bool vis[N];
vector<int> g[N]; 

void dfs(int u, int par = 0) {
    vis[u] = 1; 
    for(int v : g[u]) {
        if ( v == par ) continue; 
        if(!vis[v]) dfs(v, u); 
    }
}

void input() {
    cin >> n >> m; 

    for(int i = 1; i <= n; ++i) {
        int u; cin >> u; 

        while(u--) {
            int v; cin >> v; 
            g[i].emplace_back(v); 
        }
    }

    dfs(m); 
    vector<int> p; 
    for(int i = 1; i <= n; ++i) 
        if (vis[i]) p.emplace_back(i);
    sort(p.begin(), p.end());

    cout << p.size() << '\n'; 
    for(const int& i : p) cout << i << ' '; 
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    freopen("EBOLA.INP", "r", stdin); 
    freopen("EBOLA.OUT", "w", stdout);
     
    input(); 
    return 0; 
}
