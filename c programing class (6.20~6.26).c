//�����غ�

//6.22
//���������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	FILE* ifp = fopen("run.txt", "r");//���� �б�
	FILE* ofp = fopen("result.txt", "w");//���� ����
	//ifp�� ofp�� �̸��� �׳� ���� ���̴�
	char name[10];
	double avg, n1, n2, n3;
	//scanf("%s %d %d %d", name, &n1, &n2, &n3);
	fscanf(ifp, "%s %lf %lf %lf", name, &n1, &n2, &n3);
	avg = (n1 + n2 + n3) / 3.0;
	fprintf(ofp, "%s %.1f", name, avg);
	fclose(ifp);
	fclose(ofp);
	return 0;
}
//run.txt������ ���� result.txt���Ͽ� �����ؼ� �ִ´�

//�Ҽ����ϱ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int isPrime(int n)
{
	//for (int i = 2;i<n;i++)
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	while (1)
	{
		int n;
		printf("���� : ");
		scanf("%d", &n);

		if (n < 2)return 0;//2�̸��� ���� ���ٸ�
		if (n >= 1000)
		{
			printf("\n");
			continue;
		}
		int primeCnt = 1;
		for (int i = 2; i <= n; i++)
		{
			if (isPrime(i))
			{
				printf("%d ", i);
				if (primeCnt == 10)
				{
					printf("\n");
					primeCnt = 1;
				}//10������ �ٹٲ�
				primeCnt++;
			}
		}
	}
	return 0;
}







//�⸻����� 
//�ڽ����̸������
#include <stdio.h>
int main()
{
	printf("�ں���");
	return 0;
}
//�ڽ����̸������η����
#include <stdio.h>
int main()
{
	printf("��\n��\n��");
	return 0;
}
//�Ұ�
#include <stdio.h>
int main()
{
	char name[10] = "�ں���";
	int age = 17;
	char string[22] = "�ּ��� ���� �������";
	printf("�ȳ�!!!\n");
	printf("�� �̸��� : %s�̾�\n",name);
	printf("���� %d���̾�.\n",age);
	printf("���� �¿���� \"%s\"", string);
	return 0;
}
//���������� �Է¹޾� ������ ����� ���ϴ� ���α׷�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int K, E, M, C;
	int sum = 0, avg = 0;
	scanf("%d %d %d %d", &K, &E, &M, &C);
	sum = K + E + M + C;
	avg = sum / 4;
	printf("sum %d\navg %d", sum, avg);

	return 0;
}
//�� ������ �Է¹޾� ��� �������� ����ϴ� ���α׷�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int one, two;
	scanf("%d %d", &one, &two);
	printf("%d / %d = %d...%d", one, two, one / two, one % two);

	return 0;
}
//���簢���� ���μ��θ� �Է¹ް�
//���δ� + 5 ���δ� * 2�ؼ� ���μ��γ��� ����ϴ� ���α׷�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int w, h;
	scanf("%d %d", &w, &h);
	printf("width = %d\n", w += 5);
	printf("lenght = %d\n", h *= 2);
	printf("area = %d\n", h * w);

	return 0;
}
//���� a�� b�� �Է¹޾� 
//a = ��ġ, b = ��ġ �����ڸ� ���,
//a = ����, b = ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a, b, c;
	scanf("%d %d", &a, &b);
	c = ++a + b--;
	printf("a = %d, b = %d, c = %d", a, b, c);
	return 0;
}
//3������ ������ �Է¹޾� ����� ���� �� �ݿø� => �Ҽ� ù°�ڸ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a, b, c;
	float avg = 0;
	//scanf("%f %f %f", &a, &b, &c);
	scanf("%d %d %d", &a, &b, &c);
	avg = a + b + c;
	printf("avg = %.2f", avg / 3);
	return 0;
}
//3������ ������ �Է¹޾� ������ �����κ��� �հ�, ����� �Ǽ��� ����� ���ϴ� ���α׷�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	float a, b, c;
	int sum;
	float avg;
	scanf("%f %f %f", &a, &b, &c);
	sum = (int)a + (int)b + (int)c;
	printf("sum = %d\n", sum);
	avg = a + b + c;
	printf("avg = %.f", avg/3);

	return 0;
}
//5���� ������ �Է� �޾� ������ ���� +3, -3, ��3, /3, %3�� ������ �����Ͽ� 
//�� ���� ������ �� ���ʴ�� ����ϴ� ���α׷�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a, b, c, d, e;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	a += 3;
	b -= 3;
	c *= 3;
	d /= 3;
	e %= 3;
	printf("%d %d %d %d %d", a, b, c, d, e);
	return 0;
}
//���ĺ� ��A������ ��Z������ ����ϴ� ���α׷�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 65;
	while (a<91)
	{
		printf("%c", a++);
	}
	return 0;
}
//1���� 20���� Ȧ���� ���ʴ�� ����ϴ� ���α׷�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 1;
	for (a = 1; a < 20; a += 2)
	{
		printf("%d ", a);
	}
	return 0;
}
//10 �̸��� ������ �Է¹޾� ���丮���� ���ϴ� ���α׷�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int num;
	int val = 1;
	scanf("%d", &num);
	for (int i = 1; i <= num; i++)
	{
		val *= i;
	}
	printf("%d", val);
	return 0;
}
//6���� ü���� �Է¹޾� ����� ����ϴ� ���α׷�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	float weight[6];
	float avg = 0;
	for (int i = 0; i < 6; i++)
	{
		scanf("%d", &weight[i]);
		avg += weight[i];
	}
	printf("avg = %.1f", avg);
	return 0;
}	