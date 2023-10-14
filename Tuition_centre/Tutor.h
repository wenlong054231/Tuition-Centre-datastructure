#include <iostream>
#include <regex>
#include <sstream>
#include<ctime>
#include<tuple>

#pragma warning(disable : 4996)
using namespace std;

int sizeLinkedList = 0;
int tsizeLinkedList = 0;


struct Tutor {
	int tutor_id;
	string firstName;
	string lastName;
	tm* date_joined;
	tm* date_terminated;
	double hourly_rate;
	string phone;
	string address;
	string centre_code;
	string centre_name;
	string subject_code;
	string subject_name;
	int rating;
	Tutor* next_address;
	Tutor* prev_address;

}*thead, *ttail;


Tutor* addNewNode(int tutor_id, string firstName, string lastName, tm* date_joined, tm* date_terminated, /*tm* date_joined_day, tm* date_joined_month, tm* date_joined_year, tm* date_terminated_day, tm* date_terminated_month, tm* date_terminated_year,*/double hourly_rate, string phone, string address, string centre_code, string centre_name, string subject_code, string subject_name, int rating)
{
	
	Tutor* newnode = new Tutor;
	newnode->tutor_id = tutor_id;
	newnode->firstName = firstName;
	newnode->lastName = lastName;
	newnode->date_joined = date_joined;
	newnode->date_terminated = date_terminated;
	newnode->hourly_rate = hourly_rate;
	newnode->phone = phone;
	newnode->address = address;
	newnode->centre_code = centre_code;
	newnode->centre_name = centre_name;
	newnode->subject_code = subject_code;
	newnode->subject_name = subject_name;
	newnode->rating = rating;
	newnode->next_address = NULL;
	newnode->prev_address = NULL;

	sizeLinkedList++;
	return newnode;
}
template<typename T>
void bubbleSortFunction(Tutor** headRef, T Tutor::* anyAddress);
void BubbleSortByType(Tutor** headRef, int sortChoice);

void InsertTutorRecord(Tutor* newnode) {

	Tutor* current = thead;

	if (thead == NULL) {

		thead = newnode;
		thead->next_address = ttail;
		ttail = NULL;


	}
	else {
		
		while (thead != NULL) {
			
			//Head not null make new node as 2nd node if head only
			//If ady has tail then make new node as tail
			//Make previous tail after head

			if (current -> next_address == NULL) {
				
				current->next_address = newnode;
				newnode-> prev_address = current;
				newnode->next_address = NULL;
				ttail = newnode;
				current = current->next_address;
				break;

			}
			else {

				//If only has one record
				//Make new node as tail
				
				if (current == ttail) {
					
					current->next_address = newnode;
					newnode->prev_address = current;
					ttail = newnode;
					newnode->next_address = NULL;
					
				}
				

			}
			current = current->next_address;
		}


	}

}
	

tm* setDate(int day, int month, int year) {
	tm* time = new tm();
	time->tm_year = year - 1900;
	time->tm_mon = month - 1;
	time->tm_mday = day;
	return time;
}

void preTutorData()
{
	//time_t ttime = time(0);
	//tm* local_time = localtime(&ttime);
	//tm* t = setDate(30,4,2022);

	InsertTutorRecord(addNewNode(8, "Siow", "Yang", setDate(2, 4, 2022), setDate(2, 10, 2022), 10.0, "0123456789", "Bukit Jalil", "cc1", "ccname1", "sub1", "Math", 5));
	InsertTutorRecord(addNewNode(3, "Jason", "Chia", setDate(2, 5, 2022), setDate(2, 11, 2022), 7.0, "0123456789", "Taman Counaught", "cc1", "ccname1", "sub1", "Science", 4));
	InsertTutorRecord(addNewNode(6, "Teo", "Yeong", setDate(2, 3, 2022), setDate(2, 9, 2022), 7.0, "0123456789", "Maluri", "cc1", "ccname1", "sub1", "Math", 3));
	InsertTutorRecord(addNewNode(5, "Yeow", "Yang", setDate(5, 5, 2022), setDate(5, 11, 2022), 7.0, "0123456789", "Sri Petaling", "cc1", "ccname1", "sub1", "Science", 2));
	InsertTutorRecord(addNewNode(7, "Chin", "Zhe", setDate(5, 4, 2022), setDate(5, 10, 2022), 5.0, "0123456789", "Maluri", "cc1", "ccname1", "sub1", "Math", 1));
	InsertTutorRecord(addNewNode(4, "Chow", "Long", setDate(5, 3, 2022), setDate(5, 9, 2022), 5.0, "0123456789", "Bukit Bintang", "cc1", "ccname1", "sub1", "Science", 1));
	InsertTutorRecord(addNewNode(10, "Er", "Kai", setDate(3, 3, 2022), setDate(3, 9, 2022), 7.0, "0123456789", "Taman Counaught", "cc1", "ccname1", "sub1", "Math", 2));
	InsertTutorRecord(addNewNode(2, "Dang", "Wei", setDate(3, 5, 2022), setDate(3, 11, 2022), 5.0, "0123456789", "Puchong", "cc1", "ccname1", "sub1", "Science", 3));
	InsertTutorRecord(addNewNode(1, "Chow", "Shiang", setDate(3, 4, 2022), setDate(3, 10, 2022), 7.0, "0123456789", "Puchong", "cc1", "ccname1", "sub1", "Math", 4));
	InsertTutorRecord(addNewNode(9, "Michelle", "Lam", setDate(10, 2, 2022), setDate(10, 8, 2022), 7.0, "0123456789", "Bukit Jalil", "cc1", "ccname1", "sub1", "Science", 5));

	
}

void displayTutor()
{
	system("cls");
	int sort_choice = 0;
	int count = 0;
	int number = 0;
	int navigate = 0;
	Tutor* current = thead;

	if (thead == NULL)
	{
		cout << "List is empty!!" << endl << endl;
	}
	else
	{

		while (thead != NULL) {
			count++;
			
			cout << "====================Tutor===================" << endl;
			cout <<  count << ".  " << endl;
			cout << "Tutor ID: " << current->tutor_id << endl;
			cout << "First Name: " << current->firstName << endl;
			cout << "Last Name: " << current->lastName << endl;
			current = current->next_address;
			if (current == ttail) {

				break;
			}	
		}

		cout << "1. View detail. 2. Back." << endl;
		cin >> number;
		
		switch (number) {

		case 1:
			number = 0;
			cout << "Choose tutor (No. of tutor):" << endl;
			cin >> number;
			current = thead;
			count = 0;
			while (current -> next_address != NULL) {
				count++;

				if (count == number) {
					system("cls");
					cout << count << ".  " << endl;
					cout << "Tutor ID: " << current->tutor_id << endl;
					cout << "First Name: " << current->firstName << endl;
					cout << "Last Name: " << current->lastName << endl;
					cout << "Date joined: " << current->date_joined->tm_mday << "-" << current->date_joined->tm_mon + 1 << "-" << current->date_joined->tm_year + 1900 << endl;
					cout << "Date terminated: " << current->date_terminated->tm_mday << "-" << current->date_terminated->tm_mon + 1 << "-" << current->date_terminated->tm_year + 1900 << endl;
					cout << "Hourly pay rate: " << current->hourly_rate << endl;
					cout << "Phone: " << current->phone << endl;
					cout << "Address: " << current->address << endl;
					cout << "Centre Code: " << current->centre_code << endl;
					cout << "Centre Name: " << current->centre_name << endl;
					cout << "Subject Code: " << current->subject_code << endl;
					cout << "Subject Name: " << current->subject_name << endl;
					cout << "Rating: " << current->rating << endl;
					cout << "============================================";
					cout << "\n";	

					cout << "1.Next Page 2. Previous Page 3. Quit" << endl;
					cin >> navigate;
					
					switch (navigate) {

					case 1:
						if (current != thead) {
							count++;
							current = current->next_address;
						
						}
						break;
					case 2:
						if (current != thead) {
							count--;
							current = current->prev_address;
							
						}
						break;
					case 3:
						break;
					}

					while (navigate != 3) {

						if (thead != NULL ) {
							system("cls");

							cout << count << ".  " << endl;
							cout << "Tutor ID: " << current->tutor_id << endl;
							cout << "First Name: " << current->firstName << endl;
							cout << "Last Name: " << current->lastName << endl;
							cout << "Date joined: " << current->date_joined->tm_mday << "-" << current->date_joined->tm_mon + 1 << "-" << current->date_joined->tm_year + 1900 << endl;
							cout << "Date terminated: " << current->date_terminated->tm_mday << "-" << current->date_terminated->tm_mon + 1 << "-" << current->date_terminated->tm_year + 1900 << endl;
							cout << "Hourly pay rate(RM): " << current->hourly_rate << endl;
							cout << "Phone: " << current->phone << endl;
							cout << "Address: " << current->address << endl;
							cout << "Centre Code: " << current->centre_code << endl;
							cout << "Centre Name: " << current->centre_name << endl;
							cout << "Subject Code: " << current->subject_code << endl;
							cout << "Subject Name: " << current->subject_name << endl;
							cout << "Rating: " << current->rating << endl;
							cout << "============================================";
							cout << "\n";

							cout << "1.Next Page 2. Previous Page 3. Quit" << endl;
							cin >> navigate;
							
							switch (navigate) {

							case 1:
								if (current != ttail ) {
									count++;
									current = current->next_address;
									continue;
								}
								else {

									continue;
								}
							case 2:
								if (current != thead) {
									count--;
									current = current->prev_address;
									continue;
								}
								else {

									continue;
								}
							case 3: 
								navigate = 3;
								break;
							}
						}

						if (navigate == 3) {

							break;
						}

					}
				
				}
				else {
										
					if (current == ttail) {
						
						break;
					}

				}
				if (navigate == 3) {

					return;
				}
				else {
	
					current = current->next_address;
				}
				
			}

		case 2:
			break;

		default:
			break;
		}


	}

	cout << "1. Sort By Tutor ID. 2. Sort By Hourly 3. Sort By Rating 4. Quit" << endl;
	cin >> sort_choice;

	switch (sort_choice) {

	case 1:

		BubbleSortByType(&thead,sort_choice);
		break;

	case 2:
		BubbleSortByType(&thead, sort_choice);
		break;
	case 3:
		BubbleSortByType(&thead, sort_choice);
		break;

	case 4: 
		break;
	}
}

void addInMain()
{
	int tutor_id;
	string firstName;
	string lastName;
	tm* date_joined;
	tm* date_terminated;
	int date_joined_day;
	int date_joined_month;
	int date_joined_year;
	int date_terminated_day;
	int date_terminated_month;
	int date_terminated_year;
	double hourly_rate;
	string phone;
	string address;
	string centre_code;
	string centre_name;
	string subject_code;
	string subject_name;
	int rating;
	int choice;
	bool option = false;

	do {
		system("cls");
		do {

			cout << "Enter Tutor ID: " << endl;
			cin >> tutor_id;
			if (tutor_id < 0) {
				cout << "Invalid input!!" << endl;
			}
		} //if input is not number, request input
		while (tutor_id < 0);

		cout << "Enter First Name: " << endl;
		cin >> firstName;
		cin.ignore();
		cout << "Enter Last Name: " << endl;
		cin >> lastName;
		getline(cin, lastName);

		cout << "Enter date join (day): " << endl;
		cin >> date_joined_day;
		cout << "Enter date join (month): " << endl;
		cin >> date_joined_month;
		cout << "Enter date join (year): " << endl;
		cin >> date_joined_year;

		cout << "Enter date terminated (day): " << endl;
		cin >> date_terminated_day;
		cout << "Enter date terminated (month): " << endl;
		cin >> date_terminated_month;
		cout << "Enter date terminated (year): " << endl;
		cin >> date_terminated_year;

		cout << "Enter hourly rate: " << endl;
		cin >> hourly_rate;

		do {
			cout << "Enter Phone: " << endl;
			cin >> phone;
			if (!regex_match(phone, regex(("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?")))) {
				cout << "Invalid input!!" << endl;
			}
		} //if input is not number, request input
		while (!regex_match(phone, regex(("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?"))));
		cin.ignore();
		cout << "Enter Address: " << endl;
		getline(cin, address);
		cout << "Enter Centre Code: " << endl;
		cin >> centre_code;
		cin.ignore();
		cout << "Enter Centre Name: " << endl;
		getline(cin, centre_name);
		cout << "Enter Subject Code: " << endl;
		cin >> subject_code;
		cout << "Enter Subject Name: " << endl;
		cin >> subject_name;
		cout << "Enter Rating: " << endl;
		cin >> rating;

		Tutor* newnode = addNewNode(tutor_id, firstName, lastName, setDate(date_joined_day,date_joined_month,date_joined_year), setDate(date_joined_day,date_joined_month,date_joined_year), hourly_rate, phone, address, centre_code, centre_name, subject_code, subject_name, rating);
		InsertTutorRecord(newnode);

		cout << endl << "Record added!" << endl << endl;

		cout << "Do you want to continue add? 1 -Yes, Others -No" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			option = true;
			break;
		default:
			option = false;
			break;
		}
	} while (option);
}

void deleteTutor(int index)
{
	Tutor* current = thead;
	Tutor* prev = NULL;
	bool check = false;

	if (thead != NULL)
	{
		for (int i = 0; i < sizeLinkedList; i++)
		{
			if (index - 1 == i)
			{
				check = true;
				break;
			}
			prev = current;
			current = current->next_address;
		}
		if (check == true)
		{
			if (current == thead)
			{ //if it is the first 
				thead = thead->next_address;
				delete current;
				sizeLinkedList--;

			}
			else
			{
				prev->next_address = current->next_address;
				delete current;
				sizeLinkedList--;

			}
			cout << "Delete Successful" << endl;

		}
		else
			cout << "Doesn't exist" << endl;
	}

}

void deleteTutorInMain()
{
	int choice;
	char confirm;
	bool option;

	displayTutor();

	do
	{

		cout << "Enter the number you want to delete:  " << endl;
		cin >> choice;
		deleteTutor(choice);
		system("pause");
		displayTutor();

		cout << "Do you want to continue delete? 1 -Yes Others -No" << endl;
		cin >> confirm;

		switch (confirm)
		{
		case'1':
			option = true;

			break;
		default:
			option = false;
			break;
		}

	} while (option);
}

bool searchTutor(int searchTutorKey)
{
	Tutor* current = thead;
	bool check = false;

	//list empty
	if (thead == NULL)
	{
		cout << "List is empty" << endl;
	}
	//list not empty
	else
	{
		current = thead;

		//travesal
		while (current != NULL)
		{
			if (current->tutor_id == searchTutorKey)
			{
				cout << "====================Tutor===================" << endl;
				cout << "Tutor ID: " << current->tutor_id << endl;
				cout << "First Name: " << current->firstName << endl;
				cout << "Last Name: " << current->lastName << endl;
				cout << "Date joined: " << current->date_joined->tm_mday << "-" << current->date_joined->tm_mon + 1 << "-" << current->date_joined->tm_year + 1900 << endl;
				cout << "Date terminated: " << current->date_terminated->tm_mday << "-" << current->date_terminated->tm_mon + 1 << "-" << current->date_terminated->tm_year + 1900 << endl;
				cout << "Hourly pay rate: " << current->hourly_rate << endl;
				cout << "Phone: " << current->phone << endl;
				cout << "Address: " << current->address << endl;
				cout << "Centre Code: " << current->centre_code << endl;
				cout << "Centre Name: " << current->centre_name << endl;
				cout << "Subject Code: " << current->subject_code << endl;
				cout << "Subject Name: " << current->subject_name << endl;
				cout << "Rating: " << current->rating << endl;
				cout << "============================================";
				cout << "\n";
				check = true;
				break;
			}

			current = current->next_address;
		}

		if (!check)
		{
			cout << "Doesn't exist" << endl;
		}
		return !check;
	}
}

void searchTutorInMain()
{
	int choice;
	char confirm;
	bool option;
	bool notExist = false;

	do
	{
		do {
			system("cls");
			cout << "Enter Tutor ID to search: " << endl;
			cin >> choice;
			bool check = searchTutor(choice);
			notExist = check;
			system("pause");
		} while (notExist);


		cout << "Do you want to continue search? 1 -Yes Others -No" << endl;
		cin >> confirm;

		switch (confirm)
		{
		case'1':
			option = true;
			break;
		default:
			option = false;
			break;
		}

	} while (option);
}

//Adjust type until argument pass to parameter
template <typename T>
void bubbleSortFunction(Tutor** headRef, T Tutor::* anyAddress) {

	Tutor* current = *headRef;
	Tutor* after = (*headRef)->next_address;

	bool didChange;
	int counter = 0;

	while (1) {

		while (after != NULL) {

			if (current->*anyAddress > after->*anyAddress) {

				current->next_address = after->next_address; // Point first node to next next node
				after->prev_address = current->prev_address; // Move next node to infront current
				current->prev_address = after; // Make next node as current previous node 2 <- 1
				after->next_address = current; // Make next node next address point to current 2 -> 1

				
				if (after->prev_address != NULL) {
					// If not first node make next node to the front 
					Tutor* beforeAfter = after->prev_address;
					beforeAfter->next_address = after;
				}

				if (current->next_address != NULL) {
					// if not last node make next node pointed by current node
					Tutor* afterCurrent = current->next_address;
					afterCurrent->prev_address = current;

				}

				after = after->next_address->next_address;

				didChange = 1;
			}
			else {

				current = current->next_address;
				after = after->next_address;

			}
		}
	
		while ((*headRef)->prev_address != NULL) {

			(*headRef) = (*headRef)->prev_address;
		}

		current = *headRef;
		after = (*headRef)->next_address;


		if (didChange == 0) {

			break;
		}
		else if (didChange == 1) {
			didChange = 0;
		}
	}
	displayTutor();
}

void BubbleSortByType(Tutor** headRef ,  int sortChoice) {

	//Use tuple to store multiple type variable
	//Tuple use get<> to get variable inside tuple
	// :: for type to get variable 
	//object pointer use -> 
	tuple<int Tutor::*, double Tutor::*, int Tutor::* >  value = make_tuple(&Tutor::tutor_id, &Tutor::hourly_rate, &Tutor::rating);
	int Tutor::* sortBy;
	double Tutor::* sortByRating;

	switch (sortChoice) {

	case 1:
		sortBy = get<0>(value);
		break;
	case 2:
		 sortByRating = get<1>(value);
		break;
	case 3:
		sortBy = get<2>(value);
		break;
	}


	if ((*headRef == NULL) || (*headRef)->next_address == NULL){

		return;
	}

	switch (sortChoice) {
	case 1:
		bubbleSortFunction(headRef, sortBy);
		break;
	case 2:
		bubbleSortFunction(headRef, sortByRating);
		break;
	case 3:
		bubbleSortFunction(headRef, sortBy);
		break;

	}
}

