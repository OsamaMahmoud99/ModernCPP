#include <iostream>

using namespace std;


template <typename T> void display(T x, int y);

int main()
{
	display("osama", 5);

 	return 0;

}

template <typename T> void display(T x, int y) {
	
	for (int i = 1; i <= y; ++i) {
		cout << x << endl;
	}
}

