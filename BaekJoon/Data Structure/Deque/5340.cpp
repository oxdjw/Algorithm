/*
BOJ 5430 AC
https://www.acmicpc.net/problem/5430
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int testcase;
	scanf("%d",&testcase);
	string command;
	while(testcase--)
	{
		deque<int> dq;
		bool reverse = false;
		bool errorFlag = false;	//���� �߻��� ������� �ʰԲ�  
		cin >> command;
		int n;
		scanf("%d",&n);
		string elem;
		cin >> elem;
		string str = "";	//[����,����,����..] �� �����ε� ���ڰ� ���ڸ��� �� ��� ��� 
		for(int i = 0 ; i < elem.length() ; i++)
		{
			if(elem[i] == '[')
				continue;
			else if('0' <= elem[i] && elem[i] <= '9')	//���ڸ� �켱 ���� 
				str += elem[i];
			else if(elem[i] == ',' || elem[i] == ']')	//,�� ]�� ���� ������ �� deque�� push 
			{
				if(!str.empty())
				{
					dq.push_back(stoi(str));
					str.clear();
				}
			}
		}
		for(int i = 0 ; i < command.length() ; i++)
		{
			if(command[i] == 'R')	//������ ��� reverse���� �̿��ؼ� front,back ����  
			{
				if(reverse)
					reverse = false;
				else reverse = true;
			}
			else
			{
				if(dq.empty())
				{
					cout << "error\n"; 
					errorFlag = true;
					break;
				}
				if(reverse)
				{
					dq.pop_back();
				}
				else
				{
					dq.pop_front();
				}
			}
		}
		
		if(!errorFlag)
		{	//reverse ���� �̿��Ͽ� ������ش� ������� ��� [] ��µǰԲ� dq.empty()Ȱ�� 
			printf("[");
			if(!reverse && !dq.empty())
			{	
				for(int i = 0 ; i < dq.size() ; i++)
				{
					if(i != dq.size()-1)
						printf("%d,",dq[i]);
					else
						printf("%d",dq[i]);
				}
			}
			else if(reverse&&!dq.empty())
			{			
				for(int i = dq.size()-1 ; i >= 0 ; i--)
				{	
					if(i != 0)
						printf("%d,",dq[i]);
					else
						printf("%d",dq[i]);
				}
			}
		if(!errorFlag)
			printf("]\n");
		}
	}
}
