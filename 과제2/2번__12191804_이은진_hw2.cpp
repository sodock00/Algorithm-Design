#include <iostream>
#include <algorithm>
#include <string>
#include <locale>
using namespace std;
// 메모리 문제 때문에 전역 변수로 2차원 배열 선언
double D2[1001][1001];

void EditDistanceRoute(wstring& s, wstring& t, double minNum) {
	// string
	int n = s.length();
	int m = t.length();

	// 아래에서 진행 될 삽입, 삭제, 교환 연산을 실행 순서대로 저장할 배열
	double* distanceList{ new double[static_cast<int>(s.length() * t.length()) + 1]{ } };
	// 삽입, 삭제, 교환 연산 중 최소값을 넣을 변수
	//double minNum = 0;

	// 행렬의 맨 끝부터 시작하게 하기 위해 반복자 i, j, k 선언
	int i = n; //5
	int j = m; //8
	int k = n * m;
	double cost ;

	while (1) {
		// 만약 minNum의 값이 현재 값과 같다면 다음 연산으로 넘김
		if ((D2[i][j] == D2[i-1][j-1]) && (i > 0 && j > 0)) {
			i--, j--;
		}
		// D2[i][j]의 값과  D2[i-1][j-1] 값이 서로 다를 경우
		// 즉, source와 target이 달라서 0이 더해지는 교환연산이 진행되지 않을 경우
		// 같은 값을 찾아 distanceList에 해당 연산에 해당하는 거리를 넣는다
		else {
			minNum = min({ D2[i][j - 1] + 0.7, D2[i - 1][j] + 0.5, D2[i - 1][j - 1] + 0.3 });
			if ((minNum == D2[i][j - 1] + 0.7) && (j > 0)) { // 삽입 연산
				distanceList[k--] = 0.7;
				j--;
			}
			else if ((minNum == D2[i - 1][j] + 0.5) && (i > 0)) { // 삭제 연산
				distanceList[k--] = 0.5;
				i--;
			}
			else if ((minNum == D2[i - 1][j - 1] + 0.3) && (i > 0 && j > 0)) { // 교환 연산
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

	// 위의 반복문에서 끝에서부터 역순으로 넣은 값을 역으로 다시 출력
	for (int i = 0; i <= (n * m); i++) {
		if (distanceList[i] == 0.7)
			cout << "삽입 연산 " << distanceList[i] << "\n";
		else if (distanceList[i] == 0.5)
			cout << "삭제 연산 " << distanceList[i] << "\n";
		else if (distanceList[i] == 0.3)
			cout << "교환 연산 " << distanceList[i] << "\n";
	}

}

double EditDistance(wstring& s, wstring& t) {
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
		D2[0][j] = D2[0][j - 1] + 0.7;
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
			D2[i][j] = min(D2[i][j - 1] + 0.7, min(D2[i - 1][j] + 0.5, D2[i - 1][j - 1] + cost));
		}
	}
	for (int j = 0; j <= m; j++) {
		for (int i = 0; i <= n; i++) {
			cout << D2[i][j] << "\t";
		} cout << "\n";
	}

	EditDistanceRoute(s, t, D2[n][m]);
	// 최종 편집거리 return
	return D2[n][m];
}

int main() {
	// 3번 예제 때문에 와이드 문자열을 사용하고 로케일을 한국의 한국어로 설정한다.
	setlocale(LC_ALL, "ko_KR");
	wstring s, t;
	cout << "Source: ";
	wcin >> s;
	cout << "Target: ";
	wcin >> t;
	cout << "삽입비용 = 0.7, 삭제비용 = 0.5, 교환비용 = 0/0.3 일때\n\n";
	cout << "Levenshtein Distance: " << EditDistance(s, t) << endl;
	cout << "\n12191804 이은진\n";
}