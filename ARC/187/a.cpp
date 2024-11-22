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

int main(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    
    vector<int> b;
    if(n == 2){
        if(inr(1, a[0]-a[1], k)){
            cout << "No" << endl;
            return 0;
        }else{
            if(a[0] > a[1]) b.push_back(0);
        }
    }else if(n == 3){
        if(inr(1, a[0]-a[1], k) && inr(1, a[1]-a[2], k)){
            cout << "No" << endl;
            return 0;
        }else{
            if(inr(1, a[1]-a[2], k)){
                rrep(i, 1, 0){
                    b.push_back(i);
                    swap(a[i+1], a[i]);
                    a[i] += k;
                }
            }
            if(a[1] > a[2]){
                b.push_back(1);
                swap(a[2], a[1]);
                a[1] += k;
            }
            while(a[0] > a[1]){
                rep(_, 0, 2) b.push_back(1);
                a[1] += k;
                a[2] += k;
            }
        }
    }else{
        for(int i = n-2; i >= 2; i -= 2){
            // a[i-2], a[i-1], a[i], a[i+1] について、
            // !inr(1, a[i-2]-a[i-1], k) && !inr(1, a[i]-a[i+1], k) が成り立つように 操作 i-1 を2回ずつ行う
            while(inr(1, a[i-2]-a[i-1], k) || inr(1, a[i]-a[i+1], k)){
                rep(_, 0, 2) b.push_back(i-1);
                a[i-1] += k;
                a[i] += k;
            }
        }
        for(int i = n%2; i < n; i += 2){
            if(a[i] > a[i+1]){
                b.push_back(i);
                swap(a[i+1], a[i]);
                a[i] += k;
            }
            while(a[i-1] > a[i]){
                rep(_, 0, 2) b.push_back(i);
                a[i] += k;
                a[i+1] += k;
            }
        }
    }

    cout << "Yes" << endl;
    cout << b.size() << endl;
    for(auto bb: b){
        cout << bb+1 << ' ';
    }
    cout << endl;

    return 0;
}