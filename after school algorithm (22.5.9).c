// 1������
// 1���� n������ ���� ���� ī�尡 �ִ�
// �� ī��� ���� ���� �ִ� ù ° ī�带 �� �Ʒ��� �ְ�
// ��° ī�带 ���߸� 1,
// �� ����  ��° ī�带 �ڷ� ������,
// �� ���� ī�带 ���߸� 2,
// . . .

# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>

int main() {
	int arr[100] = { 0, };
	int num;
	scanf_s("%d", &num);

	int counter = 1;// �ε����� ���� ��
	int i = -1;// �ε����� �� ��
	int toggle = 0;// �� ĭ ������� �ƴ���
	while (counter < num + 1) {
		i++;
		if (i == num) {
			i = 0;
		}

		if (arr[i] == 0) {
			if (toggle == 0) {
				toggle = 1;
				continue;
			}
			else {
				arr[i] = counter++;
				toggle = 0;
				continue;
			}

		}

	}

	for (int i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}



// 2������
// num���� ���̽���ŭ
// 5���� ������ �ο��Ǵµ�,
// ���� ū ��, ���� ���� ���� ������ ���� �ִ�,�ּ� ���� ���̰� 4�� ���� ��
// KIN�� ���, �ƴ� ���� �� 3���� ���� ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void fun(int tempArr[]) {
	int temp;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			if (tempArr[j] > tempArr[j + 1]) {
				temp = tempArr[j];
				tempArr[j] = tempArr[j + 1];
				tempArr[j + 1] = temp;
			}
		}
	}
	if (tempArr[1] - tempArr[3] >= 4 ||
		tempArr[3] - tempArr[1] >= 4) {
		printf("KIN\n");
	}
	else {
		printf("%d", tempArr[1] + tempArr[2] + tempArr[3]);
		printf("\n");
	}
}

int main() {
	int num;
	int arr[10][5];
	scanf_s("%d", &num);
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &arr[i][j]);
		}
		fun(arr[i]);
	}

	return 0;
}