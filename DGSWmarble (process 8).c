//과정 8
// 
// 게임이 끝나는 경우를 만듬
// 
// 파산하면 파산한 플레이어의
// 땅 건물과 소유를 초기화 하는 부분에서
// if문 버그 수정
// 
// 코드 정리
// 
// 맵 만들기(그림)
// windows 라이브러리 사용
// 맵 프린트
// 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <windows.h>

#define CLS system("cls")

struct PLAYER
{
	int money;//플레이어의 돈
	int location;//플레이어의 위치
};
struct MAP
{
	int building[32];//빌딩의 개수
	int who[32];//빌딩의 소유자
	int cost[32];
};

int map[33][33] = {
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

struct PLAYER PLAYER[4] = { 0, };
struct MAP MAP = { 0, };


void TURN();
//플레이어의 수를 받아서 순서를 정하는 함수
int dice();
//주사위를 돌리는 함수
void GS(int s);//gamesetting
//게임이 시작되기 전 세팅
int judge(int s);
//어떤 상황인지 판단하는 함수(내땅인지 상대땅인지 등)
void CM(int s);//changingmoney
//어떤 상황에 따라 돈을 + - 하는 함수
void BB(int s);//buildingbuilding
//상황에 따라 빌딩을 짓는 함수
int YORN(int s);
//상황에 따라 Y또는N을 받아서 1또는 0을 반환하는 함수
void GF(int s);//gamefuntion
//게임의 기능(파산한사람의 순서를 넘기기)
int END(int s);
//게임의 끝일 상황을 판단하는 함수
void CBC(int s);//changingbuildingcost
//건물을 지을 때 마다 땅의 가격을 바꾸는 함수
void CW(int s);//changingwho
//상황에 따라 건물의 소유자를 바꾸는 함수
void SP();//specialplace
//상황에 따라 무인도, 올림픽개최, 세계여행등
void PM();// printmap
//맵 출력 함수
void MV();// move
//플레이어의 좌표를 이동시키는 함수



int i = 0;//main for문에서 사용되는 변수
int n = 0;//플레이어의 수
int random[4];//순서
char YorN;//아무키나 눌러 넘기기 / Y or N
int DorS;//더블인지 아닌지
int BN;//지을 건물의 개수
int choice;//선택하는 건물(올림픽 개최, 세계 여행 등)
char buildingname[32][20] = { "정문", "운동장", "체육관", "사회전용실", "국어전용실",
"수학전용실", "시청각실", "미술실", "기숙사", "방송실","창의공작실",
"모바일프로그래밍실", "DB네트웨크실습실", "윈도우프로그래밍실", "오케스트라실", "도서관",
"급식실", "언턴드","보안동아리", "세븐랩스", "스타봇", "CnS", "ducami", "b1nd", "귀가 버스",
"사감실", "교무실", "교장실", "재덕정", "대니산", "1학년1반", "박병관" };
//빌딩의 이름
int cnt = 0;//파산한 사람의 개수 +


int main()
{
	srand((unsigned)time(NULL));
	GS(2);//풀스크린
	GS(1);//빌딩값 초기화
	TURN();//순서 정하기
	GS(0);//순서그대로 플레이어 돈 초기화
	for (i = 0; i < n; i++)
	{
		GF(0);
		dice();
		if (judge(3))//특수한 지역일 때
		{
			SP();
		}
		else//특수한 지역이 아닐 때
		{
			if (judge(0))// 상대땅인지 아닌지 판별 아니면
			{
				if (!(judge(1)))//랜드마크인지 아닌지 아니라면
				{
					if (!(judge(2)))//건물이 3개 미만일 때
					{
						if (YORN(0))//건설할 때
						{
							BB(0);
							CW(0);
						}
					}
					else//건물이 3개일 때
					{
						if (YORN(1))//랜드마크를 지을 것인가
						{
							BB(1);
						}
					}
					CM(0);//짓는 건물의 개수에 따라 
					CBC(0);//건물을 지음에 따라 땅의 가격을 바꿔주기
				}
				//else 랜드마크라면 넘기기
			}
			else // 맞으면
			{
				CM(1);//일단 돈을 내고
				if (!(judge(1)))//랜드마크가 아니라면(인수가 가능하다면)
				{
					if (YORN(2))//인수를 할 것인가? 맞다면
					{
						CM(2);
						CW(0);
						if (YORN(0))//건물을 추가로 지을건지 아닌지 맞으면
						{
							if (judge(2))//인수한 땅의 건물이 3개인지 아닌지 맞으면
							{
								if (YORN(1))//랜드마크를 지을거면
								{
									BB(1);
									CM(0);
								}
							}
							else//아니면
							{
								BB(0);
								CM(0);
							}
						}
						//else
					}
				}
			}
		}
		//CLS;
		PM();

		//확인코드
		for (int x = 0; x < n; x++)
		{
			printf("%d번 플레이어의 자산 %d\n", random[x], PLAYER[random[x]].money);
		}
		for (int x = 0; x < 32; x++)
		{
			printf("%d번 건물의 개수 %d\n", x, MAP.building[x]);
			printf("%d번 건물의 소유 %d\n", x, MAP.who[x]);
		}

		END(0);//더블사이에 끝이 날 수도 있다
		if (DorS)//더블일 때 한번 더
		{
			i--;
			continue;//continue가 쓰여서
			//함수에 넣게되면 더 길어진다
		}
		GF(1);//순서돌리기
	}

	return 0;
}

void TURN()
{
	while (1)
	{
		printf("\n---------------\n");
		printf("플레이어의 수를 입력하세요(2~4) ");
		scanf("%d", &n);
		if (n > 1 && n < 5)
		{
			break;
		}
		printf("\n2명 이상, 4명 이하의 플레이어 수를 입력해주세요\n");
	}
	printf("각자 번호를 정하세요 (다 정했으면 아무키나 입력해 주세요) ");
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
		printf("\n%d번째순서 = %d번 플레이어", x + 1, random[x]);
	}
	printf("\n---------------\n");
}

int dice()
{
	DorS = 0;//더블인지아닌지 판단하는 변수를 초기화
	int power;
	int n1 = 0;//주사위1
	int n2 = 0;//주사위2
	printf("\t%d번 플레이어 차례\n", random[i]);
	while (1)
	{
		printf("주사위 강도를 입력해주세요(1~5) ");
		scanf("%d", &power);
		if (power < 1 && power > 5)
		{
			printf("1이상 5이하의 수를 입력해주세요");
			continue;
		}
		break;
	}
	n1 = rand() % 2 + power;
	n2 = rand() % 6 + 1;
	printf("\n주사위 = %d %d\n", n1, n2);
	PLAYER[random[i]].location += (n1 + n2);
	if (PLAYER[random[i]].location > 31)
	{
		PLAYER[random[i]].location -= 32;
		PLAYER[random[i]].money += 60;
		printf("\n월급 지급!\n");
	}
	printf("\n%s 도착!\n\n", buildingname[PLAYER[random[i]].location]);
	printf("%d번 플레이어의 위치 = %d\n", random[i], PLAYER[random[i]].location);
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
	else if (s == 1)//빌딩가격을 칸 * 2로 초기화
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
	if (s == 0)//파산한 플레이어를 뛰어 넘는 상황
	{
		if (PLAYER[random[i]].money <= 0)
		{
			if (i == n - 1)//i가 마지막일 때
			{
				i = -1;
			}
			i++;
		}
	}
	if (s == 1)
	{
		if (i == n - 1)//순서돌리기
		{
			i = -1;
		}
	}
}

int judge(int s)
{
	if (s == 0)//상대땅인지 아닌지 판단
	{
		if (MAP.who[PLAYER[random[i]].location] != random[i] && MAP.building[PLAYER[random[i]].location] != 0)//상대땅일 때
		{
			return 0;
		}
		else//건설 할 수 있을 때
		{
			return 1;
		}
	}
	else if (s == 1)//랜드마크인지 아닌지 판단
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
	else if (s == 2)//건물이 3개인지 3개 미만인지 판단(랜드마크건설)
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
	else if (s == 3)//특수한 지역인지 아닌지 판단(무인도 등)
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


void CM(int s)
{
	if (s == 0)//아무것도 없을 때 건설
	{
		//PLAYER[random[i]].money -= MAP.cost[PLAYER[random[i]].location];
		//건물을 지을 때 마다 더 비싸게 주고 건물을 지어야함
		if (PLAYER[random[i]].money -= BN * PLAYER[random[i]].location > 0)
		{
			PLAYER[random[i]].money -= BN * PLAYER[random[i]].location;
		}
		else
		{
			printf("\n돈이 부족합니다\n");
		}
	}
	else if (s == 1)//통행료
	{
		PLAYER[random[i]].money -= MAP.cost[PLAYER[random[i]].location];//건물에 온 사람
		PLAYER[MAP.who[PLAYER[random[i]].location]].money += MAP.cost[PLAYER[random[i]].location];//건물주인
	}
	else if (s == 2)//인수료
	{
		PLAYER[random[i]].money -= PLAYER[random[i]].location * 2;//건물에 온 사람
		PLAYER[MAP.who[PLAYER[random[i]].location]].money += PLAYER[random[i]].location * 2;//건물주인
		//MAP.cost[PLAYER[random[i]].locaiton]하지 않고 위치 * 2를 하는 이유는
		//올림픽 개최로 인해 MAP.cost가 올라가면 인수 할 때 cost가 올라간 채로 인수가 되기때문에
	}
	if (PLAYER[random[i]].money < 0)//파산확인
	{
		printf("\n%d번 플레이어 파산\n", random[i]);
		for (int x = 1; x < 32; x++)
		{
			if (MAP.who[x] == random[i])//지도를 비교해서 파산한 사람의 땅을 모두 없앤다
			{
				MAP.who[x] = 0;
				MAP.building[x] = 0;
			}
		}
	}
}

void BB(int s)
{
	if (s == 0)
	{
		while (1)
		{
			printf("몇 개의 건물을 짓겠습니까? (추가로 지을 건물의 개수) ");
			scanf("%d", &BN);
			if (BN + MAP.building[PLAYER[random[i]].location] >= 4 || BN <= 0 || BN > 3)
			{
				printf("\n건물의 개수가 잘못 되었습니다 (초과 / 미만 등의 이유)\n");
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
		printf("\n***%s 건설***\n", buildingname[PLAYER[random[i]].location]);
		BN = 1;//빌딩넘버를 1로 맞춰서 가격이 건물 하나를 지을 때와 같이 올라가도록 하기
	}
}

int YORN(int s)
{
	if (s == 0)
	{
		printf("건물을 짓겠습니까? (y / n)");
	}
	else if (s == 1)
	{
		printf("랜드마크를 짓겠습니까? (y / n)");
	}
	else if (s == 2)
	{
		printf("건물을 인수하시겠습니까? (y / n)");
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
			printf("\nY(y)또는 N(n)중 하나의 문자를 입력해주세요\n");
		}
	}
}

int END(int s)
{
	if (s == 0)
	{
		cnt = 0;
		for (int x = 0; x < n; x++)
		{
			if (PLAYER[random[x]].money <= 0)
			{
				cnt++;
			}
		}
		if (cnt == n - 1)
		{
			return 1;
		}
		return 0;
	}
}


void CBC(int s)
{
	if (s == 0)//그냥 건물을 지을 때(+로 가격 올리기)
	{
		MAP.cost[PLAYER[random[i]].location] += (PLAYER[random[i]].location * BN);
	}
}

void CW(int s)
{
	if (s == 0)
	{
		MAP.who[PLAYER[random[i]].location] = random[i];
	}
}

void SP()
{
	choice = 0;
	if (PLAYER[random[i]].location == 8)
	{
		printf("\n다음턴에 다시 플레이가 가능합니다\n");
	}
	else if (PLAYER[random[i]].location == 16)
	{
		while (1)
		{
			printf("선택한 땅의 가격이 2배가 됩니다(현재 플레이어의 땅) ");
			scanf("%d", &choice);
			if (random[i] != MAP.who[choice] || choice < 0 || choice > 31)
			{
				printf("\n가능한 땅이 아닙니다\n");
				continue;
			}
			MAP.cost[choice] *= 2;
			break;
		}

	}
	else if (PLAYER[random[i]].location == 24)
	{
		while (1)
		{
			while (1)
			{
				printf("선택한 땅으로 이동합니다");
				scanf("%d", &choice);
				if (choice > 32 || choice < 0)
				{
					printf("\n이동 가능한 땅이 아닙니다\n");
					continue;
				}
				PLAYER[random[i]].location = choice;
				break;
			}
		}
	}
	else if (PLAYER[random[i]].location == 0)
	{
		while (1)
		{
			printf("선택한 땅을 건설할 수 있습니다");
			scanf("%d", &choice);
		}
	}

}

void PM()
{
	printf("\n\n");
	for (int x = 0; x < 33; x++)
	{
		printf("\t\t\t\t\t\t\t\t");
		for (int y = 0; y < 33; y++)
		{
			if (map[x][y] == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00);
				printf("□");
			}
			if (map[x][y] == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x88);
				printf("■");
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00);
		printf("\n");
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
	printf("\n\n");
}
