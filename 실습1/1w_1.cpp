#include <iostream>
#include <ctime>
using namespace std;
#define n 200

//���� ����� ��� x �ɸ� �ð��� ����ϸ� �ȴ�
int main() {
	clock_t start, end;
	float res;
	int i;
	start = clock();

	//2�� ���(n*n���) a,b,c���� 
	int a[n][n];
	int b[n][n];
	int c[n][n];

	//��� b,c�� �� ������ ��� res1���� 
	int res1[n][n];
	//��� a,res1�� �� ������ ��� res1���� 
	int res2[n][n];

	//��� 
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

	//��� b,c�� ��
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				res1[i][j] = b[i][k] * c[k][j];
			}
		}
	}

	//��� a,res1�� ��
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