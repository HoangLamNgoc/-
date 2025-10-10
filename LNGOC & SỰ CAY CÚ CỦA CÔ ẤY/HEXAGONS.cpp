#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

const double EPS = 1e-9;

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    freopen("HEXAGONS.INP", "r", stdin);
    freopen("HEXAGONS.OUT", "w", stdout); 

    int n;
    cin >> n;
    string ans = ""; 

    while (n--) {
        int cnt = 0; 
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
        for (int i = 1; i < dist.size(); ++i) {
            if (fabs(dist[i - 1] - dist[i]) < EPS)
                ++cnt; 
        }

        double x = 0, y = 0;
        for (int i = 0; i < 6; ++i) {
            x += p[i].first;
            y += p[i].second;
        }
        x /= 6.0; y /= 6.0;

        double R = sqrt((p[0].first - x)*(p[0].first - x) + (p[0].second - y)*(p[0].second - y));
        bool ok = true;
        
        for (int i = 1; i < 6; ++i) {
            double r2 = sqrt((p[i].first - x)*(p[i].first - x) + (p[i].second - y)*(p[i].second - y));
            if (fabs(r2 - R) > EPS) {
                ok = false;
                break;
            }
        }
        if (cnt == 6 && ok) ans += "Y";
        else ans += "N";  
    }
    cout << ans << endl; 
    return 0;
}
