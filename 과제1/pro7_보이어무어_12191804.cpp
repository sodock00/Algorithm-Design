#include<iostream>
#include<string>
#include <cstring>
#include<stdlib.h>
#include <fstream>

using namespace std;

#define NUM 256
int skip[256];
// 27은 알파벳의 수

int index(char a) {
    if (a == 32)
        return 0;
    // a 가 space 면, index는 0
    else
        return (a - 32);
    // 아스키코드 특수기호의 시작은 33번부터 시작
    // 따라서 ! - 32 = 1 이므로 index는 1
}

void InitSkip(char* p) {
    int i, M = strlen(p);

    for (i = 0; i < NUM; i++)
        skip[i] = M;
    // skip 값을 모두 M 으로 초기화

    for (i = 0; i < M; i++)
        skip[index(p[i])] = M - i - 1;
    // int형 형변환을 통해 인덱스로 사용한다.
    // 패턴에 해당하는 글자들만 해당 위치에 따른 값을 넣어준다. (나머지는 건너뜀)
}

int MisChar(char p[], char t[]) {
    int M = strlen(p); // 패턴의 길이
    int N = strlen(t); // 텍스트의 길이
    int i, j, k;

    InitSkip(p);
    for (i = M - 1, j = M - 1; j >= 0; i--, j--) {
        // 보이어 무어 알고리즘은 뒤에서부터 진행되기 때문에 i와 j의 값이 1씩 감소한다. 
        while (t[i] != p[j]) { // text와 pattern이 다를 경우
            k = skip[index(t[i])]; // 틀린 index가 몇번째 index 인지 skip에 저장

            if (M - j > k) { // M-j > k 인 경우(이동거리 비교)
                i = i + M - j;
            }
            else i = i + k; // M-j <= k 인 경우

            if (i >= N) {
                return N;
            }

            j = M - 1;
        }
    }
    return i + 1;
}

int main() {
    char p[100] ;

    //파일 읽어오기
    int array_size = 60000;
    char* t = new char[array_size];
    int position = 0;

    ifstream fin("RFC2616_modified.txt");
    if (fin.is_open()) {
        cout << "파일 오픈 성공" << endl;
        while (!fin.eof()) {
            fin.get(t[position]);
            position++;
        }
        t[position - 1] = '\0';
    }
    else //파일 오픈 실패시
    {
        cout << "파일 오픈 실패" << endl;
    }

    int M, N;
    int pos = 0;
    int pre = 0;
    int i = 0;

    cout << "패턴: ";
    cin >> p;

    M = strlen(p);
    N = strlen(t);

    for (;;) {
        pos = MisChar(p, t + pre);
        pos = pos + pre;
        i = pos + M;

        if (i <= N)
            printf("패턴이 발생한 위치 : %d\n", pos);
        else
            break;

        pre = i;
    }
    cout << "스트링 탐색 종료.\n";
    cout << "12191804 이은진\n";
}