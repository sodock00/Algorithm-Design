#include <iostream>
using namespace std;
#define N 1000000

void maxHeapSort(int*&);
void maxHeapify(int*&, int, int);
void minHeapSort(int*&);
void minHeapify(int*&, int, int);

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

void maxcheckSort(int* arr, int n) {
	int i, sorted;
	sorted = true;
	for (i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			sorted = false;
		}
		if (!sorted) break;
	}
	if (sorted) cout << "Maxheap sorting �Ϸ�.\n";
	else cout << "Maxheap sorting ����!!\n";
}
void mincheckSort(int* arr, int n) {
	int i, sorted;
	sorted = true;
	for (i = n - 1; i < 0; i--) {
		if (arr[i] < arr[i + 1]) {
			sorted = false;
		}
		if (!sorted) break;
	}
	if (sorted) cout << "Minheap sorting �Ϸ�.\n";
	else cout << "Minheap sorting ����!!\n";
}

int main() {
	int* arr = new int[N];
	clock_t start, end;
	float res;

	for (int i = 0; i < N; i++) {
		arr[i] = rand() % N;
	}
	start = clock();
	maxHeapSort(arr);
	maxcheckSort(arr, N);
	end = clock();
	res = (float)(end - start);

	cout << "Maxheap sorting ���� �ð� (N = "
		<< N << "): " << res << "ms" << endl;

	for (int i = 0; i < N; i++) {
		arr[i] = rand() % N;
	}
	start = clock();
	minHeapSort(arr);
	mincheckSort(arr, N);
	end = clock();
	res = (float)(end - start);

	cout << "Minheap sorting ���� �ð� (N = "
		<< N << "): " << res << "ms" << endl;
}

void maxHeapSort(int*& arr) {
	//���� ũ�� n - 1 (arr[1:n]�� ���Ҹ� ������������ ����)
	int n = static_cast<int>(_msize(arr) / sizeof(int));

	//�迭 arr[]�� ������ ��ȯ (������������)
	for (int i = n / 2 - 1; i >= 0; i--) {
		maxHeapify(arr, n, i); //i�� ���� ���
	}

	//�迭 arr[]�� ������������ ����
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]); //���� ū ���� a[0]�� a[i]�� ��ȯ
		maxHeapify(arr, i, 0);
	}
}
void maxHeapify(int*& arr, int n, int i) {
	//���� �������� ����� �ִ� ���� ���� ��ȣ�� m
	int p = i; //�θ� ���
	int left = i * 2 + 1; //���� �ڽ� ���
	int right = i * 2 + 2; //������ �ڽ� ���

	//���� �ڽ� ��尡 ���� ũ�⺸�� �۰� �θ� ���ʺ��� ���� ��� 
	if (left < n && arr[p] < arr[left])
		p = left; //�� ����

	//������ �ڽ� ��尡 ���� ũ�⺸�� �۰� �θ� �����ʺ��� ���� ���
	if (right < n && arr[p] < arr[right])
		p = right; //�� ����

	//�θ� ���� ���� ���� ��尡 �ٲ���� ���
	//�����ڵ� �󿡼� �ݺ������� ���������� ���
	if (i != p) {
		//���� ���� �θ� ��� ���� �ٲ��ش�.
		swap(arr[i], arr[p]);
		maxHeapify(arr, n, p);
	}
}
void minHeapSort(int*& arr) {
	//���� ũ�� n - 1 (arr[1:n]�� ���Ҹ� ������������ ����)
	int n = static_cast<int>(_msize(arr) / sizeof(int));

	//�迭 arr[]�� ������ ��ȯ (������������)
	for (int i = n / 2 - 1; i >= 0; i--) {
		minHeapify(arr, n, i); //i�� ���� ���
	}

	//�迭 arr[]�� ������������ ����
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]); //���� ū ���� a[0]�� a[i]�� ��ȯ
		minHeapify(arr, i, 0);
	}
}
void minHeapify(int*& arr, int n, int i) {
	//���� �������� ����� �ִ� ���� ���� ��ȣ�� m
	int p = i; //�θ� ���
	int left = i * 2 + 1; //���� �ڽ� ���
	int right = i * 2 + 2; //������ �ڽ� ���

	//���� �ڽ� ��尡 ���� ũ�⺸�� �۰� �θ� ���ʺ��� Ŭ ��� 
	if (left < n && arr[p] > arr[left])
		p = left; //�� ����

	//������ �ڽ� ��尡 ���� ũ�⺸�� �۰� �θ� �����ʺ��� Ŭ ���
	if (right < n && arr[p] > arr[right])
		p = right; //�� ����

	//�θ� ���� ���� ���� ��尡 �ٲ���� ���
	//�����ڵ� �󿡼� �ݺ������� ���������� ���
	if (i != p) {
		//���� ���� �θ� ��� ���� �ٲ��ش�.
		swap(arr[i], arr[p]);
		minHeapify(arr, n, p);
	}
}