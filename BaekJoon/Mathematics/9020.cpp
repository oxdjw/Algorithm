/*
BOJ 9020 �������� ����
https://www.acmicpc.net/problem/9020 
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int sosu[10000] = {0};
	for(int i = 1 ; i < 10000 ; i++)
	{
		sosu[i] = 1;
	}
	for(int i = 2 ; i < sqrt(10000) ; i++)
	{
		if(sosu[i] == 0)
			continue;
		for(int j = i+i ; j < 10000 ; j += i)
		{
			sosu[j] = 0;
		}
	}//�������� ������ �ִ� ���� 10000������ �Ҽ����� �迭�� �̸� ǥ���س��´� 
	int n;
	cin >> n;
	
	for(int testcase = 0 ; testcase < n ; testcase++)
	{
		vector<pair<int,int>> vc;
		int input;
		cin >> input;//���� �Է¹ް�  
		for(int i = 2 ; i < input ; i++) //� �� ���� ������ �� input�� �Ǿ�� �ϰ� �Ҽ��� ���Ǳ��� ������ 
		{		//input��ŭ ����� ���� �̾� �����ְ� �Ҽ��迭�� �Ǵ��Ͽ� �� �� ��� �Ҽ��̸� pair�� push_back 
			if(sosu[i] == 1 && sosu[input-i] == 1)
				vc.push_back(make_pair(i,input-i));
		}	//���ļ� input�� �ǰ�, �� �� ��� �Ҽ��� ����� �����ֵ��� vc�� �־��� ����
		int mingap = 10000;	 //�������� �ּ� ���̸� �˱����� mingap���� 
		pair<int,int> answer;
		for(int i = 0 ; i < vc.size() ; i++)
		{
			if(mingap > (vc[i].first - vc[i].second > 0 ? vc[i].first - vc[i].second : (-1)*(vc[i].first - vc[i].second ) ) )
			{	//���̰� �ּ��� ��쿡 answer�� �� pair�� ��� ���ŵǰԲ� ���� 
				mingap = (vc[i].first - vc[i].second > 0 ? vc[i].first - vc[i].second : (-1)*(vc[i].first - vc[i].second ) );
				answer.first = vc[i].first;
				answer.second = vc[i].second;
			}
		}
		cout << answer.first <<" " << answer.second << "\n";
	}
}
