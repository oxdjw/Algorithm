/*
���� 2751 �� �����ϱ�2 
N���� ���� �־����� ��, �̸� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ���� N(1 �� N �� 1,000,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ���� �־�����. �� ���� ������ 1,000,000���� �۰ų� ���� �����̴�. ���� �ߺ����� �ʴ´�.

���
ù° �ٺ��� N���� �ٿ� ������������ ������ ����� �� �ٿ� �ϳ��� ����Ѵ�.

���� �Է� 1 
5
5
4
3
2
1
���� ��� 1 
1
2
3
4
5
*/

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	vector<int> vec;
	for(int i = 0 ; i < n ; i++)
	{
		int ipt;
		scanf("%d",&ipt);
		vec.push_back(ipt);
	}
	sort(vec.begin(),vec.end());
	for(int i = 0 ; i < n ; i++)
	{
		printf("%d\n",vec[i]);
	}
}

