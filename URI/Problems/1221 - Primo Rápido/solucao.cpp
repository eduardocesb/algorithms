#include <iostream>
#include <cmath>


using namespace std;

void r(int x){
    bool primo = true;
    int m = sqrt(x);
    for(int i=2; i<m; i++){
        if(x%i == 0){
            primo = false;
            break;
        }
    }
    if(primo){
        cout << "Prime" << endl;
    }else{
        cout << "Not Prime" << endl;
    }
}

int main(){

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        r(x);
    }

    return 0;
}
