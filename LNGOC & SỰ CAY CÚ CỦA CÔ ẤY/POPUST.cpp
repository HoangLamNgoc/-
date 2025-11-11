#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    freopen("POPUST.INP", "r", stdin); 
    freopen("POPUST.OUT", "w", stdout); 
    
    int n; 
    cin >> n; 

    pair<int,int> a[n + 1]; 

    for(int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second; 
    } 
    sort(a + 1, a + n + 1); 

    long long dp[n + 1][2];  
    dp[1][1] = a[1].first;
    dp[1][0] = a[1].second; 

    for(int i = 2; i <= n; ++i) {
        int u = a[i].first; 
        int v = a[i].second; 

        dp[i][1] = min(dp[i - 1][0] + u, dp[i - 1][1] + v);
        dp[i][0] = dp[i - 1][0] + v;  
    }

    bool ok = 0; 
    for(int i = 1; i <= n; ++i) {
        cout << dp[i][1] << '\n'; 
    }
}
