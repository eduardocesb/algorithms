#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)

using namespace std;

int main(int argc, char const *argv[])
{
	optimize;

	int N, O, x;

	while(cin >> N){
		queue<int> fila;
		stack<int> pilha;
		priority_queue<int> pq;

		bool is_queue, is_stack, is_pq;

		is_queue = is_stack = is_pq = true;


		for (int i = 0; i < N; ++i)
		{
			cin >> O >> x;

			if(O == 1)
			{
				fila.push(x);
				pilha.push(x);
				pq.push(x);
			}
			else
			{
				if(fila.front() != x)
					is_queue = false;
				if(pilha.top() != x)
					is_stack = false;
				if(pq.top() != x)
					is_pq = false;
				
				fila.pop();
				pilha.pop();
				pq.pop();
			}
		}

		if(is_queue + is_stack + is_pq)
			if(is_queue + is_stack + is_pq > 1)
				cout << "not sure" << endl;
			else if(is_queue)
				cout << "queue" << endl;
			else if(is_stack)
				cout << "stack" << endl;
			else
				cout << "priority queue" << endl;
		else
			cout << "impossible" << endl;

	}
	
	return 0;
}