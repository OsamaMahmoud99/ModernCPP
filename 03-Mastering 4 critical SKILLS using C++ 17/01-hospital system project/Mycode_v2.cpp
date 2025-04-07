#include <iostream>
#include <string.h>
using namespace std;


#define MAX_SPEC       20
#define MAX_QUEUE       5

#define REGULAR         0
#define URGENT          1

string Names[MAX_SPEC+1][MAX_QUEUE+1];
int Status[MAX_SPEC+1][MAX_QUEUE+1];           // 0->regular 1->urgent
int queue_len[MAX_SPEC+1];

int menu(void)
{
    int choice = -1;
    while(choice == -1)
    {
        cout << "\nEnter your choice:\n";
        cout << "1) Add new patient\n";
        cout << "2) Print all patients\n";
        cout << "3) Get next patient\n";
        cout << "4) Exit\n";

        cin >> choice;

        if( !(choice>=1 && choice<=4))
        {
            cout << "Invalid choice. Try Again\n";
            choice = -1;
        }
    }

    return choice;
}

void Add_patient_shiftRight(int spec_num , string names_sp[], int status_sp[])
{
    int len = queue_len[spec_num];
    for(int i=len-1; i>=0; i--)
    {
        names_sp[i+1] = names_sp[i];
        status_sp[i+1] = status_sp[i];
    }
    queue_len[spec_num]++;
}


void Add_patient(void)
{
    static int spec_num = 0;
    static int prev_spec_num = 0;
    string name;
    int patient_status;

    cout << "Enter specialization, name, status: ";
    cin >> spec_num >> name >> patient_status;

    int pos = queue_len[spec_num];
    if(pos >= MAX_QUEUE)
    {
        cout << "Sorry we can't add more patients for this specialization\n";
        return;
    }

    if(patient_status == REGULAR)
    {
        Names[spec_num][pos] = name;
        Status[spec_num][pos] = patient_status;
        queue_len[spec_num]++;
    }
    else
    {
        Add_patient_shiftRight(spec_num, Names[spec_num] , Status[spec_num]);
        Names[spec_num][0] = name;
        Status[spec_num][0] = patient_status;
    }

}

void Print_all_patients(void)
{
    for(int spec_num=1; spec_num<20; ++spec_num)
    {
        if(queue_len[spec_num] != 0)
        {
            cout << "There are "<< queue_len[spec_num] <<" patients in specialization "<< spec_num <<"\n";
            for(int i=0; i<queue_len[spec_num]; ++i)
            {
                if(Status[spec_num][i] == URGENT)
                {
                    cout << Names[spec_num][i] << " Urgent\n";
                }
                else
                {
                    cout << Names[spec_num][i] << " Regular\n";
                }
            }
            cout <<"\n";
        }
    }

}

void Delete_Patient_ShiftLeft(int spec_num)
{
    int len = queue_len[spec_num];

    for(int i=0; i<len-1; ++i)
    {
        Names[spec_num][i] = Names[spec_num][i+1];
        Status[spec_num][i] = Status[spec_num][i+1];
    }

    queue_len[spec_num]--;
}

void Get_next_patient(void)
{
    int spec_num;
    cout << "Enter specialization: ";
    cin >> spec_num;

    cout << Names[spec_num][0] <<" please go with the Dr\n";

    Delete_Patient_ShiftLeft(spec_num);

}

void Hospital_system(void)
{
    while(1)
    {
        int choice = menu();

        if(choice == 1)
        {
            Add_patient();
        }
        else if(choice == 2)
        {
            Print_all_patients();
        }
        else if(choice == 3)
        {
            Get_next_patient();
        }
        else if(choice == 4){
            break;
        }
    }
}
int main()
{

    Hospital_system();

}
