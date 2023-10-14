#pragma once
#include <string>
#include <iostream>
using namespace std;

struct Account {

    string username;
    string password;
    string role;
    Account* next_address;
}*accountNodeHead;

Account* CreateAccountNode(string Username, string Password, string role) {

    Account* newnode = new Account;
    newnode->username = Username;
    newnode->password = Password;
    newnode->role = role;
    newnode->next_address = NULL;

    return newnode;
}


void modifyUserAccount(int position);
void displayAllAccount();

void InsertNewAccount(Account* newnode) {

    Account* current = accountNodeHead;

    if (current == NULL) {

        current = newnode;

    }
    else {

        while (accountNodeHead != NULL) {
            
            if (current->next_address != NULL) {
                current = current->next_address;
            }
            else {

                current->next_address = newnode;
                break;
            }

        }

        

    }
   
}

void deleteAccount(int position) {

    Account* current = accountNodeHead;
    Account* previous = current;
    int nodeCount = 0;

    while (current != NULL) {

        nodeCount++;

        if (position == nodeCount) {

            //Scenario where current is head when deleting
            if (current = accountNodeHead) {
                //Unlink head from other node
                accountNodeHead = current->next_address;
                //Make next node to head
                current->next_address = NULL;
                delete current;
                cout << "User deleted successfully." << endl;
                break;

            }
            else {

                //Unlink previous node from the deleting node
                //Link it to the next node of deleting node
                previous->next_address = current->next_address;
                delete current;
                cout << "User deleted successfully." << endl;
                break;

            }

        }
        //If end of the node and last node dont have result then result not found
        else if (current->next_address == NULL) {

            if (position == nodeCount) {

                previous->next_address = current->next_address;
                delete current;
                cout << "User deleted successfully." << endl;
                break;

            }
            else {

                cout << "User Account not found!" << endl;
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

void modifyUserAccount(int position) {

    Account* current = accountNodeHead;
    int sizeofList = 0;
    string user_name;
    string password;
    string role;
    int choice = 0;

    displayAllAccount();
    while (accountNodeHead != NULL ) {
        
        sizeofList++;
        if (position == sizeofList || current -> next_address == NULL) {

            cout << "Select info to modify: 1. username 2. password 3. role" << endl;
            cin >> choice;

            switch (choice) {

            case 1:
                cout << "Enter username:" << endl;
                cin >> user_name;

                current->username = user_name;
                cout << "Info Update Sucessfully!" << endl;
                break;
            case 2:
                cout << "Enter password:" << endl;
                cin >> password;
                current->password = password;
                cout << "Info Update Sucessfully!" << endl;
                break;

            case 3:
                cout << "Enter role:" << endl;
                cin >> role;
                current->role = role;
                cout << "Info Update Sucessfully!" << endl;
                break;

            }
            break;
        }
        else {

            current = current->next_address;
        }  
    }

}  



void displayAllAccount() {

    Account* current = accountNodeHead;
    int sizeofList = 0;
    string back;
    sizeofList++;

    if (accountNodeHead != NULL) {

        cout << "No." << "\t" << "|" << "Username" << "\t" << "|" << "Password" << "|" << "Role" << "|" << "\t" << endl;
        cout << sizeofList << " \t|" << current->username << " \t|" << current->password << "|" << current->role << endl;

        while (accountNodeHead != NULL) {

            if (current->next_address == NULL) {
                break;
            }
            else {
                sizeofList++;
                current = current->next_address;
                cout << sizeofList << " \t|" << current->username << " \t|" << current->password << "|" << current->role << endl;
            }
        }

    }
    else {
        
        cout << "No." << "\t" << "|" << "Username" << "\t" << "|" << "Password" << "|" << "Role" << "|" << "\t" << endl;
        cout << "Empty record" << endl;

        
    }

}


