#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(ll i = a; i < n; i++)
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
    ll x; cin >> x;
    if(x == 1){
        cout << "2" << endl;
        cout << "1 2" << endl;
        cout << "b g" << endl;
        return 0;
    }

    vector<ll> yakusu;
    rep(i, 2, 200000){
        if(x%i == 0) yakusu.push_back(i);
    }
    int m = (int)yakusu.size();

    vector<ll> p, q;
    ll sum_q = 0, sum_p = 200001;
    ll score_p = 200001, score_q = 0;
    auto f = [&](auto self, ll y, int pos=0) -> void {
        if(y == 1){
            if(score_p > score_q){
                p = q;
                sum_p = sum_q;
                score_p = score_q;
            }
            return;
        }
        // 4で割れるときは４で割るのが一番良い
        if(y%4 == 0){
            q.push_back(4);
            sum_q += 4;
            score_q += 5;
            self(self, y/4, pos);
            return;
        }

        rep(id, pos, m){
            ll i = yakusu[id];
            if(i > y || score_q+(i+1) >= score_p) break;
            if(y%i == 0){
                q.push_back(i);
                sum_q += i;
                score_q += i+1;
                self(self, y/i, id);
                q.pop_back();
                sum_q -= i;
                score_q -= i+1;
            }
        }
    };

    f(f, x);
    if(score_p > 200000LL){
        cout << -1 << endl;
        return 0;
    }
    int n = (int)p.size();
    cout << sum_p+n << endl;
    int adj = n+1;
    rep(i, 0, n){
        if(i > 0) cout << i << ' ' << i+1 << endl;
        rep(j, 0, p[i]){
            cout << i+1 << ' ' << adj++ << endl;
        }
    }
    rep(i, 0, n){
        cout << 'b' << ' ';
    }
    rep(i, 0, sum_p){
        cout << 'g' << ' ';
    }
    cout << endl;

    
    return 0;
}