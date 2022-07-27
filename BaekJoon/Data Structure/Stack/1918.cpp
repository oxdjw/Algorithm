/*
BOJ 1918 ����ǥ���
https://www.acmicpc.net/problem/1918
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	stack<pair<char,int>> st;	//<������,�켱����> �־��� stack  
	vector<pair<char,int>> vc;	//�Է¹��� <string ��,�켱����> �� �ɰ��� �־��� vector 
	string s;
	cin >> s;	//���� �Է¹ޱ�  
	for(int i = 0 ; i < s.length() ; i++)	//string�� �ε��� �ϳ��ϳ� �켱���� �����ؼ� vector�� �־��ֱ�  
	{
		char c = s[i];
		if(c >= 'A' && c <= 'Z')
		{
			vc.push_back(make_pair(c,0));
		}
		else if(c == '+' || c == '-')
		{
			vc.push_back(make_pair(c,1));
		}
		else if(c == '*' || c == '/')
		{
			vc.push_back(make_pair(c,2));
		}
		else	// '(' or ')'
		{
			vc.push_back(make_pair(c,3));
		}
	}
	
	for(int i = 0 ; i < s.length() ; i++)
	{
		if(vc[i].second == 0) // 'A' ~ 'Z'�� �׳� ��� 
			printf("%c",s[i]);
		else
		{
			if(vc[i].first == ')') //')'�� ������ش� 
			{
				while(st.top().first != '(')	//��ȣ�� ���� �� ���� 
				{
					printf("%c",st.top().first);	//�����ڵ� ���Ƽ� ��� 
					st.pop();
				}
				st.pop();	//���� '(' ��� 
				if(i != s.length()-1)	//������ �ε������� ���� ������ 74���� ������ �� ������� �ڵ�� �����ϹǷ� continue ������ �ʴ´� 
				{
					continue;	//������ �ε����� �ƴ� ��쿣 ( ) ���� �͵� �� ó�� �����Ƿ� �ٷ� ���� �ε����� �Ѿ�Բ� continue;  
				}
			}
			if(st.empty())	//������ ������ ��������� ���� �͵� �����Ƿ� �׳� �־��� 
			{
				st.push(vc[i]);
			}
			else
			{
				while(!st.empty() && st.top().second >= vc[i].second)	//���ÿ� ���� �����ڶ� top�̶� �� 
				{
					if(st.top().second != 3) //'(',')' �� �ƴϸ� �� ��� 
					{
						printf("%c",st.top());
						st.pop();
					}
					else break;
				}
				st.push(vc[i]);
			}
		}
		if(i == s.length()-1)	//���� �ε��� ���������� ���� �� ���� ������ �� ��� 
		{
			while(!st.empty())
			{
				if(st.top().second != 3) //'(',')' �� �ƴϸ� �� ��� 
					printf("%c",st.top().first);
				st.pop();
			}
		}
	}
} 
