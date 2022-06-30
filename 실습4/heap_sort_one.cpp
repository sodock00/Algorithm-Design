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
	cout << "MinHeap 정렬 결과: \n";
	print(arr);

	maxHeapSort(arr);
	cout << "MaxHeap 정렬 결과: \n";
	print(arr);

}

void maxHeapSort(int* arr) {
	//힙의 크기 n - 1 (arr[1:n]의 원소를 오름차순으로 정렬)
	int n = 10;

	//배열 arr[]을 힙으로 변환 (오름차순으로)
	for (int i = n / 2 - 1; i >= 0; i--) {
		maxHeapify(arr, n, i); //i는 내부 노드
	}

	//배열 arr[]을 오름차순으로 정렬
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]); //제일 큰 원소 a[0]과 a[i]를 교환
		maxHeapify(arr, i, 0);
	}
}
void maxHeapify(int* arr, int n, int i) {
	//현재 시점으로 노드의 최대 레벨 순서 번호는 m
	int p = i; //부모 노드
	int left = i * 2 + 1; //왼쪽 자식 노드
	int right = i * 2 + 2; //오른쪽 자식 노드

	//왼쪽 자식 노드가 힙의 크기보다 작고 부모가 왼쪽보다 작을 경우 
	if (left < n && arr[p] < arr[left])
		p = left; //값 변경

	//오른쪽 자식 노드가 힙의 크기보다 작고 부모가 오른쪽보다 작을 경우
	if (right < n && arr[p] < arr[right])
		p = right; //값 변경

	//부모 노드와 기존 상위 노드가 바뀌었을 경우
	//슈도코드 상에서 반복문에서 빠져나왔을 경우
	if (i != p) {
		//상위 노드와 부모 노드 값을 바꿔준다.
		swap(arr[i], arr[p]);
		maxHeapify(arr, n, p);
	}
}
void minHeapSort(int* arr) {
	//힙의 크기 n - 1 (arr[1:n]의 원소를 내림차순으로 정렬)
	int n = 10;

	//배열 arr[]을 힙으로 변환 (내림차순으로)
	for (int i = n / 2 - 1; i >= 0; i--) {
		minHeapify(arr, n, i); //i는 내부 노드
	}

	//배열 arr[]을 내림차순으로 정렬
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]); //제일 큰 원소 a[0]과 a[i]를 교환
		minHeapify(arr, i, 0);
	}
}
void minHeapify(int* arr, int n, int i) {
	//현재 시점으로 노드의 최대 레벨 순서 번호는 m
	int p = i; //부모 노드
	int left = i * 2 + 1; //왼쪽 자식 노드
	int right = i * 2 + 2; //오른쪽 자식 노드

	//왼쪽 자식 노드가 힙의 크기보다 작고 부모가 왼쪽보다 클 경우 
	if (left < n && arr[p] > arr[left])
		p = left; //값 변경

	//오른쪽 자식 노드가 힙의 크기보다 작고 부모가 오른쪽보다 클 경우
	if (right < n && arr[p] > arr[right])
		p = right; //값 변경

	//부모 노드와 기존 상위 노드가 바뀌었을 경우
	//슈도코드 상에서 반복문에서 빠져나왔을 경우
	if (i != p) {
		//상위 노드와 부모 노드 값을 바꿔준다.
		swap(arr[i], arr[p]);
		minHeapify(arr, n, p);
	}
}