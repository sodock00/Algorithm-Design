#include <iostream>
#include <algorithm>
#include <string>
#include <locale>
using namespace std;
// �޸� ���� ������ ���� ������ 2���� �迭 ����
int D[1001][1001];
double D2[1001][1001];

int EditDistance_a(wstring& s, wstring& t) {
	// string
	int n = s.length();
	int m = t.length();
	// ��ȯ��� ����
	int cost = 0; 

	D[0][0] = 0;
	// ù �� (����) 1�� ����
	for (int i = 1; i <= n; i++) {
		D[i][0] = D[i - 1][0] + 1;
	}
	// ù �� (����) 1�� ����
	for (int j = 1; j <= m; j++) {
		D[0][j] = D[0][j - 1] + 1;
	}
	// (a) ���̽� > ���Ժ�� = ������� = 1, ��ȯ��� = 0/1 �϶�
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// sourcr�� target�� ���� ���
			if (s[i - 1] == t[j - 1]) {
				cost = 0;
			}
			else cost = 1;
			// ����, ����, ��ȯ �� �ּҰ��� �����Ѵ�. 
			D[i][j] = min(D[i][j - 1] + 1, min(D[i - 1][j] + 1, D[i - 1][j - 1] + cost));
			
		}
	}

	for (int j = 0; j <= m; j++) {
		for (int i = 0; i <= n; i++) {
			cout << D[i][j] << "\t";
		} cout << "\n";
	}
	// ���� �����Ÿ� return
	return D[n][m];
}
double EditDistance_b(wstring& s, wstring& t) {
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
		D2[0][j] = D2[0][j-1] + 0.7;
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
			D2[i][j] = min( D2[i][j - 1] + 0.7, min (D2[i - 1][j] + 0.5, D2[i - 1][j - 1] + cost) );
		}
	}
	for (int j = 0; j <= m; j++) {
		for (int i = 0; i <= n; i++) {
			cout << D2[i][j] << "\t";
		} cout << "\n";
	}
	// ���� �����Ÿ� return
	return D2[n][m];
}

int main() {
	setlocale(LC_ALL, "ko_KR");
	wstring s, t;
	cout << "Source: ";
	wcin >> s;
	cout << "Target: ";
	wcin >> t;
	cout << "(a) ���Ժ�� = ������� = 1, ��ȯ��� = 0/1 �϶�\n";
	cout << "Levenshtein Distance: " << EditDistance_a(s, t) << endl << endl;
	cout << "(b) ���Ժ�� = 0.7, ������� = 0.5, ��ȯ��� = 0/0.3 �϶�\n";
	cout << "Levenshtein Distance: " << EditDistance_b(s, t) << endl;
	cout << "\n12191804 ������\n";
}