#include <iostream>
using namespace std;

//배열 출력 함수
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void oddEvenSort(int arr[], int n)
{
    bool isSorted = false;

    while (!isSorted) { //정렬이 될 때까지 반복
        isSorted = true;

        //odd 홀수 case
        for (int i = 0; i <= n - 2; i = i + 2) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                isSorted = false;
            }
        }
        cout << "odd index\n";
        print(arr, n);

        //even 짝수 case
        for (int i = 1; i <= n - 2; i = i + 2) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                isSorted = false;
            }
        }
        cout << "even index\n";
        print(arr, n);
    }

    return;
}


void checkSort(int* arr, int n) {
    int i, sorted;
    sorted = true;
    for (i = 0; i < n-1; i++) {
        if (arr[i] > arr[i + 1]) {
            sorted = false;
        }
        if (!sorted) break;
    }
    if (sorted) cout << "정렬 완료.\n";
    else cout << "정렬 오류!!\n";
}

int main()
{
    int arr[] = { 4, 13, 2, 5, 6, 70, 8, 3, 10, 11, 24, 23, 21, 7, 9, 12 };

    int n = sizeof(arr) / sizeof(arr[0]);


    oddEvenSort(arr, n);
    cout << "\n최종 정렬 결과\n";
    print(arr, n);
   

    return (0);
}