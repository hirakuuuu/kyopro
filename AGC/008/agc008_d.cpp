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
// https://atcoder.jp/contests/agc008/tasks/agc008_d

int main(){
    int n; cin >> n;
    vector<int> x(n);
    rep(i, 0, n){
        cin >> x[i];
        x[i]--;
    }
    vector<int> ans(n*n);
    rep(i, 0, n){
        ans[x[i]] = i+1;
    }

    vector<pair<int, int>> px(n);
    rep(i, 0, n){
        px[i] = {x[i], i};
    }
    sort(px.begin(), px.end());
    int cnt = 0, l = 0;
    rep(i, 0, n){
        if(i) cnt += px[i].first-px[i-1].first-1;
        else cnt += px[0].first;
        if(cnt < px[i].second){
            cout << "No" << endl;
            return 0;
        }
        int rest = px[i].second;
        rep(j, l, n*n){
            if(!rest) break;
            if(ans[j]) continue;
            ans[j] = px[i].second+1; 
            rest--;
            l++;
        }
        cnt -= px[i].second;
    }
    cnt = 0;
    int r = n*n-1;
    rrep(i, n-1, 0){
        if(i != n-1) cnt += px[i+1].first-px[i].first-1;
        else cnt += n*n-px[n-1].first-1;
        if(cnt < n-1-px[i].second){
            cout << "No" << endl;
            return 0;
        }
        int rest = n-1-px[i].second;
        rrep(j, r, 0){
            if(!rest) break;
            if(ans[j]) continue;
            ans[j] = px[i].second+1;
            rest--;
            r--;
        }
        cnt -= n-1-px[i].second;
    }
    cout << "Yes" << endl;
    rep(i, 0, n*n){
        cout << ans[i] << ' ';
    }
    cout << endl;



    
    return 0;
}