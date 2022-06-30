#include <iostream>
#include <algorithm>
#include <string>
#include <locale>
using namespace std;
// 메모리 문제 때문에 전역 변수로 2차원 배열 선언
int D[1001][1001];
double D2[1001][1001];

int EditDistance_a(wstring& s, wstring& t) {
	// string
	int n = s.length();
	int m = t.length();
	// 교환비용 변수
	int cost = 0; 

	D[0][0] = 0;
	// 첫 행 (삭제) 1씩 증가
	for (int i = 1; i <= n; i++) {
		D[i][0] = D[i - 1][0] + 1;
	}
	// 첫 열 (삽입) 1씩 증가
	for (int j = 1; j <= m; j++) {
		D[0][j] = D[0][j - 1] + 1;
	}
	// (a) 케이스 > 삽입비용 = 삭제비용 = 1, 교환비용 = 0/1 일때
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// sourcr과 target이 같을 경우
			if (s[i - 1] == t[j - 1]) {
				cost = 0;
			}
			else cost = 1;
			// 삽입, 삭제, 교환 중 최소값을 선택한다. 
			D[i][j] = min(D[i][j - 1] + 1, min(D[i - 1][j] + 1, D[i - 1][j - 1] + cost));
			
		}
	}

	for (int j = 0; j <= m; j++) {
		for (int i = 0; i <= n; i++) {
			cout << D[i][j] << "\t";
		} cout << "\n";
	}
	// 최종 편집거리 return
	return D[n][m];
}
double EditDistance_b(wstring& s, wstring& t) {
	// string
	int n = s.length();
	int m = t.length();
	// 교환비용 변수
	double cost = 0;

	D2[0][0] = 0;
	// 첫 행 (삭제) 0.5씩 증가
	for (int i = 1; i <= n; i++) {
		D2[i][0] = D2[i - 1][0] + 0.5;
	}
	// 첫 열 (삽입) 0.7씩 증가
	for (int j = 1; j <= m; j++) {
		D2[0][j] = D2[0][j-1] + 0.7;
	}
	// (b) 삽입비용 = 0.7, 삭제비용 = 0.5, 교환비용 = 0/0.3 일때
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// string과 text가 같을 경우
			if (s[i - 1] == t[j - 1]) {
				cost = 0;
			}
			else cost = 0.3;
			// 삽입, 삭제, 교환 중 최소값을 선택한다. 
			D2[i][j] = min( D2[i][j - 1] + 0.7, min (D2[i - 1][j] + 0.5, D2[i - 1][j - 1] + cost) );
		}
	}
	for (int j = 0; j <= m; j++) {
		for (int i = 0; i <= n; i++) {
			cout << D2[i][j] << "\t";
		} cout << "\n";
	}
	// 최종 편집거리 return
	return D2[n][m];
}

int main() {
	setlocale(LC_ALL, "ko_KR");
	wstring s, t;
	cout << "Source: ";
	wcin >> s;
	cout << "Target: ";
	wcin >> t;
	cout << "(a) 삽입비용 = 삭제비용 = 1, 교환비용 = 0/1 일때\n";
	cout << "Levenshtein Distance: " << EditDistance_a(s, t) << endl << endl;
	cout << "(b) 삽입비용 = 0.7, 삭제비용 = 0.5, 교환비용 = 0/0.3 일때\n";
	cout << "Levenshtein Distance: " << EditDistance_b(s, t) << endl;
	cout << "\n12191804 이은진\n";
}