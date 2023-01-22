#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/arc154/tasks/arc154_c

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n), b(n);
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, n) cin >> b[i];

        if(a == b){
            cout << "Yes" << endl;
        }else{
            vector<int> c;
            c.push_back(b[0]);
            rep(i, 1, n){
                if(c.back() != b[i]) c.push_back(b[i]);
            }
            if(c.size() >= 2 and c.back() == c[0]) c.pop_back();

            if((int)c.size() == n){
                cout << "No" << endl;
            }else{
                int p = 0;
                rep(s, 0, n){
                    p = 0;
                    rep(i, 0, (int)c.size()){
                        while(p < n and a[(p+s)%n] != c[i]) p++;
                    }
                    if(p < n){
                        break;
                    }
                }
                if(p < n) cout << "Yes" << endl;
                else cout << "No" << endl;
            }
        }

    }
    
    return 0;
}