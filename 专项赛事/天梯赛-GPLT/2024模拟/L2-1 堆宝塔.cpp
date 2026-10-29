#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int b[N], a[N];
signed main(){
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int n;
    cin >> n;
    int ans=0,cnt=-1;
    int topa = 0, topb = 0;
    while(n--){
        int x;
        cin >> x;
        if(x<a[topa]||topa==0)
            a[++topa] = x;
        else{
            if(x>b[topb])
                b[++topb] = x;
            else{
                if(topa>0)
                    ans++,cnt=max(cnt,topa),topa=0;
                while(topb&&b[topb]>x){
                    a[++topa] = b[topb];
                    topb--;
                }
                a[++topa] = x;
            }
        }
    }
    if(topa>0)
        ans++, cnt = max(cnt, topa), topa = 0;
    if(topb>0)
        ans++, cnt = max(cnt, topb), topb = 0;
    cout << ans << ' ' << cnt;
    return 0;
}