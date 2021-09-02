// 8.18~8.21
// extern �̶�� ������	
// �ٸ������� ������ �� �� �ִ�
// ��)
// extern void func1();
// �� �����ϸ� �ٸ� ������ func1() �� ����� �� �ִ�'
// 
// ������(pointer) = ����Ű�� ��
// & ������ = ������ �ּҸ�����
// * ������ = �����Ͱ� ����Ű�� ���� ������ ����
// �� ��) int* p; = ������ ������ ����Ű�� �������̴�
// �������� �����͸� Ȱ���� ������ ���� ������ �� �ִ�
// 
// �迭�� �̸��� ��ǻ� �����Ϳ� ���� �����̴�

// 8.22~8.28
// call by value = ���� ���� ȣ��
// call by reference = ������ ���� ȣ��
// 
// call by value�� ���ڷ� ���� ���� �����Ͽ� ó���� �Ѵ�
// call by reference�� ���ڷ� ���� ���� �ּҸ� �����Ͽ� ���� ���� ������ �ش�
// ��  ���� ���縦 �Ͽ� ó���ϴ���, ���� ������ �ϴ��� �����̴�
// 
// call by value
// ���� = ���縦 �Ͽ� ó���ؼ� �����ϴ�. ���� ���� �����ȴ�
// ���� = ���縦 �ؼ� �޸𸮰� ��뷮�� �þ��
// 
// call by reference
// ���� = �������� �ʰ� ���� ������ �ϱ⿡ ������
// ���� = ���� ������ �ϱ⿡ ���� ���� ������ �޴´�
// 
// ��ũ�� ����Ʈ
// ���� �ʿ��� ������ ����� �Ǽ� �޸𸮸� ȿ�������� ����� �� �ִ�

//8.19
//������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

static int i = 7;//��������(�޸��� �����Ϳ���)
void func1();
void func2();

int main()
{
	int i = 5;//��������(�޸��� stack����)
	func1();
	i++;
	printf("i=%d\n", i);//���������� i
	return 0;
}

void func1()
{
	i++;//���������� i
	printf("func1 i = %d \n", i);
	func2();
}

void func2()
{
	i++;//���������� i
	printf("func2 i=%d \n", i);
}



#include <stdio.h>
int main()
{
	static int i = 7, * p, ** pp;
	p = &i;//���� i

	pp = &p;//���� i�� ����Ű�� �������� ������
	//�� ���� i

	printf("p\'s Address = %p\n,p");
	printf("pp\'s Address = %p\n,pp");

	(*p)++;
	printf("i = %d \t", i);
	printf("*p = %d \t", *p);
	printf("**pp = %d \n", **pp);

	(**pp)++;
	printf("i = %d \t", i);
	printf("*p = %d \t", *p);
	printf("**pp = %d \n", **pp);

	return 0;
}

#include <stdio.h>
int main()
{
	char string[] = "Hello";
	char* pstr = string;//pstr�� ���ڿ��� ����Ű�� �������̴�
	while (*pstr)//���ڿ��� null(��) ���� �����Ѵ�
	{
		putchar(*pstr++);//putchar�� printf�� %c �� ���� ������ �Ѵ�	
		//++�� �����鼭 �����ܾ ��µȴ�
	}

	return 0;
}

//8.23
//call by value
//call by reference
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap1(int a, int b)//call by value
{
	int t = a;
	a = b;
	b = t;
}

void swap2(int* a, int* b)//call by reference
{
	int t = *a;
	*a = *b;
	*b = t;
}//�����͸� ����ؼ� swapȣ�� �Ŀ��� ���� ����Ǿ� ����

int main()
{
	int n1 = 5, n2 = 7;
	printf("n1 = %d, n2 = %d\n", n1, n2);
	swap1(n1, n2);
	printf("n1 = %d, n2 = %d\n", n1, n2);
	swap2(&n1, &n2);//�����͸� ����ϱ� ������ �ּҸ� �Ѱܾ� �Ѵ�
	printf("n1 = %d, n2 = %d\n", n1, n2);

	return 0;
}

//���丮��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int factorial(int c)
{
	return ((c == 0) ? 1 : c * factorial(c - 1));
}

int main()
{
	int n = 10;
	printf("%d! = %d", n, factorial(n));
	return 0;
}
//10������ ������ ��� ��µǵ��� �ٲٱ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int d=0;
int factorial(int c)
{
	if (c == 0)
	{
		return 1;
	}
	d = c * factorial(c - 1);
	printf("%d! = %d\n",c, d);
	return d;
	//return c * factorial(c - 1);
	//return ((c == 0) ? 1 : c * factorial(c - 1));
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d! = %d", n, factorial(n));
	return 0;
}
//����)�ѵ������� �ݺ����� ����Ͽ� ���ϴ� �ڵ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n,v=1;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
	{
		v *= i;
	}
	printf("%d! = %d",n ,v);
	return 0;
}
//��������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input(int a[], int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		scanf("%d", &a[i]);
	}
}

void output(int a[], int cnt)
{
	int i;
	for (i = 0; i < cnt; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
}

void swap(int* x, int* y)
{
	int t = *x;
	*x = *y;
	*y = t;
}

void selectionSort(int a[], int cnt)//��������
{
	for (int i = 0; i < cnt - 1; i++)
	{
		for (int j = i + 1; j < cnt; j++)
		{
			if (a[i] > a[j])//���� �ں��� Ŭ ��
			{
				swap(&a[i], &a[j]);//call by reference
			}
		}
	}
}

int main()
{
	int n;
	int a[100];
	scanf("%d", &n);
	input(a,n);
	selectionSort(a, n);
	output(a, n);
	return 0;
}
+�������ļ���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include <time.h>
#include <stdlib.h>

int main()
{
	srand((unsigned)time(NULL));

	int a[100];
	int b,c;
	int temp = 0;


	while (1)
	{
		printf("�������� ���� �Է½�Ű���� 1\n");
		printf("���� ���� �Է��Ϸ��� 2���� �Է��ϼ���\n\n");
		scanf("%d", &b);
		printf("\n\n������, �Է��� ������ ���� �Է��ϼ���\n\n");
		scanf("%d", &c);

		if (b == 1)
		{
			printf("\n\n���� �� : ");
			for (int i = 0; i < c; i++)
			{
				a[i] = rand() % 100;
				printf("%d\t", a[i]);
			}
			break;
		}
		else if (b == 2)
		{
			for (int i = 0; i < c; i++)
			{
				scanf("%d", &a[i]);
			}
			break;
		}
	}

	for (int i = 0; i < c ; i++)
	{//������ ������ŭ ����
		for (int j = 0; j < c-1; j++)
		{//+ 1�� �ϸ� ���ϱ⶧���� ������ ���ڴ�
			//������ �ʾƵ� �ȴ�
			if (a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	printf("\n\n\n������ : ");
	for (int i = 0; i < c; i++)
	{
		printf("%d\t", a[i]);
	}

	return 0;
}