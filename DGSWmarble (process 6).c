//���� 6
// 
// �����ϰ� �ٽ�
// �Լ��� �Լ��� ����� �ϴ� ��� �ڵ带 ����
// 
// ���� ������ 3 1 2 ��� 
// �÷��̾� ����ü(PLAYER)��
// �׳� ������� 1 2 3 �̿��µ�
// random[]�迭�� Ȱ���ؼ� 
// �÷��̾� ����ü�� �÷��̾��� ��ȣ�� ��ġ��Ŵ
// 
// 
// 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

struct PLAYER
{
	int money;//�÷��̾��� ��
	int location;//�÷��̾��� ��ġ
};
struct MAP
{
	int building[31];//������ ����
	int who[31];//������ ������
	char name[31][16];
	int cost[31];

};

struct PLAYER PLAYER[4] = { 0, };
struct MAP MAP = { 0, };

void TURN();
//�÷��̾��� ���� �޾Ƽ� ������ ���ϴ� �Լ�
int dice();
//�ֻ����� ������ �Լ�
void GS(int s);//gamesetting
//������ ���۵Ǳ� �� ����
int judge(int s);
//� ��Ȳ���� �Ǵ��ϴ� �Լ�(�������� ��붥����)
void CM(int s);//changingmoney
//� ��Ȳ�� ���� ���� + - �ϴ� �Լ�
void BB(int s);//buildingbuilding
//��Ȳ�� ���� ������ ���� �Լ�
int YORN(int s);
//��Ȳ�� ���� Y�Ǵ�N�� �޾Ƽ� 1�Ǵ� 0�� ��ȯ�ϴ� �Լ�
void GF(int s);//gamefuntion
//������ ���(�Ļ��ѻ���� ������ �ѱ��)
int END(int s);
//������ ���� ��Ȳ�� �Ǵ��ϴ� �Լ�
void CBC(int s);//changingbuildingcost
//�ǹ��� ���� �� ���� ���� ������ �ٲٴ� �Լ�
void CW(int s);//changingwho
//��Ȳ�� ���� �ǹ��� �����ڸ� �ٲٴ� �Լ�


int i = 0;//main for������ ���Ǵ� ����
int n = 0;//�÷��̾��� ��
int random[4];//����
char YorN;//�ƹ�Ű�� ���� �ѱ�� / Y or N
int DorS;//�������� �ƴ���
int BN;//���� �ǹ��� ����
int choice;//�ø��� ���ַ� 

int main()
{
	srand((unsigned)time(NULL));
	GS(1);//������ �ʱ�ȭ
	TURN();//���� ���ϱ�
	GS(0);//�����״�� �÷��̾� �� �ʱ�ȭ
	for (i = 0; i < n; i++)
	{
		GF(0);
		dice();
		if (judge(0))// ��붥���� �ƴ��� �Ǻ� �ƴϸ�
		{
			// money
			// build(building , who)
			if (!(judge(1)))//���帶ũ���� �ƴ��� �ƴ϶��
			{
				if (!(judge(2)))//�ǹ��� 3�� �̸��� ��
				{
					if (YORN(0))//�Ǽ��� ��
					{
						BB(0);
						CW(0);
					}
				}
				else//�ǹ��� 3���� ��
				{
					if (YORN(1))//���帶ũ�� ���� ���ΰ�
					{
						BB(1);
					}
				}
				CM(0);//���� �ǹ��� ������ ���� 
				CBC(0);//�ǹ��� ������ ���� ���� ������ �ٲ��ֱ�
			}
			//else ���帶ũ��� �ѱ��
		}
		else// �ƴϸ�
		{
			if (judge(1))//���帶ũ���� �ƴ��� �Ǻ� ������
			{
				CM(1);
			}
			else//���帶ũ�� �ƴ϶��(�μ��� �����ϴٸ�)
			{
				CM(1);//�ϴ� ���� ����
				if (YORN(2))//�μ��� �� ���ΰ�? �´ٸ�
				{
					CM(1);
					CW(0);
				}
				//moeny
				//who
			}
		}
		//Ȯ���ڵ�
		for (int x = 0; x < n; x++)
		{
			printf("%d�� �÷��̾��� �ڻ� %d\n", random[x], PLAYER[random[x]].money);
		}
		for (int x = 0; x < 31; x++)
		{
			printf("%d�� �ǹ��� ���� %d\n", x, MAP.building[x]);
			printf("%d�� �ǹ��� ���� %d\n", x, MAP.who[x]);
		}



		if (DorS)//������ �� �ѹ� ��
		{
			i--;
			continue;
		}





		if (i == n - 1)//����������
		{
			i = -1;
		}
	}

	return 0;
}





void TURN()
{
	while (1)
	{
		printf("\n---------------\n");
		printf("�÷��̾��� ���� �Է��ϼ���(2~4) ");
		scanf("%d", &n);
		if (n > 1 && n < 5)
		{
			break;
		}
		printf("\n2�� �̻�, 4�� ������ �÷��̾� ���� �Է����ּ���\n");
	}
	printf("���� ��ȣ�� ���ϼ��� (�� �������� �ƹ�Ű�� �Է��� �ּ���) ");
	scanf(" %c", &YorN);
	for (int x = 0; x < n; x++)
	{
		random[x] = rand() % n + 1;
		for (int y = 0; y < x; y++)
		{
			if (random[y] == random[x])
			{
				random[x] = rand() % n + 1;
				y = -1;
			}
		}
		printf("\n%d��°���� = %d�� �÷��̾�", x + 1, random[x]);
	}
	printf("\n---------------\n");
}

int dice()
{
	DorS = 0;//���������ƴ��� �Ǵ��ϴ� ������ �ʱ�ȭ
	int power;
	int n1 = 0;//�ֻ���1
	int n2 = 0;//�ֻ���2
	printf("\t%d�� �÷��̾� ����\n", random[i]);
	while (1)
	{
		printf("�ֻ��� ������ �Է����ּ���(1~5) ");
		scanf("%d", &power);
		if (power < 1 && power > 5)
		{
			printf("1�̻� 5������ ���� �Է����ּ���");
			continue;
		}
		break;
	}
	n1 = rand() % 2 + power;
	n2 = rand() % 6 + 1;
	printf("\n�ֻ��� = %d %d\n", n1, n2);
	PLAYER[random[i]].location += (n1 + n2);
	if (PLAYER[random[i]].location > 31)
	{
		PLAYER[random[i]].money += 60;

	}
	printf("%d�� �÷��̾��� ��ġ = %d\n", random[i], PLAYER[random[i]].location);
	if (n1 == n2)
	{
		DorS = 1;
	}
}

void GS(int s)
{
	if (s == 0)
	{
		for (int x = 0; x < n; x++)
		{
			PLAYER[random[x]].money = 400;
		}
	}
	else if (s == 1)//���������� ĭ * 2�� �ʱ�ȭ
	{
		for (int x = 0; x < 31; x++)
		{
			MAP.cost[x] = 2 * x;
		}
	}
}
void GF(int s)
{
	if (s == 0)//�Ļ��� �÷��̾ �پ� �Ѵ� ��Ȳ
	{
		if (PLAYER[random[i]].money <= 0)
		{
			if (i == n - 1)//i�� �������� ��
			{
				i = -1;
			}
			i++;
		}
	}
}

int judge(int s)
{
	if (s == 0)//��붥���� �ƴ��� �Ǵ�
	{
		if (MAP.who[PLAYER[i].location] != i && MAP.building[PLAYER[i].location] != 0)//��붥�� ��
		{
			return 0;
		}
		else//�Ǽ� �� �� ���� ��
		{
			return 1;
		}
	}
	if (s == 1)//���帶ũ���� �ƴ��� �Ǵ�
	{
		if (MAP.building[PLAYER[random[i]].location] == 4)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if (s == 2)//�ǹ��� 3������ 3�� �̸����� �Ǵ�(���帶ũ�Ǽ�)
	{
		if (MAP.building[PLAYER[random[i]].location] == 3)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}


void CM(int s)
{
	if (s == 0)//�ƹ��͵� ���� �� �Ǽ�
	{
		//PLAYER[random[i]].money -= MAP.cost[PLAYER[random[i]].location];
		PLAYER[random[i]].money -= BN * PLAYER[random[i]].location;
		//�ǹ��� ���� �� ���� �� ��ΰ� �ְ� �ǹ��� ����� ��
	}
	else if (s == 1)
	{
		PLAYER[random[i]].money -= MAP.cost[PLAYER[random[i]].location];//�ǹ��� �� ���
		PLAYER[MAP.who[PLAYER[random[i]].location]].money += MAP.cost[PLAYER[random[i]].location];//�ǹ�����
	}
}

void BB(int s)
{
	if (s == 0)
	{
		while (1)
		{
			printf("�� ���� �ǹ��� ���ڽ��ϱ�? (�߰��� ���� �ǹ��� ����) ");
			scanf("%d", &BN);
			if (BN + MAP.building[PLAYER[random[i]].location] >= 4 || BN <= 0 || BN > 3)
			{
				printf("\n�ǹ��� ������ �߸� �Ǿ����ϴ� (�ʰ� / �̸� ���� ����)\n");
				continue;
			}
			else
			{
				MAP.building[PLAYER[random[i]].location] += BN;
				break;
			}
		}
	}
	else if (s == 1)
	{
		MAP.building[PLAYER[random[i]].location] = 4;
		printf("\n***%s �Ǽ�***\n", MAP.name[PLAYER[random[i]].location]);
		BN = 1;//�����ѹ��� 1�� ���缭 ������ �ǹ� �ϳ��� ���� ���� ���� �ö󰡵��� �ϱ�
	}
}

int YORN(int s)
{
	if (s == 0)
	{
		printf("�ǹ��� ���ڽ��ϱ�? (y / n)");
	}
	else if (s == 1)
	{
		printf("���帶ũ�� ���ڽ��ϱ�? (y / n)");
	}
	else if (s == 2)
	{
		printf("�ǹ��� �μ��Ͻðڽ��ϱ�? (y / n)");
	}
	while (1)
	{
		scanf(" %c", &YorN);
		if (YorN == 'Y' || YorN == 'y')
		{
			return 1;
		}
		else if (YorN == 'N' || YorN == 'n')
		{
			return 0;
		}
		else
		{
			printf("\nY(y)�Ǵ� N(n)�� �ϳ��� ���ڸ� �Է����ּ���\n");
		}
	}
}

int END(int s)
{
	if (s == 0)
	{

	}
	else
	{

	}
}


void CBC(int s)
{
	if (s == 0)//�׳� �ǹ��� ���� ��(+�� ���� �ø���)
	{
		MAP.cost[PLAYER[random[i]].location] += (PLAYER[random[i]].location * BN);
	}
	else if (s == 1)//�ø��� ���ַ� ������ �ö� ��
	{

	}

}

void CW(int s)
{
	if (s == 0)
	{
		MAP.who[PLAYER[random[i]].location] = random[i];
	}
}