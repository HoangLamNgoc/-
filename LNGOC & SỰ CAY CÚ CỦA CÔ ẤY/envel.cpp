#include <iostream>
#include <algorithm>

using namespace std;
struct toado
{
    int x,y;
};

int main()
{
    freopen ("ENVEL.INP", "r" , stdin);
    freopen ("ENVEL.OUT", "w" , stdout);

    const int maxn = 1e6; 
    toado a[maxn + 5];

    int n =0;
    while (cin >> a[n].x >> a[n].y) ++n;
    if ( n == 0 ) return 0;
      int a1 = a[0].y, b1 = a[0].y, c1 = a[0].x, d1 = a[0].x;
      int xpt, xpd, xtt, xtd;  
      xpt = xpd = a[0].x- a[0].y;
      xtt = xtd = a[0].x + a[0].y;

    for (int i = 1; i < n; ++i) {
        a1 = max(a[i].y, a1);
        b1 = min(a[i].y, b1);
        c1 = max(a[i].x, c1);
        d1 = min(a[i].x, d1);

        int tong = a[i].x + a[i].y, hieu = a[i].x - a[i].y;

        xpt = min(hieu, xpt);
        xpd = max(hieu, xpd);
        xtt = max(tong, xtt);
        xtd = min(tong, xtd);
    }

    int bx = xpd+ b1, ay = b1, ax = xtd- b1;
    int cx = c1, cy = c1 - xpd, dy = xtt - c1;
  
    int ex = xtt - a1, ey = a1; fx = xpt + a1;
    int gy = d1 - xpt, gx = d1; hy = xtd - d1;
  
    cout<< ax << " " << ay << '\n';
    if( ax != bx ) cout << bx << " " << ay << '\n';

    if (bx != cx && ay != cy) cout << cx << " " << cy << '\n';
    if( cy != dy) cout << cx << " " << dy << '\n';
  
    if( cx != ex && dy != ey ) cout << ex << " " << ey << '\n';
    if( ex != fx ) cout << F_x << " " << ey << '\n';

    if ( fx != gx && ey != gx) cout << gx << " " << gy << '\n';
    if( gy != hy && ax != gx && ay != hy) cout << gx << " " << hy << '\n';

    return 0;
}
