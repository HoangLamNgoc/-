#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector> 

using namespace std; 

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    // freopen("FS.INP", "r", stdin);
    // freopen("FS.OUT", "w", stdout); 

    long long s; 
    cin >> s; 
    long long x = -1, y = -1; 

    for(long long i = 1; i * i <= s; ++i) {
        long long k = s - i * i; 
        if ((long long)k == (long long)sqrt(k) * (long long)sqrt(k)) {
            y = abs((long long)sqrt(k)); 
            x = i;
        }
    }

    if (x == -1 && y == -1) {
        cout << "Impossible" << '\n'; 
    }

    else {
        vector<pair<int,int>> path; 

        path.emplace_back(make_pair(0, x)); 
        path.emplace_back(make_pair(y, 0)); 
        path.emplace_back(make_pair(x + y, y)); 
        path.emplace_back(make_pair(x, x + y));

        sort(path.begin(), path.end()); 
        for(pair<int,int> i : path) cout << i.first << ' ' << i.second << '\n'; 
    }
}
