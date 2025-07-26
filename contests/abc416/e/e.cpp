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
bash test.sh abc416 e
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // --- コーディング開始 ---

    int N, M; cin >> N >> M;

    vector<vector<int>> timeMap(N, vector<int>(N, 0));
    ll timeSum = 0;

    for (int i = 0; i < M; ++i) {
        int A, B, C; cin >> A >> B >> C; A--; B--;
        timeMap[A][B] = C;
        timeMap[B][A] = C;
        timeSum += C + C;
    }

    int K, T; cin >> K >> T;

    set<int> hasAir;
    for (int i = 0; i < K; ++i) {
        int D; cin >> D; D--;
        hasAir.insert(D);
    }

    for (int air1 : hasAir) {
        for (int air2 : hasAir) {
            if (air1 == air2) continue;

            if (timeMap[air1][air2] > T) {
                timeSum += -timeMap[air1][air2] + T;
                timeMap[air1][air2] = T;
            } else if (timeMap[air1][air2] == 0) {
                timeSum += T;
                timeMap[air1][air2] = T;
            }
        }
    }

    int Q; cin >> Q;

    for (int i = 0; i < Q; ++i) {
        int mode; cin >> mode;

        if (mode == 1) {
            int x, y, t; cin >> x >> y >> t; x--; y--;
            int ot = timeMap[x][y];
            if (t < ot) {
                timeMap[x][y] = t;
                timeSum -= (ot - t);
            }
            for (int i = 0; i < N; ++i) {
                if (timeMap[x][i] + timeMap[i][y] < timeMap[x][y]) {
                    timeSum += -timeMap[x][y] + timeMap[x][i] + timeMap[i][y];
                    timeMap[x][y] = timeMap[x][i] + timeMap[i][y];
                }
                if (timeMap[y][i] + timeMap[i][y] < timeMap[y][x]) {
                    timeSum += -timeMap[y][x] + timeMap[y][i] + timeMap[i][x];
                    timeMap[y][x] = timeMap[y][i] + timeMap[i][x];
                }
            }
        } else if (mode == 2) {
            int x; cin >> x; x--;
            hasAir.insert(x);

            for (int air1 : hasAir) {
                if (air1 == x) continue;

                if (timeMap[air1][x] > T) {
                    timeSum += -timeMap[air1][x] + T;
                    timeMap[air1][x] = T;
                } else if (timeMap[air1][x] == 0) {
                    timeSum += T;
                    timeMap[air1][x] = T;
                }

                if (timeMap[x][air1] > T) {
                    timeSum += -timeMap[x][air1] + T;
                    timeMap[x][air1] = T;
                } else if (timeMap[x][air1] == 0) {
                    timeSum += T;
                    timeMap[x][air1] = T;
                }
            }
        } else {
            cout << timeSum << endl;
        }
    }
    
    // --- コーディング終了 ---
    
    return 0;
}