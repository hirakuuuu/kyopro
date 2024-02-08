#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/arc170/tasks/arc170_a

int main(){
    int n; cin >> n;
    string s, t; cin >> s >> t;
    vector<int> ba, ab;
    set<int> sba, sab;
    rep(i, 0, n){
        if(s[i] == 'B' && t[i] == 'A'){
            ba.push_back(i);
            sba.insert(i);
        }
        if(s[i] == 'A' && t[i] == 'B'){
            ab.push_back(i);
            sab.insert(i);
        }
    }

    int ans = 0, l = 0;
    rep(i, 0, ba.size()){
        while(l < ab.size() && ab[l] < ba[i]) l++;
        if(l < ab.size()){
            ans++;
            sba.erase(ba[i]);
            sab.erase(ab[l]);
            l++;
        }
    }

    if(!sab.empty()){
        rep(i, 0, *sab.begin()){
            if(t[i] == 'A'){
                ans += sab.size();
                sab.clear();
                break;
            }
        }
        if(!sab.empty()){
            cout << -1 << endl;
            return 0;
        }
    }
    if(!sba.empty()){
        rrep(i, n-1, *sba.rbegin()+1){
            if(t[i] == 'B'){
                ans += sba.size();
                sba.clear();
                break;
            }
        }
        if(!sba.empty()){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    
    return 0;
}