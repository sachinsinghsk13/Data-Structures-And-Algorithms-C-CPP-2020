
/**
 * Sequential File Access
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
// Record class structure
class employee
{
private:
    int employee_id;
    char employee_name[40];
    double salary;
    int age;

public:
    void read_employee_info();
    void print_employee();
    bool delete_flag;
};
class employee_manager
{
private:
    char filename[40];

public:
    employee_manager();
    void insert_record();
    void search_record();
    void delete_record();
    void display_all_records();
};
int main()
{
    employee_manager em;
    int choice = 0;
    do
    {
        cout << "1. Insert Record" << endl;
        cout << "2. Search Record" << endl;
        cout << "3. Delete Record" << endl;
        cout << "4. Display All Records" << endl;
        cout << "-1. Exit" << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            em.insert_record();
            break;
        case 2:
            em.search_record();
            break;
        case 3:
            em.delete_record();
            break;
        case 4:
            em.display_all_records();
            break;
        }
    } while (choice != -1);

    return 0;
}

void employee::print_employee()
{
    cout << "ID : " << employee_id << endl;
    cout << "Name : " << employee_name << endl;
    cout << "Salary : " << salary << endl;
    cout << "Age : " << age << endl;
}

void employee::read_employee_info()
{
    cout << "Enter Employee ID : ";
    cin >> employee_id;
    cout << "Enter Employee Name : ";
    cin >> employee_name;
    cout << "Enter Employee Salary : ";
    cin >> salary;
    cout << "Enter Employee Age : ";
    cin >> age;
    delete_flag = false;
}

employee_manager::employee_manager()
{
    // cout << "Enter File Name : ";
    // cin >> filename;
    strcpy(filename, "employees.dat");
}

void employee_manager::insert_record()
{
    fstream file;
    employee emp;
    file.open(filename, ios::binary | ios::out | ios::app);
    emp.read_employee_info();
    file.write((char *)&emp, sizeof(emp));
    file.flush();
    file.close();
    cout << "Record Added Successfully" << endl;
}

void employee_manager::search_record()
{
}

void employee_manager::delete_record()
{
}

void employee_manager::display_all_records()
{
    fstream file;
    employee emp;
    int count = 0;
    file.open(filename, ios::binary | ios::in);
    while (!file.eof())
    {
        file.read((char *)&emp, sizeof(emp));
        if (file.eof())
            break;
        else if (!emp.delete_flag)
        {
            emp.print_employee();
            cout << endl;
            count++;
        }
    }
    cout << "Total " << count << " Records" << endl;
    file.close();
}