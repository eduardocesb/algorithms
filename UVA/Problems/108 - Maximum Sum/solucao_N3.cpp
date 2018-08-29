#include <bits/stdc++.h>
#define ROW 110
#define COL 110

using namespace std;

int M[ROW][COL], N;

int kadane(int arr[])
{
	int sum = 0, maxSum = INT_MIN;
	bool ok = false;

	//Calcula a soma máxima, onde ela começa e onde ela termina...
	for(int i = 0; i < N; i++)
	{
		sum += arr[i];

		if(sum < 0)
			sum = 0;
		else if(sum > maxSum)
			maxSum = sum, ok = true;
	}

	//Se teve alguma soma máxima, retorna a mesma...
	if(ok) return maxSum;

	//Caso especial em que todos os elementos são negativos...
	maxSum = arr[0];

	//Procura o maior elemento do vetor...
	for(int i = 0; i < N; i++)
		maxSum = max(maxSum, arr[i]);

	return maxSum;
}

int sum()
{
	int maxSum = INT_MIN, temp[COL];

	for(int i = 0; i < N; i++)
	{
		memset(temp, 0, sizeof temp);

		for(int j = i; j < N; j++)
		{
			for(int k = 0; k < N; k++) temp[k] += M[k][j];

			maxSum = max(kadane(temp), maxSum);
		}
	}

	return maxSum;
}

int main(int argc, char** argv)
{
	cin >> N;

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			cin >> M[i][j];

	cout << sum() << endl;

	return 0;
}
