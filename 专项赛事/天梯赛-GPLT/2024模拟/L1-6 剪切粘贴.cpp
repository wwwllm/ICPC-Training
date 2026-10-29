#include <bits/stdc++.h>
using namespace std;

string str;
int n;
signed main()
{
    cin >> str;
    cin >> n;
    while (n--)
    {
        int l, r;
        string q, p;
        cin >> l >> r >> q >> p;
        string x = str.substr(l - 1, r - l + 1);
        str = str.substr(0, l - 1) + str.substr(r);
        int len = str.length();
        int pos = -1;
        int L = len - q.length() - p.length();
        for (int i = 0; i <= L; i++)
        {
            if (str.substr(i, q.length()) == q && str.substr(i + q.length(), p.length()) == p)
            {
                pos = i + q.length() - 1;
                break;
            }
        }
        if (pos != -1)
            str = str.substr(0, pos + 1) + x + str.substr(pos + 1);
        else
            str = str + x;
    }
    cout << str << endl;
    return 0;
}