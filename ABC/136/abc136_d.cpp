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
// https://atcoder.jp/contests/abc136/tasks/abc136_d

int main(){
    string s; cin >> s;
    int n = s.size();
    vector<int> cnt(n), l(n), r(n);
    int pl = n-1, pr = 0;
    rep(i, 0, n){
        if(s[i] == 'L') l[i] = pr;
        else pr = i;
    }    
    rrep(i, n-1, 0){
        if(s[i] == 'R') r[i] = pl;
        else pl = i;
    }
    rep(i, 0, n){
        if(s[i] == 'L'){
            if((i-l[i])%2 == 0) cnt[l[i]]++;
            else cnt[l[i]+1]++;
        }else{
            if((r[i]-i)%2 == 0) cnt[r[i]]++;
            else cnt[r[i]-1]++;
        }
    }

    rep(i, 0, n){
        cout << cnt[i] << ' ';
    }
    cout << endl;
    
    return 0;
}