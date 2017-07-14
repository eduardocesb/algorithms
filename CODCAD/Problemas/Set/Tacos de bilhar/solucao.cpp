#include <iostream>
#include <set>

using namespace std;

int main(int argc, char const *argv[])
{
	int C, x;
	cin >> C;
	set<int> estoque;
	int r = 0;
	for (int i = 0; i < C; ++i)
	{
		cin >> x;
		if(estoque.find(x) == estoque.end()){
			estoque.insert(x);
			r += 2;
		}else{
			estoque.erase(x);
		}
	}

	cout << r << endl;
	return 0;
}