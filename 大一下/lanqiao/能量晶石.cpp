#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    int n;
    cin >> n;
    int minx = 1e10, sum = 0;
    for (int i = 1; i <= n;i++){
        int x;
        cin >> x;
        minx = min(minx, x);
        sum += x;
    }
    cout << sum - minx * n << endl;
    return 0;
}