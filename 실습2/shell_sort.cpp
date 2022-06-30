#include <iostream>
#include <ctime>
using namespace std;

void ShellSort_one(int *a,int n) {
	int h, i, j, v;
	clock_t start, end;
	float res;
	start = clock();

	//ù��° h�� ���
	for (h = 1; h < n; h = h * 3 + 1);

	//h���� ���ҽ�Ű�� ����
	for (; h > 0; h = h / 3) {
		for (i = h + 1; i <= n; i++) {
			v = a[i];
			j = i;

			while (j > h && a[j - h] > v) {
				a[j] = a[j - h];
				j = j - h;
			}
			a[j] = v;
		}
	}

	end = clock();
	res = (float)(end - start);

	cout << "������: 3h + 1, ���ҽ�: h/3�� ���� ���� �ð� (N = "
		<< n << "): " << res << "ms" << endl;
}

void ShellSort_two(int* a, int n) {
	int h, i, j, v;
	clock_t start, end;
	float res;
	start = clock();

	//ù��° h�� ���
	for (h = 1; h < n; h = h * 3);

	//h���� ���ҽ�Ű�� ����
	for (; h > 0; h = h / 3) {
		for (i = h + 1; i <= n; i++) {
			v = a[i];
			j = i;

			while (j > h && a[j - h] > v) {
				a[j] = a[j - h];
				j = j - h;
			}
			a[j] = v;
		}
	}

	end = clock();
	res = (float)(end - start);

	cout << "������: 3h, ���ҽ�: h/3�� ���� ���� �ð� (N = "
		<< n << "): " << res << "ms" << endl;
}

void ShellSort_three(int* a, int n) {
	int h, i, j, v;
	clock_t start, end;
	float res;
	start = clock();

	//ù��° h�� ���
	for (h = 1; h < n; h = h * 5 + 1);

	//h���� ���ҽ�Ű�� ����
	for (; h > 0; h = h / 5) {
		for (i = h + 1; i <= n; i++) {
			v = a[i];
			j = i;

			while (j > h && a[j - h] > v) {
				a[j] = a[j - h];
				j = j - h;
			}
			a[j] = v;
		}
	}

	end = clock();
	res = (float)(end - start);

	cout << "������: 5h + 1, ���ҽ�: h/5�� ���� ���� �ð� (N = "
		<< n << "): " << res << "ms" << endl;
}

void checkSort(int *a, int n) {
	int i, sorted;
	sorted = true;
	for (i = 0; i < n; i++) {
		if (a[i] > a[i + 1]) {
			sorted = false;
		}
		if (!sorted) break;
	}
	if (sorted) cout << "���� �Ϸ�.\n";
	else cout << "���� ����!!\n";
}

int main() {
	int n[5] = { 100000, 500000, 1000000, 5000000, 10000000 };
	//���� �迭 ���� 
	for (int i = 0; i < 5; i++) {
		int* list = new int[n[i]+1];
		
		//�迭�� ������ ����
		for (int j = 1; j <= n[i]; j++) 
			list[j] = rand() % n[i];

		ShellSort_one(list,n[i]);
		checkSort(list,n[i]);
	}
	cout << endl;
	for (int i = 0; i < 5; i++) {
		int* list = new int[n[i] + 1];

		//�迭�� ������ ����
		for (int j = 1; j <= n[i]; j++)
			list[j] = rand() % n[i];

		ShellSort_two(list, n[i]);
		checkSort(list, n[i]);
	}
	cout << endl;
	for (int i = 0; i < 5; i++) {
		int* list = new int[n[i] + 1];

		//�迭�� ������ ����
		for (int j = 1; j <= n[i]; j++)
			list[j] = rand() % n[i];

		ShellSort_three(list, n[i]);
		checkSort(list, n[i]);
	}



	return 0;
}