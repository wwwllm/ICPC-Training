#include <bits/stdc++.h>
using namespace std;

// 双指针模板：
// for (int i = 1, j = 1; i <= n;i++){
//     while(j<=i&&check(j,i))j++
// }
const int N = 1e5 + 10;
int a[N], b[N];
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1, j = 1; i <= n; i++)
    {
        while (j <= i && b[a[i]])
        {
            b[a[j++]] = 0;
        }
        b[a[i]] = 1;
        ans = max(i - j + 1, ans);
    }
    cout << ans << endl;
    return 0;
}