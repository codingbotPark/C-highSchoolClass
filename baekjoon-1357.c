//���� 1357��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int reverse(int num)
{
	int i = 0;
	int cpynum = num;
	int temp = 1;
	int value = 0;
	while (cpynum != 0)
	{
		i++;
		cpynum /= 10;
	}
	//i�� ������ ���̰� �ȴ�
	for (int j = 1; j < i; j++)
	{
		temp *= 10;
	}

	for (int j = 0; j < i; j++)
	{
		value += temp * (num % 10);
		num /= 10;
		temp /= 10;
	}
	return value;
}

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	printf("%d", reverse(reverse(x) + reverse(y)));
}


////������ �ڵ�
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int rev(int n) {
//	int sum = 0;
//	while (n) {
//		sum = sum * 10 + n % 10;
//		n /= 10;
//		//�Ҽ��� ���� int������ ���ܽ�Ų��
//		//12345 ���� 5�� ��� �� 1234.5�� ����� 5�� ����
//	}
//	return sum;
//}
//
//int main(void) {
//	int x, y;
//	scanf("%d %d", &x, &y);
//	printf("%d", rev(rev(x) + rev(y)));
//	return 0;
//}