#include <iostream>
using namespace std;

struct Jewelry {
    int weight, val;
};

int value[101][100001], n, k;
Jewelry jewelry[101];
int result[2];

int main() {
    for (int in = 0; in < 2; in++) {
        cout << "\n입력" << in + 1 << "번째 값 입력\n";

        // 보석의 갯수 n과 배낭 무게 k를 입력받는다.
        cout << "배낭 무게: ";
        cin >> k;
        cout << "보석의 갯수: ";
        cin >> n;

        // 보석들의 무게와 가치(w, v)를 갯수 n만큼 입력받는다.
        for (int i = 1; i <= n; i++) {
            int w, v;
            cin >> w >> v;
            jewelry[i] = { w, v };
        }

        // dp를 사용하여 풀이
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                int wi = jewelry[i].weight;
                int vi = jewelry[i].val;

                // i 번째 물체의 무게를 포함하는 경우
                if (wi > j) {
                    value[i][j] = value[i - 1][j];
                }// i 번째 물체의 무게를 포함하지 않는 경우
                else {
                    value[i][j] = max(vi + value[i - 1][j - wi], value[i - 1][j]);
                }

            }
        }

        result[in] = value[n][k];
    }
    
    for (int j = 0; j < 2; j++) {
        cout << "입력" << j + 1 << "에 대하여 가방에 담은 보석의 최대 가치 : " << result[j] << "\n";
    }
    
    return 0;
}