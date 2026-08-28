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
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
- suffix_array と lcp_array があるといろいろできる
    - lcp_array は suffix_array の隣接する接尾辞の共通接頭辞の長さ
*/

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<pair<int, int>> rle;
    for(int i = 0; i < n; ){
        int j = i;
        while(j < n && a[i] == a[j]){
            j++;
        }
        rle.emplace_back(a[i], j-i);
        i = j;
    }

    vector<int> b;
    for(auto [num, len]: rle){
        if(num > len){
            b.push_back(0);
        }else if(num == len){
            b.push_back(num);
        }else{
            b.push_back(num);
            b.push_back(0);
            b.push_back(num);
        }
    }

    // rep(i, 0, b.size()){
    //     cout << b[i] << ' ';
    // }
    // cout << endl;

    vector<int> sa = suffix_array(b);
    vector<int> lcp = lcp_array(b, sa);


    vector<ll> nz(b.size());
    for(int i = 0; i < b.size(); i++){
        if(b[i] == 0) continue;
        int j = i;
        while(j < b.size() && b[j] > 0) j++;
        rep(k, i, j){
            nz[k] = j-k;
        }
        i = j;
    }
    // rep(i, 0, b.size()){
    //     cout << sa[i] << ' ';
    // }
    // cout << endl;
    // rep(i, 0, b.size()-1){
    //     cout << lcp[i] << ' ';
    // }
    // cout << endl;
    // rep(i, 0, b.size()){
    //     cout << nz[sa[i]] << ' ';
    // }
    
    // cout << endl;

    ll ans = nz[sa[0]];
    rep(i, 1, b.size()){
        ll cnt = 0;
        if(nz[sa[i]] > lcp[i-1]) cnt = nz[sa[i]]-lcp[i-1];
        ans += cnt;
    }
    cout << ans << endl;

    return 0;
}