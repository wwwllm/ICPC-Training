#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
vector<int> h[N];
void insert(int x)
{
    int p = (x % N + N) % N;
    h[p].push_back(x);
}
bool find(int x)
{
    int p = (x % N + N) % N;
    for (auto it : h[p])
    {
        if (it == x)
            return 1;
    }
    return 0;
}
signed main()
{
    int n;
    cin >> n;
    while (n--)
    {
        char op;
        int x;
        cin >> op >> x;
        if(op=='I')
            insert(x);
        else
            cout << (find(x) ? "Yes" : "No") << endl;
    }
    return 0;
}