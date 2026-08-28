#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int T; cin >> T;
    while(T--){
        string s; cin >> s;
        int n = (int)s.size();
        vector<int> cnt(26);
        rep(i, 0, n){
            cnt[s[i]-'a']++;
        }
        bool f = true;
        rep(j, 0, 26){
            if(cnt[j] > (n+1)/2){
                f = false;
            }
        }
        if(!f){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
            vector<int> ind(26);
            iota(ind.begin(), ind.end(), 0);
            sort(ind.begin(), ind.end(), [&](int i, int j){
                return cnt[i] > cnt[j];
            });
            vector<char> ans(n);
            vector<char> t;
            rep(i, 0, 26){
                int c = ind[i];
                rep(j, 0, cnt[c]) t.push_back('a'+c);
            }
            int id = 0;
            for(int i = 0; i < n; i += 2){
                ans[i] = t[id++];
            }
            for(int i = 1; i < n; i += 2){
                ans[i] = t[id++];
            }
            rep(i, 0, n){
                cout << ans[i];
            }
            cout << endl;
        }
    }
    
    return 0;
}