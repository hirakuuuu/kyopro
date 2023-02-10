#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    vector<int> a(n);
    rep(i, 0, n){
        if(i == 0 and s[0] == 'R' and s[1] == 'R') a[0] = 1;
        else if(i == n-1 and s[n-2] == 'L' and s[n-1] == 'L') a[n-1] = 1;
        else if((s[i] == 'R' and s[i+1] == 'R') or (s[i] == 'L' and s[i-1] == 'L')) a[i] = 1;
    }

    int l = 0, r = 0;
    while(k > 0){



    }
    
    return 0;
}