#include <iostream>
#include <vector>

using namespace std;
int mapa[101];

int main(int argc, char const *argv[])
{
	int A, V;
	cin >> A >> V;
	int n = 1;
	while(A != 0 || V != 0){
		for (int i = 0; i <= A; ++i)
		{
			mapa[i] = 0;
		}
		int max = 0;
		vector<int> r;
		for (int i = 0; i < V; ++i)
		{
			int x, y;
			cin >> x >> y;
			mapa[x]++;
			mapa[y]++;
			if(max < mapa[x]){
				max = mapa[x];
			}
			if(max < mapa[y]){
				max = mapa[y];
			}
		}
		cout << "Teste " << n << endl;	
		for (int i = 1; i <= A; ++i)
		{
			if(max == mapa[i]){
				cout << i << ' ';
			}
		}
		cout << "\n\n";
		n++;
		cin >> A >> V;
	}
	return 0;
}