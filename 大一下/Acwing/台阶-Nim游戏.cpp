#include <bits/stdc++.h>
using namespace std;

// nim先手必胜：当且仅当a1^a2a^a3^a4……^an!=0
signed main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if(i&1)ans ^= x;
    }
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}