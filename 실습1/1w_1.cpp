#include <iostream>
#include <ctime>
using namespace std;
#define n 200

//연산 결과는 출력 x 걸린 시간만 출력하면 된다
int main() {
	clock_t start, end;
	float res;
	int i;
	start = clock();

	//2차 행렬(n*n행렬) a,b,c선언 
	int a[n][n];
	int b[n][n];
	int c[n][n];

	//행렬 b,c의 곱 저장할 행렬 res1선언 
	int res1[n][n];
	//행렬 a,res1의 곱 저장할 행렬 res1선언 
	int res2[n][n];

	//행렬 
	for (int i = 0; i < n; i++) {
		int num = 1;
		for (int j = 0; j < n; j++) {
			a[i][j] = num;
		}
	}
	for (int i = 0; i < n; i++) {
		int num = 2;
		for (int j = 0; j < n; j++) {
			b[i][j] = num;
		}
	}
	for (int i = 0; i < n; i++) {
		int num = 3;
		for (int j = 0; j < n; j++) {
			c[i][j] = num;
		}
	}

	//행렬 b,c의 곱
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				res1[i][j] = b[i][k] * c[k][j];
			}
		}
	}

	//행렬 a,res1의 곱
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				res2[i][j] = a[i][k] * res1[k][j];
			}
		}
	}

	end = clock();
	res = (float)(end - start);
	cout << res << "ms" << endl;

	return 0;
}