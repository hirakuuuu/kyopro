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
// https://atcoder.jp/contests/abc324/tasks/abc324_c

int main(){
    int n; cin >> n;
    string t; cin >> t;

    vector<int> ans;
    rep(i, 0, n){
        string s; cin >> s;
        if(s.size() == t.size()){
            int cnt = 0;
            rep(j, 0, s.size()){
                cnt += (s[j] != t[j]);
            }
            if(cnt <= 1) ans.push_back(i+1);
        }else if(s.size() == t.size()-1){
            int j_ = 0, cnt = 0;
            for(int j = 0; j_ < t.size() && j<s.size(); j++){
                if(s[j] != t[j_]){
                    cnt++;
                    j--;
                }
                j_++;
            }

            if(cnt <= 1) ans.push_back(i+1);
        }else if(s.size() == t.size()+1){
            int j_ = 0, cnt = 0;
            for(int j = 0; j_ < s.size() && j<t.size(); j++){
                if(t[j] != s[j_]){
                    cnt++;
                    j--;
                }
                j_++;
            }
            if(cnt <= 1) ans.push_back(i+1);
        }
    }

    cout << ans.size() << endl;
    for(auto aa: ans){
        cout << aa << ' ';
    }
    cout << endl;
    
    return 0;
}