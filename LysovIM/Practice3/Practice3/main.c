#include <stdlib.h> //����������� ���������
#include <stdio.h>
#include <time.h>

#define MIN_DIGITS_NUM 2 //������� �������� �������
#define MAX_DIGITS_NUM 5
#define NUM_OF_DIGITS 10

void reverse(int n, int* array) { // �������������� �������
	int temp;
	for (int i = 0; i < n / 2; i++) {
		temp = array[i];
		array[i] = array[n - i - 1];
		array[n - i - 1] = temp;
	}
}


int is_win(int n, int* needed, int* cur) { // ��������, ��������� �� ���������� ����� � ��������� 
	for (int i = 0; i < n; i++) 
		if (needed[i] != cur[i])
			return 1;
	return 0;
}

int process(int n, int* needed, int cur, int playing) {
	// �������� ������ ��� ��������� �����
	int* recieved = (int*)malloc(n * sizeof(int));
	// �������������� ����� int � ������
	for (int i = 0; i < n; i++) {
		recieved[i] = cur % 10;
		cur /= 10;
	}
	// ����������� ���������� ������
	reverse(n, recieved);
	int cows = 0, bulls = 0, i, j;  // �������������� �������� � ���������
	
for (i = 0; i < n; i++)
		// ������� �����
		if (needed[i] == recieved[i]) bulls++;
		else
			for (j = 0; j < n; j++)
				// ������� ������
				if (needed[i] == recieved[j])
					cows++;

	// �������� �� �������� ��
	if (!is_win(n, needed, recieved)) {
		printf(" You won!");
		return 0;
	}
	// ����� ���������� ����� � �����
	printf(" There're %d bulls and %d cows\n", bulls, cows);
}

int read(int n) {//������� ���������� ����� � �������� �� �� �������� �� ��������� ����� ��� �������� n-�������� �����.
	int temp = 0;
	int c = 0;
	char ch = 'a';
	while (c < n) {
		ch = getchar();
		switch (ch) {
			case'0':
			case'1':
			case'2':
			case'3':
			case'4':
			case'5':
			case'6':
			case'7':
			case'8':
			case'9': {
				temp = temp * 10 + atoi(&ch);
				c++;
				break;
			}
		}
	}
	return temp;
}

void shuffle(int* array) { // ������������ ������ 
	 // ������������� ������� ����� � �������� ������ ��� ���������� ��������������� �����
	srand(time(NULL));
	int j, temp;
	for (int i = NUM_OF_DIGITS - 1; i >= 1; i--) {
		// �������� ��������� ������, �� ������������� i
		j = rand() % (i + 1);
		// ������ �������� � ������� �������
		temp = array[j];
		array[j] = array[i];
		array[i] = temp;
	}

}

void check(int* array) { // ������������ ������ 
	 // ������������� ������� ����� � �������� ������ ��� ���������� ��������������� �����
	int j, temp;
	for (int i = NUM_OF_DIGITS - 1; i >= 1; i--) {
		// �������� ��������� ������, �� ������������� i
		j = rand() % (i + 1);
		// ������ �������� � ������� �������
		temp = array[j];
		array[j] = array[i];
		array[i] = temp;
	}
}
int* gen(int n) { // ���������� ��������� �����-������ �������� ������
	int digits[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	// ������������ ��������� ���� ������ �� ��� ���, ���� ������ ����� �� ����� ������� �� ����
	do
		shuffle(digits);
	while (digits[0] == 0);
	// ����� ������� ���������, ������� ��������� �� ������, �������� ��� ���� ������
	int* result = (int*)malloc(n * sizeof(int));
	// ������������ � result ���������� ������������ ������
	for (int i = 0; i < n; i++)
		result[i] = digits[i];
	return result;
}

int introduction() {//����������
	int n = 0;
	printf(" ==================== BULLS & COWS ====================\n\n");
	printf(" You have to quess the num I've made.  You should  tell\n");
	printf(" me how many digits there'll be in the made num (2 - 5)\n");
	printf(" Number length: ");
	while (1) { //����������� ����
		 // ��������� ����� �����
		scanf("%d", &n);
		// ��������� �� ������������
		if (n >= 2 && n <= 5) {
			printf("\n");
			printf(" I've made the num with length of %d. Try to quess it!\n", n);
			return n;
		}
		printf("\n Something went wrong, try again!");
	}
}

void main() {
	int n = introduction();
	int* num = gen(n);
	int playing = 1, cur;

	while (playing) {  // ���� ����
		cur = read(n); // ��������� ���������������� �����
		playing = process(n, num, cur, playing); // ������������
		if (!playing) { // ���������� ������� �����, ������������ �����
			printf("\n\n Do you want to play again?\n 1 - play again\n 0 - exit\n\n ");
			scanf("%d", &playing);
			if (playing) {
				system("cls");//������ �������
				n = introduction();
				num = gen(n);
			}
		}
	}
	printf("\n\n\n");
}