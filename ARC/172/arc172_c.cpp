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
// https://atcoder.jp/contests/arc172/taks/arc172_c

int main(){
    int n; cin >> n;
    string c; cin >> c;
    vector<vector<int>> cnt(n+1, vector<int>(2));
    string result;
    rep(i, 1, n+1){
        rep(j, 0, 2){
            cnt[i][j] = cnt[i-1][j];
            if(j == c[i%n]-'A') cnt[i][j]++;
        }
        if(cnt[i][0] > cnt[i][1]) result += 'A';
        if(cnt[i][0] < cnt[i][1]) result += 'B';
        if(cnt[i][0] == cnt[i][1]) result += 'C';
    }
    int ans = 1;
    rrep(i, n-1, 1){
        if(c[i] != c[0]){
            string cur = result.substr(i-1, 2);
            string tmp;
            rep(ii, i, i+2){
                rep(j, 0, 2){
                    cnt[ii][j] = cnt[ii-1][j];
                    if(ii == i && j == c[0]-'A') cnt[ii][j]++;
                    if(ii == i+1 && j == c[i]-'A') cnt[ii][j]++;
                }
                if(cnt[ii][0] > cnt[ii][1]) tmp += 'A';
                if(cnt[ii][0] < cnt[ii][1]) tmp += 'B';
                if(cnt[ii][0] == cnt[ii][1]) tmp += 'C';
            }
            if(cur != tmp){
                ans++;
                rep(ii, i-1, i+1) result[ii] = tmp[ii-i+1];
            }
        }
    }
    cout << ans << endl;
    return 0;
}