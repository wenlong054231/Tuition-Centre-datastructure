#pragma once
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

int admin_choice = 0;
int admin_id;
string admin_fname;
string admin_lname;
string admin_centre_code;
string admin_centre_name;
string admin_centre_address;
string admin_phone;
string admin_email;


struct Admin {

    int admin_id;
    string firstName;
    string lastName;
    string centre_code;
    string centre_name;
    string centre_address;
    string phone;
    string email;
    Admin* next_address;
}*adminNodeHead;


Admin* CreateAdminNode(int Admin_id, string FirstName, string LastName, string centre_code, string centre_name, string centre_address, string Phone, string Email) {

    Admin* Newnode = new Admin;
    Newnode->admin_id = Admin_id;
    Newnode->firstName = FirstName;
    Newnode->lastName = LastName;
    Newnode->centre_code = centre_code;
    Newnode->centre_name = centre_name;
    Newnode->centre_address = centre_address;
    Newnode->phone = Phone; 
    Newnode->email = Email;
    Newnode->next_address = NULL;

    return Newnode;
}

void ModifyAdminRecord(int position);
void displayAdminRecord();
void deleteAdminRecord(int position);
void searchRecordByLocation(string search_location );

void InsertIntoEndAdmin(Admin* newnode) {

    //first node
    Admin* current = adminNodeHead;


    if (adminNodeHead == NULL) {

        adminNodeHead = newnode;

    }
    else {

        while (current->next_address != NULL) {

            current = current->next_address;

        }

        current->next_address = newnode;

    }
   
}

void checkEmptyAdminRecord() {

    //Check any record exists
    Admin* newnode;
    Admin* current = adminNodeHead;
    int count = 0;

    if (adminNodeHead == NULL) {

        cout << "No record created." << endl;
        cout << "Do you want to create new admin record." << endl;
        cout << "Yes = 1, No = 2" << endl;
        cin >> choice;

        while (current != NULL) {
            count++;
            current = current->next_address;

        }
        
        switch (choice) {

        case 1:
            cout << "Create New Admin Record" << endl;
            cout << string(20, '-') << endl;
            cout << "Enter First Name:" << endl;
            cin >> admin_fname;
            cout << "Enter Last Name:" << endl;
            cin >> admin_lname;
            cout << "Enter centre code:" << endl;
            cin >> admin_centre_code;
            cout << "Enter centre name:" << endl;
            cin >> admin_centre_name;
            cout << "Enter centre address:" << endl;
            getline(cin, admin_centre_address);
            cout << "Enter Phone:" << endl;
            cin >> admin_phone;
            cout << "Enter Email:" << endl;
            cin >> admin_email;
            newnode = CreateAdminNode(1, admin_fname, admin_lname, admin_centre_code, admin_centre_name, admin_centre_address, admin_phone, admin_email);
            InsertIntoEndAdmin(newnode);
            break;

        default:
            break;
        }
    }


}

void displayAdminRecord() {

    Admin* current = adminNodeHead;
    int sizeofList = 0;
    string back;
    sizeofList++;


    if (adminNodeHead != NULL) {

        cout << "No." << "|" << setw(10) << "Admin ID" <<"|" << setw(10) << "Name" << "|" << setw(10) << "Centre Code" << "|" << setw(10) << "Centre Name" << "|" << setw(20) << "Centre address"
            << "|" << setw(10) << "Phone"<< "|" << setw(21) << "Email" << "|"  << endl;
        cout << sizeofList << "|" << setw(10) << current->admin_id << " |" << setw(10) << current->firstName + " " + current->lastName << "|" << setw(10) << current->centre_code << "|" << setw(10) << current->centre_name << "|" << setw(20) << current->centre_address << " |" <<
             current->phone << " |" << setw(21) << current->email << " |" << endl;

        while (adminNodeHead != NULL) {

            if (current->next_address == NULL) {
                break;
            }
            else {
                sizeofList++;
                current = current->next_address;
                cout << sizeofList << "|" << setw(10) << current->admin_id << " |" << setw(10) << current->firstName + " " + current->lastName << "|" << setw(10) << current->centre_code << "|" << setw(10) << current->centre_name << "|" << setw(20) << current->centre_address << " |" <<
                    current->phone << " |" << setw(21) << current->email << " |" << endl;
            }
        }

    }
    else {

        cout << "No." << "|" << setw(10) << "Admin ID" << "|" << setw(10) << "Name" << "|" << setw(10) << "Centre Code" << "|" << setw(10) << "Centre Name" << "|" << setw(20) << "Centre address"
            << "|" << setw(10) << "Phone" << "|" << setw(21) << "Email" << "|" << endl;
        cout << "Empty record" << endl;


    }

}

void searchRecordByLocation(string search_location) {

    int sizeofList = 0;
    if (adminNodeHead != NULL) {

        Admin* current = adminNodeHead;
        sizeofList++;

        cout << "No." << "|" << setw(10) << "Admin ID" << "|" << setw(10) << "Name" << "|" << setw(10) << "Centre Code" << "|" << setw(10) << "Centre Name" << "|" << setw(20) << "Centre address"
            << "|" << setw(10) << "Phone" << "|" << setw(21) << "Email" << "|" << endl;

        while (current != NULL) {


            if (current->centre_address == search_location) {
                cout << sizeofList << "|" << setw(10) << current->admin_id << " |" << setw(10) << current->firstName + " " + current->lastName << "|" << setw(10) << current->centre_code << "|" << setw(10) << current->centre_name << "|" << setw(20) << current->centre_address << " |" <<
                    current->phone << " |" << setw(21) << current->email << " |" << endl;
                break;

            }
            else if (current->next_address == NULL) {

                if (current->centre_address == search_location){
                    cout << sizeofList << "|" << setw(10) << current->admin_id << " |" << setw(10) << current->firstName + " " + current->lastName << "|" << setw(10) << current->centre_code << "|" << setw(10) << current->centre_name << "|" << setw(20) << current->centre_address << " |" <<
                        current->phone << " |" << setw(21) << current->email << " |" << endl;
                    break;

                }
                else {

                    break;

                }

            }
            else {
                sizeofList++;
                current = current->next_address;

            }

        }
    }
}

void deleteAdminRecord(int position) {

    Admin* current = adminNodeHead;
    Admin* previous = current;
    int nodeCount = 0;

    while (current != NULL) {

        nodeCount++;

        if (position == nodeCount) {

            //Scenario where current is head when deleting
            if (current = adminNodeHead) {
                //Unlink head from other node
                adminNodeHead = current->next_address;
                //Make next node to head
                current->next_address = NULL;
                delete current;
                cout << "Admin deleted successfully." << endl;
                break;

            }
            else {

                //Unlink previous node from the deleting node
                //Link it to the next node of deleting node
                previous->next_address = current->next_address;
                delete current;
                cout << "Admin deleted successfully." << endl;
                break;

            }

        }
        //If end of the node and last node dont have result then result not found
        else if (current->next_address == NULL) {

            if (position == nodeCount) {

                previous->next_address = current->next_address;
                delete current;
                cout << "Admin deleted successfully." << endl;
                break;

            }
            else {

                cout << "Admin Account not found!" << endl;
                break;
            }


        }
        else {
            //Move to next node
            previous = current;
            current = current->next_address;


        }

    }
}

void ModifyAdminRecord(int position) {

    Admin* current = adminNodeHead;
    int sizeofList = 0;
    string firstname;
    string lastname;
    string centre_code;
    string centre_name;
    string centre_address;
    string phone;
    string email;

    int choice = 0;

    while (adminNodeHead != NULL) {

        sizeofList++;

        if (position == sizeofList) {

            cout << "Select info to modify: 1. First name 2. Last name 3. Centre code 4. Centre name 5. Centre address 6. Phone 7. Email" << endl;
            cin >> choice;
            cin.ignore();

            switch (choice) {

            case 1:
                cout << "Enter first name:" << endl;
                cin >> firstname;

                current->firstName = firstname;
                cout << "Info Update Sucessfully!" << endl;
                break;
            case 2:
                
                cout << "Enter last name:" << endl;
                getline(cin, lastname);
                current->lastName = lastname;
                cout << "Info Update Sucessfully!" << endl;
                break;

            case 3:
                cout << "Enter centre code:" << endl;
                cin >> centre_code;
                current->centre_code = centre_code;
                cout << "Info Update Sucessfully!" << endl;
                break;

            case 4:
                cout << "Enter centre name:" << endl;
                cin >> centre_name;
                current->centre_name = centre_name;
                cout << "Info Update Sucessfully!" << endl;
                break;
            case 5:
                cin.ignore();
                cout << "Enter centre address:" << endl;
                getline(cin, centre_address);
                current->centre_address = centre_address;
                cout << "Info Update Sucessfully!" << endl;
                break;
            case 6:
                cout << "Enter phone:" << endl;
                cin >> phone;
                current->phone = phone;
                cout << "Info Update Sucessfully!" << endl;
                break;

            case 7:
                cout << "Enter email:" << endl;
                cin >> email;
                current->email = email;
                cout << "Info Update Sucessfully!" << endl;
                break;
            }
            return;
        }
        else {

            current = current->next_address;
        }



    }

}
