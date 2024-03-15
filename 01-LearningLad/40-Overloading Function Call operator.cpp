#include <iostream>

using namespace std;


class Marks {
	int mark;

public:
	Marks(int m) {
		mark = m;
	}

	void whatsYourMark() {
		cout << "hey i got " << mark << " marks" << endl;
	}

	Marks operator()(int mk) {
		mark = mk;
		return *this;
	}
};


int main()
{
	Marks osama(85);

	osama.whatsYourMark();

	osama(55);

	osama.whatsYourMark();


}

