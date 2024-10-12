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
「不変量」と「簡単な操作」に着目する
- k 回操作した後の A の総和は sum(A)+k*n*(n+1)/2 と書け, これが n の倍数でないといけない
- １回操作して、それの reverse で操作すると, 全体に n+1 を足せる.
- ２つ選んで swap すると, n, n+2, 残りは n+1 を足せる.
- この操作を 平均より大きい index と 平均より小さい index を選んで行うといずれ全部そろう
- 操作回数も十分余裕がある
*/

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    int sum_a = 0;
    rep(i, 0, n) sum_a += a[i];

    if(sum_a%n != 0 && (sum_a+n*(n+1)/2)%n != 0){
        cout << "No" << endl;
        return 0;
    }

    vector<vector<int>> ans;
    if(sum_a%n != 0){
        ans.push_back({});
        rep(i, 0, n){
            a[i] += i+1;
            ans.back().push_back(i+1);
        }
        sum_a += n*(n+1)/2;
    }

    // (1, 2, ... , n-1, n) と (n-1, n, n-2, ... , 2, 1) を組み合わせると, 
    // 特定の２項について -1, +1 して, 他は 0 とできる
    while(true){
        // 平均値
        assert(sum_a%n == 0);
        int mean = sum_a/n;
        int mini = -1, maxi = -1;
        rep(i, 0, n){
            if(a[i] > mean) maxi = i;
            if(a[i] < mean) mini = i;
        }
        if(mini == -1 || maxi == -1) break;

        vector<int> p1(n), p2(n);
        int l = 3;
        rep(i, 0, n){
            if(i == maxi) p1[i] = 1;
            else if(i == mini) p1[i] = 2; 
            else p1[i] = l++;
        }
        rep(i, 0, n){
            if(i == maxi) p2[i] = n-1;
            else if(i == mini) p2[i] = n; 
            else p2[i] = (n+1)-p1[i];
        }
        ans.push_back(p1);
        rep(i, 0, n) a[i] += p1[i];
        ans.push_back(p2);
        rep(i, 0, n) a[i] += p2[i];
        sum_a += n*(n+1);
    }

    cout << "Yes" << endl;
    int m = (int)ans.size();
    cout << m << endl;
    rep(i, 0, m){
        for(auto p: ans[i]){
            cout << p << ' ';
        }
        cout << endl;
    }
    
    return 0;
}