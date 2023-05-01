#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int a, b, c; cin >> a >> b >> c;
    if(c){
        if(b <= a) cout << "Takahashi" << endl;
        else cout << "Aoki" << endl;
    }else{
        if(b < a) cout << "Takahashi" << endl;
        else cout << "Aoki" << endl;
    }
    
    return 0;
}