#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("PERMUTATION.INP", "r", stdin);
    freopen("PERMUTATION.OUT", "w", stdout); 
    
	int n;
    long long k; 
    cin >> n >> k;
    vector<int> a; 
    int n1 = n; 

    long long fa[20]; fa[0] = 1; 
    for(int i = 1; i <= 20; ++i) 
        fa[i] = fa[i - 1] * i;
    bool vis[n + 1] = {0}; 
    vector<int> v; 
    for(int i = 0; i <= n; ++i) v.push_back(i);  

    for(int i = 1; i <= n1; ++i) {
        int pos; 
        if(n > 20) {
            pos = 1;
            n = 20; 
        }
        else pos = (k - 1) / fa[n - i] + 1; 
        k = (k - 1) % fa[n - i] + 1;
        
        if(pos > v.size()) {
            cout << -1 << endl; 
            return 0; 
        }
        a.push_back(v[pos]); 
        v.erase(v.begin() + pos); 
    }
    for(const int i : a) cout << i << " "; 
    return 0; 
}
