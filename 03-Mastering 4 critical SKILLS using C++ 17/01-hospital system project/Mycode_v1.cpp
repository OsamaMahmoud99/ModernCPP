#include <iostream>
#include <string.h>
using namespace std;


#define MAX_SPEC       20
#define MAX_QUEUE       5

#define REGULAR         1
#define URGENT          2

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

void Add_patient_shiftRight(string str , int spec_num , int patient_num)
{
    string s;
    int status , i;
    for(i=0; i<patient_num; i++)
    {
        s = Names[spec_num][patient_num-i];
        Names[spec_num][patient_num-i] = Names[spec_num][patient_num-i-1];
        Names[spec_num][patient_num-i-1] = s;

        status = Status[spec_num][patient_num-i];
        Status[spec_num][patient_num-i] = Status[spec_num][patient_num-1-i];
        Status[spec_num][patient_num-1-i] = status;
    }
    Status[spec_num][0] = URGENT;
    Names[spec_num][0] = str;
}


void Add_patient(void)
{
    static int spec_num = 0;
    static int prev_spec_num = 0;
    string name;
    int patient_status;
    static int flag = 0;

    cout << "Enter specialization, name, status: ";
    cin >> spec_num;
    getline(cin , name);
    cin >> patient_status;

    if(flag == 0)
    {
        prev_spec_num = spec_num;
        flag = 1;
    }

    if(queue_len[spec_num] == MAX_QUEUE)
    {
        cout << "Sorry we can't add more patients for this specialization\n";
        return;
    }

    if(patient_status == URGENT)
    {
        Add_patient_shiftRight(name, spec_num , queue_len[spec_num]);
        queue_len[spec_num]++;
    }
    else if( (spec_num >=1 && spec_num<=20 ) && (spec_num == prev_spec_num)
              && (patient_status==REGULAR || patient_status==URGENT))
    {
        Names[spec_num][queue_len[spec_num]] = name;
        Status[spec_num][queue_len[spec_num]] = patient_status;
        queue_len[spec_num]++;
    }
    else if ((spec_num >=1 && spec_num<=20 ) && (spec_num != prev_spec_num)
              && (patient_status==REGULAR || patient_status==URGENT))
    {
        queue_len[spec_num] = 0;
        Names[spec_num][queue_len[spec_num]] = name;
        Status[spec_num][queue_len[spec_num]] = patient_status;
        queue_len[spec_num]++;
    }

    prev_spec_num = spec_num;
}

void Print_all_patients(void)
{
    for(int num=1; num<=20; ++num)
    {
        if(queue_len[num] != 0)
        {
            cout << "There are "<< queue_len[num] <<" patients in specialization "<< num <<"\n";
            for(int i=0; i<=queue_len[num]; ++i)
            {
                if(Status[num][i] == REGULAR)
                {
                    cout << Names[num][i] << " Regular\n";
                }
                else if(Status[num][i] == URGENT)
                {
                    cout << Names[num][i] << " Urgent\n";
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
