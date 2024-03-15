#include <iostream>
#include <string>

using namespace std;

class Father {
public:
    int height;

    void askFather() {
        cout << "am your father ask me what u want" << endl;
    }

};

class Mother{
public:
    string skincolor;
    void askMother() {
        cout << "am your mother ask me what u want" << endl;
    }
};

class child : public Father, public Mother {
public:
    void askParents() {
        cout << "am asking my parents" << endl;
    }

    void setColorandheight(string icolor, int iheight) {
        skincolor = icolor;
        height = iheight;
    }

    void display() {
        cout << "height is " << height << " and color is " << skincolor << endl;
    }
};

int main()
{
    child Ahmed;

    Ahmed.setColorandheight("white", 7);
    Ahmed.display();
    Ahmed.askFather();
    Ahmed.askMother();

    return 0;
}


