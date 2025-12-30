#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const string t = "<censored>";
string s[N];
int n;
string ans;
signed main()
{
    cin >> n;
    cin.ignore();
    for (int i = 1; i <= n; i++)
        getline(cin, s[i]);
    int k;
    cin >> k;
    string str;
    int res = 0;
    cin.ignore();
    getline(cin, str);
    int len = str.length();
    for (int j = 1; j <= n; j++)
    {
        int l = s[j].length();
        string ans = "";
        for (int i = 0; i < len; i++)
        {
            if (str[i] == '<')
                if (str.substr(i, t.length()) == t)
                    ans += t, i += t.length();
            if (i + l <= len && str.substr(i, l) == s[j])
            {
                res++;
                ans = ans + t;
                i += l;
            }
            ans += str[i];
        }
        str = ans;
        len = str.length();
    }
    if (res >= k)
        cout << res << endl
             << "He Xie Ni Quan Jia!" << endl;
    else
        cout << str << endl;
    return 0;
}