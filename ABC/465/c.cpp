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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    int rev = 0;
    deque<int> deq;
    rep(i, 0, n){
        char c; cin >> c;
        if(rev == 0){
            deq.push_back(i+1);
        }else{
            deq.push_front(i+1);
        }
        if(c == 'o'){
            rev = 1-rev;
        }
    }

    if(rev == 0){
        while(!deq.empty()){
            int q = deq.front(); deq.pop_front();
            cout << q << ' ';
        }
        cout << endl;
    }else{
        while(!deq.empty()){
            int q = deq.back(); deq.pop_back();
            cout << q << ' ';
        }
        cout << endl;
    }
    
    return 0;
}