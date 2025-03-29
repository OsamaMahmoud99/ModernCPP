#include <iostream>
#include <list>
#include <ostream>
#include <stdint.h>
#include <string.h>
#include <vector>

using namespace std;

class MyString
{
private:
    int size;    
    char* literals;
   

public:
    MyString() : 
    size(0), 
    literals(nullptr)
    { 
        cout << "Default constructor Called\n";
    }

    MyString(const char* inputLiterals):
    size(strlen(inputLiterals)),
    literals(new char[size + 1])
    {

        memcpy(literals , inputLiterals , size);
        literals[size] = '\0';
        cout << "Parameterized constructor Called\n";
    }
    void print()
    {
        if(literals != nullptr) {
            cout << literals << endl;
        }
        
    }

    int getSize() {
        return size;
    }
    
    void setLiterals(const char* str) {
        int newSize(strlen(str));
        if(newSize > size) {
            // throw exception
            // return error
        }
        else {
            memcpy(literals , 0 , size);
            memcpy(literals , str , newSize);
            literals[newSize] = '\0';
        }
    }
    ~MyString() {
        if(literals != nullptr) {
            delete[] literals;
        }
        size = 0;
    }

    // copy constructor >> Data Init
    MyString(const MyString& other)
    : size(other.size),
      literals(new char[size + 1])
    {
        memcpy(literals, other.literals, size);
        literals[size] = '\0';
        cout << "copy constructor called\n";

    }

    MyString operator+(const MyString& other) {
        std::cout << "operator + called\n";
        char  * newLiterals = new char[size + other.size + 1];
        memcpy(newLiterals, literals, size); // hello [size = 5]
        memcpy(&newLiterals[size], other.literals, other.size); // world [size = 6]
        newLiterals[size + other.size] = '\0';

        MyString newObject(newLiterals);
        delete[] newLiterals;
        return newObject;
    }

    MyString operator+(const uint8_t age) {
        char  * newLiterals = new char[size + 1 + 1]; //Ahmed26
        
        memcpy(newLiterals, literals, size);
        newLiterals[size] = age;
        newLiterals[size + 1] = '\0';

        MyString newObject(newLiterals);
        delete[] newLiterals;
        return newObject;
    }

    friend std::ostream& operator<<(std::ostream& out, const MyString& other);

    MyString& operator=(const MyString& other) {
        // Handling self assignment
        if(this == &other) {
            return *this;
        }
        // Deep copying

        if(literals != nullptr) {
            delete[] literals;
        }
        size = 0;

        literals = new char[other.size + 1];
        size = other.size;
        memcpy(literals, other.literals, other.size);
        literals[size] = '\0';

        std::cout << "Assignment operator called\n";
        
        return *this;
    }
};

std::ostream& operator<<(std::ostream& out, const MyString& other)
{
    out << other.literals;
    return out;
}

class Employee {
private:
    MyString name;

public:
    Employee(int id): name(id == 0? "Ahmed" : "Mohamed") {
        
    }


};

class Dummy1;

class Dummy2 {
    private:
        int num = 40;

        friend int operator+(const Dummy1& ob1, const Dummy2& ob2);
    
    public:
        int getNum() const {
            return num;
        }
};
class Dummy1 {
    private:
        int num = 20;
    public:
        /*int operator+(const Dummy2& other) {
            return num + other.getNum();
        }*/
        
        friend int operator+(const Dummy1& ob1, const Dummy2& ob2);
};

int operator+(const Dummy1& ob1, const Dummy2& ob2)
{
    return ob1.num + ob2.num;
}

class List 
{
    private:
        int* arr;
        int emptyPosition;
    public:
        List() : arr(new int[10]), emptyPosition(0) {}

        List& operator<<(const int num) {
            arr[emptyPosition] = num;
            emptyPosition++;
            return *this;
        }
};

class Task
{
    private:
        int priority;
    public:
        Task(const int priority): priority(priority){}

        bool operator<(const Task& other) {
            return priority < other.priority;
        }

        friend std::ostream& operator<<(std::ostream& out, const Task& task){
            out << task.priority;
            return out;
        }
};

class Container
{
    private:
        std::vector<Task> vec;
    
    public:
        Container& operator<<(const Task task) {
            vec.push_back(task);
            return *this;
        }

        void printMinimum() {

            Task minValue = vec[0];
            for(size_t i=0; i< vec.size(); i++) {
                if(vec[i] < minValue) {
                    minValue = vec[i];
                }
            }

            std::cout << "Minimum value is: "<< minValue << std::endl;
        }

       
         friend std::ostream& operator<<(std::ostream& out, const Container& object) {
            for(size_t i=0; i<object.vec.size(); i++) {
                out << object.vec[i] << ",";
            }

            return out;
         }
};

class IntList {
private:
    int list[5] = {1,2,3,4,5};

public:
    int& operator[] (int index){
        return list[index];
    }
};

enum TaskId
{
    TASK1,
    TASK2
};
class BaseTask {
private:
    TaskId id;

public:
    BaseTask(const TaskId tasktype) : id(tasktype){ }

    TaskId getId() const {
        return id;
    }

};

class Task1 : public BaseTask{
public:
    Task1() : BaseTask(TASK1){ }

    void executeTask1() {
        std::cout << "Executing task 1\n";
    }
};

class Task2 : public BaseTask {
public:
    Task2() : BaseTask(TASK2){ }

    void executeTask2() {
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
            if(list[i]->getId() == TASK1){
                // Downcasting [ Explicitly]
                Task1 *castedobject = static_cast<Task1 *>(list[i]);
                castedobject->executeTask1();
            }
            else if(list[i]->getId() == TASK2){
                Task2 *castedobject = static_cast<Task2 *>(list[i]);
                castedobject->executeTask2();
            } 
            
            
        }
    }
};

class parent {};

class child :public parent{
    public:
    void print(){
        std::cout << "child is called\n";
    }
};

void executeTask(parent& object) {
    // Downward casting
    child& ob = static_cast<child&>(object);
    ob.print();
}


int main()
{
    child c;
    executeTask(c);
  /*container c(10);
  Task1 *c1 = new Task1();
  Task2 *c2 = new Task2();
  c.AddElement(c1);
  c.AddElement(c2);
  c.executeAllTasks();

  delete c1;
  delete c2;*/

  /*MyString student1("Ahmed");
  MyString student2(student1);

  student1.print(); 
  student2.print();*/

  /*MyString hello("Hello");
  MyString world(" world");

  MyString helloworld = hello + world;
  helloworld.print();*/
  
  /*MyString name("Ahmed");
  int age = 26;

  MyString combinedInfo = name + age;
  combinedInfo.print();*/

  /*Dummy1 ob1;
  Dummy2 ob2;

  std::cout << ob1 + ob2 << std::endl;*/

  /*MyString name = "hamada";
  MyString age = "49";
  std::cout << name << age <<std::endl;*/

  /*List list;
  list << 20 << 30 << 40;*/

  /*Container object;
  object << 20 << 10 << 3 << 7;
  object.printMinimum();*/

  /*IntList list;
  list[2] = 10;
  cout << list[2] << endl;*/

  /*MyString name("ahmed");
  MyString name3;
  name3 = name;*/

  /*MyString name1, name2;
  MyString name3("hello");

  name1 = name2 = name3;*/

}