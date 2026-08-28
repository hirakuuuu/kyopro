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

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

int main(){
    int n; cin >> n;
    if(n%10 == 0){
        cout << -1 << endl;
        return 0;
    }
    vector<vector<int>> pre(n, vector<int>(10, -1));
    deque<pair<int, int>> que;
    rep(i, 1, 10){
        que.push_back({(i%n<<5)+i, -2});
    }
    int mask = (1<<5)-1;
    while(!que.empty()){
        auto [tmp, ptmp] = que.front(); que.pop_front();
        int r = tmp>>5, last = tmp&mask;
        if(pre[r][last] != -1) continue;
        pre[r][last] = ptmp;
        if(r == 0) break;
        if(pre[(r*10+last)%n][last] == -1){
            que.push_back({((r*10+last)%n<<5)+last, tmp});
        }
        if(last != 9 && pre[r][last+1] == -1){
            que.push_front({(r<<5)+last+1, tmp});
        }
    }


    string ans;
    rep(i, 1, 10){
        if(pre[0][i] != -1){
            string tmp;
            int r = 0, last = i;
            while(r != -1){
                if(pre[r][last] == -2){
                    tmp += (char)('0'+last);
                    break;
                }

                int pr = pre[r][last]>>5, plast = pre[r][last]&mask;
                if(r != pr) tmp += (char)('0'+last);
                r = pr, last = plast;
            }
            reverse(tmp.begin(), tmp.end());
            if(ans.empty() || (ans.size() > tmp.size())){
                swap(ans, tmp);
            }else if(ans.size() == tmp.size() && ans > tmp){
                swap(ans, tmp);
            }
        }
    }

    if(ans.empty()) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}