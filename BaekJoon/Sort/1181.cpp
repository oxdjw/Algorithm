/*
����
���ĺ� �ҹ��ڷ� �̷���� N���� �ܾ ������ �Ʒ��� ���� ���ǿ� ���� �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

���̰� ª�� �ͺ���
���̰� ������ ���� ������
�Է�
ù° �ٿ� �ܾ��� ���� N�� �־�����. (1 �� N �� 20,000) ��° �ٺ��� N���� �ٿ� ���� ���ĺ� �ҹ��ڷ� �̷���� �ܾ �� �ٿ� �ϳ��� �־�����. �־����� ���ڿ��� ���̴� 50�� ���� �ʴ´�.

���
���ǿ� ���� �����Ͽ� �ܾ���� ����Ѵ�. ��, ���� �ܾ ���� �� �Էµ� ��쿡�� �� ������ ����Ѵ�.

���� �Է� 1 
13
but
i
wont
hesitate
no
more
no
more
it
cannot
wait
im
yours
���� ��� 1 
i
im
it
no
but
more
wait
wont
yours
cannot
hesitate
*/
#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool compare(const string& s1, const string& s2)
{
	if(s1.length() == s2.length())
	{
		return s1 < s2;
	}
	return s1.length() < s2.length();
}
int main()
{
	int N;
	cin >> N;
	vector<string> vc;
	
	for(int i = 0 ; i < N ; i++)
	{
		string s;
		cin >> s;
		if(find(vc.begin(),vc.end(),s)==vc.end())
			vc.push_back(s);
	}
	sort(vc.begin(),vc.end(),compare);
	for(int i = 0 ; i < vc.size() ; i++)
	{
		cout << vc[i] << endl;
	}
}
/*
find()�� �ߺ�üũ ���ְ�, compare�Լ��� �������ָ� �Ǵ� ������ ���Ĺ� 
*/
