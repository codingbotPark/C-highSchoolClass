//�η� ���� (���� 1)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
//typedef struct PLAYER layer PL;
struct PLAYER
{
	int location;
	int money;
};
struct MAP
{
	int map[];
};
int main()
{
	struct PLAYER PLAYER[4] = { 0, };
	struct MAP MAP = { 0, };
	int n;
	char m;
	int random[4];
	srand((unsigned)time(NULL));
	while (1)//�÷��̾��� ���� ������ ���ϱ�
	{
		printf("\n------------------------\n");
		printf("�÷��̾� ���� �Է��ϼ���(2~4)  ");
		scanf("%d", &n);
		if (n <= 4 && n >= 2)
		{
			printf("���� ��ȣ�� ���ϼ��� (�� �������� �ƹ�Ű�� �Է��� �ּ���) ");
			scanf("%d", &m);
			printf("\n\t����\n");
			for (int i = 0; i < n; i++)
			{
				random[i] = rand() % n + 1;
				for (int j = 0; j < i; j++)
				{
					if (random[i] == random[j])
					{
						random[i] = rand() % n + 1;
						j = -1;
					}
				}
				printf("%d�� �÷��̾� = %d��°\n", i + 1, random[i]);
			}
			printf("------------------------\n");
			break;
		}
		else
		{
			printf("2�� �̻�, 4�� ������ �÷��̾� ���� �Է����ּ���\n");
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d�� �÷��̾��� ����");
		for (int j = 0; j < n; j++)
		{
			if (PLAYER[j].money < 0)
			{

			}
		}

		if (i == n - 1)
		{
			i = -1;
		}
	}

	return 0;
}