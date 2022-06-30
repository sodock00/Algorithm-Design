#include <iostream>
#include <ctime>
using namespace std;

//피보나치 수열

int Fibo(int num) {
    if (num == 0) return 0;
    else if (num == 1)return 1;
    else return Fibo(num - 1) + Fibo(num - 2);
}

int main() {

    clock_t start, end;
    float res;
    int i;
    start = clock();

    int num;
    cin >> num;
    Fibo(num);

    end = clock();
    res = (float)(end - start);
    cout << res << "ms" << endl;


    return 0;
}