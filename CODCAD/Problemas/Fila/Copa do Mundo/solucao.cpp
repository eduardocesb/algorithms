#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
	int x, y;
	//Número de times...
	int N = 16;
	queue<char> time;
	for (int i = 0; i < N; ++i)
	{
		time.push('A' + i);
	}

	for (int i = 0; i < N - 1; ++i)
	{
		cin >> x >> y;
		if(x > y){
			time.push(time.front());
			time.pop();
			time.pop();
		}else{
			time.pop();
			time.push(time.front());
			time.pop();
		}
	}

	cout << time.front() << endl;
	return 0;
}