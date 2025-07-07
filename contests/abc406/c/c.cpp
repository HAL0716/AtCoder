#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> P(N);
    for(int i=0; i<N; i++) cin >> P[i];

    vector<int> D(N-1);
    for(int i=0; i<N-1; i++){
        D[i] = (P[i] < P[i+1]) ? 1 : -1;
    }

    // 符号連続区間を取得
    vector<int> lengths;
    vector<int> signs;
    int cur_sign = D[0];
    int cur_len = 1;
    for(int i=1; i<N-1; i++){
        if(D[i] == cur_sign) {
            cur_len++;
        } else {
            signs.push_back(cur_sign);
            lengths.push_back(cur_len);
            cur_sign = D[i];
            cur_len = 1;
        }
    }
    signs.push_back(cur_sign);
    lengths.push_back(cur_len);

    long long ans = 0;
    int M = (int)lengths.size();

    // 3連続区間で "+, -, +" パターンを探す
    for(int i=0; i+2<M; i++){
        if(signs[i] == 1 && signs[i+1] == -1 && signs[i+2] == 1){
            int a = lengths[i];
            int b = lengths[i+1];
            int c = lengths[i+2];

            // 条件: x + y >= 4 - b
            int limit = 4 - b;
            if(limit <= 2) {
                // x, y >=1 なので最小値は2なので全部OK
                // 部分列の数は a*c 個
                ans += (long long)a * c;
            } else {
                // limit > 2 なら条件に注意
                // x,y>=1
                // x + y >= limit を満たす組み合わせ数を求める
                // x in [1,a], y in [1,c]
                // total = a*c
                // 条件 x + y < limit の個数を引く

                long long total = (long long)a * c;
                long long invalid = 0;
                // x + y < limit  => y < limit - x

                for(int x=1; x<=a; x++){
                    int max_y = limit - x -1;
                    if(max_y < 1) continue;
                    int cnt_y = min(max_y, c);
                    if(cnt_y > 0) invalid += cnt_y;
                }
                ans += total - invalid;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
