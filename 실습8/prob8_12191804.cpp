#include <iostream>
using namespace std;

template <size_t N1, size_t N2>
void Cheese_Trap(const int(&)[N1][N2]);

int main() {
	// 치즈는 1 쥐덫은 2 나머지는 -1 로 2차원 배열 cheese를 설정해주었다. 
	const int cheese[9][9]{
	{-1, -1, 1, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1, 1, -1, 2, -1},
	{1, -1, 2, -1, -1, -1, -1, 1, -1},
	{-1, -1, -1, -1, 1, 2, -1, -1, -1},
	{-1, 1, -1, 1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1, 2, 1, 2, -1},
	{-1, 1, -1, -1, 1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1, 1, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1} };

	//미로 출력
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << cheese[i][j] << '\t';
		cout << endl;
	}

	Cheese_Trap(cheese);

	return 0;
}

template <typename T>
inline const T max(const T& a, const T& b) {
	return a >= b ? a : b;
}


template <size_t N1, size_t N2>
void Cheese_Trap(const int(&cheese)[N1][N2]) {
	int result[9][9]{ };

	if (cheese[8][0] == 1)
		result[8][0] = 1;

	// 첫번째 열 (왼쪽 열)
	for (int i = 7; i >= 0; i--) {
		// 치즈가 없는 경우
		if (cheese[i][0] == -1)
			result[i][0] = result[i + 1][0];
		// 치즈가 있는 경우
		else if (cheese[i][0] == 1)
			result[i][0] = result[i + 1][0] + 1;

		// 쥐덫이 있는 경우
		else {
			// 쥐덫의 위치에 -1 대입 이후 반복문을 빠져나온다.
			result[i][0] = -2;
			break;
		}
	}

	// 마지막 행 (맨 아래 열)
	for (int j = 1; j < 9; j++) {
		if (cheese[8][j] == -1)
			result[8][j] = result[8][j - 1];

		else if (cheese[8][j] == 1)
			result[8][j] = result[8][j - 1] + 1;

		else {
			result[8][j] = -2;
			break;
		}
	}

	// 나머지 [7][0]부터 [0][8]까지 진행
	for (int i = 7; i >= 0; i--) {
		for (int j = 1; j < 9; j++)
			if (cheese[i][j] == -1)
				result[i][j] = max(result[i][j - 1], result[i + 1][j]);

			else if (cheese[i][j] == 1)
				result[i][j] = max(result[i][j - 1], result[i + 1][j]) + 1;
			else
				result[i][j] = -2;
	}

	cout << endl;

	// 먹을 수 있는 치즈의 최댓값 경로 출력
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << result[i][j] << '\t';
		cout << endl;
	}

	cout << "\n먹을 수 있는 치즈의 최댓값은 : " << result[0][8] << endl;
}