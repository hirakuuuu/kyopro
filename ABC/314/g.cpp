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

/*
各階層で最低いくつお守りがあれば到達できるかを求められればよい
この数列は広義単調増加
最後の階層から、順に求めていくと計算量が減りそう
*/

int main(){
    ll n, m, h; cin >> n >> m >> h;
    vector<ll> a(n), b(n);
    rep(i, 0, n){
        cin >> a[i] >> b[i];
        b[i]--;
    }

    multiset<ll> mi, mx;
    vector<ll> d(m);
    rep(i, 0, n) d[b[i]] += a[i];
    rep(i, 0, m) mx.insert(d[i]);
    ll sum_mi = 0;
    while(!mx.empty() && sum_mi+(*mx.begin()) < h){
        sum_mi += *mx.begin();
        mi.insert(*mx.begin());
        mx.erase(mx.begin());
    }
    vector<int> cnt(n); // 各階層にたどり着くために最低いくつのお守りが必要か.
    cnt[n-1] = (int)mx.size(); // mx に入っているタイプの敵はお守りで防ぐ必要がある.

    rrep(i, n-2, 0){
        // i+1 階層の分を除く
        if(!mx.empty() && *mx.begin() <= d[b[i+1]]){
            mx.erase(mx.find(d[b[i+1]]));
            d[b[i+1]] -= a[i+1];
            mx.insert(d[b[i+1]]);
            // mx.begin と mi.rbegin が逆転している場合は入れ替える
            if(!mi.empty() && (*mx.begin()) < (*mi.rbegin())){
                ll p1 = *mx.begin(), p2 = *mi.rbegin();
                mx.erase(mx.begin()), mi.erase(mi.find(p2));
                mx.insert(p2), mi.insert(p1);
                sum_mi -= p2;
                sum_mi += p1;
            }
        }else{
            mi.erase(mi.find(d[b[i+1]]));
            d[b[i+1]] -= a[i+1];
            mi.insert(d[b[i+1]]);
            sum_mi -= a[i+1];
        }
        // sum_mi <= h の間、お守りを減らす
        while(!mx.empty() && sum_mi+(*mx.begin()) < h){
            sum_mi += (*mx.begin());
            mi.insert(*mx.begin());
            mx.erase(mx.begin());
        }
        cnt[i] = (int)mx.size();
    }

    vector<int> ans(m+1);
    rep(i, 0, m+1){
        ans[i] = upper_bound(cnt.begin(), cnt.end(), i)-cnt.begin();
        cout << ans[i] << ' ';
    }
    cout << endl;


    
    return 0;
}