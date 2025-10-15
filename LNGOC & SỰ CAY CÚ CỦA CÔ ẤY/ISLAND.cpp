#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    freopen("ISLAND.INP", "r", stdin); 
    freopen("ISLAND.OUT", "w", stdout); 
    int n; cin >> n; 

    int a[n]; 
    for(int& i : a) cin >> i; 

    vector<pair<int,int>> v; 
    for(int i = 0; i < n - 1; ++i) {
        if(i == 0 && a[i] < a[i + 1]) v.push_back({a[i], 1}); 
        if(i == 0 && a[i] > a[i + 1]) v.push_back({a[i], -1}); 
        if(i != 0 && a[i] < a[i - 1] && a[i] < a[i + 1]) v.push_back({a[i], 1});
        if(i != 0 && a[i] > a[i - 1] && a[i] > a[i + 1]) v.push_back({a[i], -1});     
    }

    sort(v.begin(), v.end());
    for (int i = 1; i < (int)v.size(); ++i) {
        if (v[i].first == v[i - 1].first)
            v[i].second += v[i - 1].second, v[i - 1].second = 0;
    }
  
    int dem = 1, maxval = 1, m = v.size();  
    for(int i = 0; i < m; ++i) {
        dem += v[i].second;
        maxval = max(maxval, dem);  
    } 

    cout << maxval << endl; 
    return 0;
}
