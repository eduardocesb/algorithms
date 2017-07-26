#include <bits/stdc++.h>
#define MAXN 31623

using namespace std;

vector<int> primos;
unordered_map<int, int> fatores;
unordered_set<int> divisores;

void crivo(){
	bool nums[MAXN];
	memset(nums, true, sizeof(nums));
	for (int i = 2; i < MAXN; ++i)
	{
		if(!nums[i]) continue;
		primos.push_back(i);
		for (int j = 2 * i; j < MAXN; j += i)
		{
			nums[j] = false;
		}
	}
}

void fatorar(int N){
	vector<int>::iterator i;
	for(i = primos.begin(); i != primos.end();){
		if(N % *i == 0) fatores[*i]++, N /= *i;
		else i++;
	}
}

void dividir(int N){
	crivo();
	fatorar(N);
	divisores.insert(1);
	unordered_set<int>::iterator i;
	unordered_map<int, int>::iterator it;
	for (it = fatores.begin(); it != fatores.end(); it++)
	{
		for (int j = 0; j < it->second; ++j)
		{
			unordered_set<int> temp;
			for (i = divisores.begin(); i != divisores.end(); i++)
			{
				temp.insert((*i) * (it->first));
			}
			for(i = temp.begin(); i != temp.end(); i++){
				divisores.insert(*i);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	dividir(C);

	unordered_set<int>::iterator it;
	
	int menor = -1;
	for (it = divisores.begin(); it != divisores.end(); it++){
		if((*it % A == 0) && (*it % B != 0) && (D % *it != 0) && (menor == -1 || *it < menor))
			menor = *it;
	}

	 cout << menor << endl;
	return 0;
}