//�η� ���� (���� 3)
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
	int who[32];
	int building[32];
	char name[32][16];//dgsw�ǵ�
};
int dice(int power);//�ֻ����� ������ �Լ�
//�ʿ� ���� �� ������ �Լ�

int main()
{
	struct PLAYER PLAYER[4] = { 0, };
	struct MAP MAP = { 0, };
	int n;//�÷��̾��� ��
	char m;//�ƹ�Ű�� / �ǹ����� ����
	int random[4];//�÷��� ����
	int cnt;//�Ļ��� �÷��̾��� ���� ���Ʒ� ���� ����
	int power;//�ֻ����� ����
	int SorD;//�������� �ƴ���
	int turn = 0;//��(1~4�� �÷��̾ �� �Ͻ�)�� 15�� ���� �� ���� ����
	int biggest = 0;//���� 15�� �ż� ���� ���� �÷��̾��� �ڻ� ��
	int BN;//building number ������ �� �� ���� ������
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
			SorD = dice(power);
			if (power >= 1 && power <= 5)
			{
				printf("%dĭ �̵�\n", n1 + n2);//������ �ƴ� ��
				PLAYER[i].location += n1 + n2;
				if (PLAYER[i].location >= 32)//�÷��̾��� ��ġ�� 32ĭ�� �Ѿ��� ��
				{
					PLAYER[i].money += //�ѹ��� �� ���� ����
						PLAYER[i].location -= 32;
				}
				printf("%d�� �÷��̾��� ��ġ = %d\n", random[i], PLAYER[i].location);
				if (MAP.building[PLAYER[i].location] > 0)//�÷��̾ �ִ� ���� ������ ���� ��
				{//�ڱⲫ�� �� 
				//������ ���� ��(�μ� y / n)
					if (MAP.who[PLAYER[i].location] == i)//�ڱ� �ǹ��� ���� ��
					{
						if (MAP.building[PLAYER[i].location] < 4)//���帶ũ�� �ƴ� ��
						{
							while (1)
							{
								printf("�ǹ��� ���ڽ��ϱ�? (y / n)");
								scanf(" %c", &m);
								if (m == 'Y' || m == 'y')
								{
									if (MAP.who[PLAYER[i].location] == 3)//�ǹ��� 3���� ��
									{
										while (1)
										{
											printf("���帶ũ�� �Ǽ��ϰڽ��ϱ�? (y / n)");
											scanf(" %c", &m);
											if (m == 'Y' || m == 'y')
											{
												MAP.building[PLAYER[i].location] = 4;
												printf("\n***���帶ũ �Ǽ�***\n");
											}
											else if (m == 'N' || m == 'n')
											{
												break;
											}
											else
											{
												printf("Y(y) �Ǵ� N(n) �� �ϳ��� ���ڸ� �Է����ּ���");
											}
										}
									}
									else
									{
										printf("���� �ǹ��� ���� %d��\n", MAP.building[PLAYER[i].location]);
										printf("�� ���� �ǹ��� ���ڽ��ϱ�?(�ִ� %d��)", 3 - MAP.building[PLAYER[i].location]);
										scanf("%d", &BN);
										if (BN > MAP.building[PLAYER[i].location] && BN < 3 - MAP.building[PLAYER[i].location])
										{
											MAP.building[PLAYER[i].location] = BN;
											break;
										}
										else
										{
											printf("�߸��� �� �Է�");
										}
									}
								}
								else if (m == 'N' || m == 'n')
								{
									break;
								}
								else
								{
									printf("Y(y) �Ǵ� N(n) �� �ϳ��� ���ڸ� �Է����ּ���");
								}
							}
						}
						else//������ �ڱ� �ǹ��� ���帶ũ �� ��
						{

						}
					}
					else//�ڱ� �ǹ��� �ƴҶ� �� ����
					{

					}
				}
				else//������ ���� ��(���� y / n)
				{
					while (1)
					{
						printf("�ǹ��� ���ڽ��ϱ�? (y / n)");
						scanf(" %c", &m);
						if (m == 'y' || m == 'Y')
						{
							while (1)
							{
								printf("�� ���� �ǹ��� ���ڽ��ϱ�?(�ִ� 3��)");
								scanf("%d", &BN);
								if (BN > 0 && BN < 4)
								{
									//�ǹ� ���� �Լ�
									MAP.who[PLAYER[i].location] = i;
									MAP.building[PLAYER[i].location] = BN;
								}
								else
								{
									printf("1�̻�, 3������ ���� �Է��� �ּ���");
								}
							}
						}
						else if (m == 'n' || m == 'N')
						{
							break;
						}
						else
						{
							printf("Y(y) �Ǵ� N(n) �� �ϳ��� ���ڸ� �Է����ּ���");
						}
					}
				}
				if (SorD == 0)//������ �ƴ� ��
				{
					break;
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
		for (int j = 0; j < n; j++)
		{
			printf("\n%d�� �÷��̾��� �ڻ� %d", random[i], PLAYER[j].money);
		}
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
#endif


#if 0
int n1 = 0;
int n2 = 0;
int all = 0;
while (1)
{
	n1 = rand() % 6 + 1;
	n2 = rand() % 6 + 1;
	all += (n1 + n2);
	printf("\n�ֻ��� = %d %d\n", n1, n2);
	if (n1 == n2)
	{
		printf("�����Դϴ�.");
		continue;
	}
	else
	{
		printf("%dĭ �����ϼ���\n", all);
		break;
	}
}