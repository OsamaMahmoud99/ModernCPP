#include <iostream>

using namespace std;

int main()
{
    const int MAX = 10000;
 
    string names[MAX];
    int Ages[MAX];
    int Salaries[MAX];
    char Genders[MAX];
    int added = 0;
    
    while(1)
    {
        int choice = -1;
        cout << "Enter your choice:\n";
        cout << "1)Add new employee\n";
        cout << "2)Print all employees\n";
        cout << "3)Delete by age\n";
        cout << "4)Update Salary by name\n";
        cin >> choice;
        
        if (!(1 <= choice && choice <= 4)) {
			cout << "Invalid choice. Try again\n";
			continue;
		}
		
        if(choice == 1)
        {
            cout << "Enter name: ";
            cin >> names[added];
            
            cout << "Enter age: ";
            cin >> Ages[added];
            
            cout << "Enter salary: ";
			cin >> Salaries[added];

			cout << "Enter gender (M/F): ";
			cin >> Genders[added];
			++added;
        }
        else if(choice == 2)
        {
            cout << "****************************\n";
            for(int i=0; i<added; ++i)
            {
                if(Ages[i] != -1)
                {
                    cout << names[i] <<" "<<Ages[i]<<" "<<Salaries[i]<<" "<<Genders[i]<<"\n";
                }
                
            }
        }
        else if(choice == 3)
        {
            cout << "Enter start and end age: ";
            int start,end;
            cin >> start >> end;
            for(int i=0; i<added; ++i)
            {
                if(Ages[i]>=start && Ages[i]<=end)
                {
                    Ages[i] = -1;         //lazy delete
                }
            }
            
        }
        else if(choice == 4)
        {
            cout << "Enter the name and salary: ";
            string name;
            int salary;
            cin >> name >> salary;
            
            bool is_found = 0;
            for(int i=0; i<added; ++i)
            {
                if(Ages[i]!=-1 && names[i]==name)
                {
                    is_found = 1;
                    Salaries[i] = salary;
                    break;
                }
            }
            if (!is_found)
			   cout << "No employee with this name!\n";
        }
    }
    

    return 0;
}