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
// https://atcoder.jp/contests/abc178/tasks/abc178_f

int main(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    vector<int> cnt_a(n+1), cnt_b(n+1);
    rep(i, 0, n) cnt_a[a[i]]++;
    rep(i, 0, n) cnt_b[b[i]]++;

    rep(i, 1, n+1){
        if(cnt_a[i] + cnt_b[i] > n){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    vector<int> same;
    rep(i, 0, n){
        if(a[i] == b[i]) same.emplace_back(i);
    }

    int pos = 0;
    rep(i, 0, (same.size()+1)/2){
        pos = i;
        if(a[same[i]] != a[same[same.size()-1-i]]) swap(b[same[i]], b[same[same.size()-1-i]]);
        else break;
    }

    int tmp = n-1;
    rep(j, 0, n){
        if(a[j] != b[j]) continue;
        while(tmp >= 0){
            if(a[j] != a[tmp] && a[j] != b[tmp]){
                swap(b[j], b[tmp]);
                break;
            }
            tmp--;
        }
    }

    rep(i, 0, n){
        cout << b[i] << ' ';
    }
    cout << endl;



    
    return 0;
}