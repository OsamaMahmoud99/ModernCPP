#include <iostream>
#include <stdexcept>

using namespace std;




int main()
{

	try {
		
		//throw runtime_error("runtime error");
		throw 20;
	}
	catch (int error) {
		cout << error << endl;
	}
	// catch all exceptions

	catch (...) {
		cout << "some exception occurred" << endl;
	}
	/*catch (const char* error) {
		cout << error << endl;
	}
	catch (int error) {
		cout << error << endl;
	}
	catch (runtime_error e) {
		cout << e.what()<< endl;
	}*/

	
	return 0;

}

