#include <iostream>
using namespace std;

template <size_t N1, size_t N2>
void Cheese_Trap(const int(&)[N1][N2]);

int main() {
	// ġ��� 1 �㵣�� 2 �������� -1 �� 2���� �迭 cheese�� �������־���. 
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

	//�̷� ���
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

	// ù��° �� (���� ��)
	for (int i = 7; i >= 0; i--) {
		// ġ� ���� ���
		if (cheese[i][0] == -1)
			result[i][0] = result[i + 1][0];
		// ġ� �ִ� ���
		else if (cheese[i][0] == 1)
			result[i][0] = result[i + 1][0] + 1;

		// �㵣�� �ִ� ���
		else {
			// �㵣�� ��ġ�� -1 ���� ���� �ݺ����� �������´�.
			result[i][0] = -2;
			break;
		}
	}

	// ������ �� (�� �Ʒ� ��)
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

	// ������ [7][0]���� [0][8]���� ����
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

	// ���� �� �ִ� ġ���� �ִ� ��� ���
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << result[i][j] << '\t';
		cout << endl;
	}

	cout << "\n���� �� �ִ� ġ���� �ִ��� : " << result[0][8] << endl;
}