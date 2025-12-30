#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 2e5 + 10;
vector<array<int, 4>> a; //{s,t,w}
int n;
int ans[N];
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int s, t, w;
        cin >> w >> s >> t;
        a.push_back({s, t, w, i});
    }
    sort(a.begin(), a.end(), [](const array<int, 4> &a, const array<int, 4> &b)
         { return a[0] < b[0]; });
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    for (int i = 0; i < n; i++)
    {
        while (heap.size())
        {
            auto [w, t] = heap.top();
            if (t <= a[i][0])
                heap.pop();
            else
                break;
        }
        if (heap.empty())
            ans[a[i][3]] = 0;
        else
        {
            auto [w, t] = heap.top();
            ans[a[i][3]] = max(0, a[i][2] - w);
        }
        heap.push({a[i][2], a[i][1]});
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}