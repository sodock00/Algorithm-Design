#include <iostream>
using namespace std;

struct Jewelry {
    int weight, val;
};

int value[101][100001], n, k;
Jewelry jewelry[101];
int result[2];

int main() {
    for (int in = 0; in < 2; in++) {
        cout << "\n�Է�" << in + 1 << "��° �� �Է�\n";

        // ������ ���� n�� �賶 ���� k�� �Է¹޴´�.
        cout << "�賶 ����: ";
        cin >> k;
        cout << "������ ����: ";
        cin >> n;

        // �������� ���Կ� ��ġ(w, v)�� ���� n��ŭ �Է¹޴´�.
        for (int i = 1; i <= n; i++) {
            int w, v;
            cin >> w >> v;
            jewelry[i] = { w, v };
        }

        // dp�� ����Ͽ� Ǯ��
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                int wi = jewelry[i].weight;
                int vi = jewelry[i].val;

                // i ��° ��ü�� ���Ը� �����ϴ� ���
                if (wi > j) {
                    value[i][j] = value[i - 1][j];
                }// i ��° ��ü�� ���Ը� �������� �ʴ� ���
                else {
                    value[i][j] = max(vi + value[i - 1][j - wi], value[i - 1][j]);
                }

            }
        }

        result[in] = value[n][k];
    }
    
    for (int j = 0; j < 2; j++) {
        cout << "�Է�" << j + 1 << "�� ���Ͽ� ���濡 ���� ������ �ִ� ��ġ : " << result[j] << "\n";
    }
    
    return 0;
}