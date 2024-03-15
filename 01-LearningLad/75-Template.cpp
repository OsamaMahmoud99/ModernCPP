#include <iostream>

using namespace std;


/*int max(int x, int y) {
	return (x > y) ? x : y;
}

float max(float x, float y) {
	return (x > y) ? x : y;
}*/

/*template <typename identifier> ret_type fun_name(parameters) {

}
*/

template <typename myType> void display(myType x) {

	cout << " you have passes " << x << endl;
}
int main()
{
	    
	display(10);
	display(10.55);
	display("osama");

 	return 0;

}

