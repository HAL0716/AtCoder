#include <bits/stdc++.h>
using namespace std;

// 型エイリアス
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
bash test.sh abc412 c
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // --- コーディング開始 ---

    int T; cin >> T;

    while (T--) {
        int N; cin >> N;

        vector<int> S(N);
        for (int j = 0; j < N; ++j)
            cin >> S[j];
        
        int st = S.front(), ed = S.back();

        vector<int> S2;
        for (int s : S)
            if (st <= s && s <= ed)
                S2.push_back(s);

        if (S2.empty()) {
            cout << -1 << '\n';
            continue;
        }

        sort(S2.begin(), S2.end(), greater<int>());
        S2.erase(unique(S2.begin(), S2.end()), S2.end());

        stack<pair<int,int>> visited;
        visited.push({ed, 0});
        int cnt = 1;
        bool isOK = false;

        while (!visited.empty()) {
            const auto [s, n] = visited.top();
            visited.pop();
            isOK = false;
            
            if (s == st) {
                isOK = true;
                break;
            }

            for (int i = n+1; i < S2.size(); ++i) {
                if (S2[i] < (s+1) / 2)
                    break;
                
                visited.push({S2[i], i});
                if (!isOK) {
                    isOK = true;
                    ++cnt;
                }
            }
        }
        
        cout << (isOK ? cnt : -1) << endl;

        // vector<int> Svec(N);
        // for (int j = 0; j < N; ++j)
        //     cin >> Svec[j];

        // int st = Svec.front(), ed = Svec.back();

        // vector<int> Sfiltered;
        // for (int s : Svec)
        //     if (st <= s && s <= ed)
        //         Sfiltered.push_back(s);
        
        // if (Sfiltered.empty()) {
        //     cout << -1 << "\n";
        //     continue;
        // }

        // sort(Sfiltered.begin(), Sfiltered.end(), greater<int>());
        // Sfiltered.erase(unique(Sfiltered.begin(), Sfiltered.end()), Sfiltered.end());


        // int cnt = 1;
        // int nowS = Sfiltered[0];
        // bool isOK = false;
        // que

        // for (size_t j = 1; j < Sfiltered.size(); ++j) {
        //     if (Sfiltered[j] < (nowS + 1) / 2) {
        //         if (!isOK) {
        //             cnt = -1;
        //             break;
        //         }
        //         nowS = Sfiltered[j - 1];
        //         isOK = false;
        //     }

        //     if (!isOK && Sfiltered[j] >= (nowS + 1) / 2) {
        //         ++cnt;
        //         isOK = true;
        //     }
        // }

        // cout << cnt << "\n";
    }

    // --- コーディング終了 ---
    
    return 0;
}