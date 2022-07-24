/*
����
�� �������Ʈ�� ��ȸ �غ� �ϴٰ� ���������� ����ڽ� ������ ������ũ����Ʈ���� �״�. ����ũ����Ʈ�� 1 �� 1 �� 1(����, ����, ����) ũ���� ���ϵ�� �̷���� 3���� ���迡�� �����Ӱ� ���� �İų� ���� ���� �� �ִ� �����̴�.

���縦 ����� ���� lvalue�� ���� ����� �Ͽ���. ������ ������ ���� ������ ���� ���� �� ���� ������ ���� ���̸� ��� �����ϰ� ����� ���� �����⡯ �۾��� �ؾ� �Ѵ�.

lvalue�� ���� N, ���� M ũ���� ���͸� �����. ���� �� ���� ���� ��ǥ�� (0, 0)�̴�. �츮�� ������ �� ���� ���� ���� ���̸� �����ϰ� �ٲٴ� ���̴�. �츮�� ������ ���� �� ������ �۾��� �� �� �ִ�.

��ǥ (i, j)�� ���� ���� �ִ� ������ �����Ͽ� �κ��丮�� �ִ´�.
�κ��丮���� ���� �ϳ��� ������ ��ǥ (i, j)�� ���� ���� �ִ� ���� ���� ���´�.
1�� �۾��� 2�ʰ� �ɸ���, 2�� �۾��� 1�ʰ� �ɸ���. �㿡�� ������ ���͵��� ������ ������ �ִ��� ���� �� ������ �۾��� ���ľ� �Ѵ�. ���� �����⡯ �۾��� �ɸ��� �ּ� �ð��� �� ��� ���� ���̸� ����Ͻÿ�.

��, ���� �Ʒ��� ���� �� �� ������ �������� ������, ���� �ٱ����� ������ ������ �� ����. ����, �۾��� ������ �� �κ��丮���� B���� ������ ��� �ִ�. ���� ���̴� 256������ �ʰ��� �� ������, ������ �� �� ����.

�Է�
ù° �ٿ� N, M, B�� �־�����. (1 �� M, N �� 500, 0 �� B �� 6.4 �� 107)

��° �ٺ��� N���� �ٿ� ���� M���� ������ ���� ���̰� �־�����. (i + 2)��° ���� (j + 1)��° ���� ��ǥ (i, j)������ ���� ���̸� ��Ÿ����. ���� ���̴� 256���� �۰ų� ���� �ڿ��� �Ǵ� 0�̴�.

���
ù° �ٿ� ���� ������ �� �ɸ��� �ð��� ���� ���̸� ����Ͻÿ�. ���� ���� �� �ִٸ� ���߿��� ���� ���̰� ���� ���� ���� ����Ͻÿ�.

���� �Է� 1 
3 4 99
0 0 0 0
0 0 0 0
0 0 0 1
���� ��� 1 
2 0
�� ������ �Ʒ��� ������ �����ϸ� ��� ���̰� 0���� ���� ���°� �ȴ�. ���� ������ �� �� �����ϴ� �ð� 2�ʰ� �ҿ�ȴ�.

���� �Է� 2 
3 4 1
64 64 64 64
64 64 64 64
64 64 64 63
���� ��� 2 
1 64

 

�κ��丮�� ������ �ϳ� �ֱ� ������, �� ������ �Ʒ��� ������ �ϳ� ä��� �ȴ�.

���� �Է� 3 
3 4 0
64 64 64 64
64 64 64 64
64 64 64 63
���� ��� 3 
22 63
�κ��丮�� ��� �ֱ� ������, �� ������ �Ʒ��� ������ ��� ��ǥ���� ������ �ϳ��� �����ؾ� �Ѵ�.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x,y,block,ans1=INT_MAX,ans2;
	scanf("%d %d %d",&x,&y,&block);
	int** arr = new int*[x];
	for(int i = 0 ; i < x ; i++)
	{
		arr[i] = new int[y];
	}
	for(int i = 0 ; i < x ; i++)
	{
		for(int j = 0 ; j < y ; j++)
		{
			int ipt;
			scanf("%d",&ipt);
			arr[i][j] = ipt;
		}
	}
	int max = 0;
	int min = 256;
	for(int i = 0 ; i < x ; i++)	//�ִ��ּ� ���ϱ� 
	{
		if(max < *max_element(arr[i],arr[i]+y))
			max = *max_element(arr[i],arr[i]+y);
		if(min > *min_element(arr[i],arr[i]+y))
			min = *min_element(arr[i],arr[i]+y);
	}
	for(int i = min ; i <= max ; i++)
	{
		int build=0,remove=0;
		for(int j = 0 ; j < x ; j++)
		{
			for(int t = 0 ; t < y ; t++)
			{
				int temp = i - arr[j][t];
				if(temp>0)	//������ ���� ��� 
				{
					build += temp;
				}
				else	//������ ������ ��� 
				{
					remove += -temp;
				}
			}
		}
		if(remove + block >= build)
		{
			int temp = (build + 2*remove);	//���� �ø� �� 1��, ������ �� 2�� �ҿ� 
			if(temp <= ans1)	//�ּҽð��϶� ���亯���� ���� 
			{
				ans1 = temp;
				ans2 = i;
			}
		}
	}
	
	printf("%d %d",ans1,ans2);	
}
/*
���� ���ٹ��� ������� Ǯ�̸� ���� �����ߴ�.
 �ּ�~�ִ� ���̿� ������ ���� ������ i�� �������鼭 �ʿ��� �ð���
 ���ϰ��� ������ ������ �� �� �ִ� i�� �ð������� �������־���. 
*/