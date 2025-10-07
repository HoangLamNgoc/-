#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

struct toado {
    int x, y;
    int s = x * x + y * y; 
};

bool cmp (const toado& a, const toado& b) {
    return a.s <= b.s;
}

int main() {
    int n; cin >> n; 

    const int maxn = 1e4;
    toado a[maxn + 5], b[maxn + 5]; 

    for(int i = 1; i <= n; ++i) cin >> a[i].x >> a[i].y;     
    for (int i = 1; i <= n; ++i) cin >> b[i].x >> b[i].y; 

    sort(a + 1, a + n + 1, cmp); 
    sort(b + 1, b + n + 1, cmp); 

    int lo = 1; hi = n; 
    while(lo <= hi) {
      int mid = (lo + hi) / 2; 
      upper_bound(a + 1, a + n + 1, a[mid].s); 
      
