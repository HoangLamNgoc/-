#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0); 

    freopen("CIRCLE.INP","r", stdin);
    freopen("CIRCLE.OUT","w", stdout); 

    int n; 
    cin >> n;

    const int maxn = 1e4;
    int sa[maxn + 5], sb[maxn + 5]; 

    for(int i = 1; i <= n; ++i) {
        int u, v; 
        cin >> u >> v; 
        sa[i] = u * u + v * v;
    }
    for(int i = 1; i <= n; ++i) {
        int u, v; 
        cin >> u >> v;
        sb[i] = u * u + v * v;
    }

    sort(sa + 1, sa + n + 1);
    sort(sb + 1, sb + n + 1);

    int i = 1;
    while(i <= n) {
        int maxv = max(sa[i], sb[i]);
        int minv = min(sa[i + 1], sb[i + 1]);
        if(maxv < minv) {
            cout << fixed << setprecision(6) << sqrt(max(sa[i], sb[i])) << endl;
            return 0;
        }
        else i++;
    }

    cout << fixed << setprecision(6) << sqrt(max(sa[n], sb[n])) << endl;
    return 0;
}
