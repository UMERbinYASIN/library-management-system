#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
// global variables
int b, c, i = 0;
string a;
string username, password;

//structure
struct book
{
	string id;
	string title;
	string author;
	bool isborrowed = false;
};
//vector
vector<book> library;
book d;

//function declaration
void main_menu();
void loadbooksfromfile();
void login_path();
void librarian_login();
void addbook();
void display_all();
void search();
void borrow_book();
void return_book();
void view_borrow();
void delete_book();
void student_login();

//main function
int main()
{
	loadbooksfromfile();
	main_menu();

}
//user-defined function
void loadbooksfromfile()
{
	ifstream read("books.txt");
	if (!read)
	{
		cout << "Error! can't open file.";
		return;
	}
	string line;
	while (getline(read, line))
	{
		stringstream ss(line);

		string id, title, author, isborrowed;

		getline(ss, id, ',');
		getline(ss, title, ',');
		getline(ss, author, ',');
		getline(ss, isborrowed, ',');

		book b;
		b.id = id;
		b.title = title;
		b.author = author;
		b.isborrowed = (isborrowed == "1");
		library.push_back(b);
	}
	read.close();
}
//user_defined function
void main_menu()
{
	cout << endl << "\t\t\t\t*Library Management System*" << endl << endl;
	cout << "\t\t\t\t\t\t1. Librarian." << endl;
	cout << "\t\t\t\t\t\t2. Student." << endl;
	cout << "\t\t\t\t\t\t3. Exit." << endl;
	cout << "\t\t\t\t\t\tChoice: ";
	cin >> a;
	if (a == "1")
	{
		login_path();
	}
	else if (a == "2")
	{
		student_login();
	}
	else if (a == "3")
	{
		exit(0);
	}
	else
	{
		cout << "Error! You enter invalid input.";
		main_menu();
	}

}
//user_defined function
void login_path()
{
	cout << endl << "\t\t\t\t***********************  login  ***********************" << endl << endl;
	cout << "\t\t\t\t\t\tUsername: ";
	cin >> username;
	cout << "\t\t\t\t\t\tPassword: ";
	cin >> password;
	if (username == "admin" && password == "admin123")
	{
		librarian_login();
	}
	else if (username != "admin" || password != "admin123")
	{
		cout << "\t\t\t\t\t\tWrong credentials!." << endl;
		main_menu();
	}
}
//user_defined function
void librarian_login()
{
	cout << endl << "\t\t\t\t*Librarian Login*" << endl << endl;
	cout << "\t\t\t\t\t\t1. Add Book." << endl;
	cout << "\t\t\t\t\t\t2. Display All." << endl;
	cout << "\t\t\t\t\t\t3. Search." << endl;
	cout << "\t\t\t\t\t\t4. Borrow." << endl;
	cout << "\t\t\t\t\t\t5. Return." << endl;
	cout << "\t\t\t\t\t\t6. View Borrow." << endl;
	cout << "\t\t\t\t\t\t7. Delete." << endl;
	cout << "\t\t\t\t\t\t8. Exit." << endl;
	cout << "\t\t\t\t\t\tChoice: ";
	cin >> b;
	switch (b)
	{
	case 1:
		addbook();
		break;
	case 2:
		i = 1;
		display_all();
		break;
	case 3:
		i = 1;
		search();
		break;
	case 4:
		borrow_book();
		break;
	case 5:
		return_book();
		break;
	case 6:
		view_borrow();
		break;
	case 7:
		delete_book();
		break;
	case 8:
		main_menu();
		break;
	default:
		cout << "Error! you enter invalid input.";
	}

}
//user_defined function
void addbook()
{

	cout << "\t\t\t\t\t\tID: ";
	cin >> d.id;
	cin.ignore();
	cout << "\t\t\t\t\t\tTitle : ";
	getline(cin, d.title);
	cout << "\t\t\t\t\t\tAuthor : ";
	getline(cin, d.author);
	d.isborrowed = false;
	library.push_back(d);
	ofstream write("books.txt", ios::app);
	if (!write)
	{
		cout << "Error! file not found.";
		return;
	}
	write << d.id << "," << d.title << "," << d.author << "," << d.isborrowed << endl;
	write.close();
	cout << "\t\t\t\t\t\tBook added successfully! " << endl;
	librarian_login();
}
//user_defined function
void display_all()
{
	ifstream read("books.txt", ios::app);
	if (!read)
	{
		cout << "\t\t\t\t\t\tError! File is not opening";
		return;
	}
	string line;
	while (getline(read, line))
	{
		stringstream ss(line);
		string id, title, author, isborrowed;
		getline(ss, id, ',');
		getline(ss, title, ',');
		getline(ss, author, ',');
		getline(ss, isborrowed, ',');

		cout << "\t\t\t\t\t\tID : " << id << " , " << "Title : " << title << " , " << "Author : " << author << " , " << "Status : " << (isborrowed == "1" ? "Borrowed" : "Available") << endl;
	}
	read.close();
	if (i == 1)
	{
		librarian_login();
	}
	else if (i == 2)
	{
		student_login();
	}
}
//user_defined function
void search()
{
	int a;
	string c;
	cout << "\t\t\t\t\t\tPress 1. search by ID. " << endl << "\t\t\t\t\t\t Press 2. search by Title.";
	cin >> a;
	if (a == 1)
	{
		cout << "\t\t\t\t\t\t Enter ID : ";
		cin >> c;
		cin.ignore();
	}
	else
	{
		cout << "\t\t\t\t\t\tEnter Title : ";
		getline(cin, c);
	}
	ifstream read("books.txt");
	if (!read)
	{
		cout << "Error! File is not opening.";
		return;
	}
	string line;
	while (getline(read, line))
	{
		stringstream ss(line);
		string id, title, author, isborrowed;
		getline(ss, id, ',');
		getline(ss, title, ',');
		getline(ss, author, ',');
		getline(ss, isborrowed, ',');
		if (id == c || title == c)
		{
			cout << "\t\t\t\t\t\tID : " << id << " , " << "Title : " << title << " , " << "Author : " << author << " , " << "Status : " << (isborrowed == "1" ? "Borrowed" : "Available") << endl;

		}

	}
	read.close();
	if (i == 1)
	{
		librarian_login();
	}
	else if (i == 2)
	{
		student_login();
	}
}
//user_defined function
void borrow_book()
{
	string choice, input;
	cout << "\t\t\t\t\t\tPress 1. ID" << endl;
	cout << "\t\t\t\t\t\tPress 2. Title" << endl;
	cout << "\t\t\t\t\t\tChoice: ";
	cin.ignore();
	getline(cin, choice);

	if (choice == "1") {
		cout << "\t\t\t\t\t\tEnter ID : ";
		getline(cin, input);
	}
	else if (choice == "2") {
		cout << "\t\t\t\t\t\tEnter Title : ";
		getline(cin, input);
	}
	else {
		cout << "\t\t\t\t\t\tError! Invalid input." << endl;
		librarian_login();
		return;
	}

	// Read the entire file and prepare updated content
	ifstream read("books.txt");
	if (!read) {
		cout << "\t\t\t\t\t\tError! File not opening." << endl;
		return;
	}

	vector<string> updatedBooks;
	bool found = false;
	string line;

	while (getline(read, line)) {
		stringstream ss(line);
		string id, title, author, isborrowed;
		getline(ss, id, ',');
		getline(ss, title, ',');
		getline(ss, author, ',');
		getline(ss, isborrowed, ',');

		if ((choice == "1" && id == input) || (choice == "2" && title == input)) {
			found = true;
			if (isborrowed == "1") {
				cout << "\t\t\t\t\t\tBook is already borrowed." << endl;
			}
			else {
				isborrowed = "1";
				cout << "\t\t\t\t\t\tBook borrowed successfully!" << endl;
			}
		}

		updatedBooks.push_back(id + "," + title + "," + author + "," + isborrowed);
	}

	read.close();

	// Rewriting the entire file
	ofstream write("books.txt", ios::trunc); // <---- VERY IMPORTANT: ios::trunc clears the file before writing
	if (!write) {
		cout << "Error! Could not open file for writing." << endl;
		return;
	}

	for (const string& record : updatedBooks) {
		write << record << "\n";
	}

	write.close();
	librarian_login();
}


//user_defined function
void return_book()
{

	string choice, input;
	cout << "\t\t\t\t\t\tPress 1. ID" << endl;
	cout << "\t\t\t\t\t\tPress 2. Title" << endl;
	cout << "\t\t\t\t\t\tChoice: ";
	cin.ignore();
	getline(cin, choice);

	if (choice == "1") {
		cout << "\t\t\t\t\t\tEnter ID : ";
		getline(cin, input);
	}
	else if (choice == "2") {
		cout << "\t\t\t\t\t\tEnter Title : ";
		getline(cin, input);
	}
	else {
		cout << "\t\t\t\t\t\tError! Invalid input." << endl;
		librarian_login();
		return;
	}

	// Read the entire file and prepare updated content
	ifstream read("books.txt");
	if (!read) {
		cout << "\t\t\t\t\t\tError! File not opening." << endl;
		return;
	}

	vector<string> updatedBooks;
	bool found = false;
	string line;

	while (getline(read, line)) {
		stringstream ss(line);
		string id, title, author, isborrowed;
		getline(ss, id, ',');
		getline(ss, title, ',');
		getline(ss, author, ',');
		getline(ss, isborrowed, ',');

		if ((choice == "1" && id == input) || (choice == "2" && title == input)) {
			found = true;
			if (isborrowed == "0") {
				cout << "\t\t\t\t\t\tBook is not borrowed.It is available." << endl;
			}
			else {
				isborrowed = "0";

				cout << "\t\t\t\t\t\tStatus updated successfully!" << endl;
			}
		}

		updatedBooks.push_back(id + "," + title + "," + author + "," + isborrowed);
	}

	read.close();

	// Rewriting the entire file
	ofstream write("books.txt", ios::trunc); // <---- VERY IMPORTANT: ios::trunc clears the file before writing
	if (!write) {
		cout << "Error! Could not open file for writing." << endl;
		return;
	}

	for (const string& record : updatedBooks) {
		write << record << "\n";
	}

	write.close();
	librarian_login();
}

//user_defined function
void view_borrow()
{
	ifstream read("books.txt");
	if (!read)
	{
		cout << "\t\t\t\t\t\tError! File is not opening.";
		return;
	}
	string line;
	while (getline(read, line))
	{
		stringstream ss(line);
		string id, title, author, isborrowed;
		getline(ss, id, ',');
		getline(ss, title, ',');
		getline(ss, author, ',');
		getline(ss, isborrowed, ',');

		if (isborrowed == "1")
		{
			cout << "\t\t\t\t\t\tID : " << id << " , " << "Title : " << title << " , " << "Author : " << author << " , " << "Status : Borrowed" << endl;
		}
	}
	read.close();
	librarian_login();
}
//user_defined function
void delete_book()
{

	string choice, input;
	cout << "\t\t\t\t\t\tPress 1. ID" << endl;
	cout << "\t\t\t\t\t\tPress 2. Title" << endl;
	cout << "\t\t\t\t\t\tChoice: ";
	cin.ignore();
	getline(cin, choice);

	if (choice == "1") {
		cout << "\t\t\t\t\t\tEnter ID : ";
		getline(cin, input);
	}
	else if (choice == "2") {
		cout << "\t\t\t\t\t\tEnter Title : ";
		getline(cin, input);
	}
	else {
		cout << "\t\t\t\t\t\tError! Invalid input." << endl;
		librarian_login();
		return;
	}

	// Read the entire file and prepare updated content
	ifstream read("books.txt");
	if (!read) {
		cout << "\t\t\t\t\t\tError! File not opening." << endl;
		return;
	}

	vector<string> updatedBooks;
	string line;

	while (getline(read, line)) {
		stringstream ss(line);
		string id, title, author, isborrowed;
		getline(ss, id, ',');
		getline(ss, title, ',');
		getline(ss, author, ',');
		getline(ss, isborrowed, ',');
		int found = 1;
		if ((choice == "1" && id == input) || (choice == "2" && title == input))
		{
			cout << "\t\t\t\t\t\tBook deleted successfully!";
			found = 0;
		}
		if (found == 1)
		{
			updatedBooks.push_back(id + "," + title + "," + author + "," + isborrowed);
		}
	}

	read.close();

	// Rewriting the entire file
	ofstream write("books.txt", ios::trunc); // <---- VERY IMPORTANT: ios::trunc clears the file before writing
	if (!write) {
		cout << "Error! Could not open file for writing." << endl;
		return;
	}

	for (const string& record : updatedBooks) {
		write << record << "\n";
	}

	write.close();
	librarian_login();


}
//user_defined function
void student_login()
{
	cout << endl << "\t\t\t\t**Student Login" << endl << endl;
	cout << "\t\t\t\t\t\t1. search." << endl;
	cout << "\t\t\t\t\t\t2. Display All." << endl;
	cout << "\t\t\t\t\t\t3. Exit." << endl;
	cout << "\t\t\t\t\t\tChoice: ";
	cin >> c;
	switch (c)
	{
	case 1:
		i = 2;
		search();
		break;
	case 2:
		i = 2;
		display_all();
		break;
	case 3:
		main_menu();
		break;
	default:
		cout << "Error! You enter invalid input.";
	}

}