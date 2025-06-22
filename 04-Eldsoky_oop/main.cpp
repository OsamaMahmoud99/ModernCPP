#include <iostream>

using namespace std;


template <typename T> void whatYouGot(T x);

void whatYouGot(int x);

int main()
{
	whatYouGot(25.55);
	whatYouGot(25);
	whatYouGot("osama");

 	return 0;

}

template <typename T> void whatYouGot(T x) {

	cout << "inside generic function" << endl;
	cout << "x= " << x << endl;
}

void whatYouGot(int x) {
	cout << "inside normal function" << endl;
	cout << "x= " << x << endl;
}

