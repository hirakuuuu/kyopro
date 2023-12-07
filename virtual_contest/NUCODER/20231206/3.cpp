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
// 

// 0ならば素数, 0でないなら最小の素因数
const int MAX_I = 1000005;
vector<int> erat(MAX_I);
void init_e(){
    rep(i, 2, sqrt(MAX_I)){
        if(erat[i] == 0){
            for(int j = i*i; j < MAX_I; j += i){
                if(erat[j] == 0) erat[j] = i;
            }
        }
    }
}

int main(){
    init_e();
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    int G = a[0];
    rep(i, 1, n) G = gcd(G, a[i]);

    if(G != 1){
        cout << "not coprime" << endl;
    }else{
        map<int, bool> exist;
        rep(i, 0, n){
            int b = a[i];
            set<int> s;
            while(b != 1){
                int c = erat[b];
                if(c == 0){
                    s.insert(b);
                    break;
                }
                while(b%c == 0) b /= c;
                s.insert(c);
            }
            for(auto cc: s){
                if(exist[cc]){
                    cout << "setwise coprime" << endl;
                    return 0;
                }
                exist[cc] = true;
            }
        }
        cout << "pairwise coprime" << endl;

    }

    
    return 0;
}