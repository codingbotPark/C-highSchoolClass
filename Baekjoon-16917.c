// ���� 16917
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a, b, c, x, y;
	scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
	int i = 0,j=0,o=0,p=0,t=0,T=0;
	
	// i�� ���� �� ū�� 0 = ��� 1 = �Ķ��̵�
	// j�� �� ���� ���� �� = 
	// 

	if (x > y)
	{
		j = y;
		i = 0;
	}
	else
	{
		j = x;
		i = 1;
	}
	//�� �� ���� ���� j�� �����

	if (a + b >= c * 2)//�ݹ� �� ���� ��� �ͺ��� ���� ��°��� �� �̵��� ��
	{
		o = (c * 2);
	}
	else//�ݹ� �� ���� ��� ���� �� �̵��� ��
	{
		o = (a + b);
	}

	if (i == 0)//x�� �� Ŭ ��
	{
		p = a*(x - y);
	}
	else
	{
		p = b * (y - x);
	}

	t = (o * j) + p;

	if (x > y)//x�� �� Ŭ��
	{
		T = x * (c * 2);
	}
	else
	{
		T = y * (c * 2);
	}

	if (T > t)
	{
		printf("%d", t);
	}
	else
	{
		printf("%d", T);
	}

	return 0;
}