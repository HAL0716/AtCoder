#include <bits/stdc++.h>
using namespace std;

// 型エイリアス
using str = string;
using ll = long long;

// 定数
const int MOD = 1e9 + 7;            // モジュラ演算の定数
const int MOD2 = 998244353;         // 別のモジュラ演算用定数
const int MODULUS = 1e9 + 9;        // ハッシュ用の素数
const double PI = 3.14159265358979323846;  // 円周率
const double EPS = 1e-9;            // 浮動小数点誤差許容範囲
const int MAXN = 100000;            // 配列の最大サイズ
const int ALPHABET_SIZE = 26;       // アルファベットのサイズ
const int LIMIT = 1000;             // 入力の最大制限
const int INF = 1e9;                // 無限大

// 最大値・最小値の定義
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

// デバッグ用
#ifdef LOCAL
#define debug(x) cerr << #x << ": " << (x) << endl
#else
#define debug(x)
#endif

/*
実行コマンド例
bash test.sh abc416 c
*/

void dfs(int depth, int K, const vector<string>& S, vector<int>& idx, vector<string>& all) {
    if (depth == K) {
        string t;
        for (int i = 0; i < K; ++i)
            t += S[idx[i]];
        all.push_back(std::move(t));
        return;
    }
    for (int i = 0; i < (int)S.size(); ++i) {
        idx[depth] = i;
        dfs(depth + 1, K, S, idx, all);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // --- コーディング開始 ---

    int N, K; cin >> N >> K;
    ll X; cin >> X; X--;

    std::vector<std::string> S(N);
    for (int i = 0; i < N; ++i) cin >> S[i];

    ll total = 1;
    for (int i = 0; i < K; ++i) total *= N;

    vector<string> all;
    all.reserve(pow(N, K));
    vector<int> idx(K, 0);
    dfs(0, K, S, idx, all);

    sort(all.begin(), all.end());

    cout << all[X] << "\n";
    
    // --- コーディング終了 ---
    
    return 0;
}