#include <iostream>

using namespace std;


template <typename T1, typename T2> void display(T1 x, T2 y);

int main()
{
	display("osama", 5);
	display(25, 26);
	display(5.5, 5);

 	return 0;

}

template <typename T1 , typename T2> void display(T1 x, T2 y) {

	cout << x << " and " << y << endl;
}

