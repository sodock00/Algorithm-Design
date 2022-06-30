#include<iostream>
#include<string>
using namespace std;

int* InitNext(string pattern)
{
	int M = pattern.size(); //패턴의 길이 변수에 저장
	int* Next = new int[M]; //next배열 동적할당으로 선언
	Next[0] = 0;
	int j = 0;
	for (int i = 1; i < M; i++) //for 반복문을 통해 next 배열 값 채워줌
	{
		while (j > 0 && pattern[j] != pattern[i])
			j = Next[j - 1]; //같지 않을 경우 next배열 값으로 돌아감
		if (pattern[j] == pattern[i]) 
			j = j + 1;
		Next[i] = j;
	}
	return Next;
}

//KMP함수 
void kmp(string text, string pattern) 
{
	int* Next = InitNext(pattern); //next배열을 initNext 함수의 결과 값으로 받아옴
	int j = 0;
	for (int i = 0; i < text.length(); i++)
	{
		while (j > 0 && pattern[j] != text[i]) //값이 같지 않을 경우
			j = Next[j - 1]; //돌아감

		if (pattern[j] == text[i])//값이 같을 경우
			j = j + 1; //다음 j값으로 비교 시작 

		if (j == (pattern.length()))
		{
			cout << "패턴이 발생한 위치: " << i - (pattern.length() - 1) << endl;
			j = Next[j - 1];
		}
	}
	cout << "탐색 종료" << endl;
}
int main()
{
	string p = "algorithm" ;
	string t = "This class is an algorithm design class. Therefore, students will have time to learn about algorithms and implement each algorithm themselves.";

	kmp(t, p);

	return 0;
}