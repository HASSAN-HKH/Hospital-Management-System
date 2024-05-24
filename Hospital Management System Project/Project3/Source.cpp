#include <iostream>
using namespace std;

// Queue – Linked List Implementation
class Hospital {
	struct patient { // node 
		int id, age, durOfTreat;
		string name, moNum, dis;
		patient* next = NULL;
	};

	patient* front, * rear;
private: int d = 1;
public:

	Hospital() {
		rear = NULL;
		front = NULL;
	}

	// Check if there exist any patients
	bool noPatient() {
		return d == 1;
	}

	// Adding new Patient
	void addPatient(string name, int age, string dis, string num, int dur) {
		patient* newnext = new patient();
		newnext->age = age;
		newnext->dis = dis;
		newnext->id = d;
		newnext->moNum = num;
		newnext->durOfTreat = dur;
		newnext->name = name;
		if (noPatient()) {
			newnext->next = NULL;
			front = newnext;
			rear = newnext;
		}
		else {
			newnext->next = NULL;
			rear->next = newnext;
			rear = newnext;
		}
		d++;
	}

	// Retrieve Information about Patients
	void retrieveInfo() {
		patient* temp = front;
		cout << "Name  Age	ID	Disease	 Mobile	  Treatment Duration" << "\n";
		while (temp != NULL) {
			cout << temp->name << " " << temp->age << " " << temp->id << " " << temp->dis << " " << temp->moNum << " " << temp->durOfTreat << "days\n";
			temp = temp->next;
		}
	}

	// Check if a specific Patient Exist or Not
	bool isExist(string name, int id) {
		patient* temp = front;
		while (temp != NULL) {
			if (temp->id == id && temp->name == name) {
				return true;
			}
			temp = temp->next;
		}
		return false;
	}

	// Updating some information in the patient's report
	bool updateInfo(string name, int id, string moNum) {
		patient* temp = front;
		while (temp != NULL) {
			if (temp->id == id && temp->name == name) {
				temp->moNum = moNum;
				return true;
			}
			temp = temp->next;
		}
		return false;
	}

	// Deleting a Patient from the Hospital System
	bool deletePatient(string name, int id) {
		patient* temp = front, * del = front;
		bool ch = false;
		if (temp->id == id && temp->name == name) { // if first element
			del = temp;
			temp = temp->next;
			front = temp;
			delete del;
			return !ch;
		}
		else {
			while (temp->next != NULL) {
				if (temp->next->id == id && temp->next->name == name) {
					del = temp->next;
					temp->next = temp->next->next;
					delete del;
					return !ch;
				}
				temp = temp->next;
			}
		}
		return ch;
	}

};



int main() {

	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int op = 0;

	cout << "********************************************** Hospital Management System **********************************************" << endl;

	Hospital hos;
	while (op != -1) {
		// Getting the data of a patient
		string name, phone, disease;
		int age, duration, id;
		cout << "Choose the operation from the list" << endl;
		cout << "1 - Adding Patient\n" << "2 - Deleting Patient\n" << "3 - Searching for patient\n" << "4 - Updating patient's information\n" << "5 - Displaying patient's information\n" << "Press -1 to exit \n";
		cin >> op;
		// Adding Patient
		if (op == 1) {
			cout << "Enter the name\n";
			cin >> name;
			cout << "Enter the Age in years\n"; // in case of string
			cin >> age;
			while (age <= 0) {
				cout << "Enter valid age please\n";
				cin >> age;
			}
			cout << "Enter the phone number\n";
			cin >> phone;
			cout << "Enter the disease\n"; // getline
			cin >> disease;
			cout << "Enter the treatment duration in days\n"; // in case of string
			cin >> duration;
			while (duration <= 0) {
				cout << "Enter valid duration please\n";
				cin >> duration;
			}
			hos.addPatient(name, age, disease, phone, duration);
			cout << "Adding Succeeded\n";
		}
		// Deleting Patient
		else if (op == 2) {
			if (hos.noPatient()) {
				cout << "There is no patient\n";
			}
			else {
				cout << "Enter the patient id\n"; // in case of string
				cin >> id;
				cout << "Enter the name\n";
				cin >> name;
				while (!hos.deletePatient(name, id)) {
					cout << "Not existed, Please enter valid name or id\n";
					cout << "Enter the patient id\n";
					cin >> id;
					cout << "Enter the name\n";
					cin >> name;
				}
				cout << "Deleteing Succeeded\n";
			}
		}
		// Searching for patient
		else if (op == 3) {
			if (hos.noPatient()) {
				cout << "There is no patient\n";
			}
			else {
				cout << "Enter the patient id\n"; // in case of string
				cin >> id;
				cout << "Enter the name\n";
				cin >> name;
				if (hos.isExist(name, id)) {
					cout << "Patient is existed\n";
				}
				else {
					cout << "Not existed\n";
				}
			}
		}
		// Updating patient's information
		else if (op == 4) {
			if (hos.noPatient()) {
				cout << "There is no patient\n";
			}
			else {
				cout << "Enter the patient id\n"; // in case of string
				cin >> id;
				cout << "Enter the name\n";
				cin >> name;
				cout << "Enter the mobile number you want to update\n";
				cin >> phone;
				while (!hos.updateInfo(name, id, phone)) {
					cout << "Not existed, Please enter valid name or id\n";
					cout << "Enter the patient id\n"; // in case of string
					cin >> id;
					cout << "Enter the name\n";
					cin >> name;
					cout << "Enter the mobile number you want to update\n";
					cin >> phone;
				}
				cout << "Updating Succeeded\n";
			}
		}
		// Displaying patient's information
		else if (op == 5) {
			if (hos.noPatient()) {
				cout << "There is no patient\n";
			}
			else {
				hos.retrieveInfo();
			}
		}
		// Accepting only valid operation number
		else if (op != -1) {
			cout << "Invalid operation\n";
		}
	}

	return 0;
}

