#include <bits/stdc++.h>

using namespace std;

int N;

int max_sum(int nums[]){
	int r = 0, atual = 0;

	for(int i = 0; i < N; i++){
		atual = max(0, atual + nums[i]);
		r = max(r, atual);
	}

	return r;
}

int main(){

	cin >> N;
	
	int S = 0;
	int numsA[N],  numsB[N];

	memset(numsA, 0, sizeof(numsA));

	for(int i = 0; i < N; i++){
		cin >> numsA[i];
		S += numsA[i];
		numsB[i] = -1 * numsA[i];
	}
	
	cout << (max(max_sum(numsA), S + max_sum(numsB))) << endl;
	return 0;
}