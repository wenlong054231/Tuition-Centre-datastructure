#include <iostream>
#include <string>
#include <stdlib.h>
#include "Account.h"
#include "Tutor.h"
#include "Manager.h"
#include "Admin.h"
using namespace std;

void Menu( string role);
void ManagerMenu();
void ManageAdminMenu();
void ManageAccountMenu();
void ManageTutorMenu();

void Login() {
    string username;
    string password;
    string role;
    int relogin = 0;
    bool account_check = true;

    
    cout << "Enter username:";
    cin >> username;
    cout << "Enter password:";
    cin >> password;

    Account* current = accountNodeHead;
    
    while (accountNodeHead != NULL) {
        
        if (username == current->username && password == current->password) {

            role = current->role;
            system("cls");
            Menu(role);

        }
        else {
            if (current->next_address == NULL) {
                
                cout << "Wrong username or password!" << endl;
                cout << "Try Again?" << endl;
                cout << "1. Login 2. Quit" << endl;
                cin >> relogin;

                switch (relogin) {

                case 1:
                    system("cls");
                    Login();
                    break;
                case 2:
                    exit(0);
                    break;

                default:
                    Login();
                }
                break;

            }
            else {

                current = current->next_address;

            }
        }
       
    }

}

void Menu(string role) {

    int menu_choice = 0;

    cout << "Tutor Management System" << endl;
    cout << string(20, '-') << endl;

    if (role == "manager") {
        cout << "1. Manage Tutor Records" << endl;
        cout << "2. Manage Account" << endl;
        cout << "3. Manage Manager Records" << endl;
        cout << "4. Manage Admin" << endl;
        cout << "5. Logout" << endl;
        cin >> menu_choice;

        switch (menu_choice) {

        case 1:
            system("cls");
            ManageTutorMenu();
            break;
        case 2:
            system("cls");
            ManageAccountMenu();
            break;
        case 3:
            system("cls");
            ManagerMenu();
            break;

        case 4:
            system("cls");
            ManageAdminMenu();
            break;

        case 5:
            system("cls");
            Login();
            break;
        }
    }
    if(role =="admin") {

        cout << "1. Manage Tutor Records" << endl;
        cout << "2. Logout" << endl;
        cin >> menu_choice;

        switch (menu_choice) {

        case 1:
            system("cls");
            ManageTutorMenu();
            break;
        case 2:
            system("cls");
            Login();
            break;
        }

    }

}

void ManageTutorMenu()
{
    char number;
    char confirm;
    do
    {
        system("cls");
        cout << "====================Tutor===================" << endl;;
        cout << "1. Add tutor" << endl;
        cout << "2. Display tutor" << endl;
        cout << "3. Edit tutor" << endl;
        cout << "4. Delete tutor" << endl;
        cout << "5. Sort tutor" << endl;
        cout << "6. Search tutor" << endl;
        cout << "7. Exit " << endl;
        cout << "============================================" << endl;
        cout << "Please insert the number you want" << endl;

        cin >> number;

        switch (number)
        {
            //case1
        case '1':
            addInMain();
            displayTutor();
            break;

            //case2
        case '2':
            /*displayTutor();*/
            displayTutor();
            ManageTutorMenu();
            break;

            //case3
        case '3':

            break;

            //case4
        case '4':
            deleteTutorInMain();
            break;

            //case5
        case '5':
            BubbleSortByType(&thead,1);
            break;

            //case6
        case'6':
            searchTutorInMain();
            break;

            //case7
        case'7':
            system("cls");
            Menu("manager");
            break;
        default:
            break;
        }

    } while (number != '7');
}



void ManageAdminMenu() {

    int admin_id = 0;
    int count = 0;
    int choice = 0;
    int position = 0;
    Admin* new_admin;
    Admin* current = adminNodeHead;
    cout << "Manage Admin" << endl;
    cout << "1. View all admin record." << endl;
    cout << "2. Add new admin record." << endl;
    cout << "3. Modify admin record." << endl;
    cout << "4. Delete admin record." << endl;
    cout << "5. Back." << endl;
    cin >> choice;
    system("cls");


    switch (choice) {

    case 1:
        displayAdminRecord();
        cout << endl;
        cout << "Do you want to continue at Manage Admin? Yes = 1, No = 2" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            ManageAdminMenu();
            break;
        case 2:
            Menu("Admin");
            break;
        default:
            Menu("Admin");

        }

    case 2:
        while (current!= NULL) {
            count++;
            current = current->next_address;
        }
        cin.ignore();
        cout << "Create New Admin Record" << endl;
        cout << string(20, '-') << endl;
        cout << "Enter First Name:" << endl;
        getline(cin, admin_fname);
        cin.ignore();
        cout << "Enter Last Name:" << endl;
        getline(cin, admin_lname);
        
        cout << "Enter centre code:" << endl;
        cin >> admin_centre_code;
        cin.ignore();
        cout << "Enter centre name:" << endl;
        getline(cin, admin_centre_name);
        cin.ignore();
        cout << "Enter centre address:" << endl;
        getline(cin, admin_centre_address);
        cin.ignore();
        cout << "Enter Phone:" << endl;
        cin >> admin_phone;
        cout << "Enter Email:" << endl;
        cin >> admin_email;

        new_admin = CreateAdminNode(count, admin_fname, admin_lname, admin_centre_code, admin_centre_name, admin_centre_address, admin_phone, admin_email);
        InsertIntoEndAdmin(new_admin);
        ManageAdminMenu();
        break;

    case 3:
        displayAdminRecord();
        cout << "Enter No. of Account to modify:" << endl;
        cin >> position;
        ModifyAdminRecord(position);
        ManageAdminMenu();
        break;
    case 4:
        displayAdminRecord();
        cout << "Enter No. of Account to delete:" << endl;
        cin >> position;
        deleteAdminRecord(position);
        ManageAdminMenu();
        break;
    case 5:
        Menu("Admin");
        break;
    }
}

void ManageAccountMenu() {

    string new_username;
    string new_password;
    string role;
    int manage_account_choice = 0;
    int position = 0;
    Account* new_account;
    cout << "Manage Account" << endl;
    cout << "1. View all account." << endl;
    cout << "2. Add new account." << endl;
    cout << "3. Modify account." << endl;
    cout << "4. Delete account" << endl;
    cout << "5. Back." << endl;
    cin >> manage_account_choice;
   
    switch (manage_account_choice) {

    case 1:
        displayAllAccount();
        cout << endl;
        cout << "Do you want to continue at Manage Account? Yes = 1, No = 2" << endl;
        cin >> manage_account_choice;

        switch (manage_account_choice) {
        case 1:
            ManageAccountMenu();
            break;
        case 2:
            Menu("Manager");
            break;
        default:
            Menu("Manager");

        }

    case 2:
        cout << manage_account_choice << endl;
        cout << "Create new account" << endl;
        cout << "User username:" << endl;
        cin >> new_username;
        cout << "User password:" << endl;
        cin >> new_password;

        while(true){
        
        cout << "User role:" << endl;
        cin >> role;

        if (role == "manager" || role == "admin") {

            break;
            
        }
        else {
            cout << "Invalid Role!" << endl;
            continue;
        }
        }
        
        new_account = CreateAccountNode(new_username, new_password, role);
        InsertNewAccount(new_account);
        cout << "New account created successfully." << endl;
        ManageAccountMenu();
        break;
        
    case 3:
        displayAllAccount();
        cout << "Enter No. of Account to modify:" << endl;
        cin >> position;
        modifyUserAccount(position);
        ManageAccountMenu();
        break;
    case 4:
        displayAllAccount();
        cout << "Enter No. of Account to delete:" << endl;
        cin >> position;
        deleteAccount(position);
        ManageAccountMenu();
        break;
    case 5: 
        Menu("Manager");
        break;
    }
}

void ManagerMenu() {
    string fname;
    string lname;
    string phone;
    string address;
    string email;
    int id = 0;
    int count = 0;
    int stay_section = 0;
    Manager* newnode;
    Manager* current = managerNodeHead;
    cout << "Manage Manager" << endl;
    cout << "1. View all manager record." << endl;
    cout << "2. Add new manager record." << endl;
    cout << "3. Modify manager record." << endl;
    cout << "4. Delete manager record." << endl;
    cout << "5. Back." << endl;
    cin >> choice;
    system("cls");
    switch (choice) {

    case 1:
        displayManagerRecord();
        cout << "1. Search record." << endl;
        cout << "2. Back." << endl;
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter manager id to search:" << endl;
            cin >> id;

            while (id <= 0) {

                cout << "Invalid input!" << endl;
                cout << "Try Again!" << endl;
                cout << "Enter manager id to search:" << endl;
                cin >> id;
            }
            searchRecordByID(id);
            break;

        default:
            break;
        }

        cout << "Do you want to continue at Manage Manager? Yes = 1, No = 2" << endl;
        cin >> stay_section;

        switch (stay_section) {
        case 1:
            ManagerMenu();
            break;
        case 2:
            Menu("Manager");
            break;
        }

        break;

    case 2:
        
        checkEmptyRecord();
        cout << "Create New Manager Record" << endl;
        cout << string(20, '-') << endl;
        cout << "Enter First Name:" << endl;
        cin >> fname;
        cout << "Enter Last Name:" << endl;
        cin >> lname;
        cout << "Enter Phone:" << endl;
        cin >> phone;
        cin.ignore();
        cout << "Enter Address:" << endl;
        getline(cin,address);

        cout << "Enter Email:" << endl;
        cin >> email;
        
       count++;
        while (managerNodeHead != NULL) {
            count++;
            current = current->next_address;
            if (current->next_address == NULL) {
                count++;
                break;
            }
        }

        newnode = CreateManagerNode(count, fname, lname, phone, address, email);
        InsertIntoEndManager(newnode);
        ManagerMenu();
        break;

    case 3:
        cout << "Enter manager id to modify:" << endl;
        cin >> id;
        ModifyManagerRecord(id);
        ManagerMenu();
        break;
    case 4:
        displayManagerRecord();
        cout << "Enter manager id to delete:" << endl;
        cin >> id;
        deleteManagerRecord(id);
        ManagerMenu();
        break;

    }

}


int main()
{
    //Predefined data
    managerNodeHead = CreateManagerNode(1, "Chow", "Wen Long", "0123456", "wenlongchow@yahoo.com", "jalan abc");
    Manager* manager_record_1 = CreateManagerNode(2, "Chow", "Wen Long", "0123456", "wenlongchow@yahoo.com", "jalan abc");
    InsertIntoEndManager(manager_record_1);

    accountNodeHead = CreateAccountNode("manager1","12345","manager");
    Account* new_account = CreateAccountNode("admin1", "12345", "admin");
    Account* new_account1 = CreateAccountNode("tutor3", "12345", "tutor");
    
    InsertNewAccount(new_account);
    InsertNewAccount(new_account1);
    adminNodeHead = CreateAdminNode(1, "Chow","Wen Long","T001","SUPER EDU","Jalan ABC", "0123123","yahoo");
    Admin* admin2 = CreateAdminNode(1, "Chow", "Wen Long", "T001", "SUPER EDU", "Jalan ABC", "0123123", "yahoo");
    InsertIntoEndAdmin(admin2);

    thead= addNewNode(8, "Siow", "Yang", setDate(2, 4, 2022), setDate(2, 10, 2022), 10.0, "0123456789", "Bukit Jalil", "cc1", "ccname1", "sub1", "Math", 5);
    Tutor* new_tutor = addNewNode(8, "Sohai", "Yang", setDate(2, 4, 2022), setDate(2, 10, 2022), 10.0, "0123456789", "Bukit Jalil", "cc1", "ccname1", "sub1", "Math", 5);
    InsertTutorRecord(new_tutor);
    preTutorData();

    int option = 0;
    cout << "Tutor Management System" << endl;
    cout << string(20, '-') << endl;
    cout << "1. Login" << endl;
    cout << "2. Quit" << endl;
    cin >> option;


    if (option == 1) {

        Login();

    }
    else {

        exit(0);

    }
    
    return 0;
}

