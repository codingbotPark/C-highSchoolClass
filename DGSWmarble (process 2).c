//�η� ���� (���� 2)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int n1 = 0;
int n2 = 0;

//typedef struct PLAYER layer PL;
struct PLAYER
{
	int location;
	int money;
};
struct MAP
{
	int map[32];
	int building[32];
};
int dice(int power);//�ֻ����� ������ �Լ�


int main()
{
	struct PLAYER PLAYER[4] = { 0, };
	struct MAP MAP = { 0, };
	int n;
	char m;
	int random[4];
	int cnt;
	int power;
	srand((unsigned)time(NULL));
	while (1)//���� �� ����(�÷��̾��� ���� ������ ���ϱ�)
	{
		printf("\n------------------------\n");
		printf("�÷��̾� ���� �Է��ϼ���(2~4)  ");
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			PLAYER[i].money = 400;//�⺻ �� 400����
		}
		if (n <= 4 && n >= 2)
		{
			printf("���� ��ȣ�� ���ϼ��� (�� �������� �ƹ�Ű�� �Է��� �ּ���) ");
			scanf(" %c", &m);
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
				printf("%d�� �÷��̾� = %d��°\n", random[i], i + 1);
			}
			printf("------------------------\n");
			break;
		}
		else
		{
			printf("2�� �̻�, 4�� ������ �÷��̾� ���� �Է����ּ���\n");
		}
	}
	for (int i = 0; i < n; i++)//����
	{
		cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (PLAYER[j].money <= 0)//�Ļ������� ��������
			{
				i++;
				break;
			}
		}
		while (1)//�ֻ��� ������
		{//�׳� PLAYER[i]
			printf("\t%d�� �÷��̾��� ���� \n", random[i]);
			printf("�ֻ����� ���� ������ �Է��ϼ���(1~5)  ");
			scanf("%d", &power);
			if (power >= 1 && power <= 5)
			{
				if (dice(power) == 0)
				{
					printf("%dĭ �̵�\n", n1 + n2);//������ �ƴ� ��
					PLAYER[i].location += n1 + n2;
					printf("%d�� �÷��̾��� ��ġ = %d\n", random[i], PLAYER[i].location);
					break;
				}
				else
				{
					printf("%dĭ �̵�\n", n1 + n2);//����
					PLAYER[i].location += n1 + n2;
					printf("%d�� �÷��̾��� ��ġ = %d\n", random[i], PLAYER[i].location);
				}
			}
			else
			{
				printf("\n1�̻�, 5������ ������ �Է��� �ּ���\n");
			}
		}


		for (int j = 0; j < n; j++)//������ ��(�Ѹ��� ������ ������ ������� �Ļ�)
		{
			if (PLAYER[j].money <= 0)
			{
				cnt++;
				if (cnt == n - 1)
				{
					for (int m = 0; m < n; m++)
					{
						if (PLAYER[m].money > 0)
						{
							printf("********\n%d�� �÷��̾� �¸�\n********", random[m]);
							return 0;
						}
					}
				}
			}
		}
		if (i == n - 1)//���� ������
		{
			i = -1;
		}
		printf("------------------------\n");
	}

	return 0;
}

int dice(int power)
{
	n1 = 0;
	n2 = 0;
	n1 = rand() % 2 + power;
	n2 = rand() % 6 + 1;
	//all += (n1 + n2);
	printf("\n�ֻ��� = %d %d\n", n1, n2);
	if (n1 == n2)
	{
		//printf("�����Դϴ�.");
		return 1;
	}
	else
	{
		//printf("%dĭ �����ϼ���\n", all);
		return 0;
	}
}