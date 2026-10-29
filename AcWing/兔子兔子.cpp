#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
const int N = 1e6 + 10;
const ULL P = 131;
char str[N];
int n;
ULL p[N],h[N];
ULL get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}
signed main(){
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    cin >> str+1;
    cin >> n;
    p[0] = 1, h[0] = 0;
    int len = strlen(str + 1);
    for (int i = 1; i <= len; i++)
    {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i];
    }
    while(n--){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        cout << (get(l1, r1) == get(l2, r2) ? "Yes" : "No") << endl;
    }
        return 0;
}