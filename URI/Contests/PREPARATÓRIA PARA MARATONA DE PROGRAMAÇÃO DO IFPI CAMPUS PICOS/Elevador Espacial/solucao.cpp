#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

long long valor;
char numero[22];
unsigned long long dp[20][10][2];
bool checked[20][10][2];
int limiteDigitos, length;

bool read() {
	if (scanf("%lld", &valor) == EOF) {
		return false;
	}
	return true;
}

unsigned long long solve(int digits, int lastDigit, int limit) {
	unsigned long long &ret = dp[digits][lastDigit][limit];
	if (checked[digits][lastDigit][limit]) {
		return ret;
	}
	checked[digits][lastDigit][limit] = true;
	ret = 0;

	if (digits == limiteDigitos) {
		ret = 1;
		return ret;
	}
	for (int newDigit = (digits == 0 ? 1 : 0); newDigit <= (limit ? numero[digits] - '0' : 9);
		 newDigit++) {

		if (newDigit != 4 && (newDigit != 3 or lastDigit != 1)) {
			ret += solve(digits + 1, newDigit, limit and newDigit == (numero[digits] - '0'));
		}
	}
	return ret;
}

unsigned long long f(unsigned long long value) {
	sprintf(numero, "%llu", value);
	length = strlen(numero);
	unsigned long long ret = 0;
	for (limiteDigitos = 1; limiteDigitos <= length; limiteDigitos++) {
		memset(checked, false, sizeof checked);
		ret += solve(0, 0, limiteDigitos == length);
	}
	return ret;
}

void process() {
	unsigned long long lo = valor, hi = ~0ULL;
	while (lo < hi) {
		unsigned long long mid = lo + (hi - lo) / 2;
		unsigned long long val = f(mid);
		if (val >= valor) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	printf("%llu\n", lo);
}
int main() {
	while (read()) {
		process();
	}
	return 0;
}