#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

struct toado {
    int x, y; 
}; 

double area(const vector<toado> &p) {
    double S = 0;
    int n = p.size();
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        S += 1.0 * p[i].x * p[j].y - 1.0 * p[j].x * p[i].y;
    }
    return fabs(S) / 2.0;
}

bool cmp(const toado& a, const toado& b) {
    return (a.x < b.x) || (a.x == b.x && a.y > b.y); 
}

bool ccw(const toado& a, const toado& b,const toado& c) {
    long long S = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x); 
    return S <= 0; 
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    freopen("CONVEXHULL.INP", "r", stdin);
    freopen("CONVEXHULL.OUT", "w", stdout);

    int n; cin >> n; 
    vector<toado> p(n);
    for(int i = 0; i < n; ++i) cin >> p[i].x >> p[i].y;

    sort(p.begin(), p.end(), cmp); 
    vector<toado> hull;
    hull.push_back(p[0]);

    for (int i = 1; i < n; ++i) {
        while(hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), p[i])) {
            hull.pop_back();
        }
        hull.push_back(p[i]);
    }
    
    vector<toado> hull2; hull2.push_back(hull.back()); 
    hull.pop_back();
    for (int i = n - 2; i >= 0; --i) {
        while (hull2.size() >= 2 && ccw(hull2[hull2.size() - 2], hull2.back(), p[i])) {
            hull2.pop_back();
        }
        hull2.push_back(p[i]);
    }
    if (n > 1) hull2.pop_back(); 
    reverse(hull2.begin(), hull2.end()); 
    while(!hull2.empty()){
        hull.push_back(hull2.back()); 
        hull2.pop_back(); 
    }
    

    cout << hull.size() << endl; 
    cout << fixed << setprecision(1) << area(hull) << endl; 
    for(const toado& x : hull) cout << x.x << " " << x.y << endl;       
}
