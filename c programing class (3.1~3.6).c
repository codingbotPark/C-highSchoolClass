//shift + DelŰ = �� �� ����
//#in ��Ű ������
//ctrl + f7 = ������
//ctrl + B = ����
//ctrl + = f5����	
//alt + ����Ű = ���̵�
//ctrl + D = ����

//3.1
#include <stdio.h>
int main()
{
	printf("Hello World\n");
	printf("Hello World");
	printf("Hello\n World");
	printf("\nõ���� 70 105�� 1504ȣ");
	printf("\n%d", 1234);
	printf("%d%d", 10, 20);
	return 0;
}

#include <stdio.h>
int main()
{
	printf("My age : %d", 17);
	printf("���� c��� ���� : %d ", 100);
	return 0;
}

#include <stdio.h>
int main()
{
	int n1 = 1, n2 = 2, n3 = 3;
	printf("n1 = %d n2 = %d n3 = %d\n", n1, n2, n3);
	printf("n1 = %d n2 = %d n3 = %d\n", n1 + 1, n2 + 1, n3 + 1);
	printf("n1 = %d n2 = %d n3 = %d\n", ++n1, ++n2, ++n3);
	printf("n1 = %d n2 = %d n3 = %d\n", n1++, n2++, n3++);
	return 0;
}


#include <stdio.h>
int main()
{
	int n = 1;
	printf("n1=%d", n1);
	n1++;
	printf("n1=%d", n1++);
	printf("n1=%d", n1);


	return 0;
}

//3.2
#include <stdio.h>
int main()
{
	//�񱳿�����
	int n1 = 1, n2 = 2;
	int ���=0;
	printf("��� : %d\n", ���);
	��� = (n1 == n2);
	printf("��� : %d\n", ���);
	n2 = 1;
	��� = (n1 == n2);
	printf("��� : %d\n", ���);
	��� = (n1 >= n2);
	printf("��� : %d\n", ���);
	��� = (n1 <= n2);
	printf("��� : %d\n", ���);
	��� = (n1 > n2);
	printf("��� : %d\n", ���);
	��� = (n1 < n2);
	printf("��� : %d\n", ���);

	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n1=0, n2=0;
	scanf("%d", &n1);
	scanf("%d", &n2);
	printf("n1 = %d\nn2 = %d", n1,n2);\
	return 0;
}

//3.3
#include <stdio.h>
int main()
{
	printf("\t��");

	return 0;
}

#include <stdio.h>
int main()
{
	printf("��\n��\n��");
	return 0;
}

#include <stdio.h>
int main()
{
	printf("�ȳ�!!\n");
	printf("�� �̸��� : ȫ�浿�̾�.");
	printf("���� 17���̾�.");
	printf("���� �¿���� \"�ּ��� ���� �������\"");

	return 0;
}

//3.4
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char d = 0;
	scanf("%c", &d);
	printf("%c", d);
	return 0;
}

#include <stdio.h>
int main()
{
	int x = 2147483647;
	char y = 127;
	printf("%d\n", x);
	x += 1;
	printf("%d\n", x);
	printf("%d\n", y);
	y += 1;
	printf("%d\n", y);
	return 0;
}

//3.10
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
int Korean = 0, English = 0, math = 0, computer = 0, sum = 0, avg = 0;
printf("����, ����, ����, ��ǻ�� ���� ������ ���ʴ�� �Է��ϼ���");
scanf("%d%d%d%d", &Korean, &English, &math, &computer);
sum = Korean + English + math + computer;
printf("sum %d\n", sum);
avg = sum / 4;
printf("avg %d", avg);
return 0;
}

#define _crt_secure_no_warnings
#include <stdio.h>
int main()
{
	int a = 0, b = 0;
	printf("�� ������ �Է��ϼ���");
	scanf("%d %d", &a, &b);
	printf(" %d / %d = %d . . . %d", a, b, a / b, a % b);

	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 0, b = 0;
	printf("���� ������ ���̸� �Է��ϼ���");
	scanf("%d %d", &a, &b);
	a += 5;
	b = b * 2;
	printf("%d\n%d\n%d", a, b, a * b);
	return 0;
}

//3.11
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 0, b = 0;
	printf("�� ���� �Է��ϼ���");
	scanf("%d %d", &a, &b);
	printf("%d %d", ++a, b--);
	printf("\n%d %d", a, b);

	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 0, b = 0, c = 0, d = 0, e = 0,f=0;
	printf("�μ��� Ű�� �����Ը� �Է��ϼ���");
	scanf("%d %d", &a, &b);
	printf("�⿵���� Ű�� �����Ը� �Է��ϼ���");
	scanf("%d %d", &c, &d);
	printf("%d", (a > c && b > d) ? (e = 1) : (e = 0));
	return 0;
}


