#include <bits/stdc++.h>
#define int double
using namespace std;

int f(int a){
    return a * a * a;
}
signed main()
{
    int n;
    cin >> n;
    int l = -10000, r = 10000,mid;
    while(r-l>=1e-7){
        mid = (l + r) / 2;
        if(f(mid)<n)
            l = mid;
        else
            r = mid;
    }
    cout << fixed << setprecision(6) << l;
    return 0;
}