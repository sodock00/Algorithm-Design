#include<iostream>
#include<string>
#include <cstring>
#include<stdlib.h>
#include <fstream>

using namespace std;

#define NUM 256
int skip[256];
// 27�� ���ĺ��� ��

int index(char a) {
    if (a == 32)
        return 0;
    // a �� space ��, index�� 0
    else
        return (a - 32);
    // �ƽ�Ű�ڵ� Ư����ȣ�� ������ 33������ ����
    // ���� ! - 32 = 1 �̹Ƿ� index�� 1
}

void InitSkip(char* p) {
    int i, M = strlen(p);

    for (i = 0; i < NUM; i++)
        skip[i] = M;
    // skip ���� ��� M ���� �ʱ�ȭ

    for (i = 0; i < M; i++)
        skip[index(p[i])] = M - i - 1;
    // int�� ����ȯ�� ���� �ε����� ����Ѵ�.
    // ���Ͽ� �ش��ϴ� ���ڵ鸸 �ش� ��ġ�� ���� ���� �־��ش�. (�������� �ǳʶ�)
}

int MisChar(char p[], char t[]) {
    int M = strlen(p); // ������ ����
    int N = strlen(t); // �ؽ�Ʈ�� ����
    int i, j, k;

    InitSkip(p);
    for (i = M - 1, j = M - 1; j >= 0; i--, j--) {
        // ���̾� ���� �˰����� �ڿ������� ����Ǳ� ������ i�� j�� ���� 1�� �����Ѵ�. 
        while (t[i] != p[j]) { // text�� pattern�� �ٸ� ���
            k = skip[index(t[i])]; // Ʋ�� index�� ���° index ���� skip�� ����

            if (M - j > k) { // M-j > k �� ���(�̵��Ÿ� ��)
                i = i + M - j;
            }
            else i = i + k; // M-j <= k �� ���

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

    //���� �о����
    int array_size = 60000;
    char* t = new char[array_size];
    int position = 0;

    ifstream fin("RFC2616_modified.txt");
    if (fin.is_open()) {
        cout << "���� ���� ����" << endl;
        while (!fin.eof()) {
            fin.get(t[position]);
            position++;
        }
        t[position - 1] = '\0';
    }
    else //���� ���� ���н�
    {
        cout << "���� ���� ����" << endl;
    }

    int M, N;
    int pos = 0;
    int pre = 0;
    int i = 0;

    cout << "����: ";
    cin >> p;

    M = strlen(p);
    N = strlen(t);

    for (;;) {
        pos = MisChar(p, t + pre);
        pos = pos + pre;
        i = pos + M;

        if (i <= N)
            printf("������ �߻��� ��ġ : %d\n", pos);
        else
            break;

        pre = i;
    }
    cout << "��Ʈ�� Ž�� ����.\n";
    cout << "12191804 ������\n";
}