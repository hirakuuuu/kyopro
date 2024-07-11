#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
行列計算用
*/

template<class T>
struct Matrix {
    vector<vector<T>> A;

    Matrix() {}
    Matrix(size_t n, size_t m) : A(n, vector<T>(m, 0)) {}
    Matrix(size_t n) : A(n, vector<T>(n, 0)) {};

    // 行列のサイズ（縦、横）
    size_t height() const {
        return (A.size());
    }
    size_t width() const {
        return (A[0].size());
    }

    // k行目の取得 
    inline const vector<T> &operator[](int k) const {
        return (A.at(k));
    }
    inline vector<T> &operator[](int k) {
        return (A.at(k));
    }

    // 単位行列
    static Matrix I(size_t n) {
        Matrix mat(n);
        for(int i = 0; i < (int)n; i++) mat[i][i] = 1;
        return (mat);
    }

    // 足し算  O(n^2)
    Matrix &operator+=(const Matrix &B) {
        size_t n = height(), m = width();
        assert(n == B.height() && m == B.width());
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                (*this)[i][j] += B[i][j];
            }
        }
        return (*this);
    }

    // 引き算  O(n^2)
    Matrix &operator-=(const Matrix &B) {
        size_t n = height(), m = width();
        assert(n == B.height() && m == B.width());
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                (*this)[i][j] -= B[i][j];
            }
        }
        return (*this);
    }

    // 行列積  O(n^3)
    Matrix &operator*=(const Matrix &B) {
        size_t n = height(), m = B.width(), p = width();
        assert(p == B.height());
        vector<vector<T>> C(n, vector<T>(m, 0));
        for(int i = 0; i < (int)n; i++){
            for(int j = 0; j < (int)m; j++){
                for(int k = 0; k < (int)p; k++){
                    C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);
                }
            }
        }
        A.swap(C);
        return (*this);
    }

    // 行列累乗  O(n^3logk）
    Matrix &operator^=(long long k) {
        Matrix B = Matrix::I(height());
        while(k > 0) {
            if(k & 1) B *= *this;
            *this *= *this;
            k >>= 1LL;
        }
        A.swap(B.A);
        return (*this);
    }

    Matrix operator+(const Matrix &B) const {
        return (Matrix(*this) += B);
    }
    Matrix operator-(const Matrix &B) const {
        return (Matrix(*this) -= B);
    }
    Matrix operator*(const Matrix &B) const {
        return (Matrix(*this) *= B);
    }
    Matrix operator^(const long long k) const {
        return (Matrix(*this) ^= k);
    }

    // 行列式  O(n^3)
    T determinant() {
        Matrix B(*this);
        assert(width() == height());
        T ret = 1;
        for(int i = 0; i < width(); i++) {
            int idx = -1;
            for(int j = i; j < width(); j++) {
                if(B[j][i] != 0) idx = j;
            }
            if(idx == -1) return (0);
            if(i != idx) {
                ret *= -1;
                swap(B[i], B[idx]);
            }
            ret *= B[i][i];
            T vv = B[i][i];
            for(int j = 0; j < width(); j++) {
                B[i][j] /= vv;
            }
            for(int j = i + 1; j < width(); j++) {
                T a = B[j][i];
                for(int k = 0; k < width(); k++) {
                    B[j][k] -= B[i][k] * a;
                }
            }
        }
        return (ret);
    }
};

const int vmax = 20005; // ここは問題ごとに考慮が必要
mint fact[vmax], finv[vmax];
void initfact(){
	fact[0]= 1;
	for(int i = 1; i < vmax; i++) fact[i] = fact[i-1]*i; // 階乗の計算
	finv[vmax-1] = fact[vmax-1].inv();
	for(int i = vmax-2; i >=0; i--) finv[i] = finv[i+1]*(i+1); // 階乗の逆元
}
// nCk
mint choose(int n,int k){
    if(n < 0 || k < 0 || n < k) return 0;
    if(n == 0 && k == 0) return 1;
	return fact[n]*finv[n-k]*finv[k];
}
// (a+b)!/(a!b!)
mint binom(int a,int b){
	return 0<=a&&0<=b?fact[a+b]*finv[a]*finv[b]:0;
}
// カタラン数（括弧列とか）
mint catalan(int n){
	return binom(n,n)-(n-1>=0?binom(n-1,n+1):0);
}
// 重複組み合わせ
mint homogeneous(int n, int k){
    return choose(n+k-1, k);
}

// verify: https://atcoder.jp/contests/abc256/tasks/abc256_g
int main(){
    initfact();
    ll n;
    int d; cin >> n >> d;
    
    mint ans = 2; // 全部白, 全部黒 はそれぞれ1通り

    // i = 1, d-1, d あたりが怪しい
    rep(i, 1, d+1){
        // 最初が白の場合
        Matrix<mint> dp_w(2, 1);
        dp_w[0][0] = choose(d-1, i-2); // 端点を含む
        dp_w[1][0] = choose(d-1, i-1); // 端点を含まない

        // 最初が黒の場合
        Matrix<mint> dp_b(2, 1);
        dp_b[0][0] = choose(d-1, i-1); // 端点を含む
        dp_b[1][0] = choose(d-1, i);   // 端点を含まない

        Matrix<mint> A(2, 2);
        A[0][0] = choose(d-1, i-2);
        A[0][1] = choose(d-1, i-1);
        A[1][0] = choose(d-1, i-1);
        A[1][1] = choose(d-1, i);
        
        A ^= n-1; // n-1 乗

        Matrix<mint> W = A*dp_w, B = A*dp_b;
        ans += W[0][0]+B[1][0];
    }
    cout << ans.val() << endl;
    
    return 0;
}