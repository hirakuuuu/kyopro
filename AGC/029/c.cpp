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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


/*
種類数を決め打って二分探索
- a[i] < a[i+1] であれば、後ろに a を付けるだけ
- a[i] >= a[i+1] であれば、辞書順で一番大きい文字でない文字で一番右のものを1進める

嘘解法
- 最小のところで区切って、区間の数と文字数から必要な種類数を求める
- 分割した区間で再帰的に解いていく
- 種類数の最大値がボトルネック
- 分割したところで必要な種類数が増えたとき、最初にその数で分割しておけば良い場合があり得る.
*/

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    ll ok = n, ng = 0;
    auto solve = [&](ll kind) -> bool {
        stack<pair<int, int>> stc;
        stc.push({0, a[0]});
        rep(i, 1, n){
            if(a[i-1] < a[i]){
                if(stc.top().first == 0){
                    stc.top().second += a[i]-a[i-1];
                }else{
                    stc.push({0, a[i]-a[i-1]});
                }
            }else{
                // 文字を削る
                int d = a[i-1]-a[i];
                while(d){
                    pair<int, int> k = stc.top(); stc.pop();
                    if(k.second > d){
                        stc.push({k.first, k.second-d});
                        d = 0;
                    }else{
                        d -= k.second;
                    }
                }
                // 辞書順で1進める
                pair<int, int> k1 = stc.top(); stc.pop();
                if(k1.first != kind-1){
                    if(k1.second-1 > 0) stc.push({k1.first, k1.second-1});
                    if(!stc.empty() && stc.top().first == k1.first+1) stc.top().second++;
                    else stc.push({k1.first+1, 1});
                }else{
                    if(stc.empty()) return false;
                    pair<int, int> k2 = stc.top(); stc.pop();
                    if(k2.second-1 > 0) stc.push({k2.first, k2.second-1});
                    if(!stc.empty() && stc.top().first == k2.first+1) stc.top().second++;
                    else stc.push({k2.first+1, 1});
                    stc.push({0, k1.second});
                }
            }
        }
        return true;
    };

    while(ok-ng > 1){
        ll mid = (ok+ng)/2;
        if(solve(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    
    return 0;
}