#include <iostream>
#include <ctime>
using namespace std;
#define N 100000

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

        //even 짝수 case
        for (int i = 1; i <= n - 2; i = i + 2) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                isSorted = false;
            }
        }
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
    int arr[N] = {};

    //배열에 랜덤값 삽입
    for (int j = 0; j < N; j++)
        arr[j] = rand() % 1001;

    clock_t start, end;
    float res;
    start = clock();
    oddEvenSort(arr, N);
    end = clock();
    res = (float)(end - start);

    cout << "N = "
        << N << " 일 경우 실행 시간 : " << res << "ms" << endl;

    checkSort(arr, N);

    return (0);
}