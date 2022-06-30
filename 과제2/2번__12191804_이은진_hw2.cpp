#include <iostream>
#include <algorithm>
#include <string>
#include <locale>
using namespace std;
// �޸� ���� ������ ���� ������ 2���� �迭 ����
double D2[1001][1001];

void EditDistanceRoute(wstring& s, wstring& t, double minNum) {
	// string
	int n = s.length();
	int m = t.length();

	// �Ʒ����� ���� �� ����, ����, ��ȯ ������ ���� ������� ������ �迭
	double* distanceList{ new double[static_cast<int>(s.length() * t.length()) + 1]{ } };
	// ����, ����, ��ȯ ���� �� �ּҰ��� ���� ����
	//double minNum = 0;

	// ����� �� ������ �����ϰ� �ϱ� ���� �ݺ��� i, j, k ����
	int i = n; //5
	int j = m; //8
	int k = n * m;
	double cost ;

	while (1) {
		// ���� minNum�� ���� ���� ���� ���ٸ� ���� �������� �ѱ�
		if ((D2[i][j] == D2[i-1][j-1]) && (i > 0 && j > 0)) {
			i--, j--;
		}
		// D2[i][j]�� ����  D2[i-1][j-1] ���� ���� �ٸ� ���
		// ��, source�� target�� �޶� 0�� �������� ��ȯ������ ������� ���� ���
		// ���� ���� ã�� distanceList�� �ش� ���꿡 �ش��ϴ� �Ÿ��� �ִ´�
		else {
			minNum = min({ D2[i][j - 1] + 0.7, D2[i - 1][j] + 0.5, D2[i - 1][j - 1] + 0.3 });
			if ((minNum == D2[i][j - 1] + 0.7) && (j > 0)) { // ���� ����
				distanceList[k--] = 0.7;
				j--;
			}
			else if ((minNum == D2[i - 1][j] + 0.5) && (i > 0)) { // ���� ����
				distanceList[k--] = 0.5;
				i--;
			}
			else if ((minNum == D2[i - 1][j - 1] + 0.3) && (i > 0 && j > 0)) { // ��ȯ ����
				distanceList[k--] = 0.3;
				i--, j--;
			}
		}

		if (i == 0 && j != 0) {
			distanceList[k--] = 0.7;
			j--;
		}
		if (i != 0 && j == 0) {
			distanceList[k--] = 0.5;
			i--;
		}
		if (i == 0 && j == 0) break;
	}

	// ���� �ݺ������� ���������� �������� ���� ���� ������ �ٽ� ���
	for (int i = 0; i <= (n * m); i++) {
		if (distanceList[i] == 0.7)
			cout << "���� ���� " << distanceList[i] << "\n";
		else if (distanceList[i] == 0.5)
			cout << "���� ���� " << distanceList[i] << "\n";
		else if (distanceList[i] == 0.3)
			cout << "��ȯ ���� " << distanceList[i] << "\n";
	}

}

double EditDistance(wstring& s, wstring& t) {
	// string
	int n = s.length();
	int m = t.length();
	// ��ȯ��� ����
	double cost = 0;

	D2[0][0] = 0;
	// ù �� (����) 0.5�� ����
	for (int i = 1; i <= n; i++) {
		D2[i][0] = D2[i - 1][0] + 0.5;
	}
	// ù �� (����) 0.7�� ����
	for (int j = 1; j <= m; j++) {
		D2[0][j] = D2[0][j - 1] + 0.7;
	}
	// (b) ���Ժ�� = 0.7, ������� = 0.5, ��ȯ��� = 0/0.3 �϶�
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// string�� text�� ���� ���
			if (s[i - 1] == t[j - 1]) {
				cost = 0;
			}
			else cost = 0.3;
			// ����, ����, ��ȯ �� �ּҰ��� �����Ѵ�. 
			D2[i][j] = min(D2[i][j - 1] + 0.7, min(D2[i - 1][j] + 0.5, D2[i - 1][j - 1] + cost));
		}
	}
	for (int j = 0; j <= m; j++) {
		for (int i = 0; i <= n; i++) {
			cout << D2[i][j] << "\t";
		} cout << "\n";
	}

	EditDistanceRoute(s, t, D2[n][m]);
	// ���� �����Ÿ� return
	return D2[n][m];
}

int main() {
	// 3�� ���� ������ ���̵� ���ڿ��� ����ϰ� �������� �ѱ��� �ѱ���� �����Ѵ�.
	setlocale(LC_ALL, "ko_KR");
	wstring s, t;
	cout << "Source: ";
	wcin >> s;
	cout << "Target: ";
	wcin >> t;
	cout << "���Ժ�� = 0.7, ������� = 0.5, ��ȯ��� = 0/0.3 �϶�\n\n";
	cout << "Levenshtein Distance: " << EditDistance(s, t) << endl;
	cout << "\n12191804 ������\n";
}