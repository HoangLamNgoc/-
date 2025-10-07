#include <iostream>
#include <map> 

using namespace std; 

int main() {
    freopen("TRICOUNT.INP", "r" , stdin); 
    freopen("TRICOUNT.OUT", "w", stdout); 
  
    int n; cin >> n; 
    map<int, int> x, y;

    while (n--) {
        int i, j; 
        cin >> i >> j; 
        ++x[i], ++y[i];
    }

    long long dem = 0; 
    for (auto it = x.begin(); it != x.end(); ++it) 
        dem += it->second - 1; 

    for (auto it = y.begin(); it != y.end(); ++it) 
        dem += it->second - 1; 

    cout << dem << endl; 
    return 0; 
}
