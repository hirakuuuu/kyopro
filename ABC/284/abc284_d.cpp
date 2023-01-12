#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc284/tasks/abc284_d
vector<int> erat(3000005);
vector<ll> p_list;
void init_e(){
    rep(i, 2, 3000005){
        if(erat[i] == 0){
            p_list.push_back(i);
            for(int j = i; j <= 3000005; j += i){
                if(erat[j] == 0) erat[j] = i;
            }
        }
    }
}


int main(){
    init_e();
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll p, q;
        for(auto &pp: p_list){
            if(n%(pp*pp) == 0){
                p = pp;
                n /= pp*pp;
                cout << p << ' ' << n << endl;
                break;
            }else if(n%pp == 0){
                q = pp;
                n /= pp;
                cout << (ll)sqrt(n) << ' ' << q << endl;
                break;
            }
        }
    }
    
    return 0;
}