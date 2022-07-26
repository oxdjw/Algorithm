/*
BOJ 17298 ��ū��
https://www.acmicpc.net/problem/17298 
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	stack<int> stk;
	int n;
	cin >> n;
	vector<int> vc(n);
	for(int i = 0 ; i < n ; i++)
	{
		int s;
		cin >> s;
		stk.push(s);
	}
	int cnt = 0;
	while(!stk.empty())	//�ð����⵵ n 
	{
		int ans = -1;
		for(int i = 0 ; i < vc.size() ; i++) //�ð����⵵ n 
		{
			if(stk.top() < vc[i])
				ans = vc[i];
		}
		vc.push_back(stk.top());
		stk.pop();
		vc[n-cnt-1] = ans;
		cnt++;
	}
	for(int i =0  ; i < n ; i++)
	{
		if(i != vc.size()-1)
			cout << vc[i] << " ";
		else
			cout << vc[i] << "\n";
	}
} 
/*
2���������� �ð��ʰ��� ���� ���ٰ� �ϴ� �����̴�
���� while���� for���� ���� ��µ� �ð��ʰ��� �ڲٸ� ���� �ڵ带 �ᱹ ���� ®��.. 
*/
