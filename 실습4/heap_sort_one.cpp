#include <iostream>
using namespace std;

void maxHeapSort(int*);
void maxHeapify(int*, int, int);
void minHeapSort(int*);
void minHeapify(int*, int, int);

void print(int* arr)
{
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

int main() {
	int arr[10] = { 6, 2, 8, 1, 3, 9, 4, 5, 10, 7 };

	minHeapSort(arr);
	cout << "MinHeap ���� ���: \n";
	print(arr);

	maxHeapSort(arr);
	cout << "MaxHeap ���� ���: \n";
	print(arr);

}

void maxHeapSort(int* arr) {
	//���� ũ�� n - 1 (arr[1:n]�� ���Ҹ� ������������ ����)
	int n = 10;

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
void maxHeapify(int* arr, int n, int i) {
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
void minHeapSort(int* arr) {
	//���� ũ�� n - 1 (arr[1:n]�� ���Ҹ� ������������ ����)
	int n = 10;

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
void minHeapify(int* arr, int n, int i) {
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