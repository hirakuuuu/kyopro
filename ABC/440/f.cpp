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
- 全部2倍だと，１個だけ２倍にできない
- そうでなければ，２倍の個数分だけ２倍にできる．この個数を k とする．
- A の降順に馬を並べ，最初の k 匹が全部２倍のとき，k 番目の馬でなく，k+1 番目の馬（この馬は１倍）を２倍
- そうでないとき，大きい方から k 匹をすべて２倍にできる．
*/

int main(){
    int n, q; cin >> n >> q;
    vector<ll> a(n), b(n);
    ll sum_a = 0;
    ll sum_b = 0;
    rep(i, 0, n){
        cin >> a[i] >> b[i]; b[i]--;
        sum_a += a[i];
        sum_b += b[i];
    }

    multiset<ll> mx, mi;
    ll sum_mx = 0, sum_mi = 0;
    ll cnt_mx = 0, cnt_mi = 0;
    {
        vector<ll> ab(n);
        rep(i, 0, n){
            ab[i] = (a[i]<<1)+(1-b[i]);
        }
        sort(ab.rbegin(), ab.rend());
        rep(i, 0, sum_b) mx.insert(ab[i]), sum_mx += ab[i]>>1, cnt_mx += 1-(ab[i]&1);
        rep(i, (int)sum_b, n) mi.insert(ab[i]), sum_mi += ab[i]>>1, cnt_mi += 1-(ab[i]&1);
    }

    // if(sum_b == n) cout << sum_a+sum_a-((*mx.begin())>>1) << endl;
    // else if(cnt_mx != sum_b) cout << sum_a+sum_mx << endl;
    // else cout << sum_a+(sum_mx-((*mx.begin())>>1)+((*mi.rbegin())>>1)) << endl;

    while(q--){
        ll w, x, y; cin >> w >> x >> y; w--, y--;
        { // erase
            ll num = (a[w]<<1)+(1-b[w]);
            if(mx.find(num) != mx.end()){
                mx.erase(mx.find(num));
                sum_mx -= num>>1;
                cnt_mx -= b[w];
            }else{
                mi.erase(mi.find(num));
                sum_mi -= num>>1;
                cnt_mi -= b[w];
            }
            sum_a -= a[w];
            sum_b -= b[w];
        }
        
        a[w] = x;
        b[w] = y;

        { // insert
            sum_a += a[w];
            sum_b += b[w];
            {
                ll num = (a[w]<<1)+(1-b[w]);
                mi.insert(num);
                sum_mi += num>>1;
                cnt_mi += b[w];
            }


            while(mx.size() < sum_b){
                auto itr = mi.rbegin();
                ll num = *itr;
                mi.erase(mi.find(num));
                mx.insert(num);
                sum_mx += num>>1;
                cnt_mx += 1-(num&1); 
                sum_mi -= num>>1; 
                cnt_mi -= 1-(num&1); 
            }
            while(mx.size() > sum_b){
                auto itr = mx.begin();
                ll num = *itr;
                mx.erase(itr);
                mi.insert(num);
                sum_mx -= num>>1;
                cnt_mx -= 1-(num&1); 
                sum_mi += num>>1; 
                cnt_mi += 1-(num&1);  
            }

            while(!mx.empty() && !mi.empty() && (*mx.begin()) < (*mi.rbegin())){
                {
                    auto itr = mi.rbegin();
                    ll num = *itr;
                    mi.erase(mi.find(num));
                    mx.insert(num);
                    sum_mx += num>>1;
                    cnt_mx += 1-(num&1); 
                    sum_mi -= num>>1; 
                    cnt_mi -= 1-(num&1); 
                }
                {
                    auto itr = mx.begin();
                    ll num = *itr;
                    mx.erase(itr);
                    mi.insert(num);
                    sum_mx -= num>>1;
                    cnt_mx -= 1-(num&1);
                    sum_mi += num>>1; 
                    cnt_mi += 1-(num&1); 
                }
            }
        }

        if(sum_b == 0) cout << sum_a << endl;
        else if(sum_b == n) cout << sum_a+sum_a-((*mx.begin())>>1) << endl;
        else if(cnt_mx != sum_b) cout << sum_a+sum_mx << endl;
        else cout << sum_a+(sum_mx-((*mx.begin())>>1)+((*mi.rbegin())>>1)) << endl;

        // cout << sum_a << ' ' << sum_b << endl;
        // cout << sum_mx << ' ' << sum_mi << endl;
        // cout << cnt_mx << ' ' << cnt_mi << endl;
    }
    
    return 0;
}