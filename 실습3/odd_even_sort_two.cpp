#include <iostream>
#include <ctime>
using namespace std;
#define N 100000

void oddEvenSort(int arr[], int n)
{
    bool isSorted = false;

    while (!isSorted) { //������ �� ������ �ݺ�
        isSorted = true;

        //odd Ȧ�� case
        for (int i = 0; i <= n - 2; i = i + 2) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                isSorted = false;
            }
        }

        //even ¦�� case
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
    if (sorted) cout << "���� �Ϸ�.\n";
    else cout << "���� ����!!\n";
}

int main()
{
    int arr[N] = {};

    //�迭�� ������ ����
    for (int j = 0; j < N; j++)
        arr[j] = rand() % 1001;

    clock_t start, end;
    float res;
    start = clock();
    oddEvenSort(arr, N);
    end = clock();
    res = (float)(end - start);

    cout << "N = "
        << N << " �� ��� ���� �ð� : " << res << "ms" << endl;

    checkSort(arr, N);

    return (0);
}