//���� �˾Ƴ���
//1�� 1�� 1���� �Ͽ������� ���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int Y, M, D;
	int all = 0;
	char printday[8][10] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	int MD[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };//���� ��¥ ��
	int i, j, k;
	int cnt = 0;
	int cntY = 0;

	scanf("%d", &Y);
	scanf("%d", &M);
	scanf("%d", &D);

	for (i = 1; i < Y; i++)//�⵵ Ž��
	{
		for (j = 0; j < 365; j++)//1���� ��¥ �÷���
		{
			cnt++;
		}
		if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0))
		{
			cntY++;
		}
	}
	//������ ���ظ� ������ ��ü ��¥ ���� ����

	for (j = 1; j < M; j++)
	{
		cnt += MD[j];
		//���ذ� �����̰� �˻��ϴ� ���� 2�� �̻��� ��
		//()
		if (j > 2 && (Y % 4 == 0 && (Y % 100 != 0 || Y % 400 == 0)))
		{
			cntY++;
		}
		//������ �˻��ϴ� ��¥�� �� �������� ��¥ ���� ����
	}

	for (i = 0; i < D; i++)
	{
		cnt++;
	}
	//������ ���ϴ� ��¥������ ��¥ ���� ����

	printf("\n0���� ��¥ : %d\n\n", cnt + cntY);
	printf("%s", printday[(cnt + cntY) % 7]);


	return 0;
}