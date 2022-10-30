#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

/*
max-ヒープ：完全二分木であり、各節点のキーがその親のキー以下であるもの
*/

// const int MAX_K = 2000000001;
vector<int> parent(500005, 500005), Left(500005, 500005), Right(500005, 500005), Key(500005);
int h;
void maxHeapify(int i){
    int l = Left[i];
    int r = Right[i];
    int largest = i;
    // 左の子、自分、右の子で値が最大のノードを選ぶ
    if(l <= h and Key[l] > Key[largest]) largest = l;
    if(r <= h and Key[r] > Key[largest]) largest = r;
    // iの子の方が値が大きい場合
    if(largest != i){
        swap(Key[i], Key[largest]);
        maxHeapify(largest);
    }
}



void print(){
    rep(i, 0, h) printf(" %d", Key[i+1]);
    printf("\n");
}

void buildMaxHeap(){
    for(int i = h/2; i > 0; i--){
        maxHeapify(i);
    }
}

int main(){
    cin >> h;
    rep(i, 1, h+1){
        cin >> Key[i];
        if(1 <= i/2) parent[i] = i/2;
        if(2*i <= h) Left[i] = 2*i;
        if(2*i+1 <= h) Right[i] = 2*i+1;
    }
    buildMaxHeap();
    print();
}