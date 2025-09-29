#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 1e6;
bool visit[N];
int par[N], d[N]; 
vector<int> g[N];

void bfs(int s) {
	fill_n(visit, N, false);
	fill_n(d, N, -1); 
	fill_n(par, N, -1); 
	
	d[s] = 0; 
	visit[s] = true;
	queue<int> q; 
	q.push(s); 
	
	while (!q.empty()) {
		auto u = q.front(); 
		q.pop(); 
		
		for (auto v : g[u]) {
			if (!visit[v]) {
				d[v] = d[u] + 1; 
				par[v] = u; 
				visit[v] = true; 
				q.push(v);
			}
		}
	}
}

int main() {
	int n, m; 
	cin >> n >> m;
	
	while(m--) {
		int u, v; 
		cin >> u >> v; 
		
		g[u].push_back(v);
		g[v].push_back(u); 
	}
	
	bfs(1);
	cout << d[n] << endl;
	
	vector<int> path; 
	for(auto v = n; v != -1; v = par[v]) 
		path.push_back(v); 
	reverse(path.begin(), path.end()); 
	
	for (int& i : path) cout << i << " "; 
	return 0; 
}
