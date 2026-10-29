#include<bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int q[maxn];
int hh = 0; 
int tt = -1; 
void push(int x)
{
    q[++tt] = x;
}
void pop()
{
    hh++;
}
void empty()
{
    if (tt >= hh)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}
void query()
{
    cout << q[hh] << endl;
}

int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        string s;
        cin >> s;
        if (s == "push")
        {
            int x;
            cin >> x;
            push(x);
        }
        if (s == "pop")
        {
            pop();
        }
        if (s == "empty")
        {
            empty();
        }
        if (s == "query")
        {
            query();
        }
    }
}