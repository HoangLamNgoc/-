#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); a
    cin.tie(0); cout.tie(0); 

    freopen("STRESS.INP", "r", stdin); 
    freopen("STRESS.OUT", "w", stdout); 
    
    int n; cin >> n; 
    int m = 2 * n; 
    vector<int> v; 

    while (m > 0) {
        if (m % 2 == 0) m /= 2; 
        else {
            v.push_back(n); 
            --m;
        }
        --n;
    }

    reverse(v.begin(), v.end());
    cout << v.size() << endl; 
    for(const int& i : v ) cout << i << " ";
    return 0; 
}
