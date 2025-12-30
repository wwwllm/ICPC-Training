#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct ch{
    char c;
    int num;
};
const int maxn = 2e5 + 50;
ch arr[maxn];
int p0[maxn], p1[maxn],top0,top1;
void solve()
{
    int n;
    cin >> n;
    int ans = 1;
    int top = 0;
    top1 = 0, top0 = 0;
    for (int i = 1; i <= n;i++)
        cin >> arr[i].c;
    for (int i = 1; i <= n;i++){
        if(arr[i].c=='0'){
            if(top1==0){
                top++;
                p0[++top0] = top;
                arr[i].num = top;
            }else{
                int j = p1[top1--];
                arr[i].num = j;
                p0[++top0] = j;
            }
        }
        if (arr[i].c == '1')
        {
            if (top0 == 0)
            {
                top++;
                p1[++top1] = top;
                arr[i].num = top;
            }
            else
            {
                int j = p0[top0--];
                arr[i].num = j;
                p1[++top1] = j;
            }
        }
    }
    cout << top << endl;
    for (int i = 1; i <= n;i++){
        cout << arr[i].num << ' ';
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}