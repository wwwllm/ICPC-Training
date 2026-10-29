#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n;
int a[N], dp[N], top = 0;
int find(int x)
{
    int l = 0, r = top + 1, mid;
    while (l + 1 != r)
    {
        mid = (l + r) >> 1;
        if (dp[mid] >= x)
            r = mid;
        else
            l = mid;
    }
    return r;
}
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp[++top] = a[1];
    for (int i = 2; i <= n; i++){
        if(a[i]>dp[top])
            dp[++top] = a[i];
        else
            dp[find(a[i])] = a[i];
    }
    cout << top << endl;
    return 0;
}