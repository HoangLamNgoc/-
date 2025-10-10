#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

const double EPS = 1e-5;

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    freopen("HEXAGONS.INP", "r", stdin);
    freopen("HEXAGONS.OUT", "w", stdout); 

    int n;
    cin >> n;
    string ans = ""; 

    while (n--) {
        pair<double, double> p[6];
        vector<double> dist;

        for (int i = 0; i < 6; ++i)
            cin >> p[i].first >> p[i].second;

        for (int i = 0; i < 6; ++i) {
            for (int j = i + 1; j < 6; ++j) {
                double dx = p[i].first - p[j].first;
                double dy = p[i].second - p[j].second;
                dist.push_back(sqrt(dx * dx + dy * dy));
            }
        }

        sort(dist.begin(), dist.end());
        bool equal = true;
        for (int i = 1; i < 6; ++i)
            if (fabs(dist[i] - dist[0]) > EPS) equal = false;

        bool ok = true;
        for (int i = 12; i < 15; ++i)
            if (fabs(dist[i] - dist[14]) > EPS) ok = false;

        if (equal && ok) ans += "Y";
        else ans += "N";
    }

    cout << ans << endl;
    return 0;
}


/* cách lấy EPS 
- 1 -> 1000 : EPS = 1e-8
- 1e6 -> 1e9 : EPS = 1e-5 
- EPS ~ max(1e-9, 1e-12 * M) với M là constraints; 
*/
