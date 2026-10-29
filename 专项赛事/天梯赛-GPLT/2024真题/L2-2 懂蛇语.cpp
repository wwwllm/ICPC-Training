#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 1e3 + 10;
int n, m;
vector<string> g[N];
map<string, int> mp;
signed main()
{
    cin >> n;
    int top = 0;
    cin.ignore();
    for (int i = 1; i <= n; i++)
    {
        string s;
        getline(cin, s);
        string p = "";
        p += s[0];
        int len = s.size();
        for (int i = 1; i < len; i++)
        {
            if (s[i] == ' ')
            {
                while (s[i] == ' ' && i < len)
                    i++;
                if (i < len)
                    p += s[i];
            }
        }
        if (mp.find(p) == mp.end())
        {
            mp[p] = ++top;
            g[top].push_back(s);
        }
        else
        {
            g[mp[p]].push_back(s);
        }
    }
    for (int i = 1; i <= top; i++)
    {
        sort(g[i].begin(), g[i].end());
    }
    cin >> m;
    cin.ignore();
    while (m--)
    {
        string s;
        getline(cin, s);
        string p = "";
        p += s[0];
        int len = s.size();
        for (int i = 1; i < len; i++)
        {
            if (s[i] == ' ')
            {
                while (s[i] == ' ' && i < len)
                    i++;
                if (i < len)
                    p += s[i];
            }
        }
        if (mp.find(p) == mp.end())
        {
            cout << s << endl;
            continue;
        }
        int pos = mp[p];
        cout << g[pos][0];
        len = g[pos].size();
        for (int i = 1; i < len; i++)
            cout << '|' << g[pos][i];
        cout << endl;
    }
    return 0;
}