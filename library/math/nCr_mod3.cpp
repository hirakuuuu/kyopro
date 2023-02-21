#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
nCr%3の求め方：
f(n)：n が 3 で何回割れるか（f(117)=2,f(260)=0,f(729)=6）
g(n)：n を 3 の倍数でなくなるまで割ってできた整数を、3 で割った余り（例：g(117)=1,g(260)=2,g(729)=1）とする
f(n!)-f(r!)-f((n-r)!) > 0のとき：
・nCrは明らかに3の倍数なので余りは0.
f(n!)-f(r!)-f((n-r)!) = 0のとき：
・g(n!) = (g(r!)*g((n-r)!))%3ならば余り1.
・そうでないならば余り2.
*/


vector<ll> bf(400005), bg(400005);

void init(){
    rep(i, 1, 400005){
        int j = i;
        while(j%3 == 0){
            j /= 3;
            bf[i]++;
        }
        bg[i] = j%3;
    }
    bg[0] = 1;
    rep(i, 1, 400005) bf[i] += bf[i-1];
    rep(i, 1, 400005) bg[i] = (bg[i]*bg[i-1])%3;
}

ll nCr_mod3(ll n, ll r){
    if(bf[n] - bf[n-r] - bf[r] > 0) return 0;
    else{
        if(bg[n] == (bg[n-r]*bg[r])%3) return 1;
        else return 2;
    }
}

int main(){
    return 0;
}