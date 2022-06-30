#include <iostream>
#include <algorithm>

using namespace std;
int dp[8][9] = {
{3, 4, 9, -2, 2, 51, -23, 2, -1},
{223, 7, 8, -11, 5, -99, 2, 3, -4},
{2, 51, -23, -23, 6, 3, 2, 4, 5},
{5, -99, 2, -1, 32, 2, 5, -99, 2},
{6, 3, 3, -4, 2, -1, 6, 3, 3},
{32, 2, 4, 5, 3, -4, 2, -1, 4},
{4, 4, 23, 6, 2, -1, 3, -4, 34},
{78, 32, 1, 7, 3, -4, -23, -23, 6},
};

int main() {
 
    //반복문을 돌아서 위에서의 최단 경로를 찾는다. 
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            dp[i][j] += max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i - 1][j + 1]));
        }
    }

    //가장 마지막 행에서 가장 최댓값이 나오는 것을 찾는다. 
    int maxNum = 0;
    for (int i = 0; i < 9; i++) {
        if (maxNum < dp[7][i]) {
            maxNum = dp[7][i];
        }
    }

    //최댓값 출력
    cout << "최댓값은: " << maxNum <<endl;

    //그냥 다 출력
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 9; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    //경로 출력
    int arr[8][9] = {
{3, 4, 9, -2, 2, 51, -23, 2, -1},
{223, 7, 8, -11, 5, -99, 2, 3, -4},
{2, 51, -23, -23, 6, 3, 2, 4, 5},
{5, -99, 2, -1, 32, 2, 5, -99, 2},
{6, 3, 3, -4, 2, -1, 6, 3, 3},
{32, 2, 4, 5, 3, -4, 2, -1, 4},
{4, 4, 23, 6, 2, -1, 3, -4, 34},
{78, 32, 1, 7, 3, -4, -23, -23, 6},
    };
    cout << "경로 출력 : " << endl;
    cout << arr[0][1] << " "
        << arr[1][0] << " "
        << arr[2][1] << " "
        << arr[3][0] << " "
        << arr[4][0] << " "
        << arr[5][0] << " "
        << arr[6][0] << " "
        << arr[7][0] << " "
        << endl;


    return 0;
}
