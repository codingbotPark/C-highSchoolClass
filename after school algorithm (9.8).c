//��ȣ�ص�
// ���ڿ��� �Է¹޾Ƽ�
// ���ڸ� ������ �� �� ������ ����ŭ
// �ݴ�� ��� 
// ��) l1ov2e1 = lvoe
// ��) love13 = evol
// 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char input[20];
	int length = 0;//���� ��ġ�� �ٲ�
	int len = 0;
	int temp = 0;//�ӽ÷� ���ڸ� ����
	char chartemp = 0;//�ӽ÷� 

	scanf("%s", input);

	while (input[length] != NULL)//NULL�� �ƴ� ������ ����
	{
		if (input[length] >= 49 && input[length] <= 57)//������ ��
		{
			temp = input[length] - 48;//���ڷ� ��ȯ
			input[length] = '0';//���ڰ� �ִ� �ڸ��� 0���� ����

			for (int i = 0; i < temp; i++)//�� ���ڸ�ŭ
			{
				printf("%c", input[--length]);
				input[length] = '0';//����� �ڸ��� 0���� ����
			}

			//�ڿ� ���� �͵��� ������ ���
			for (int i = 0; i < temp + 1; i++)//���ڰ� �ִ� �ڸ�, ����� ���� ������ŭ ������ ��ܾ� �Ѵ�
			{
				len = length + temp - i + 1;//temp��ŭ ���� = ���� ���� ���� �����ڸ�
				//length = ��µ� ������ ���� ��
				while (input[len] != NULL)//������ ���ڿ� ����
				{
					input[len - 1] = input[len];
					len++;

				}
				//��������° �ε����� �� NULL���� �����
				input[len - 1] = input[len];
			}

			length--;//length�� �� �ڸ��� �ӹ����� - �ϱ�
		}
		length++;
	}

	return 0;
}