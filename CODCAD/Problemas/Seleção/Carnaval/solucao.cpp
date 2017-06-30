#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
	double a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	double min, max;
	if(a <= b && a <= c && a <= d && a <= e){
		min = a;
	}else if(b <= a && b <= c && b <= d && b <= e){
		min = b;
	}else if(c <= a && c <= b && c <= d && c <= e){
		min = c;
	}else if(d <= a && d <= b && d <= c && d <= e){
		min = d;
	}else if(e <= a && e <= b && e <= c && e <= d){
		min = e;
	}

	if(a >= b && a >= c && a >= d && a >= e){
		max = a;
	}else if(b >= a && b >= c && b >= d && b >= e){
		max = b;
	}else if(c >= a && c >= b && c >= d && c >= e){
		max = c;
	}else if(d >= a && d >= b && d >= c && d >= e){
		max = d;
	}else if(e >= a && e >= b && e >= c && e >= d){
		max = e;
	}
	cout << fixed << setprecision(1);
	cout << a + b + c + d + e - min - max << endl;
}