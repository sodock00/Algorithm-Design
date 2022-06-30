#include <iostream>
using namespace std;

//�迭 ��� �Լ�
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

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
        cout << "odd index\n";
        print(arr, n);

        //even ¦�� case
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
    if (sorted) cout << "���� �Ϸ�.\n";
    else cout << "���� ����!!\n";
}

int main()
{
    int arr[] = { 4, 13, 2, 5, 6, 70, 8, 3, 10, 11, 24, 23, 21, 7, 9, 12 };

    int n = sizeof(arr) / sizeof(arr[0]);


    oddEvenSort(arr, n);
    cout << "\n���� ���� ���\n";
    print(arr, n);
   

    return (0);
}