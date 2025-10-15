#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct point {
    int x,y; 
};

bool ccw(const point& a,const point& b, const point& c) {
    long double S = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x); 
    if (S <= 0) return true; 
    return false; 
}

long double area(vector<point> p) {
    long double S = 0; 
    int n = p.size(); 

    for(int i = 0; i < n; ++i) {
        int j = (i + 1) % n; 
        S += 1.0 * p[i].x * p[j].y - 1.0 * p[i].y * p[j].x; 
    }

    return fabs(S) / 2.0; 
}

bool cmp(const point& a, const point& b) {
    return (a.x < b.x) || (a.x == b.x && a.y < b.y); 
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    freopen("CONVEXHULL.INP", "r", stdin); 
    freopen("CONVEXHULL.OUT", "w", stdout); 
    int n; 
    cin >> n; 
    
    vector<point> p(n); 
    for(int i = 0; i < n; ++i) cin >> p[i].x >> p[i].y; 
    sort(p.begin(), p.end(), cmp);

    vector<point> up, lo;  
    for(int i = 0; i < n; ++i) {
        while (up.size() >= 2 && ccw(up[up.size() - 2], up.back(), p[i])) {
            up.pop_back(); 
        }
        up.push_back(p[i]); 
    }

    for(int i = n - 1; i >= 0; --i) {
        while (lo.size() >= 2 && ccw(lo[lo.size() - 2], lo.back(), p[i])) {
            lo.pop_back(); 
        }
        lo.push_back(p[i]); 
    }

    if(!up.empty()) up.pop_back(); 
    if(!lo.empty()) lo.pop_back(); 

    vector<point> hull = up; 
    for(point& i : lo) hull.push_back(i); 

    cout << hull.size() << '\n'; 
    cout << fixed << setprecision(1) << area(hull) << '\n'; 
    for(point& i : hull) cout << i.x << ' ' << i.y << '\n'; 
    return 0; 
}
