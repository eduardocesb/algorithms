#include <bits/stdc++.h>
#define MAXP 21

using namespace std;

int pot[MAXP];

int ele(int i)
{
	return pot[i] = (pot[i] != -1 ? pot[i] : (i ? 2 * ele(i - 1) : 1));
}

int main(int argc, char** argv)
{
	memset(pot, -1, sizeof pot);
	
	int N, L, R;
	
	cin >> N >> L >> R;
	
	int resp_min = 0, resp_max = 0;
	
	for(int i = 0; i < L; i++)
		resp_min += ele(i);
	
	for(int i = 0; i < R; i++)
		resp_max += ele(i);
	
	resp_min += (N - L);
	resp_max += (N - R) * ele(R - 1);
	
	cout << resp_min << " " << resp_max << endl;
	
	return 0;
}