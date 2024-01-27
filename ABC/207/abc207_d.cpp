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
// https://atcoder.jp/contests/abc207/tasks/abc207_d


int main(){
    const double eps = 1e-6;
    int n; cin >> n;
    vector<double> a(n), b(n), c(n), d(n);
    rep(i, 0, n) cin >> a[i] >> b[i];
    rep(i, 0, n) cin >> c[i] >> d[i];
    pair<double, double> g1, g2;
    rep(i, 0, n){
        g1.first += a[i];
        g1.second += b[i];
        g2.first += c[i];
        g2.second += d[i];
    }
    rep(i, 0, n){
        a[i] -= g1.first/n;
        b[i] -= g1.second/n;
        c[i] -= g2.first/n;
        d[i] -= g2.second/n;
    }

    int cnt1 = 0, cnt2 = 0;
    vector<double> a_, b_, c_, d_;
    rep(i, 0, n){
        if(abs(a[i]) < eps && abs(b[i]) < eps){
            cnt1++;
        }else{
            a_.push_back(a[i]);
            b_.push_back(b[i]);
        }
        if(abs(c[i]) < eps && abs(d[i]) < eps){
            cnt2++;
        }else{
            c_.push_back(c[i]);
            d_.push_back(d[i]);
        }
    }
    if(cnt1 != cnt2){
        cout << "No" << endl;
        return 0;
    }

    int m = n-cnt1;
    if(m == 0){
        cout << "Yes" << endl;
        return 0;
    }

    swap(a, a_);
    swap(b, b_);
    swap(c, c_);
    swap(d, d_);

    rep(i, 0, n){
        double t = atan2(d[i], c[i])-atan2(b[0], a[0]);
        bool f2 = true;
        rep(j, 0, n){
            double na = a[j]*cos(t)-b[j]*sin(t);
            double nb = a[j]*sin(t)+b[j]*cos(t);
            bool f3 = false;
            rep(k, 0, n){
                if(abs(na-c[k]) < eps && abs(nb-d[k]) < eps) f3 = true;
            }
            if(!f3) f2 = false;
        }
        if(f2){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}