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

//frequency가 더 큰 것을 찾는다. 
class compare {
public:
	bool operator() (nodetype* a, nodetype* b) {
		return (a->frequency > b->frequency);
	}
};

//코드 출력 함수
void print_codes(nodetype* node, string str) {
	if (node != nullptr) {
		//더미데이터가 아닐 경우에만 출력
		if (node->symbol.compare("*") != 0)
			cout << node->symbol[] << " " << str << endl;

		print_codes(node->left, str + '0');
		print_codes(node->right, str + '1');
	}
}

// null이 될 때 까지 반복해서 노드를 삭제하는 함수
void remove(nodetype* node) {
	if (node != nullptr) {
		remove(node->left);
		remove(node->right);

		delete node;
	}
}

//허프만 암호화 함수
void huffman_encode(char* arr, int* freq, size_t n) {
	nodetype* left, * right, * r;
	//PQ(priority_queue) p 선언
	priority_queue<nodetype*, vector<nodetype*>, compare> q;

	// PG(우선순위 큐)에 문자열 데이터 넣기
	for (size_t i = 0; i < n; i++) {
		q.push(new nodetype(arr[i], freq[i]));
	}

	// PQ에 가장 작은 값들을 pop 출력하는 과정
	for (size_t i = 1; i < n; i++) {
		left = q.top();
		q.pop();

		right = q.top();
		q.pop();

		// 빈 문자열 대신 *을 사용하여 채워넣음
		r = new nodetype('*', left->frequency + right->frequency, left, right);
		q.push(r);
	}

	print_codes(q.top(), "");

	remove(q.top());
}

int main() {
	//문자열
	char symbol[] = { 'ROOT', 'ABC', 'ABCC', 'AB', 'A', 'B', 'BABA' };
	//각 문자의 빈도수
	int frequency[] = { 27, 12, 7, 19, 35, 40, 15 };
	
	//허프만 암호화
	huffman_encode(symbol, frequency, sizeof(symbol));

	return 0;
}