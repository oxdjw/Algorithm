/*
����
������ �����ϴ� ť�� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� ���� �����̴�.

push X: ���� X�� ť�� �ִ� �����̴�.
pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ť�� ����ִ� ������ ������ ����Ѵ�.
empty: ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
front: ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
�Է�
ù° �ٿ� �־����� ����� �� N (1 �� N �� 10,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����. �־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. ������ �������� ���� ����� �־����� ���� ����.

���
����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.

���� �Է� 1 
15
push 1
push 2
front
back
size
empty
pop
pop
pop
size
empty
pop
push 3
empty
front
���� ��� 1 
1
2
2
0
1
2
-1
0
1
-1
0
3
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	queue<int> que;
	int n;
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++)
	{
		string s;
		cin >> s;
		if(s == "push")
		{
			int j;
			scanf("%d",&j);
			que.push(j);
		}
		else if(s == "pop")
		{
			if(!que.empty())
			{
				printf("%d\n",que.front());
				que.pop();
			}
			else
			{
				printf("-1\n");
			}
		}
		else if(s == "size")
		{
			printf("%d\n",que.size());
		}
		else if(s == "empty")
		{
			if(que.empty())
			{
				printf("1\n");
			}
			else
			{
				printf("0\n");
			}
		}
		else if(s == "front")
		{
			if(!que.empty())
			{
				printf("%d\n",que.front());
			}
			else
			{
				printf("-1\n");
			}
		}
		else if(s == "back")
		{
			if(!que.empty())
			{
				printf("%d\n",que.back());
			}
			else
			{
				printf("-1\n");
			}
		}
	}
}
