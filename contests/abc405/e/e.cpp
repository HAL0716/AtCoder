#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

// 階乗の計算
vector<long long> fact, inv_fact;

// モジュラー逆元の計算 (a^(MOD-2) % MOD)
long long mod_inv(long long a) {
    long long result = 1;
    long long exp = MOD - 2;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * a) % MOD;
        }
        a = (a * a) % MOD;
        exp /= 2;
    }
    return result;
}

// 階乗の初期化
void precompute(int max_n) {
    fact.resize(max_n + 1);
    inv_fact.resize(max_n + 1);
    fact[0] = 1;
    for (int i = 1; i <= max_n; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv_fact[max_n] = mod_inv(fact[max_n]);
    for (int i = max_n - 1; i >= 0; --i) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }
}

// 組み合わせの計算 (nCr % MOD)
long long comb(int n, int r) {
    if (n < 0 || r < 0 || n < r) return 0;
    return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

// 多項式係数の計算 (a1! * a2! * ... * an! のような計算)
long long multinom(const vector<int>& counts) {
    long long result = fact[counts[0] + counts[1] + counts[2] + counts[3]];
    for (int i = 0; i < 4; ++i) {
        result = result * inv_fact[counts[i]] % MOD;
    }
    return result;
}

int main() {
    // 入力
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    
    // 階乗の前処理
    int max_n = A + B + C + D;
    precompute(max_n);

    // 果物の個数をベクトルにまとめる
    vector<int> counts = {A, B, C, D};
    
    // 結果を計算
    long long result = multinom(counts);
    
    // 結果を出力
    cout << result << endl;
    
    return 0;
}
