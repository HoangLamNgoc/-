#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("NBES.INP", "r", stdin); 
    freopen("NBES.OUT", "w", stdout); 
    int n;
    long long k;
    cin >> n >> k; 
  
    vector<long long> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());  

    multiset<long long> tails; 

    for (auto x : a) {
        auto it = tails.upper_bound(x - k);
        if (it == tails.begin()) {
            tails.insert(x);
        } else {
            --it;
            tails.erase(it);  
            tails.insert(x);
        }
    }

    long long ans = 0;
    for (auto v : tails) ans += v;
    cout << ans << '\n';
    return 0;
}
