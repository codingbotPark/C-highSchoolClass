//���ڿ��� �Է¹ް� ���� ���� ���� ���ĺ� ���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	
int main()
{
	int value[26] = { 0, };//���ĺ��� 26��
	char arr[10000000];//�Է¹��� char�� �迭
	int temp = 0;//arr�� ������ �� ����

	scanf("%s", &arr);

	while (arr[temp] != NULL)//arr�� ������
	{
		if (arr[temp] >= 97)//�ҹ����� ��
		{
			value[arr[temp] - 97]++;
		}
		else
		{
			value[arr[temp] - 65]++;
		}
		temp++;
	}

	int max = 0;
	int cnt = 0;

	for (int i = 1; i < 26; i++)//���� ū ���� ���ϱ�
	{
		if (value[i] > value[max])
		{
			cnt = 0;
			max = i;
		}
		else if (value[i] == value[max])
		{
			cnt++;
		}
	}

	if (cnt > 0)
	{
		printf("?");
	}
	else
	{
		printf("%c", max + 65);
	}
}