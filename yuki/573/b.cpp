#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<int> c(n);
    rep(i, 0, n){
        cin >> c[i];
    }
    if(n%2 == 1){
        sort(c.begin(), c.end());
        mint ans = mint(c[0])*mint(10).pow(n/2);
        mint ten = 1;
        rrep(i, n/2, 1){
            ans += ten*c[i];
            ten *= 10;
        }
        rrep(i, n-1, n/2+1){
            ten /= 10;
            ans -= ten*c[i];
        }
        cout << ans.val() << endl;
    }else{
        vector<int> cnt(10);
        rep(i, 0, n) cnt[c[i]]++;
        vector<int> p;
        rep(i, 1, 10){
            if(cnt[i]%2 == 1) p.push_back(i);
        }
        int ans = IINF;
        {
            vector<int> q = p;
            int m = (int)q.size();
            do{
                int x = 0, y = 0;
                int ten = 1;
                rep(i, 0, m/2){
                    x += ten*q[i];
                    ten *= 10;
                }
                rep(i, m/2, m){
                    ten /= 10;
                    y += ten*q[i];
                }
                chmin(ans, abs(x-y));
            }while(next_permutation(q.begin(), q.end()));
        }
        rep(a, 1, 10){
            if(cnt[a]%2 == 1) continue;
            if(cnt[a] == 0) continue;
            vector<int> q = p;
            rep(_, 0, 2) q.push_back(a);
            int m = (int)q.size();
            do{
                int x = 0, y = 0;
                int ten = 1;
                rep(i, 0, m/2){
                    x += ten*q[i];
                    ten *= 10;
                }
                rep(i, m/2, m){
                    ten /= 10;
                    y += ten*q[i];
                }
                chmin(ans, abs(x-y));
            }while(next_permutation(q.begin(), q.end()));
        }

        if(p.empty()) ans = 0;
        cout << ans << endl;
    }
   
    
    return 0;
}