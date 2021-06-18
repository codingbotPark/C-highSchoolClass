//�η� ���� (���� 5)
// ������ ������ �ϳ��ϳ� ����ߴ� �Լ� (BN�Լ�)��
// =>
// ���� ����ü�� ������ ������ �ְ� �׳� �μ� �� ���� BN�Լ����� * 2 �θ����
// ������ �� �� �� �� �ֵ��� ��
// 
// +�𼭸��κп� start�� �����ϸ� 3�� �̸��� �ǹ��� �� �Ǽ��� �� �ִ� ���
// 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int n1 = 0;
int n2 = 0;
struct PLAYER
{
	int location;
	int money;
};
struct MAP
{
	int who[32];
	int building[32];
	char name[32][16];
	int cost[32];
};
struct PLAYER PLAYER[4] = { 0, };
struct MAP MAP = { 0, };
int dice(int power);
void change(int i, int S);

char m;//�ƹ�Ű�� / �ǹ����� ����
int n;//�÷��̾��� ��

int main()
{
	int random[4];//�÷��� ����
	int cnt;//�Ļ��� �÷��̾��� ���� ���Ʒ� ���� ����
	int power;//�ֻ����� ����
	int SorD;//�������� �ƴ���
	int turn = 0;//��(1~4�� �÷��̾ �� �Ͻ�)�� 15�� ���� �� ���� ����
	int biggest = 0;//���� 15�� �ż� ���� ���� �÷��̾��� �ڻ� ��
	int BN;//building number ������ �� �� ���� ������
	srand((unsigned)time(NULL));

	for (int i = 0; i < 32; i++)//31���� ����Ѵ�
	{
		MAP.cost[i] *= 4;
	}
	while (1)//���� �� ����(�÷��̾��� ���� ������ ���ϱ�)
	{
		printf("\n------------------------\n");
		printf("�÷��̾� ���� �Է��ϼ���(2~4)  ");
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			PLAYER[i].money = 400;
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
	for (int i = 0; i < n; i++)
	{
		cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (PLAYER[j].money <= 0)
			{
				i++;
				break;
			}
		}
		while (1)
		{//�׳� PLAYER[i]
			printf("\t%d�� �÷��̾��� ���� \n", random[i]);
			printf("�ֻ����� ���� ������ �Է��ϼ���(1~5)  ");
			scanf("%d", &power);
			SorD = dice(power);
			if (power >= 1 && power <= 5)
			{
				printf("%dĭ �̵�\n", n1 + n2);
				PLAYER[i].location += n1 + n2;
				if (PLAYER[i].location >= 32)
				{
					PLAYER[i].money += 60;
					PLAYER[i].location -= 32;
				}
				printf("%d�� �÷��̾��� ��ġ = %d\n", random[i], PLAYER[i].location);
				if (PLAYER[i].location == 8 || PLAYER[i].location == 16 || PLAYER[i].location == 24 || PLAYER[i].location == 0)//Ư���� ���� ���� ��
				{// 8 = �����(���ε�)		16 = �޽Ľ�(�ø��� ����)		24 = �Ͱ�����(���迩��)		0 = ����(�����)
					if (PLAYER[i].location == 8)
					{
						printf("\n����� ����!\n");
						break;//�� �� �ѱ��
					}
					else if (PLAYER[i].location == 16)
					{
						printf("\n�޽Ľ� ����!\n");
					}
					else if (PLAYER[i].location == 24)
					{
						printf("\n�Ͱ����� ����!\n");
					}
					else
					{
						printf("\n���� ����!\n");
					}
					break;
				}
				else if (MAP.who[PLAYER[i].location] != i && MAP.building[PLAYER[i].location] != 0)//�ǹ��� ����� ���� ��
				{
					change(random[i], 2);
					break;
				}
				else//�ǹ��� ���ų� ���� ���� ��
				{
					if (MAP.building[PLAYER[i].location] < 3)//�ǹ� 3�� �̸�
					{
						while (1)
						{
							printf("�ǹ��� ���ڽ��ϱ�? (y / n)");
							scanf(" %c", &m);
							if (m == 'Y' || m == 'y')
							{
								while (1)
								{
									printf("�� ���� �ǹ��� ���ڽ��ϱ�? (�߰��� ���� �ǹ��� ����)");
									scanf("%d", &BN);
									if (BN + MAP.building[PLAYER[i].location] > 3 || BN <= 0)
									{//�ǹ��� ������ ���� �ǹ��� �������� ���� ���� ����
										printf("\n�ǹ��� ������ �߸� �ž����ϴ� (�ʰ� / �̸�)�� ����\n");
										continue;
									}
									else
									{
										change(i, 1);
										MAP.building[PLAYER[i].location] += BN;
										MAP.who[PLAYER[i].location] = random[i];
										break;
									}
								}
								break;
							}
							else if (m == 'N' || m == 'n')
							{
								break;
							}
							else
							{
								printf("\nY(y) �Ǵ� N(n)�� �ϳ��� ���ڸ� �Է��� �ּ���\n");
							}
						}
					}
					else if (MAP.building[PLAYER[i].location] == 3)//�ǹ��� 3��
					{
						while (1)
						{
							printf("���帶ũ�� ���ڽ��ϱ�? (y / n)");
							scanf(" %c", &m);
							if (m == 'Y' || m == 'y')
							{
								MAP.building[PLAYER[i].location] = 4;
								printf("\n***%s �Ǽ�***\n", MAP.name[PLAYER[i].location]);
								break;
							}
							else if (m == 'N' || m == 'n')
							{
								break;
							}
							else
							{
								printf("Y(y) �Ǵ� N(n)�� �ϳ��� ���ڸ� �Է����ּ���");
							}
						}
					}
					if (SorD == 0)//������ �ƴ� ��
					{
						break;
					}
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
							//random�迭�� ������� ����ü�� ����� ���� �ƴ�
							//�׳� 1��°�� ����ü1��, 2��°�� ����ü2�� ...
						{
							printf("********\n%d�� �÷��̾� �¸�\n********", random[m]);
							return 0;
						}
					}
				}
			}
		}

		//���� ����

		//Ȯ���ڵ�
		//--------------------
		for (int j = 0; j < n; j++)
		{
			printf("\n%d�� �÷��̾��� �ڻ� %d", random[j], PLAYER[j].money);//�� ���� ������ �ڻ��� ǥ��
		}
		for (int j = 0; j < 32; j++)
		{
			printf("\n%d��° �ǹ��� ���� %d", j, MAP.building[j]);
			printf("\n%d��° �ǹ��� ���� %d", j, MAP.who[j]);
		}
		//---------------------
		if (i == n - 1)//���� ������
		{
			i = -1;
			turn++;//���� �� �Ͼ� ���� ��
			if (turn >= 15)//turn�� 15�� �� �� �ݾ��� ���� ���� ����� �¸�
			{
				for (int j = 1; j < n; j++)
				{
					if (PLAYER[biggest].money < PLAYER[j].money)
					{
						biggest == j;
					}
					if (j == n - 1)
					{
						printf("********\n%d�� �÷��̾� �¸�\n********", random[biggest]);
						return 0;
					}
				}
			}
		}
		printf("\n------------------------\n");
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
// random�� ���ư��°�
// random[i]
// 	   3
// 	   2
// 	   1
// 
// 
// PLAYER[i]
// 	   1
// 	   2
// 	   3


void change(int i, int S)
{
	if (S == 1)//�ǹ��� ���� ��
	{
		PLAYER[i].money -= MAP.cost[PLAYER[i].location];//������ �Լ����
	}
	else if (S == 2)
	{
		if (MAP.building[PLAYER[i].location] == 4)//���ǹ��� ���帶ũ�� ��
		{
			PLAYER[i].money -= MAP.cost[PLAYER[i].location];//������ �Լ����
		}
		else//���ǹ��� ���帶ũ�� �ƴ� ��
		{
			while (1)
			{
				PLAYER[i].money -= MAP.cost[PLAYER[i].location];
				printf("�ǹ��� �μ��Ͻðڽ��ϱ�? (Y / n)");
				scanf(" %c", &m);
				if (m == 'Y' || m == 'y')
				{
					PLAYER[i].money -= 2 * MAP.cost[PLAYER[i].location];
					PLAYER[MAP.who[PLAYER[i].location]].money += 2 * MAP.cost[PLAYER[i].location];
					MAP.who[PLAYER[i].location] = i;
					break;
				}
				else if (m == 'N' || m == 'n')
				{
					break;
				}
				else
				{
					printf("\nY(y) �Ǵ� N(n)�� �ϳ��� ���ڸ� �Է����ּ���\n");
				}
			}
		}
	}
}