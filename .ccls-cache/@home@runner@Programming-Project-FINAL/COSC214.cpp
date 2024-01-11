// Created by Donovan Faucette and Alexis Lopez.
// Last Modified: 5/16/2023.

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct Node { // Node Structure
    string fName, lName; // fName and lName are the first and last names of the person.
    int id; // id is the id of the person.
    double gpa; // gpa is the gpa of the person.
    string pNumber; // pNumber is the phone number of the person.
    Node* next; // next is the next node in the list.
};

Node* head = nullptr; // We initialize the head as nullptr.

void createList(string fNameFile, string lNameFile, string IDFile, string GPAFile, string pNumbersFile) { // This function creates a list from the files.
    ifstream fNameIn(fNameFile); // We open the file.
    ifstream lNameIn(lNameFile); // We open the file.
    ifstream IDIn(IDFile); // We open the file.
    ifstream GPAIn(GPAFile); // We open the file.
    ifstream pNumbersIn(pNumbersFile); // We open the file.
    if (fNameIn.is_open() && lNameIn.is_open() && IDIn.is_open() &&
        GPAIn.is_open() && pNumbersIn.is_open()) { // If the files are open.
        string fName, lName, pNumber; // Create the following variables.
        int id;
        double gpa;
        while (fNameIn >> fName && lNameIn >> lName && IDIn >> id &&
            GPAIn >> gpa && pNumbersIn >> pNumber) { // While there are lines in the files.
            Node* newNode = new Node; // Create a new node.
            newNode->fName = fName; // Set the first name.
            newNode->lName = lName; // Set the last name.
            newNode->id = id; // Set the id.
            newNode->gpa = gpa; // Set the gpa.
            newNode->pNumber = pNumber; // Set the phone number.
            newNode->next = nullptr; // Set the next node to nullptr.

            if (head == nullptr) { // If the head is nullptr.
                head = newNode; // Set the head to the new node.
            }
            else {
                Node* current = head; // Set the current node to the head.
                while (current->next != nullptr) { // While the current node is not nullptr.
                    current = current->next; // Set the current node to the next node.
                }
                current->next = newNode; // Set the next node to the new node.
            }
        }
        fNameIn.close(); // Close the file.
        lNameIn.close();// Close the file.
        IDIn.close(); // Close the file.
        GPAIn.close(); // Close the file.
        pNumbersIn.close(); // Close the file.
        cout << "Data inserted successfully." << endl;
    }
    else {
        cout << "Unable to open file." << endl;
    }
}


void deletion(int id) { // This function deletes a person from the list
    if (head == nullptr) { // If the head is nullptr, then there is no person to delete.
        return;
    }
    if (head->id == id) { // If the head is the person to delete.
        Node* temp = head; // Set the temp node to the head.
        head = head->next; // Set the head to the next node.
        delete temp; // Delete the temp node.
        return;
    }
    Node* current = head; // Set the current node to the head.
    while (current->next != nullptr && current->next->id != id) { // While the current node is not nullptr and the current node is not the person to delete.
        current = current->next; // Set the current node to the next node.
    }
    if (current->next == nullptr) { // If the current node is the person to delete.
        cout << "Student with ID " << id << " not found." << endl;
        return;
    }
    Node* temp = current->next; // Set the temp node to the next node.
    current->next = temp->next; // Set the next node to the next node.
    delete temp; // Delete the temp node.
    cout << "Student with ID# " << id << " deleted." << endl;
}


void insert(string firstn, string lastn, int studentid, double grade, string phone) {
    Node* newNode = new Node; //Set the current node to the head
    newNode->fName = firstn; //Set the first name
    newNode->lName = lastn; // Set the last name
    newNode->id = studentid; //Set the ID
    newNode->gpa = grade; //Set the grade
    newNode->pNumber = phone; //Set the phone number
    newNode->next = nullptr; //Set the next node to nullptr

    if (head == nullptr) { //If head is nullptr
        head = newNode; //Set the head to newNode
    }
    else {
        Node* temp = head; //Set the current head to temp
        while (temp->next != nullptr) { // While the current node is not nullptr
            temp = temp->next; //set the current node to the next node
        }
        temp->next = newNode; // Set the next node to the new node
    }
    cout << "Student successfully added." << endl;
}


void search() { // This function searches for a person in the list
    int id;
    cout << "Welcome to the Student Information Search System for Bowie State University. " << endl;
    cout << "To search for a student, please enter the five-digit ID number: " << endl;
    cin >> id; // Set the id to the cin.

    Node* current = head; // Set the current node to the head.
    while (current != nullptr) { // While the current node is not nullptr.
        if (current->id == id) { // If the current node is the person to search for.
            cout << "Student found: " << endl;
            cout << "ID: " << current->id << endl;
            cout << "Full name: " << current->fName << " " << current->lName << endl;
            cout << "GPA: " << current->gpa << endl;
            cout << "Phone number: " << current->pNumber << endl;
            return;
        }
        current = current->next; // Set the current node to the next node.
    }
    cout << "Student with ID# " << id << " not found in database." << endl;
}

void honorStudents() { // This function prints the honor students
    int count = 0; // Set the count to 0.
    cout << "The list of honor students are " << endl;
    Node* current = head; // Set the current node to the head.
    while (current != nullptr) { // While the current node is not nullptr.
        if (current->gpa >= 3.6) { // If the current node is the honor student.
            cout << "Student list: " << endl;
            cout << "ID: " << current->id << ", ";
            cout << "Full Name: " << current->fName << " " << current->lName << ", ";
            cout << "GPA: " << current->gpa << ", ";
            cout << "Phone Number: " << current->pNumber << endl;
            count++; // Increment the count by 1.
        }
        current = current->next; // Set the current node to the next node.
    }
    cout << "The number of students with honor are " << count << endl;
}

void warnStudents() { // This function prints the warning students
    int count = 0; // Set the count to 0.
    cout << "These are the students that are failing: " << endl;
    Node* current = head; // Set the current node to the head.
    while (current != nullptr) { // While the current node is not nullptr.
        if (current->gpa <= 2.0) { // If the current node is the warning student.
            cout << "Student list: " << endl;
            cout << "ID: " << current->id << ", ";
            cout << "Full Name: " << current->fName << " " << current->lName << ", ";
            cout << "GPA: " << current->gpa << ", ";
            cout << "Phone Number: " << current->pNumber << endl;
            count++; // Increment the count by 1.
        }
        current = current->next; // Set the current node to the next node.
    }
    cout << "The number of students are " << count << endl;
}


void print() { // This function prints the list.
    int count = 0; // Set the count to 0.
    Node* current = head; // Set the current node to the head.
    while (current != nullptr) { // While the current node is not nullptr.     
        cout << "Student list: " << endl;
        cout << "ID: " << current->id << ", ";
        cout << "Full Name: " << current->fName << " " << current->lName << ", ";
        cout << "GPA: " << current->gpa << ", ";
        cout << "Phone Number: " << current->pNumber << endl;
        current = current->next;
        count++; // Increment the count by 1.
    }
    cout << "The number of students in the class are " << count << endl;
}


void displayMenu() {
    
        cout << "Welcome to the Student Information System for Bowie State University." << endl;
        cout << "Please select an option:(c)reateList, (i)nsert, (d)elete, (s)earch, (h)onorStudents, (w)arnStudents, (p)rint, (q)uit . Please make sure to be case-sensitive." << endl;
        char choice;
        cin >> choice;
        if (choice == 'c') {
            cout << "Welcome to the Bowie State University List System." << endl;
            cout << "This database only accepts txt files for creating the list of data." << endl;
            cout << "Please enter the file name or path for the following fields, please include .txt at the end of your file name, remember to be sure of case-sensitive: " << endl;
            string fNameFile, lNameFile, IDFile, GPAFile, pNumbersFile;
            cout << "fName file: ";
            cin >> fNameFile;
            cout << "lName file: ";
            cin >> lNameFile;
            cout << "ID file: ";
            cin >> IDFile;
            cout << "GPA file: ";
            cin >> GPAFile;
            cout << "pNumbers file: ";
            cin >> pNumbersFile;
            cout << "Inserting data.." << endl;
            createList(fNameFile, lNameFile, IDFile, GPAFile, pNumbersFile);
            cout << "Done." << endl;
        }
        else if (choice == 'd') {
            cout << "Welcome to the Bowie State University Deletion System." << endl;
            cout << "Please enter the ID of the student you would like to delete: " << endl;
            int id;
            cin >> id;
            deletion(id);
        }
        else if (choice == 'h') {
            honorStudents();
        }
        else if (choice == 'w') {
            warnStudents();
        }
        else if (choice == 'q') {
            cout << "Thank you for using the Bowie State University Student Information System, goodbye.";
            exit(0);
        }
        else if (choice == 's') {
            search();
        }
        else if (choice == 'p') {
            print();
        }
        else if (choice == 'i') {
            cout << "Welcome to the Bowie State University Insertion System" << endl;
            cout << "Please enter the following " << endl;
            string firstn, lastn, phone;
            int id;
            double gpa;
            cout << "First name: ";
            cin >> firstn;
            cout << "Last name: ";
            cin >> lastn;
            cout << "Student ID: ";
            cin >> id;
            cout << "GPA (Please make sure to enter as a decimal: 3.2, 1.0, 2.3): ";
            cin >> gpa;
            cout << "Phone Number (Add dashes inbetween the number to fully register the number: 301-312-3319): ";
            cin >> phone;
            cout << "Inserting Data..." << endl;
            insert(firstn, lastn, id, gpa, phone);
        }
        cout << "Returning to main menu.\n" << endl;
        displayMenu();
    }
   
int main() {
    displayMenu();
    return 0;
}