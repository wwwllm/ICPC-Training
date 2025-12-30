#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int st1[maxn], st2[maxn];
int top1 = 0, top2 = 0;
int n;
map<char, int> h{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}}; // 优先级
void eval()
{
    int a = st1[top1--];
    int b = st1[top1--];
    char p = st2[top2--];
    if (p == '+')
        st1[++top1] = b + a;
    if (p == '-')
        st1[++top1] = b - a;
    if (p == '*')
        st1[++top1] = b * a;
    if (p == '/')
        st1[++top1] = b / a;
}
int main()
{
    string s;
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (isdigit(s[i]))
        {
            int x = 0, j = i;
            while (j < s.size() && isdigit(s[j]))
            {
                x = x * 10 + s[j] - '0';
                j++;
            }
            st1[++top1] = x;
            i = j - 1;
        }
        else if (s[i] == '(')
        {
            st2[++top2] = '(';
        }
        else if (s[i] == ')')
        {
            while (st2[top2] != '(')
                eval();
            top2--;
        }
        else
        {
            while (top2 > 0 && h[st2[top2]] >= h[s[i]])
                eval();
            st2[++top2] = s[i];
        }
    }
    while(top2>0)
        eval();
    cout << st1[top1] << endl;
    return 0;
}