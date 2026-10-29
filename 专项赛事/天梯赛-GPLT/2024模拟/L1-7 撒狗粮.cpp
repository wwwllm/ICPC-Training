#include <bits/stdc++.h>
using namespace std;

typedef pair<string, string> PSS;
typedef pair<int, string> PIS;
const int N = 5e4 + 10, M = 8e4 + 10;
PSS p[N];
unordered_map<string, int> mp, pos_mp;
int n, m;
string a[M];
bool b[M];
int sum[M];
priority_queue<PIS> h;
string ans[M];
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string a, b;
        cin >> a >> b;
        p[i] = {a, b};
        mp[a] = i, mp[b] = i;
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
        pos_mp[a[i]] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        if (b[i])
            continue;
        if (mp.find(a[i]) != mp.end())
        {
            int pos = mp[a[i]];
            string op;
            op = p[pos].first == a[i] ? p[pos].second : p[pos].first;
            if (pos_mp.find(op) != pos_mp.end())
            {
                int j = pos_mp[op];
                b[i] = 1, b[j] = 1;
                if (j == i + 1)
                {
                    sum[i - 1]++;
                    sum[i]--;
                    sum[j + 1]++;
                    sum[j + 2]--;
                }
                else if (j > i + 1)
                {
                    sum[i + 1]++;
                    sum[j]--;
                }
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        sum[i] += sum[i - 1];
        if (!b[i])
        {
            h.push({sum[i], a[i]});
        }
    }
    int maxx = h.top().first, top = 0;
    while (!h.empty())
    {
        auto [v, p] = h.top();
        if (v == maxx)
            ans[++top] = p;
        else
            break;
        h.pop();
    }
    while (top)
    {
        if (top == 1)
            cout << ans[top--];
        else
            cout << ans[top--] << ' ';
    }
    cout << endl;
    return 0;
}
