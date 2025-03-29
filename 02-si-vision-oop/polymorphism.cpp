#include <iostream>
#include <list>
#include <ostream>
#include <stdint.h>
#include <string.h>
#include <vector>

using namespace std;


class BaseTask {
    public:
        virtual void executeTask() {
            std::cout << "N/A \n";
        }
};

class Task1 : public BaseTask {
    public:
        void executeTask() {
            std::cout << "Executing task 1\n";
        }
};

class Task2 : public BaseTask {
    public:
        void executeTask() {
            std::cout << "Executing task 2\n";
        }
};

class container 
{
private:
    BaseTask ** list;
    int size;
    int emptyLocation;

public:
    container(const int size) : list(new BaseTask*[size]),
        size(size), emptyLocation(0)
    {

    }

    void AddElement(BaseTask *task) {
        if(emptyLocation == size) {
            return;
        }
        list[emptyLocation] = task;
        emptyLocation++;
    }

    void executeAllTasks() {
        for(int i=0; i<emptyLocation; i++) {
            list[i]->executeTask();
            
        }
    }
};


int main()
{
  container c(10);
  Task1 *c1 = new Task1();
  Task2 *c2 = new Task2();
  c.AddElement(c1);
  c.AddElement(c2);
  c.executeAllTasks();

  return 0;
}