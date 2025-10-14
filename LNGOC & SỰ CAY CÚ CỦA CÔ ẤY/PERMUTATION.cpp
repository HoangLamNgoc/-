#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("PERMUTATION.INP", "r", stdin);
    freopen("PERMUTATION.OUT", "w", stdout);

    int n;
    long long k;
    cin >> n >> k;

    vector<long long> fact(21, 1);
    for (int i = 1; i <= 20; ++i)
        fact[i] = fact[i - 1] * i;

    vector<int> v;
    for (int i = 1; i <= n; ++i)
        v.push_back(i);

    vector<int> res;
    int n1 = n;
    for (int i = 1; i <= n1; ++i) {
        int rem = n - i;
        long long block = (rem > 20 ? fact[20] : fact[rem]);
        int pos = (k - 1) / block;
        k = (k - 1) % block + 1;

        if (pos >= (int)v.size()) {
            cout << -1;
            return 0;
        }

        res.push_back(v[pos]);
        v.erase(v.begin() + pos);
    }

    for (int x : res) cout << x << " ";
    return 0;
}
