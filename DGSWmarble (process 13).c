//���� 13
// 
// �Ļ��� ����� �ǹ��� �������� ���ִ� ���� ���� ����
// 
// �Ļ��� ���� �� ���� ������ ����Ǵ� ���׸� ���� 
// 
// END�Լ��� �����ϰ� CM(changmoney)�Լ��� �־
// ���� ȿ�������� ����
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <windows.h>

#define CLS system("cls")

struct PLAYER
{
	int money;//�÷��̾��� ��
	int location;//�÷��̾��� ��ġ
	int count;
};
struct MAP
{
	int building[32];//������ ����
	int who[32];//������ ������
	int cost[32];
};

int map[37][37] = {
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 0, 10, 0, 1, 0, 11, 0, 1, 0, 12, 0, 1, 0, 13, 0, 1, 0, 14, 0, 1, 0, 15, 0, 1, 0, 16, 0, 1, 0, 17, 0, 1, 0, 18, 0, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 0, 9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 19, 0, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 0, 8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 20, 0, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 0, 7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 21, 0, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 0, 6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 22, 0, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 0, 5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 23, 0, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 0, 4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 25, 0, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 0, 2, 0, 1, 0, 33, 0, 1, 0, 32, 0, 1, 0, 31, 0, 1, 0, 30, 0, 1, 0, 29, 0, 1, 0, 28, 0, 1, 0, 27, 0, 1, 0, 26, 0, 1 },
{1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1 },
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

int DICE[2][5][5] = { 0, };


struct PLAYER PLAYER[4] = { 0, };
struct MAP MAP = { 0, };


void TURN();
//�÷��̾��� ���� �޾Ƽ� ������ ���ϴ� �Լ�
int dice();
//�ֻ����� ������ �Լ�
void GS(int s);//gamesetting
//������ ���۵Ǳ� �� ����
int judge(int s);
//� ��Ȳ���� �Ǵ��ϴ� �Լ�(�������� ��붥���� ��)
int CM(int s);//changingmoney
//� ��Ȳ�� ���� ���� + - �ϴ� �Լ�
void BB(int s);//buildingbuilding
//��Ȳ�� ���� ������ ���� �Լ�
int YORN(int s);
//��Ȳ�� ���� Y�Ǵ�N�� �޾Ƽ� 1�Ǵ� 0�� ��ȯ�ϴ� �Լ�
void GF(int s);//gamefuntion
//������ ���(�Ļ��ѻ���� ������ �ѱ��)
//int END(int s);
//������ ���� ��Ȳ�� �Ǵ��ϴ� �Լ�
void CBC(int s);//changingbuildingcost
//�ǹ��� ���� �� ���� ���� ������ �ٲٴ� �Լ�
void CW(int s);//changingwho
//��Ȳ�� ���� �ǹ��� �����ڸ� �ٲٴ� �Լ�
void SP();//specialplace
//��Ȳ�� ���� ���ε�, �ø��Ȱ���, ���迩���
void PM();// printmap
//�� ��� �Լ�
int SA();//specialaction
//specialplace�� ���� �� Ư���� �ൿ
//void PD();//printdice
////�ֻ����� ���� ���� ����� ����ϴ� �Լ�
//void MD();//makedice
////dice�� ���� ���� ����ϴ� �ֻ����� ����� �ٲٴ� �Լ�


int i = 0;//main for������ ���Ǵ� ����
int n = 0;//�÷��̾��� ��
int random[4];//����
char YorN;//�ƹ�Ű�� ���� �ѱ�� / Y or N
int DorS;//�������� �ƴ���
int BN;//���� �ǹ��� ����
int choice;//�����ϴ� �ǹ�(�ø��� ����, ���� ���� ��)
char buildingname[32][20] = { "����", "���", "ü����", "��ȸ�����", "���������",
"���������", "��û����", "�̼���", "�����", "��۽�","â�ǰ��۽�",
"��������α׷��ֽ�", "DB��Ʈ��ũ�ǽ���", "���������α׷��ֽ�", "���ɽ�Ʈ���", "������",
"�޽Ľ�", "���ϵ�","���ȵ��Ƹ�", "���췦��", "��Ÿ��", "CnS", "ducami", "b1nd", "�Ͱ� ����",
"�簨��", "������", "�����", "�����", "��ϻ�", "1�г�1��", "�ں���" };
//������ �̸�
int cnt = 0;//�Ļ��� ����� �� +
int Dice[2] = { 0, };//�ֻ��� 1, 2


int main()
{
	srand((unsigned)time(NULL));
	GS(2);//Ǯ��ũ��
	GS(1);//������ �ʱ�ȭ
	TURN();//���� ���ϱ�
	GS(0);//�����״�� �÷��̾� �� �ʱ�ȭ
	for (i = 0; i < n; i++)
	{
		GF(0);
		printf("\n\n\t\t\t\t\t\t\t\t\t\t%d�� �÷��̾� ����\n\n", random[i]);
		if (PLAYER[random[i]].count != 0)//Ư���� ��ҿ� ���� �� �ֻ����� ������ �ʴ´�
		{
			if (SA())
			{
				PM();
				continue;//���ε��� �� ���� �ѱ��
			}
		}
		else
		{
			dice();
		}
		if (judge(3))//Ư���� ������ ��
		{
			SP();
		}
		else//Ư���� ������ �ƴ� ��
		{
			if (judge(0))// ��붥���� �ƴ��� �Ǻ� �ƴϸ�
			{
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
					if (CM(0))//���� �ǹ��� ������ ���� 
					{
						continue;
					}
					CBC(0);//�ǹ��� ������ ���� ���� ������ �ٲ��ֱ�
				}
				//else ���帶ũ��� �ѱ��
			}
			else // ������
			{
				if (CM(1))//�ϴ� ���� ����
				{
					continue;
				}
				if (!(judge(1)))//���帶ũ�� �ƴ϶��(�μ��� �����ϴٸ�)
				{
					if (YORN(2))//�μ��� �� ���ΰ�? �´ٸ�
					{
						if (CM(2))
						{
							continue;
						}
						CW(0);
						if (YORN(0))//�ǹ��� �߰��� �������� �ƴ��� ������
						{
							if (judge(2))//�μ��� ���� �ǹ��� 3������ �ƴ��� ������
							{
								if (YORN(1))//���帶ũ�� �����Ÿ�
								{
									BB(1);
									if (CM(0))
									{
										continue;
									}
								}
							}
							else//�ƴϸ�
							{
								BB(0);
								if (CM(0))
								{
									continue;
								}
							}
						}
						//else
					}
				}
			}
		}
		//Sleep(1000);
		//CLS;
		PM();
		//END(0);//������̿� ���� �� ���� �ִ�
		if (DorS)//������ �� �ѹ� ��
		{
			i--;
			continue;//continue�� ������
			//�Լ��� �ְԵǸ� �� �������
		}
		GF(1);//����������
	}

	return 0;
}

void TURN()
{
	while (1)
	{
		printf("\n=========================================================================================================================");
		printf("====================================================================\n");
		printf("\t\t\t\t\t\t\t\t\t�÷��̾��� ���� �Է��ϼ���(2~4) ");
		scanf("%d", &n);
		if (n > 1 && n < 5)
		{
			break;
		}
		printf("\n\t\t\t\t\t\t\t\t\t2�� �̻�, 4�� ������ �÷��̾� ���� �Է����ּ���\n");
	}
	printf("\t\t\t\t\t\t\t\t���� ��ȣ�� ���ϼ��� (�� �������� �ƹ�Ű�� �Է��� �ּ���) ");
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
		printf("\t\t\t\t\t\t\t\t\t\t%d��°���� = %d�� �÷��̾� ", x + 1, random[x]);
		if (x == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xCC);
		}
		else if (x == 1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x99);
		}
		else if (x == 2)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x66);
		}
		else if (x == 3)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xAA);
		}
		printf("��");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
		printf("\n");
	}
	printf("\n=========================================================================================================================");
	printf("====================================================================\n");
}

int dice()
{
	DorS = 0;//���������ƴ��� �Ǵ��ϴ� ������ �ʱ�ȭ
	int power;
	while (1)
	{
		printf("\t\t\t\t\t\t\t\t\t�ֻ��� ������ �Է����ּ���(1~5) ");
		scanf("%d", &power);
		if (power > 0 && power < 6)
		{
			break;
		}
		printf("\n\t\t\t\t\t\t\t\t\t   1�̻� 5������ ���� �Է����ּ���\n\n");
		continue;
	}
	Dice[0] = rand() % 2 + power;
	Dice[1] = rand() % 6 + 1;
	if (Dice[0] == Dice[1])
	{
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t  ����!\n\n");
		DorS = 1;
	}
	printf("\t\t\t\t\t\t\t\t\t\t  �ֻ��� = %d %d\n", Dice[0], Dice[1]);
	PLAYER[random[i]].location += (Dice[0] + Dice[1]);
	if (PLAYER[random[i]].location > 31)
	{
		PLAYER[random[i]].location -= 32;
		PLAYER[random[i]].money += 60;
		printf("\n\t\t\t\t\t\t\t\t\t\t      ���� ����!\n");
	}
	printf("\n\t\t\t\t\t\t\t\t\t%20s ����!\n\n", buildingname[PLAYER[random[i]].location]);
	printf("\t\t\t\t\t\t\t\t\t      %d�� �÷��̾��� ��ġ = %d\n", random[i], PLAYER[random[i]].location);
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
		for (int x = 0; x < 32; x++)
		{
			MAP.cost[x] = 2 * x;
		}
	}
	else if (s == 2)
	{
		SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
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
	if (s == 1)
	{
		if (i == n - 1)//����������
		{
			i = -1;
		}
	}
}

int judge(int s)
{
	if (s == 0)//��붥���� �ƴ��� �Ǵ�
	{
		if (MAP.who[PLAYER[random[i]].location] != random[i] && MAP.building[PLAYER[random[i]].location] != 0)//��붥�� ��
		{
			return 0;
		}
		else//�Ǽ� �� �� ���� ��
		{
			return 1;
		}
	}
	else if (s == 1)//���帶ũ���� �ƴ��� �Ǵ�
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
	else if (s == 2)//�ǹ��� 3������ 3�� �̸����� �Ǵ�(���帶ũ�Ǽ�)
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
	else if (s == 3)//Ư���� �������� �ƴ��� �Ǵ�(���ε� ��)
	{
		if (PLAYER[random[i]].location == 8 ||
			PLAYER[random[i]].location == 16 ||
			PLAYER[random[i]].location == 24 ||
			PLAYER[random[i]].location == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}


int CM(int s)
{
	if (s == 0)//�ƹ��͵� ���� �� �Ǽ�
	{
		//PLAYER[random[i]].money -= MAP.cost[PLAYER[random[i]].location];
		//�ǹ��� ���� �� ���� �� ��ΰ� �ְ� �ǹ��� �������
		PLAYER[random[i]].money -= BN * PLAYER[random[i]].location;
	}
	else if (s == 1)//�����
	{
		PLAYER[random[i]].money -= MAP.cost[PLAYER[random[i]].location];//�ǹ��� �� ���
		PLAYER[MAP.who[PLAYER[random[i]].location]].money += MAP.cost[PLAYER[random[i]].location];//�ǹ�����
	}
	else if (s == 2)//�μ���
	{
		PLAYER[random[i]].money -= PLAYER[random[i]].location * 2;//�ǹ��� �� ���
		PLAYER[MAP.who[PLAYER[random[i]].location]].money += PLAYER[random[i]].location * 2;//�ǹ�����
		//MAP.cost[PLAYER[random[i]].locaiton]���� �ʰ� ��ġ * 2�� �ϴ� ������
		//�ø��� ���ַ� ���� MAP.cost�� �ö󰡸� �μ� �� �� cost�� �ö� ä�� �μ��� �Ǳ⶧����
	}
	if (PLAYER[random[i]].money < 0)//�Ļ�Ȯ��
	{
		printf("\n\t\t\t\t\t\t\t\t\t\t%d�� �÷��̾� �Ļ�\n", random[i]);
		cnt++;
		for (int x = 1; x < 32; x++)
		{
			if (MAP.who[x] == random[i])//������ ���ؼ� �Ļ��� ����� ���� ��� ���ش�
			{
				MAP.who[x] = 0;
				MAP.building[x] = 0;
				for (int p = 2; p < 35; p += 4)
				{
					for (int P = 2; P < 35; P += 4)
					{
						if (map[p][P] == x + 2 || map[p][P] == x + 38)//map�� ��ȣ�� �迭�� �� ��ȣ�� ��
						{
							for (int k = 0; k < 3; k++)
							{
								for (int K = 0; K < 3; K++)
								{
									if (k == 1 && K == 1)//�߰�ĭ�� ����
									{
										map[p][P] = x + 2;
										continue;
									}
									map[p + 1 - k][P - 1 + K] = 0;
								}
							}
						}
					}
				}
			}
		}
		if (cnt == n - 1)//������ ���� ��
		{
			for (int x = 0; x < n; x++)
			{
				if (PLAYER[random[x]].money > 0)
				{
					printf("\n\n\n\n\t\t\t\t\t\t\t\t\t%d�� �÷��̾� �¸�!\n\n\n\n", random[x]);
					exit(1);
				}
			}
		}
		return 1;
	}
	return 0;
}

void BB(int s)
{
	if (s == 0)
	{
		while (1)
		{
			printf("\t\t\t\t\t\t\t\t�� ���� �ǹ��� ���ڽ��ϱ�? (�߰��� ���� �ǹ��� ���� 1~3)  ");
			scanf("%d", &BN);
			if (BN + MAP.building[PLAYER[random[i]].location] >= 4 || BN <= 0 || BN > 3)
			{
				printf("\n\t\t\t\t\t\t\t\t    �ǹ��� ������ �߸� �Ǿ����ϴ� (�ʰ� / �̸� ���� ����)\n\n");
				continue;
			}
			else
			{
				MAP.building[PLAYER[random[i]].location] += BN;
				for (int x = 2; x < 35; x += 4)
				{
					for (int y = 2; y < 35; y += 4)
					{
						if (PLAYER[random[i]].location == map[x][y] - 2)
						{
							for (int p = 0; p < MAP.building[PLAYER[random[i]].location]; p++)
							{
								for (int P = 0; P < 3; P++)
								{
									if (p == 1 && P == 1)
									{
										continue;
									}
									//map[x-1+p][y-1+P] = 34+i;//���� ����� �� 0�� 1�� ����ؼ�
									map[x + 1 - p][y - 1 + P] = 34 + i;//���� ����� �� 0�� 1�� ����ؼ�
									//9ĭ �� ���� �Ʒ����� ����
									//���� ��ȣ�� ���µ� 33�������
									//���� ������ ǥ���ϱ� ���� 34~37���� ���
									//random[i]�� ��ȣ���� Ȱ���ؼ� 33+random[i];
								}
							}
							x = 36;
							y = 36;
						}
					}
				}
				break;
			}
		}
	}
	else if (s == 1)
	{
		MAP.building[PLAYER[random[i]].location] = 4;
		printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t***%s �Ǽ�***\n\n\n\n\n", buildingname[PLAYER[random[i]].location]);
		BN = 1;//�����ѹ��� 1�� ���缭 ������ �ǹ� �ϳ��� ���� ���� ���� �ö󰡵��� �ϱ�
		for (int x = 2; x < 35; x += 4)
		{
			for (int y = 2; y < 35; y += 4)
			{
				if (PLAYER[random[i]].location == map[x][y] - 2)
				{
					//map[x][y] += (36 + (32 * i));//�ּ�38
					// BN�� ���� �� ����
					// �߰��� �߰�ĭ ��
					//���� �ִ� ���ڸ� �Ѽ����� �ʰ�
					// 2(0)�� 1��(0) �÷��̾�� 
					// 2+36 = 38
					// 33(31)�� 1��(0) �÷��̾��
					// 33+36 = 69
					// 
					// 2(0)�� 2��(1) �ÿ��̾��
					// 2+36+32 = 70
					// 31(33)�� 2��(1) �÷��̾��
					// 33+36+32 = 101
					// 
					// .
					// .
					// �ִ� 165
					// 
					map[x][y] += 36;
					break;
				}
			}
		}
	}
}

int YORN(int s)
{
	while (1)
	{
		if (s == 0)
		{
			printf("\t\t\t\t\t\t\t\t\t     �ǹ��� ���ڽ��ϱ�? (y / n) ");
		}
		else if (s == 1)
		{
			printf("\t\t\t\t\t\t\t\t\t     ���帶ũ�� ���ڽ��ϱ�? (y / n) ");
		}
		else if (s == 2)
		{
			printf("\t\t\t\t\t\t\t\t\t    �ǹ��� �μ��Ͻðڽ��ϱ�? (y / n) ");
		}

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
			printf("\n\t\t\t\t\t\t\t\t Y(y)�Ǵ� N(n)�� �ϳ��� ���ڸ� �Է����ּ���\n");
		}
	}
}

//int END(int s)
//{
//	if (s == 0)
//	{
//		cnt = 0;
//		for (int x = 0; x < n; x++)
//		{
//			if (PLAYER[random[x]].money <= 0)
//			{
//				cnt++;
//			}
//		}
//		if (cnt == n - 1)
//		{
//			return 1;
//		}
//		return 0;
//	}
//}


void CBC(int s)
{
	if (s == 0)//�׳� �ǹ��� ���� ��(+�� ���� �ø���)
	{
		MAP.cost[PLAYER[random[i]].location] += (PLAYER[random[i]].location * BN);
	}
}

void CW(int s)
{
	if (s == 0)
	{
		MAP.who[PLAYER[random[i]].location] = random[i];
		for (int x = 2; x < 35; x += 4)
		{
			for (int y = 2; y < 35; y += 4)
			{
				if (PLAYER[random[i]].location == map[x][y] - 2)
				{
					//������
					for (int x = 2; x < 35; x += 4)
					{
						for (int y = 2; y < 35; y += 4)
						{
							if (PLAYER[random[i]].location == map[x][y] - 2)
							{
								for (int p = 0; p < MAP.building[PLAYER[random[i]].location]; p++)
								{
									for (int P = 0; P < 3; P++)
									{
										if (p == 1 && P == 1)
										{
											continue;
										}
										//map[x-1+p][y-1+P] = 34+i;//���� ����� �� 0�� 1�� ����ؼ�
										map[x + 1 - p][y - 1 + P] = 34 + i;//���� ����� �� 0�� 1�� ����ؼ�
										//9ĭ �� ���� �Ʒ����� ����
										//���� ��ȣ�� ���µ� 33�������
										//���� ������ ǥ���ϱ� ���� 34~37���� ���
										//random[i]�� ��ȣ���� Ȱ���ؼ� 33+random[i];
									}
								}
								x = 36;
								y = 36;
							}
						}
					}
				}
			}
		}
	}
}

void SP()
{
	choice = 0;
	if (PLAYER[random[i]].location == 8)
	{
		DorS = 0;
		printf("\n\t\t\t\t\t\t\t\t\t   2�� �ڿ� �ٽ� �÷��̰� �����մϴ�\n");
		PLAYER[random[i]].count = -1;
	}
	else if (PLAYER[random[i]].location == 16)
	{
		int x = 0;
		for (x = 0; x < 32; x++)
		{
			if (MAP.who[x] == random[i])
			{
				while (1)
				{
					printf("\t\t\t\t\t\t������ ���� ������ 2�谡 �˴ϴ�(���� �÷��̾��� �� / �ߺ����ý� 2��) ");
					scanf("%d", &choice);
					if (random[i] != MAP.who[choice] || choice < 0 || choice > 31)
					{
						printf("\n\t\t\t\t\t\t\t\t������ ���� �ƴմϴ�\n");
						continue;
					}
					MAP.cost[choice] *= 2;
					printf("\n\t\t\t\t\t\t\t\t\t\t%s ���� 2�� ����\n", buildingname[choice]);
					break;
				}
				break;
			}
		}
		if (x > 31)
		{
			printf("\n\t\t\t\t\t\t\t\t\t     ���� ������ ���� �����ϴ�\n");
		}
	}
	else if (PLAYER[random[i]].location == 24)
	{
		DorS = 0;
		PLAYER[random[i]].count = 1;
		printf("\n\t\t\t\t\t\t\t\t     �����Ͽ� ������ ������ �̵��� �� �ֽ��ϴ�\n");
	}
	else if (PLAYER[random[i]].location == 0)
	{
		if (YORN(0))
		{
			int x = 0;
			for (x = 0; x < 32; x++)
			{
				if (MAP.who[x] == random[i])
				{
					while (1)//�Ǽ��� �� �ִ� ���� ���� ��
					{
						printf("\t\t\t\t\t\t\t\t\t  ������ ���� �߰� �Ǽ��� �� �ֽ��ϴ� ");
						scanf("%d", &choice);
						if (choice < 32 && choice > 0 && MAP.who[choice] == random[i] && MAP.building[choice] != 4)
							//������ ���� ���� ��, �ڱⶥ, ���帶ũ�� �ƴ� ��
						{
							if (MAP.building[choice] == 3)//���帶ũ
							{
								MAP.building[choice] = 4;
								printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t***%s �Ǽ�***\n\n\n\n\n", buildingname[choice]);
								BN = 1;//�����ѹ��� 1�� ���缭 ������ �ǹ� �ϳ��� ���� ���� ���� �ö󰡵��� �ϱ�
								//���帶ũ �� ����
								for (int p = 2; p < 35; p += 4)
								{
									for (int P = 2; P < 35; P += 4)
									{
										if (choice == map[p][P] - 2)
										{
											map[p][P] += 36;
											break;
										}
									}
								}
							}
							else//�׳� �ǹ�
							{
								//�ǹ��� ����
								while (1)
								{
									printf("\t\t\t\t\t\t\t\t\t�� ���� �ǹ��� ���ڽ��ϱ�? (�߰��� ���� �ǹ��� ����)");
									scanf("%d", &BN);
									if (BN + MAP.building[choice] > 4 || BN <= 0 || BN > 3)
									{
										printf("\t\t\t\t\t\t\t�ǹ��� ������ �߸� �Ǿ����ϴ� (�ʰ� / �̸� ���� ����)");
										continue;
									}
									else
									{
										MAP.building[choice] += BN;
										for (int x = 2; x < 35; x += 4)
										{
											for (int y = 2; y < 35; y += 4)
											{
												if (choice == map[x][y] - 2)
												{
													for (int p = 0; p < MAP.building[choice]; p++)
													{
														for (int P = 0; P < 3; P++)
														{
															if (p == 1 && P == 1)
															{
																continue;
															}
															map[x + 1 - p][y - 1 + P] = 34 + i;
														}
													}
													x = 36;
													y = 36;
												}
											}
										}
										break;
									}
								}
							}
							PLAYER[random[i]].money -= (BN * choice);
							MAP.cost[choice] += (BN * choice);
							//�÷��̾��� �� -
							//�ǹ��� ���� +



							//if (PLAYER[random[i]].money -= BN * PLAYER[random[i]].location > 0)
							//{
							//	PLAYER[random[i]].money -= BN * PLAYER[random[i]].location;
							//}

							//if (s == 0)//�׳� �ǹ��� ���� ��(+�� ���� �ø���)
							//{
							//	MAP.cost[PLAYER[random[i]].location] += (PLAYER[random[i]].location * BN);
							//}
							break;
						}
						printf("\n\t\t\t\t\t\t\t\t\t�Ǽ��� �� ���� ���Դϴ�\n");
					}
					break;
				}
			}
			if (x > 31)
			{
				printf("\n\t\t\t\t\t\t\t���� ������ ���� �����ϴ�\n");
			}
		}
	}

}

void PM()
{
	int CC = 0;
	printf("\n\n");
	for (int x = 0; x < 37; x++)
	{
		printf("\t\t\t\t\t\t\t");
		for (int y = 0; y < 37; y++)
		{
			if (map[x][y] == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00);
				printf("��");
			}
			else if (map[x][y] == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x88);
				printf("��");
			}
			else if (map[x][y] > 1 && map[x][y] < 12)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				printf("%d ", map[x][y] - 2);
			}
			else if (map[x][y] > 9 && map[x][y] < 34)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				printf("%d", map[x][y] - 2);
			}
			else if (map[x][y] == 34)//ù��° ������ �÷��̾� = ������ (33+1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12 | 12 << 4);
				printf("��");
			}
			else if (map[x][y] == 35)//�ι�° ������ �÷��̾� = �Ķ���
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9 | 9 << 4);
				printf("��");
			}
			else if (map[x][y] == 36)//����° ������ �÷��̾� = �����
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 | 6 << 4);
				printf("��");
			}
			else if (map[x][y] == 37)//�׹�° ������ �÷��̾� = �ʷϻ�
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 | 10 << 4);
				printf("��");
			}
			else if (map[x][y] > 37)//���帶ũ�� ��
			{
				//map[x][y] - 36;
				if (map[x][y + 1] == 34)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xCF);
				}
				else if (map[x][y + 1] == 35)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x9F);
				}
				else if (map[x][y + 1] == 36)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x6F);
				}
				else if (map[x][y + 1] == 37)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xAF);
				}
				if (map[x][y] < 48)//���ڸ� �� �϶�
				{
					printf(" %d", map[x][y] - 38);
				}
				else
				{
					printf("%d", map[x][y] - 38);
				}
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00);
		printf("\n");
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
	printf("\n\n");
	for (int x = 0; x < n; x++)//�÷��̾��� ����
	{
		printf("\n\t\t\t\t\t\t\t\t%d�� �÷��̾��� �ڻ� %5.d����\t��ġ = %d\t", random[x], PLAYER[random[x]].money, PLAYER[random[x]].location);
		if (x == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xCC);
		}
		else if (x == 1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x99);
		}
		else if (x == 2)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x66);
		}
		else if (x == 3)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xAA);
		}
		printf("��");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
	}
}

int SA()
{
	if (PLAYER[random[i]].location == 8)
	{
		printf("\n\t\t\t\t\t\t\t\t\t   %d�� �ڿ� �÷��� �����մϴ�\n", 2 + PLAYER[random[i]].count);
		PLAYER[random[i]].count++;
		if (i == n - 1)
		{
			i = -1;
		}
		Sleep(1500);
		return 1;
	}
	else if (PLAYER[random[i]].location == 24)
	{
		while (1)
		{
			printf("\t\t\t\t\t\t\t\t\t     ������ ������ �̵��մϴ� ");
			scanf("%d", &choice);
			if (choice > 32 || choice < 0 || choice == 24)
			{
				printf("\n�̵� ������ ���� �ƴմϴ�\n");
				continue;
			}
			if (choice >= 0 && choice < 24)
			{
				PLAYER[random[i]].money += 60;
				printf("\n\t\t\t\t\t\t\t\t\t\t      ���� ����!\n");
			}
			PLAYER[random[i]].location = choice;
			printf("\n\t\t\t\t\t\t\t\t\t\t\t �̵�����\n");
			printf("\n\t\t\t\t\t\t\t\t\t%20s ����!\n\n", buildingname[PLAYER[random[i]].location]);
			break;
		}
		PLAYER[random[i]].count--;
		return 0;
	}
}