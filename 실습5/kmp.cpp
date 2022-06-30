#include<iostream>
#include<string>
using namespace std;

int* InitNext(string pattern)
{
	int M = pattern.size(); //������ ���� ������ ����
	int* Next = new int[M]; //next�迭 �����Ҵ����� ����
	Next[0] = 0;
	int j = 0;
	for (int i = 1; i < M; i++) //for �ݺ����� ���� next �迭 �� ä����
	{
		while (j > 0 && pattern[j] != pattern[i])
			j = Next[j - 1]; //���� ���� ��� next�迭 ������ ���ư�
		if (pattern[j] == pattern[i]) 
			j = j + 1;
		Next[i] = j;
	}
	return Next;
}

//KMP�Լ� 
void kmp(string text, string pattern) 
{
	int* Next = InitNext(pattern); //next�迭�� initNext �Լ��� ��� ������ �޾ƿ�
	int j = 0;
	for (int i = 0; i < text.length(); i++)
	{
		while (j > 0 && pattern[j] != text[i]) //���� ���� ���� ���
			j = Next[j - 1]; //���ư�

		if (pattern[j] == text[i])//���� ���� ���
			j = j + 1; //���� j������ �� ���� 

		if (j == (pattern.length()))
		{
			cout << "������ �߻��� ��ġ: " << i - (pattern.length() - 1) << endl;
			j = Next[j - 1];
		}
	}
	cout << "Ž�� ����" << endl;
}
int main()
{
	string p = "algorithm" ;
	string t = "This class is an algorithm design class. Therefore, students will have time to learn about algorithms and implement each algorithm themselves.";

	kmp(t, p);

	return 0;
}