#ifndef HEADERFILE_H
#define HEADERFILE_H
#endif

#pragma once
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

int choice = 0;
string fname;
string lname;
string phone;
string address;
string email;

struct Manager {

    int manager_id = 0;
    string firstName;
    string lastName;
    string phone;
    string address;
    string email;
    Manager* next_address;

}*managerNodeHead;


Manager* CreateManagerNode(int Manager_id, string FirstName, string LastName, string Phone, string Address, string Email) {

    Manager* Newnode = new Manager;
    Newnode->manager_id = Manager_id;
    Newnode->firstName = FirstName;
    Newnode->lastName = LastName;
    Newnode->phone = Phone;
    Newnode->address = Address;
    Newnode->email = Email;
    Newnode->next_address = NULL;

    return Newnode;
}

void ModifyManagerRecord(int id);
void displayManagerRecord();
void deleteManagerRecord(int manager_id);
void searchRecordByID(int search_id);

void InsertIntoEndManager(Manager* newnode) {
    
    //first node
    Manager* current = managerNodeHead;


    if (managerNodeHead == NULL) {

        managerNodeHead = newnode;

    }
    else {

        while (current->next_address != NULL) {

            current = current->next_address;

        }

        current->next_address = newnode;

    }
    
}

void checkEmptyRecord(){
   
    //Check any record exists
    Manager* newnode;

    if (managerNodeHead == NULL) {

        cout << "No record created." << endl;
        cout << "Do you want to create new manager record." << endl;
        cout << "Yes = 1, No = 2" << endl;
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Create New Manager Record" << endl;
            cout << string(20, '-') << endl;
            cout << "Enter First Name:" << endl;
            cin >> fname;
            cout << "Enter Last Name:" << endl;
            cin >> lname;
            cout << "Enter Phone:" << endl;
            cin >> phone;
            cout << "Enter Address:" << endl;
            getline(cin, email);
            cout << "Enter Email:" << endl;
            cin.ignore();
            cin >> address;
            newnode = CreateManagerNode(1, fname, lname, phone, address, email);
            InsertIntoEndManager(newnode);
            break;

        default:
            break;
        }
    }


}
void displayManagerRecord() {

    if (managerNodeHead == NULL) {

        
        cout << "|" << setw(10) << "ID" << "|" << setw(10) << "Name" << "|" << setw(10) << "Phone"
            << "|" << setw(10) << "Email" << "|" << setw(21) << "Address" << "|" << endl;

        cout << "Empty Record" << endl;
    }
    else {

        Manager* current = managerNodeHead;
        
        cout << "|" << setw(10) << "ID" << "|" << setw(10) << "Name" << "|" << setw(10) << "Phone"
            << "|" << setw(10) << "Email" << "|" << setw(21) << "Address" << "|" << endl;

        //Check current node equal null
        while (current!= NULL) {

            //Display record and move to next node
            cout << "|" << setw(10) << current->manager_id << "|" << setw(10) << current->firstName + " " + current->lastName << "|" << setw(10) << current->phone
                << "|" << setw(10) << current->email << "|" << setw(10) << current->address << "|" << endl;


            current = current->next_address;
       
        }

       
       
    }
    
}

void searchRecordByID(int search_id) {

    //Check head not null
    if (managerNodeHead != NULL) {

        Manager* current = managerNodeHead;
       
        cout << "|" << setw(10) << "ID" << "|" << setw(10) << "Name" << "|" << setw(10) << "Phone"
            << "|" << setw(10) << "Email" << "|" << setw(21) << "Address" << "|" << endl;
        while (current != NULL) {

            //Check manager id is same with search index
            if (current->manager_id == search_id) {
                cout << "|" << setw(10) << current->manager_id << "|" << setw(10) << current->firstName + " " + current->lastName << "|" << setw(10) << current->phone
                    << "|" << setw(10) << current->email << "|" << setw(10) << current->address << "|" << endl;
                break;
                
            }
            else if (current->next_address == NULL) {

                if (current->manager_id == search_id) {
                    cout << "|" << setw(10) << current->manager_id << "|" << setw(10) << current->firstName + " " + current->lastName << "|" << setw(10) << current->phone
                        << "|" << setw(10) << current->email << "|" << setw(10) << current->address << "|" << endl;
                    break;

                }
                else {

                    break;

                }

            }
            else {

                current = current->next_address;

            }
            
        }
    }
}

void deleteManagerRecord(int manager_id) {
    
    Manager* current = managerNodeHead;
    Manager* previous = current;


    while (current != NULL) {

        
        if (current->manager_id == manager_id) {

            //Scenario where current is head when deleting
            if (current = managerNodeHead) {
                //Unlink head from other node
                managerNodeHead = current->next_address;
                //Make next node to head
                current->next_address = NULL;
                delete current;
                cout << "Manager record deleted successfully." << endl;
                break;
            }
            else {

                //Unlink previous node from the deleting node
                //Link it to the next node of deleting node
                previous->next_address = current -> next_address;
                delete current;
                cout << "Manager record deleted successfully." << endl;
                break;

            }
            
        }
        //If end of the node and last node dont have result then result not found
        else if (current->next_address == NULL) {
            
            if (current->manager_id == manager_id) {

                previous->next_address = current->next_address;
                delete current;
                cout << "Manager record deleted successfully." << endl;
                break;

            }
            else {

                cout << "Manager ID not found!" << endl;
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

void ModifyManagerRecord(int id) {

    Manager* current = managerNodeHead;
    if (managerNodeHead != NULL) {

        cout << "|" << setw(10) << "ID" << "|" << setw(10) << "Name" << "|" << setw(10) << "Phone"
            << "|" << setw(10) << "Email" << "|" << setw(21) << "Address" << "|" << endl;
            
        while (current != NULL) {

            if (current->manager_id == id) {
                cout << "|" << setw(10) << current->manager_id << "|" << setw(10) << current->firstName + " " + current->lastName << "|" << setw(10) << current->phone
                    << "|" << setw(10) << current->email << "|" << setw(10) << current->address << "|" << endl;
                cout << "Select column to modify:" << endl;
                cout << "1. First Name" << endl;
                cout << "2. Last Name" << endl;
                cout << "3. Phone" << endl;
                cout << "4. Email" << endl;
                cout << "5. Address" << endl;
                cin >> choice;

                switch (choice) {

                case 1:
                    cout << "Enter first name:" << endl;
                    cin >> fname;

                    current->firstName = fname;
                    break;
                case 2:
                    cout << "Enter last name:" << endl;
                    cin >> lname;
                    current->lastName = lname;
                    break;
                case 3:
                    cout << "Enter phone:" << endl;
                    cin >> phone;
                    current->phone = phone;
                    break;
                case 4: 
                    cin.ignore();
                    cout << "Enter email:" << endl;
                    getline(cin, email);
                    current->email = email;
                    break;
                case 5: 
                    cin.ignore();
                    cout << "Enter address:" << endl;
                    getline(cin, address);
                    cin.ignore();
                    
                    current->address = address;
                    break;
                
                }

                cout << "Do you want to continue modify? Yes = 1, No = 2" << endl;
                cin >> choice;

                switch (choice) {

                case 1:
                    ModifyManagerRecord(id);
                    break;
                default:
                    break;
                }
                break;
            }
            current = current->next_address;
        }
    }

    }




