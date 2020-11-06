// + 또는 *와 숫자 2개를 입력 받아 결과를 계산하라.
// (단, size는 unsigned long long int보다 크다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char Oper = { 0 };
	char s_a[101];
	char s_b[101];
	int i, j, k, add_len, mul_len = 0;
	int add = 0;
	int multi = 0;

	scanf("%c", &Oper);
	scanf("%s", s_a);
	scanf("%s", s_b);

	int r = strlen(s_a);
	int s = strlen(s_b);
	add_len = r > s ? r : s;
	mul_len = r + s;

	if (Oper == '+') {
		char a[101];
		char b[101];
		for (i = 0; i < r; i++) {
			a[r - i - 1] = s_a[i];
		}
		for (i = r; i < 101; i++) {
			a[i] = '0';
		}
		for (i = 0; i < s; i++) {
			b[s - i - 1] = s_b[i];
		}
		for (i = s; i < 101; i++) {
			b[i] = '0';
		}
		char c[102];
		memset(c, 0, add_len + 1);
		for (i = 0; i < 100; i++) {
			c[i] = (((a[i] - '0') + (b[i] - '0') + add) % 10) + '0';
			add = ((a[i] - '0') + (b[i] - '0') + add) > 9 ? 1 : 0;
		}
		c[100] = (a[99] - '0') + (b[99] - '0') + add > 9 ? 1 + '0' : 0 + '0';

		for (i = 100; i >= 0; i--) {
			if (c[i] != '0') {
				k = i;
				i = -1;
			}
		}
		for (i = k; i >= 0; i--)
			printf("%c", c[i]);
	}

	else {
		char c[202];
		memset(c, 0, mul_len + 1);

		for (i = 0; i < r; i++) {
			for (j = 0; j < s; j++) {
				k = mul_len - i - j;
				c[k] += (s_a[r - i - 1] - '0') * (s_b[s - j - 1] - '0');
				if (c[k] > 9) {
					c[k - 1] += (c[k] / 10);
					c[k] %= 10;
				}
			}

		}

		for (i = 0; i < mul_len + 1; i++)
			c[i] += '0';

		for (i = 0; i < mul_len + 1; i++) {
			if (c[i] != '0') {
				k = i;
				i = mul_len + 1;
			}
		}
		for (i = k; i < mul_len + 1; i++)
			printf("%c", c[i]);
	}

	return 0;
}