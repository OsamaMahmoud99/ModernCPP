#include <iostream>

using namespace std;


template <typename T> void display(T , T);

int main()
{

	cout << maxi(20, 30) << endl;
	    
	display(10, 30);
	display(10.5, 4.5);
	//display("osama", 25);  //error

 	return 0;

}

template <typename T> void display(T x, T y) {
	cout << x << " and " << y << endl;
}

template <class T> T maxi(T x, T y) {
	return (x >= y) ? x : y;
}