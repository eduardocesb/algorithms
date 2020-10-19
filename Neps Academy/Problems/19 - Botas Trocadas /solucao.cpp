#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]){
    int N, M, sum = 0;
    char L;
    vector<int> E(61, 0);
    vector<int> D(61, 0);
    cin >> N;

    for(int x = 0; x < N; x++){
        cin >> M >> L;
        if (L == 'E') E[M]++;
        else D[M]++;  
    }

    for (int i = 30; i <= 60; i++){
        sum += min(E[i], D[i]);
    }
    cout << sum << endl;

}