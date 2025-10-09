// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

bool cleft(int a[], int n) {
    if (n == a[0]) return false; 
    return true; 
}

bool cright(int a[], int t, int n) {
    if(n == a[t]) return false; 
    return true; 
}

int main() {
    ios_base::sync_with stdio(0); 
    cin.tie(0); cout.tie(0); 

    freopen("COMPUTING.INP", "r", stdin); 
    freopen("COMPUTING.OUT", "w", stdout); 
    
	int n, k; 
    cin >> n >> k; 

    int a[n], prefix[n + 1]; 
    prefix[0] = 0;
    int best = INT_MAX,w = 0;  
    long long sum, dem, cnt; 
    sum = dem = cnt = 0; 

    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        dem = max(dem, (long long)a[i]); 
        prefix[i + 1] = prefix[i] + a[i];
    } 
    for(int& i : prefix) cout << i << " "; 
    cout << endl; 
    cout << dem << endl;
    if (k == 0) 
        cout << sum << endl; 
    else {
        long long ans = 0; 
        for(int i = 0; i < n; ++i) {
            if (a[i] == dem) { 
                int k1 = min(i + k, n - 1);
                cout << k1 << " "; 
                int j = max(i - k, 0);
                cout << j << endl;  
                if (prefix[k1 + 1] - prefix[j] < best) {
                    best = prefix[k1 + 1] - prefix[j];
                    w = k1 - j + 1;
                    ans = max(ans, w * a[i] + sum - best);
                }  
            }
        }
        cout << ans << endl; 
    }
    return 0; 
}
