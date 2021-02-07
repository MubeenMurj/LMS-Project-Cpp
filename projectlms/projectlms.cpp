#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>

using namespace std;

#define UNDERLINE "\033[4m"
#define CLOSEUNDERLINE "\033[0m"


//	STRUCTURES
struct Book
{
	char book_name[100];
	int ISBN;
	char author_name[100];
	int no_of_copies;
	string date_of_issue;
	char publisher_name[100];
};
struct User
{
	char user_name[100];
	int user_id;
	char user_L_name[100];
	string date_brith;
	string student = "Student";
	string Empolyer = "Empolyer";
};
struct BookIssue
{
	char book_name[100];
	int isbn;
	int user_id;
	char book_author[100];
	char user_name[100];
	char user_L_name[100];

};


//	DECLARING FUNCTIONS
void menu();
void bookAdd();
void bookList();
void bookEdit();
void bookDelete();
void bookSearch();
void userAdd();
void userList();
void userDelete();
void userEdit();
void issueBook();
void issueBookDelete();
void userSearch();
void issueBookList();
void deleteData();


int main()
{
	menu();
}
void menu()
{
	Book obj;
	User obj1;
	BookIssue obj3;

	system("cls");
	int i, j, k;
	i = j = k = 0;

	//    Here while loop is use to represent the data in file means total number of books etc

	ifstream filedata("book_data.txt");
	while (filedata >> obj.ISBN >> obj.book_name >> obj.author_name >> obj.publisher_name >> obj.date_of_issue >> obj.no_of_copies)
	{
		i++;
	}
	filedata.close();

	ifstream user("library_user.txt ");
	while (user >> obj1.user_id >> obj1.user_name >> obj1.user_L_name >> obj1.Empolyer >> obj1.date_brith)
	{
		j++;
	}
	user.close();

	ifstream iss("issue_books.txt");
	while (iss >> obj3.isbn >> obj3.book_name >> obj3.user_id >> obj3.user_name >> obj3.user_L_name)
	{
		k++;
	}
	iss.close();


	cout << endl << UNDERLINE << "Library Mangemanent System" << CLOSEUNDERLINE << endl;
	cout << "Press option key to activate that function  " << endl << endl << endl;
	cout << "\t0   To view all book" << endl;
	cout << "\t1   Add New Book " << "( Total # of books = " << i << " )" << endl;
	cout << "\t2   Edit Book" << endl;
	cout << "\t3   Delete Book " << endl;
	cout << "\t4   Search Book " << endl;
	cout << "\t5   Add Library User  " << "(Total # of user = " << j << " )" << endl;
	cout << "\t6   View all Library User" << endl;
	cout << "\t7   Edit Library User" << endl;
	cout << "\t8   Delete Library User" << endl;
	cout << "\t9   Search Library User" << endl;
	cout << "\t10  Issue Book " << "( Total # of issue books = " << k << " )" << endl;
	cout << "\t11  Delete Issued Book " << endl;
	cout << "\t12  View all Issused books " << endl;
	cout << "\t13  Delete All Data ( reset ) " << endl;
	cout << "\t14  Exit from program" << endl << endl << endl;
	i = j = k = 0;

	int sel;
	cout << "Enter Your Choice ! " << endl;
	cin >> sel;
	while (sel < 0 || sel > 14)
	{
		cout << "WRONG SELECTION, PLEASE SELECT AGAIN" << endl;
		cin >> sel;
	}
	switch (sel)
	{
	case 0:
		bookList();
		break;
	case 1:
		bookAdd();
		break;
	case 2:
		bookEdit();
		break;
	case 3:
		bookDelete();
		break;
	case 4:
		bookSearch();
		break;
	case 5:
		userAdd();
		break;
	case 6:
		userList();
		break;
	case 7:
		userEdit();
		break;
	case 8:
		userDelete();
		break;
	case 9:
		userSearch();
		break;
	case 10:
		issueBook();
		break;
	case 11:
		issueBookDelete();
		break;
	case 12:
		issueBookList();
		break;
	case 13:
		deleteData();
		break;
	case 14:
		exit(0);
		break;
	}
}

void bookAdd()
{
loop:
	char ch;
	Book obj, abj;
	system("cls");
	system("color 31");
	bool flag = false;
	cout << endl << UNDERLINE << "Library Mangemanent System" << CLOSEUNDERLINE << endl;
	ifstream oldfile("book_data.txt");
	cout << "Enter book name :\t";
	cin >> obj.book_name;
	cout << "Enter  ISBN number :\t";
	cin >> obj.ISBN;
	cout << "Enter Author name :\t";
	cin >> obj.author_name;
	cout << "Enter publisher name :\t";
	cin >> obj.publisher_name;
	cout << "Enter Year of publish : \t";
	cin >> obj.date_of_issue;
	cout << "Enter Totals number of copies :\t";
	cin >> obj.no_of_copies;

	while (oldfile >> abj.ISBN >> abj.book_name >> abj.author_name >> abj.publisher_name >> abj.date_of_issue >> abj.no_of_copies)
	{
		if (obj.ISBN == abj.ISBN)
		{
			flag = true;
		}
	}
	oldfile.close();

	cout << endl << endl << endl;
	cout << endl << endl << "Do want to save book information Y/N" << endl;
	cin >> ch;
	if (ch == 'y' || ch == 'Y') {
		if (flag == true)
		{
			cout << "The book with this ISBN is already exist so this data is not added" << endl;
		}
		else if (flag != true) {
			ofstream myfile("book_data.txt", ios::app);
			myfile << obj.ISBN << "\t" << obj.book_name << "\t" << obj.author_name << "\t" << obj.publisher_name << "\t" << obj.date_of_issue << "\t" << obj.no_of_copies << endl;
			myfile.close();
			cout << "The book is not dublicate " << endl;
			cout << "\nThe book information is successfully added" << endl;
		}
		cout << "\n\nPress Y to add more book or N to go main menu " << endl;
		cin >> ch;
		flag = false;
		if (ch == 'y' || ch == 'Y')
			goto loop;
		if (ch == 'n' || ch == 'N')
			menu();
	}
	if (ch == 'n' || ch == 'N')
	{
		cout << "\nThe book data is not added " << endl;
		cout << "\n\nPress Y to add new book or N to go main menu " << endl;
		cin >> ch;
		if (ch == 'y' || ch == 'Y')
			goto loop;
		if (ch == 'n' || ch == 'N')
			menu();
	}

}
void bookList()
{
	system("cls");
	system("color 46");
	Book obj;
	cout << endl << UNDERLINE << "Library Mangemanent System" << CLOSEUNDERLINE << endl;
	cout << "\n\n\tALL BOOKS" << endl << endl;
	cout << "ISBN   |  " << "Book_name    | " << "Author_name   | " << "Publisher_name   | " << "Year_of_publish     | " << "Total coppies #  | " << endl << endl;
	ifstream filedata("book_data.txt");

	while (filedata >> obj.ISBN >> obj.book_name >> obj.author_name >> obj.publisher_name >> obj.date_of_issue >> obj.no_of_copies)
	{
		cout << obj.ISBN << "\t| " << obj.book_name << "\t|  " << obj.author_name << "\t |  " << obj.publisher_name << "\t| " << obj.date_of_issue << "\t | " << obj.no_of_copies << endl;
	}
	filedata.close();

	int ch;
	cout << "\n\n\nPress 0 to go back or want to want new book Press 1 " << endl;
	cin >> ch;
	if (ch == 0)
		menu();
	if (ch == 1)
		bookAdd();

}
void bookEdit()
{
	bool flag;
	system("cls");
	system("color 57");
	cout << endl << UNDERLINE << "Library Mangemanent System" << CLOSEUNDERLINE << endl;
loop:
	int ch;
	Book obj;
	int isbn;
	char bookname[100];
	cout << "Press option to access book by its \t(1). By ISBN \t (2). By name" << endl;
	cin >> ch;
	if (ch == 1) {
		cout << "Enter book ISBN " << endl;
		cin >> isbn;
	}
	if (ch == 2) {
		cout << "Enter book name " << endl;
		cin >> bookname;
	}
	ifstream myfile("book_data.txt");  //note name must be same
	ofstream newfile("new.txt");

	while (myfile >> obj.ISBN >> obj.book_name >> obj.author_name >> obj.publisher_name >> obj.date_of_issue >> obj.no_of_copies)
	{
		if (isbn == obj.ISBN || strcmp(bookname, obj.book_name) == 0)
		{
			cout << "Enter book new name :\t";
			cin >> obj.book_name;
			cout << "Enter  ISBN new number :\t";
			cin >> obj.ISBN;
			cout << "Enter Author name :\t";
			cin >> obj.author_name;
			cout << "Enter publisher name :\t";
			cin >> obj.publisher_name;
			cout << "Enter date of published : \t";
			cin >> obj.date_of_issue;
			cout << "Enter Totals number of copies :\t";
			cin >> obj.no_of_copies;
			flag = true;

		}
		newfile << obj.ISBN << "\t" << obj.book_name << "\t" << obj.author_name << "\t" << obj.publisher_name << "\t" << obj.date_of_issue << "\t" << obj.no_of_copies << endl;

	}

	if (flag == true) {
		newfile.close();
		myfile.close();
		if (remove("book_data.txt") != 0) {
			cout << "File not removed " << endl;
		}
		else if (rename("new.txt", "book_data.txt") != 0) {
			cout << "file not renamed " << endl;
		}
		else {
			cout << "The book data is successfully Edited" << endl << endl << "Press 0 to go back to main menu OR Press 1  to edit other book" << endl;
			cin >> ch;
			if (ch == 0)
				menu();
			if (ch == 1)
				goto loop;
		}
	}
	if (flag != true)
	{
		cout << "The data against this book is not found" << endl;
		cout << "Not edited succefully edited" << endl << "Press 0 to go back to main menu OR Press 1  to edit other book" << endl;
		cin >> ch;
		if (ch == 0)
			menu();
		if (ch == 1)
			goto loop;
	}
}
void bookDelete()
{

loop:
	system("cls");
	system("color 43");
	cout << endl << UNDERLINE << "Library Mangemanent System" << CLOSEUNDERLINE << endl;
	int ch;
	bool flag = false;
	Book obj;
	int isbn;
	char s1[100];
	char book_n[100];
	cout << "Press option to access book by its \t(1). By ISBN \t (2). By name" << endl;
	cin >> ch;
	if (ch == 1) {
		cout << "Enter book ISBN " << endl;
		cin >> isbn;
	}
	if (ch == 2) {
		cout << "Enter book name " << endl;
		cin >> s1;
	}
	ifstream myfile("book_data.txt");  //note name must be same
	ofstream newfile("new.txt");
	while (myfile >> obj.ISBN >> obj.book_name >> obj.author_name >> obj.publisher_name >> obj.date_of_issue >> obj.no_of_copies)
	{
		if (isbn != obj.ISBN)
		{
			newfile << obj.ISBN << "\t" << obj.book_name << "\t" << obj.author_name << "\t" << obj.publisher_name << "\t" << obj.date_of_issue << "\t" << obj.no_of_copies << endl;
		}
		if (isbn == obj.ISBN)
		{
			flag = true;
		}

	}

	if (flag != true)
	{
		cout << "The data against this book is not found" << endl << "Press 0 to go back to main menu OR Press 1  to edit other book" << endl;
		cin >> ch;
		if (ch == 0)
			menu();
		if (ch == 1)
			goto loop;
	}
	else {
		newfile.close();
		myfile.close();
		if (remove("book_data.txt") != 0)
			cout << "File not removed " << endl;
		if (rename("new.txt", "book_data.txt") != 0)

			cout << "file not renamed " << endl;
		else {
			cout << "The book data is successfully Deleted" << endl << endl << "Press 0 to go back to main menu OR Press 1  to edit other book" << endl;
			cin >> ch;
			if (ch == 0)
				menu();
			if (ch == 1)
				goto loop;
		}
	}

}
void bookSearch()
{
loop:
	bool flag = false;
	system("cls");
	system("color 69");
	cout << endl << UNDERLINE << "Library Mangemanent System" << CLOSEUNDERLINE << endl;
	int ch;
	Book obj;
	int isbn;
	char s1[100];
	char book_n[100];
	cout << "Press option to access book by its \n\t(1). By ISBN \n\t (2). By name" << endl;
	cin >> ch;
	if (ch == 1) {
		cout << "Enter book ISBN " << endl;
		cin >> isbn;
	}
	if (ch == 2) {
		cout << "Enter book name " << endl;
		cin >> s1;
	}
	ifstream myfile("book_data.txt");  //note name must be same
	while (myfile >> obj.ISBN >> obj.book_name >> obj.author_name >> obj.publisher_name >> obj.date_of_issue >> obj.no_of_copies)
	{
		if (isbn == obj.ISBN || strcmp(obj.book_name, s1) == 0)
		{
			flag = true;
			cout << "ISBN\t" << "Book_name\t" << "Author_name\t" << "Publisher_name\t" << "Year_of_publish\t" << "Total coppies # " << endl << endl;
			cout << obj.ISBN << "\t\t" << obj.book_name << "\t" << obj.author_name << "\t" << obj.publisher_name << "\t" << obj.date_of_issue << "\t" << obj.no_of_copies << endl;
		}
	}
	myfile.close();
	if (flag == false)
	{
		cout << "The data against this book is not found" << endl << endl;
	}

	cout << endl << endl << "Press 0 to go back to main menu OR Press 1  to search again book" << endl;
	cin >> ch;
	if (ch == 0)
		menu();
	if (ch == 1)
		goto loop;

}
void userAdd()
{
loop1:

	system("cls");
	system("color 71");
	cout << endl << UNDERLINE << "Library Mangemanent System" << CLOSEUNDERLINE << endl;
	int pass = 12345;
	int word;
	cout << "Enter password Keys to add user \nOr Enter 0 To Go To Main Menu " << endl;
	cin >> word;
	if (word == 0)
		menu();
	if (pass == word)
	{
	loop:
		bool flag = false;

		int ch;
		User obj, abj;
		cout << "(1). for student" << endl << "(2). for Empolyer" << endl;
		cin >> ch;
		if (ch == 1)
		{
			system("cls");
			cout << endl << UNDERLINE << "Library Mangemanent System" << CLOSEUNDERLINE << endl;
			ifstream datafile("library_user.txt");
			cout << "Please enter requried information " << endl << endl;
			cout << "Enter Student first name :  \t";
			cin >> obj.user_name;
			cout << "Enter Student Last name : \t ";
			cin >> obj.user_L_name;
			cout << "Enter Library ID : \t";
			cin >> obj.user_id;
			cout << "Enter student Age :\t";
			cin >> obj.date_brith;
			while (datafile >> abj.user_id >> abj.user_name >> abj.user_L_name >> abj.student >> abj.date_brith)
			{
				if (abj.user_id == obj.user_id)
				{
					flag = true;
				}
			}
			datafile.close();
			if (flag != true)
			{
				ofstream library_user("library_user.txt", ios::app);
				library_user << obj.user_id << "\t" << obj.user_name << " " << obj.user_L_name << "\t" << obj.student << "\t" << obj.date_brith << endl;
				library_user.close();
				cout << "The user has successfully added" << endl;
			}
			if (flag == true)
			{
				cout << "The against this ID is already Exist " << "\tThe data is not added" << endl;
			}
			cout << "\n\nPress (1) to add again  or press (0) to go back to main menu" << endl;
			cin >> ch;
			if (ch == 1)
				goto loop;
			if (ch == 0)
				menu();
		}
		else if (ch == 2)
		{
			flag = false;

			system("cls");
			cout << endl << UNDERLINE << "Library Mangemanent System" << CLOSEUNDERLINE << endl;
			ifstream datafile("library_user.txt");

			cout << "Please enter requried information " << endl << endl;
			cout << "Enter Employer first name :  \t";
			cin >> obj.user_name;
			cout << "Enter Employer Last name : \t ";
			cin >> obj.user_L_name;
			cout << "Enter Library ID : \t";
			cin >> obj.user_id;
			cout << "Enter Employer Age :\t";
			cin >> obj.date_brith;
			while (datafile >> abj.user_id >> abj.user_name >> abj.student >> abj.date_brith)
			{
				if (abj.user_id == obj.user_id)
				{
					flag = true;
				}
			}
			datafile.close();
			if (flag != true)
			{
				ofstream library_user("library_user.txt", ios::app);
				library_user << obj.user_id << "\t" << obj.user_name << " " << obj.user_L_name << "\t" << obj.Empolyer << "\t" << obj.date_brith << endl;
				library_user.close();
				cout << "The user has successfully added" << endl;
			}
			if (flag == true)
			{
				cout << "The against this ID is already Exist " << "\tThe data is not added" << endl;
			}
			flag = false;
			cout << "\n\nPress (1) to add again  or press (0) to go back to main menu" << endl;
			cin >> ch;
			if (ch == 1)
				goto loop;
			if (ch == 0)
				menu();

		}
	}
	else if (word != pass)
	{
		cout << "You have Enter incorrect password \n Enter again OR Enter 0 to go back to main menu" << endl;
		goto loop1;
	}
}
void userList()
{
	system("cls");
	system("color 3F");
	int pass = 12345;
	User obj;
	int word;
	cout << endl << UNDERLINE << "Library Mangemanent System" << CLOSEUNDERLINE << endl;
	cout << "Enter password Keys to View all user " << endl;
loop1:
	cin >> word;
	if (pass == word) {
		system("cls");
		cout << endl << UNDERLINE << "Library Mangemanent System" << CLOSEUNDERLINE << endl;
		ifstream user("library_user.txt ");
		cout << " ID#\t\t" << "Name\t\t" << "Last Name" << "Student or Empolyer\t" << "Age#\t" << endl << endl;
		while (user >> obj.user_id >> obj.user_name >> obj.user_L_name >> obj.Empolyer >> obj.date_brith)
		{
			cout << obj.user_id << "\t\t" << obj.user_name << "   " << obj.user_L_name << "\t\t" << obj.Empolyer << "\t\t" << obj.date_brith << endl;
		}
		user.close();
		int ch;
		cout << "\n\n\nPress 0 to go back or want to add new user Press 1 " << endl;
		cin >> ch;
		if (ch == 0)
			menu();
		if (ch == 1)
			userAdd();

	}
	else if (pass != word)
	{
		system("cls");
		cout << "You have Enter incorrect password \n Enter again OR Enter 0 to go back to main menu" << endl;
		goto loop1;
	}
}
void userDelete()
{
	system("cls");
	system("color 8F");
	int pass = 12345;
	User obj;

	int word;
	cout << endl << UNDERLINE << "Library Mangemanent System" << CLOSEUNDERLINE << endl;
	cout << "Enter password Keys to Delete user " << endl;
loop1:
	cin >> word;
	if (word == 0)
		menu();
	if (pass == word) {
		system("cls");
		bool flag = false;
		cout << endl << UNDERLINE << "Library Mangemanent System" << CLOSEUNDERLINE << endl;
		int user_id;
		cout << "Please Enter user id which you want remove user" << endl;
		cin >> user_id;
		ifstream user("library_user.txt ");
		ofstream newfile("new.txt");
		while (user >> obj.user_id >> obj.user_name >> obj.user_L_name >> obj.Empolyer >> obj.date_brith)
		{
			if (obj.user_id != user_id)
			{
				newfile << obj.user_id << "\t" << obj.user_name << "   " << obj.user_L_name << "\t" << obj.Empolyer << "\t" << obj.date_brith << endl;
			}
			if (obj.user_id == user_id)
			{
				flag = true;

			}
		}
		newfile.close();
		user.close();
		if (remove("library_user.txt") != 0)
			cout << "File not removed " << endl;
		else if (rename("new.txt", "library_user.txt") != 0)

			cout << "file not renamed " << endl;


		if (flag == true)
		{
			cout << "The Data of this is succeefully deleted" << endl;
		}
		if (flag != true)
		{
			cout << "The record against this data is not found" << endl;
		}
		int ch;

		cout << "\n\n\nPress 0 to go back or want to want new User Press 1 " << endl;
		cin >> ch;
		if (ch == 0)
			menu();
		if (ch == 1)
			userAdd();

	}

	else if (pass != word)
	{

		cout << "You have Enter incorrect password \n Enter again OR Enter 0 to go back to main menu" << endl;
		goto loop1;
	}
}
void userSearch()
{
loop:
	system("cls");
	system("color 64");
	cout << endl << UNDERLINE << "Library Mangemanent System" << CLOSEUNDERLINE << endl;
	int ch;
	bool flag = false;
	User obj;
	int id;
	char s1[100];
	char book_n[100];
	cout << "Press option to delete user by its \n\t(1). By ID \n\t(2). By name" << endl;
	cin >> ch;
	if (ch == 1) {
		cout << "Enter User iD " << endl;
		cin >> id;
	}
	if (ch == 2) {
		cout << "Enter user name " << endl;
		cin >> s1;
	}
	ifstream myfile("library_user.txt");  //note name must be same
	while (myfile >> obj.user_id >> obj.user_name >> obj.user_L_name >> obj.Empolyer >> obj.date_brith)
	{
		if (id == obj.user_id)
		{
			cout << " ID#\t\t" << "Name\t\t" << "Student or Empolyer\t" << "Age#\t" << endl << endl;
			cout << obj.user_id << "\t\t" << obj.user_name << "   " << obj.user_L_name << "\t\t" << obj.Empolyer << "\t\t" << obj.date_brith << endl;
			flag = true;
		}
	}
	myfile.close();
	if (flag != true)
	{
		cout << "The record against this data is not found " << endl;
	}
	cout << endl << endl << "Press 0 to go back to main menu OR Press 1  to search again book" << endl;
	cin >> ch;
	if (ch == 0)
		menu();
	if (ch == 1)
		goto loop;
}
void userEdit()
{
	system("cls");
	system("color 47");
	int pass = 12345;
	User obj;
	int word;
	cout << endl << UNDERLINE << "Library Mangemanent System" << CLOSEUNDERLINE << endl;
	cout << "Enter password Keys to Edit user " << endl;
	cin >> word;
	bool flag = false;
	if (pass == word) {
		system("cls");
		cout << endl << UNDERLINE << "Library Mangemanent System" << CLOSEUNDERLINE << endl;
		int user_id;
		cout << "Please Enter user id which you want edit user" << endl;
		cin >> user_id;
		ifstream user("library_user.txt ");
		ofstream newfile("new.txt");
		string student = "Student";
		while (user >> obj.user_id >> obj.user_name >> obj.user_L_name >> obj.Empolyer >> obj.date_brith)
		{
			if (obj.user_id == user_id)
			{
				flag = true;
				cout << "Enter  new first name :  \t";
				cin >> obj.user_name;
				cout << "Enter Last new name : \t ";
				cin >> obj.user_L_name;
				cout << "Enter Library new ID : \t";
				cin >> obj.user_id;
				cout << "Enter new Age :\t";
				cin >> obj.date_brith;
			}
			newfile << obj.user_id << "\t" << obj.user_name << "   " << obj.user_L_name << "\t" << obj.Empolyer << "\t" << obj.date_brith << endl;

		}
		newfile.close();
		user.close();
		if (flag != true)
		{
			cout << "The record this Data is not found" << endl;
		}
		if (remove("library_user.txt") != 0)
			cout << "File not removed " << endl;
		else if (rename("new.txt", "library_user.txt") != 0)
			cout << "file not renamed " << endl;
		else {
			cout << "The User data is succeefully Updated" << endl << endl;
			int ch;
			cout << "\n\n\nPress 0 to go back or want to see all User Press 1 " << endl;
			cin >> ch;
			if (ch == 0)
				menu();
			if (ch == 1)
				userList();
		}
	}
	else if (pass != word)
	{

		cout << "You have Enter incorrect password \n Enter again OR Enter 0 to go back to main menu" << endl;
		cin >> word;
		if (word == 0)
			menu();
	}
}
void issueBook()
{

	system("cls");
	system("color 74");
	cout << endl << UNDERLINE << "Library Mangemanent System" << CLOSEUNDERLINE << endl;
	int USER_ID;
loop:
	cout << "Enter user ID to issue book or Enter 0 to goback:\t";
	cin >> USER_ID;
	User obj;
	if (USER_ID == 0)
	{
		menu();
	}
	bool flag = false;
	ifstream user("library_user.txt");
	while (user >> obj.user_id >> obj.user_name >> obj.user_L_name >> obj.Empolyer >> obj.date_brith)
	{
		if (USER_ID == obj.user_id)
		{
			flag = true;
			break;
		}
	}
	user.close();
	if (flag != true)
	{
		cout << "The data against this ID is not found" << endl;
		goto loop;
	}
	if (flag == true)
	{
		bool flag2 = false;
		Book books;
		cout << "ISBN   |  " << "Book_name    | " << "Author_name   | " << "Publisher_name   | " << "Year_of_publish     | " << "Total coppies #  | " << endl << endl;
		ifstream filedata("book_data.txt");
		while (filedata >> books.ISBN >> books.book_name >> books.author_name >> books.publisher_name >> books.date_of_issue >> books.no_of_copies)
		{
			cout << books.ISBN << "\t| " << books.book_name << "\t|  " << books.author_name << "\t |  " << books.publisher_name << "\t| " << books.date_of_issue << "\t | " << books.no_of_copies << endl;
		}
	loop2:

		filedata.close();
		int BOOK_ISBN;
		cout << "Please Enter Book ISBN number from above" << endl;
		cin >> BOOK_ISBN;
		ifstream filedata2("book_data.txt");
		while (filedata2 >> books.ISBN >> books.book_name >> books.author_name >> books.publisher_name >> books.date_of_issue >> books.no_of_copies)
		{
			if (BOOK_ISBN == books.ISBN)
			{
				flag2 = true;
				break;
			}
		}
		filedata.close();
		if (flag2 != true)
		{
			cout << "Please enter valid ISBN from below or enter 0 to go back " << endl;
			goto loop2;
		}
		if (flag2 == true)
		{
			ofstream iss("issue_books.txt", ios::app);
			iss << books.ISBN << "\t" << books.book_name << "\t" << obj.user_id << "\t" << obj.user_name << "\t" << obj.user_L_name << endl;
			cout << "The book " << books.book_name << " has been issused to user " << obj.user_name << obj.user_L_name << " successfully " << endl;
			iss.close();
			int ch;
			cout << "\n\nEnter 0 to go back or 1 to issuse book again :\t";
			cin >> ch;
			if (ch == 1)
			{
				issueBook();
			}
			else
			{
				menu();
			}
		}

	}

}
void issueBookDelete()
{
	system("cls");
	system("color 6E");
	cout << endl << UNDERLINE << "Library Mangemanent System" << CLOSEUNDERLINE << endl;
	int USER_ID;
	cout << "Enter user id or enter 0 to go back : ";
	cin >> USER_ID;
	bool flag;

	if (USER_ID == 0)
	{
		menu();
	}
	BookIssue obj;
	ifstream iss("issue_books.txt");
	while (iss >> obj.isbn >> obj.book_name >> obj.user_id >> obj.user_name >> obj.user_L_name)
	{
		if (USER_ID == obj.user_id)
		{
			flag = true;
			break;

			cout << obj.isbn << "\t" << obj.book_name << "\t" << obj.user_id << "\t" << obj.user_name << "\t" << obj.user_L_name << endl;

			ofstream newfile("new.txt", ios::app);


			while (iss >> obj.isbn >> obj.book_name >> obj.user_id >> obj.user_name >> obj.user_L_name)
			{
				if (USER_ID != obj.user_id)
				{
					newfile << obj.isbn << "\t" << obj.book_name << "\t" << obj.user_id << "\t" << obj.user_name << "\t" << obj.user_L_name << endl;

				}
			}

		}
		else
		{
			flag = false;
		}
	}
	iss.close();

	if (flag == false)
	{
		cout << "The data against this id not found!!!" << endl;
	}
	if (flag == true)
	{
		cout << "Do you really want to delete this data Y/N " << endl;
		char ch2;
		cin >> ch2;
		if (ch2 == 'y' || ch2 == 'Y')
		{
			if (remove("issue_books.txt") != 0)
				cout << "File not removed " << endl;
			else if (rename("new.txt", "issue_books.txt") != 0)
				cout << "file not renamed " << endl;
			else
			{
				cout << "The data against this id is successfully removed" << endl;

			}
		}
		else
		{
			remove("new.txt");
			cout << "The data not deleted" << endl;

		}
	}
	cout << "Press 1 to delete issuse book again or press 0 to to back" << endl;
	int ch;
	cin >> ch;
	if (ch == 1)
	{
		issueBookDelete();

	}
	else
	{
		menu();
	}
}
void issueBookList()
{

	system("cls");
	system("color 7D");
	cout << endl << UNDERLINE << "Library Mangemanent System" << CLOSEUNDERLINE << endl;
	BookIssue obj;
	ifstream iss("issue_books.txt");
	cout << "ISBN|\t" << "Book_Name|\t\t" << "User_ID #|\t" << "User_name" << endl;
	while (iss >> obj.isbn >> obj.book_name >> obj.user_id >> obj.user_name >> obj.user_L_name)
	{
		cout << obj.isbn << "|\t" << obj.book_name << "|\t\t\t" << obj.user_id << "|\t\t" << obj.user_name << "  " << obj.user_L_name << endl;
	}
	iss.close();
	cout << "Press 1 to delete issuse book again or press 0 to to back" << endl;
	int ch;
	cin >> ch;
	if (ch == 1)
	{
		issueBookDelete();

	}
	else
	{
		menu();
	}



}
void deleteData()
{
loop:
	system("cls");
	system("color 90");
	cout << endl << UNDERLINE << "Library Mangemanent System" << CLOSEUNDERLINE << endl;
	int pass = 1020;
	int word;
	cout << "Enter The password" << endl;
	cin >> word;
	if (pass == word)
	{
		cout << "Do you really want to delete all data Y/N" << endl;
		char ch;
		cin >> ch;
		if (ch == 'y' || ch == 'Y')
		{
			ofstream myfile1("book_data.txt", ios::trunc);
			ofstream myfile2("issue_books.txt", ios::trunc);
			ofstream myfile3("library_user.txt ", ios::trunc);
			myfile1.close();
			myfile2.close();
			myfile3.close();
			menu();
		}
	}
	else if (pass != word)
	{
		cout << "You have Enter incorrect password \n Enter again OR Enter 0 to go back to main menu" << endl;
		goto loop;
	}

	else if (word == 0)
		menu();
}

