#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int value(val) {
	// �迭�� �� �ְ�(�׷��� �迭�� �ݴ밡 ��)
	// �迭 �ϳ��ϳ� ���鼭 10�� ���ؼ� ���ϰ�
	// 0�� ������ ���ϴ� ���� �ʱ�ȭ
	int arr[6];
	int temp = 1;
	int returnV = 0;

	int length = 0;

	for (int i = 0; val > 0; i++) {
		arr[i] = val % 10;
		val /= 10;
		length++;
	}

	for (int i = 0; i < length; i++) {
		if (arr[i] == 0) {
			temp = 1; // ���ϴ� �� �ʱ�ȭ
		}
		else {
			returnV += arr[i] * temp;
			temp *= 10;
		}
	}

	return returnV;
}

int main() {
	int num;
	scanf_s("%d", &num);
	int sum = 0;
	int temp;
	for (int i = 1; i <= num; i++) {
		//printf("i = %d\n", i);
		temp = value(i);
		//printf("temp = %d\n", temp);
		sum += temp;
		//printf("sum = %d\n", sum);
	}
	printf("%d", sum);

	//printf("%d", value(101));

	return 0;
}