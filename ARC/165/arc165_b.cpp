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
// https://atcoder.jp/contests/arc165/tasks/arc165_b

int main(){
    int n, k; cin >> n >> k;
    vector<int> p(n);
    rep(i, 0, n) cin >> p[i];
    
    // 連続ｋ個が昇順なら元の順列と同じにできる
    rep(i, 0, n){
        int j = i, cnt = 1;
        while(j < n-1 && p[j] < p[j+1]){
            j++;
            cnt++;
        }
        if(cnt >= k){
            rep(l, 0, n) cout << p[l] << ' ';
            cout << endl;
            return 0;
        }
        i = j;
    }

    set<int> s;
    vector<int> t(n);
    rep(i, 0, k) s.insert(p[i]);
    rep(i, 0, n-k+1){
        t[i] = *s.begin();
        s.erase(s.find(p[i]));
        if(i < n-k) s.insert(p[i+k]);
    }


    vector<int> q;
    rep(j, n-k, n) q.push_back(p[j]);
    sort(q.begin(), q.end());
    vector<int> r(n);
    rep(i, 0, n){
        if(n-k <= i && i < n) r[i] = q[i-(n-k)];
        else r[i] = p[i];
    }


    rrep(i, n-k, 0){
        if(t[i] == p[i]){
            while(i > 0 && t[i-1] == p[i-1]) i--;
            rep(j, i, i+k) q[j-i] = p[j];
            sort(q.begin(), q.end());
            
            bool f = true;
            rep(j, i, i+k){
                if(q[j-i] < r[j]){
                    f = false;
                    break;
                }
            }
            if(f){
                rep(j, 0, n){
                    if(i <= j && j < i+k) cout << q[j-i] << ' ';
                    else cout << p[j] << ' ';
                }
                cout << endl;
                return 0;
            }
        }
    }

    rep(i, 0, n){
        cout << r[i] << ' ';
    }
    cout << endl;

    

    
    return 0;
}