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

int main(){
    string s; cin >> s;
    string t; cin >> t;
    s += '.';
    t += '.';
    vector<pair<char, int>> S, T;
    for(int i = 0; i < s.size()-1; i++){
        int cnt = 1, j = i;
        while(i < s.size()-1 && s[i] == s[i+1]){
            cnt++;
            i++;
        }
        S.push_back({s[j], cnt});
    }
    for(int i = 0; i < t.size()-1; i++){
        int cnt = 1, j = i;
        while(i < t.size()-1 && t[i] == t[i+1]){
            cnt++;
            i++;
        }
        T.push_back({t[j], cnt});
    }
    
    bool f = S.size() == T.size();
    if(f){
        rep(i, 0, S.size()){
            auto [cs, ns] = S[i];
            auto [ct, nt] = T[i];
            if(cs != ct) f = false;
            if(ns == 1 && nt > 1) f = false;
            if(ns > nt) f = false;
        }
    }
    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}