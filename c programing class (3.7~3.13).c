//#define _CRT_SECURE_NO_WARNINGS�� ����� �������� ���� �ȳ��� ����
//(���� ���� ����� �Ѵ�)
//long -> %ld
//double -> %lf

//3.8
 #include <stdio.h>
int main()
{
	int num1 = 15; //00000000 00000000 00000000 00001111 (1+2+4+8)
	int num2 = 20; //00000000 00000000 00000000 00010100 (4+16)
	int num3 = num1 & num2; //num1�� num2�� ��Ʈ���� & ����
	printf("AND ������ ���: %d \n",num3);	
	return 0;
} 

#include <stdio.h>
int main()
{
	int a = 0, b = 0, c = 1, d = 1;
	printf("%d", a == b & c ==d);

	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n1 = 15, n2 = 20;
	int answer = n1 | n2;
	printf("%d", answer);
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 0, b = 0, c = 0, d = 0;
	printf("�� ������ �Է��ϼ���");
	scanf_s("%d %d", &a, &b);
	printf("%d", a | b);
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 2;
	printf("%d\n", n);
	printf("%d\n", n << 1);
	printf("%d\n", n << 2);
	printf("%d\n", n << 3);
	printf("%d\n", n << 4);
	printf("%d\n", n << 14);
	printf("%d\n", n << 30);//overflow (�ڷ����� ���� �� ������)
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 1024;
	printf("%d\n", n);//00000100 00000000
	printf("%d\n", n >> 1); 
	printf("%d\n", n >> 2);
	printf("%d\n", n >> 3);
	printf("%d\n", n >> 9);
	printf("%d\n", n >> 10);
	printf("%d\n", n >> 11);//0
	printf("%d\n", n >> 12);//0
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	n = ~n;
	n++;
	printf("%d\n", n);
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char ch = 9;
	printf("ch�� ũ�� : %d\n", sizeof(ch));
	printf("���� 9�� ũ�� : %d\n", sizeof(9));
	int n = 9;
	printf("n�� ũ�� : %d\n", sizeof(n));
	printf("���� 9�� ũ�� : %d\n", sizeof(9));
	double d = 9.1234;
	printf("d�� ũ�� : %d\n", sizeof(d));
	printf("���� 9.1234�� ũ�� : %d\n", sizeof(9.1234));
	return 0;
}

//3.9
�������� �Է¹޾� �����̸� ���ϴ� �ڵ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double area = 0, r = 0;
	printf("�������� �Է��ϼ���");
	scanf("%lf", &r);
	area = r * r * 3.14;
	printf("������ %.lf�� ���� ���̴� %1.lf�Դϴ�", r,area);
	return 0;
}

#include <stdio.h>
int main()
{
	char ch1 = 'A', ch2 = 65;
	int ch3 = 'Z', ch4 = 90;
	printf("%c %d \n", ch1, ch1);
	printf("%c %d \n", ch2, ch2);
	printf("%c %d \n", ch3, ch3);
	printf("%c %d \n", ch4, ch4);

	return 0;
}

ASCII��ȣ > ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n= 0;
	scanf("%d", &n);
	printf("ASCII ���� %c\n", n);
	return 0;
}

ASCII���� > ��ȣ
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char n= 0;
	scanf("%c", &n);
	printf("ASCII ��ȣ %d\n", n);
	return 0;
}

//getchar���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
		int n= 0;
	scanf("%d", &n);
	printf("ASCII ���� %c\n", n);
	getchar();
		char n= 0;
	scanf("%c", &n);
	printf("ASCII ��ȣ %d\n", n);
	return 0;
}

//�� ���� �Է¹޾� �簢���� ���̸� ���ϴ� ���α׷�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int x1 = 0, x2 = 0, x3 = 0, x4 = 0;
	int x = 0, y = 0, a = 0;
	printf("�簢���� �� �ϴ��� x,y��ǥ�� �Է��ϼ���");
	scanf("%d %d", &x1, &x2);
	getchar();
	printf("�簢���� �� ����� x,y��ǥ�� �Է��ϼ���");
	scanf("%d %d", &x3, &x4);
	x = x3 - x1;
	y = x4 - x2;
	a = x * y;
	printf("�簢���� ���� %d", a);
	return 0;
}


