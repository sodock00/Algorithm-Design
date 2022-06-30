#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct nodetype {
	string symbol;
	int frequency;
	nodetype* left;
	nodetype* right;

	nodetype(char d, int f, nodetype* l = nullptr, nodetype* r = nullptr) {
		symbol = d;
		frequency = f;

		left = l;
		right = r;
	}
};

//frequency�� �� ū ���� ã�´�. 
class compare {
public:
	bool operator() (nodetype* a, nodetype* b) {
		return (a->frequency > b->frequency);
	}
};

//�ڵ� ��� �Լ�
void print_codes(nodetype* node, string str) {
	if (node != nullptr) {
		//���̵����Ͱ� �ƴ� ��쿡�� ���
		if (node->symbol.compare("*") != 0)
			cout << node->symbol[] << " " << str << endl;

		print_codes(node->left, str + '0');
		print_codes(node->right, str + '1');
	}
}

// null�� �� �� ���� �ݺ��ؼ� ��带 �����ϴ� �Լ�
void remove(nodetype* node) {
	if (node != nullptr) {
		remove(node->left);
		remove(node->right);

		delete node;
	}
}

//������ ��ȣȭ �Լ�
void huffman_encode(char* arr, int* freq, size_t n) {
	nodetype* left, * right, * r;
	//PQ(priority_queue) p ����
	priority_queue<nodetype*, vector<nodetype*>, compare> q;

	// PG(�켱���� ť)�� ���ڿ� ������ �ֱ�
	for (size_t i = 0; i < n; i++) {
		q.push(new nodetype(arr[i], freq[i]));
	}

	// PQ�� ���� ���� ������ pop ����ϴ� ����
	for (size_t i = 1; i < n; i++) {
		left = q.top();
		q.pop();

		right = q.top();
		q.pop();

		// �� ���ڿ� ��� *�� ����Ͽ� ä������
		r = new nodetype('*', left->frequency + right->frequency, left, right);
		q.push(r);
	}

	print_codes(q.top(), "");

	remove(q.top());
}

int main() {
	//���ڿ�
	char symbol[] = { 'ROOT', 'ABC', 'ABCC', 'AB', 'A', 'B', 'BABA' };
	//�� ������ �󵵼�
	int frequency[] = { 27, 12, 7, 19, 35, 40, 15 };
	
	//������ ��ȣȭ
	huffman_encode(symbol, frequency, sizeof(symbol));

	return 0;
}