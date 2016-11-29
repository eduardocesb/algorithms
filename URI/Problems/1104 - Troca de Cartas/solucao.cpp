#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	int A, B;
	cin >> A >> B;
	while(A != 0 || B != 0){
		map<int, bool> numsA;
		map<int, bool> numsB;
		for (int i = 0; i < A; ++i)
		{
			int x;
			cin >> x;
			numsA[x] == true;
		}
		for (int i = 0; i < B; ++i)
		{
			int x;
			cin >> x;
			numsB[x] = true;
		}

		int maxA = 0;
		int maxB = 0;
		map<int, bool>::iterator it;

		for(it = numsA.begin(); it != numsA.end(); it++){
			int x = it->first;
			if(!numsB[x]){
				maxA++;
			}else{
				numsB[x] = false;
			}
		}
		for(it = numsB.begin(); it != numsB.end(); it++){
			int x = it->first;
			if(!numsA[x] && numsB[x]){
				maxB++;
			}
		}

		cout << min(maxA, maxB) << endl;
		cin >> A >> B;
	}

	return 0;
}