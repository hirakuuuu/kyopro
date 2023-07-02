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
// https://atcoder.jp/contests/agc005/tasks/agc005_c

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    // 飛んでるところが無いかをチェック
    bool ok = true;
    vector<int> b = a;
    sort(b.begin(), b.end());
    rep(i, 0, n-1) ok &= (b[i+1]-b[i] <= 1);


    priority_queue<int> que;
    rep(i, 0, n) que.push(a[i]);
    int offset = 0;
    while(!que.empty() && ok){
        int maxa = que.top();
        int cnt = 0;
        while(!que.empty() && que.top() == maxa){
            cnt++;
            que.pop();
        }

        // 木の最終状態の条件
        if(que.size() == 0){
            if(maxa-offset == 0 && cnt == 1) continue;
            if(maxa-offset == 1 && cnt == 2) continue;
            ok = false;
        }

        // 葉の数に関する条件
        if(cnt < 2){
            ok = false;
        }
        offset++;
    }

    if(ok) cout << "Possible" << endl;
    else cout << "Impossible" << endl;


    
    return 0;
}