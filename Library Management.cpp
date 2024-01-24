//the func all books works but needs some edits do it
//add delete and edit methodes;
//you can write delete part with wwriting details in a new file. like you write and write till you get to the file that you want to delete. then write next book and pass the deleted book .
//in this way the memory wastes but delet function works.
//it also needs an administrator access to delete the main file. you should solve this one too.

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <cstring>
#include <regex>

using namespace std;

void main_menu();
void print_search();
void search(int);
void search_by_name(string);
void search_by_auther(string);
void del();

//***********************************************************************************************************************************************
class  Book
{
private:

	int Version;


public:
	char NameOfBook[15];
	char Auther[15];
	int Prise;

	Book(string name_of_book = "no book found", string autehr = "no book found", int prise = 0, int version = 0)
	{
		strncpy_s(NameOfBook, name_of_book.c_str(), sizeof(NameOfBook));
		strncpy_s(Auther, autehr.c_str(), sizeof(Auther));

		NameOfBook[14] = '\0';
		Auther[14] = '\0';

		Prise = prise;
		Version = version;

		//Name = name;
		//LName = lname;

	}

	void EnterDetails();
	void PrintDetails();
	void SaveDetails();
};
//-----------------------------------------------------------------------------------------------------------------------------------------------
//this method recieves the info from user                                                                                  ###enter set method###
void Book::EnterDetails()
{
	cout << "\n\n\t\t  ----------------------------------------------------------------------------\t\t\t\n\n";
	cout << "\t\t\t      name of book :                               \b";
	cin >> NameOfBook;

	cout << "\t\t\t      name of auther :                             \b";
	cin >> Auther;
	
	cout << "\t\t\t      prise of book :                              \b";
	cin >> Prise;

	cout << "\t\t\t      version of book :                            \b";
	cin >> Version;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------
//it saves the detail in a file                                                                                                ###print method###
void Book::PrintDetails()
{
	cout << "\n\n\t\t  ----------------------------------------------------------------------------\t\t\t\n\n";
	cout << "\t\t\t      name of book :                               \b";
	for (int i = 0; NameOfBook[i]; i++)cout << NameOfBook[i];

	cout << "\n\n\t\t\t      name of auther :                             \b";
	for (int i = 0; Auther[i]; i++)cout << Auther[i];

	cout << "\n\n\t\t\t      prise of book :                              \b";
	cout << Prise;

	cout << "\n\n\t\t\t      version of book :                            \b";
	cout << Version;

}
//-----------------------------------------------------------------------------------------------------------------------------------------------
//this one moves the entered data to the file in memory                                                                         ###save method###
void Book::SaveDetails()
{
	fstream file;

	file.open("C:/C++/file.txt", ios::app | ios::out);

	if (!file)
		cout << "error while opening file ";

	file.write((char*)this, sizeof(Book));
	file.close();
}
//***********************************************************************************************************************************************
//this fumction prints the panel for each student:                                                                                    print panel
void print_panel()
{
	string wellcome_lone_0 = "\n\n";
	string wellcome_lone_1 = "\t\t\t      [1]enter details                             [2]save details\n\n\n";
	string wellcome_lone_2 = "\t\t\t      [3]see details                               [4]back to previous menu\n\n\n";
	string wellcome_lone_4 = "\t\t  -------------------------------------------------------------------------------\t\t\t\n";

	cout << wellcome_lone_0 << wellcome_lone_1 << wellcome_lone_2 << wellcome_lone_4;
}
//############################################################################################################################################### 
//this f prints the content of main menu                                                                                          print main menu
void print_main_menu()
{
	//thigs like add a student or search or list of students or 
	system("cls");
	string wellcome_lone_0 = "\n\n";
	string wellcome_lone_1 = "\t\t\t      [1]go to panel                               [2]search between books\n\n\n";
	string wellcome_lone_2 = "\t\t\t      [3]see prise details                         [4]all books\n\n\n";
	string wellcome_lone_3 = "\t\t\t      [5]edit a book                               [6]delet a book\n\n\n";
	string wellcome_lone_4 = "\t\t\t      [7]exit                                      [8]\n\n\n";
	string wellcome_lone_5 = "\t\t  -------------------------------------------------------------------------------\t\t\t\n";

	cout << wellcome_lone_0 << wellcome_lone_1 << wellcome_lone_2 << wellcome_lone_3 << wellcome_lone_4 << wellcome_lone_5;
}
//###############################################################################################################################################
//prints the ways to search                                                                                                          print search
void print_search()
{
	string wellcome_lone_0 = "\n\n";
	string wellcome_lone_1 = "\t\t\t      [1]search by code                            [2]search by name\n\n\n";
	string wellcome_lone_2 = "\t\t\t      [3]search bt auter                           [4]back to previos menu\n\n\n";
	string wellcome_lone_4 = "\t\t  -------------------------------------------------------------------------------\t\t\t\n";

	cout << wellcome_lone_0 << wellcome_lone_1 << wellcome_lone_2 << wellcome_lone_4;
}
//###############################################################################################################################################
void print_delet()
{
	system("cls");
	string s1 = "\n\n\t\t\t      [1]delete a book                             [2]delete all books\n\n\n";
	string s2 = "\n\t\t\t      [3]bacmk to previous menu                     \n\n\n";

	cout << s1 << s2;
}
//###############################################################################################################################################
//(search penel) it shows the ways to search a book like by name or code or ...                                                   searching panel
void searching_panel()
{
	char ch;
	string name;
	//search:;
	do
	{
		system("cls");
		print_search();

		ch = _getch();

		switch (ch)
		{
		case '1':
			cout << "\n\n\t\t\t      enter the number of book in list:            \b\b\b\b\b";

			int code;
			cin >> code;
			search(code);
			_getch();
			break;
		case '2':
			cout << "\n\n\t\t\t           enter the name of book :            \b\b\b\b\b";
			cin >> name;
			search_by_name(name);
			_getch();
			break;
		case'3':
			cout << "\n\n\t\t\t          enter the name of auther :            \b\b\b\b\b";
			cin >> name;
			search_by_auther(name);
			_getch();
			break;
		}
	} while (ch != '4');
	main_menu();
}
//###############################################################################################################################################
//thie func looks for a book by its code in list of books                                                                         search(by code)
void search(int which)
{
	Book ins;
	fstream file;
	file.open("C:/C++/file.txt", ios::binary | ios::in);
	file.seekp((which - 1) * (sizeof(Book)));
	file.read((char*)&ins, sizeof(Book));
	ins.PrintDetails();
	file.close();
}
//###############################################################################################################################################
//this function searches by name                                                                                                   search by name
void search_by_name(string name)
{
	Book ins;
	fstream file;
	file.open("C:/C++/file.txt", ios::binary | ios::in);

	bool flag = true;
	int counter = 0;

	while (file.is_open())
	{
		file.seekp(counter * sizeof(Book));
		file.read((char*)&ins, sizeof(Book));

		if (ins.NameOfBook == name)
		{
			cout << "\n\t\t\t\t\tI found the book! ...\n\n";
			ins.PrintDetails();
			file.close();
		}
		counter++;

		if (counter == 40)
		{
			cout << "\n\t\t\t\t\tI couldn't find the book! ...\n\n";
			file.close();
		}
	}
}
//############################################################################################################################################### 
// this one searches bt name of auther                                                                                           search by auther
void search_by_auther(string name)
{
	Book ins;
	fstream file;
	file.open("C:/C++/file.txt", ios::binary | ios::in);
	bool flag = true;
	int counter = 0;

	while (flag)
	{
		file.seekp(counter * (sizeof(Book)));
		file.read((char*)&ins, sizeof(Book));

		if (ins.Auther == name)
		{
			ins.PrintDetails();
			flag = false;
			break;
		}
		counter++;
	}

	if (counter == 40)
		file.close();
}
//###############################################################################################################################################
//do things about one book (the panel for a book)                                                                                           penel
void panel()
{
	bool data = false;//shows that a data is already entered
	char ch;
	Book book;
	int counter = 0;
	bool saved = false;//shows if the data is saved in file or not

add:;

	system("cls");

	print_panel();

	ch = _getch();

	switch (ch)
	{
	case '1':
		counter++;
		data = true;
		saved = false;
		system("cls");
		book.EnterDetails();
		cout << "student aded";
		_getch();
		goto add;


	case'2':
		if (!data)
		{
			system("cls");
			cout << "\n\n\t\t----------------------------------------------------------------------------\t\t\t\n\n";
			cout << "\t\t\t             you have not entered any data yet!!!.\n\n";
			_getch();
			goto add;

		}
		else if (data && saved)
		{
			system("cls");
			cout << "\n\n\t\t----------------------------------------------------------------------------\t\t\t\n\n";
			cout << "\t\t\t          data for this book is already saved in database.\n\n";
			_getch();
			goto add;
		}
		else {
			saved = true;
			system("cls");
			book.SaveDetails();
			cout << "\t\t----------------------------------------------------------------------------\t\t\t\n\n";
			cout << "\t\t\t                  sata successfuly saved!!!";
			_getch();
			goto add;
		}


	case'3':
		//reads and then prints
		system("cls");
		if (!data)
		{
			system("cls");
			cout << "\n\n\t\t----------------------------------------------------------------------------\t\t\t\n\n";
			cout << "\t\t\t             you have not entered any data yet!!!.\n\n";
			_getch();
			goto add;

		}
		else if (data && saved)
		{
			cout << "\t\t  ----------------------------------------------------------------------------\t\t\t\n\n";
			cout << "\t\t\t   enter code of book :                               \b";

			int n;
			cin >> n;
			search(n - 1);

			_getch();
			goto add;
		}
		else {
			book.PrintDetails();

			cout << "\n\n\t\t----------------------------------------------------------------------------\t\t\t\n\n";
			cout << "\t\t\t       you have not save the data for this book in database.\n\n";
			cout << "\t\t\t            ::::PRESS S TO SAVE THEM::::\n\n\n\n";


			char ch = _getch();

			if (ch == 's' || ch == 'S')
			{
				book.SaveDetails();
				cout << "\t\t----------------------------------------------------------------------------\t\t\t\n\n";
				cout << "\t\t\t                  sata successfuly saved!!!";
				_getch();
				saved = true;
			}
			else
				goto add;
			goto add;
		}
	case '4':
		system("cls");
		main_menu();


	default:
		goto add;
	}
}
//###############################################################################################################################################
//this one shows all details about all                                                                                              prise details
void prise_details()
{
	system("cls");

	Book ins;
	fstream file;
	file.open("C:/C++/file.txt", ios::binary | ios::in);
	int sum = 0;
	int counter = 0;
	int max = 0, min = 0;
	string max_name, min_name;
	int max_code = 1, min_code = 1;


	file.seekp(counter * sizeof(Book));
	file.read((char*)&ins, sizeof(Book));
	min = ins.Prise;
	max_name = ins.NameOfBook;
	min_name = ins.NameOfBook;
	file.close();


	file.open("C:/C++/file.txt", ios::binary | ios::in);

	while (file.seekp(counter * sizeof(Book)) && file.read((char*)&ins, sizeof(Book)))
	{
		counter++;
		sum += ins.Prise;

		if (ins.Prise >= max)
		{
			max = ins.Prise;
			max_name = ins.NameOfBook;
			max_code = counter;
		}


		if (ins.Prise <= min)
		{
			min = ins.Prise;
			min_name = ins.NameOfBook;
			min_code = counter;
		}

	}


	cout << "\n\n\t\t\t   number of books :                                    " << counter;
	cout << "\n\n\n\t\t\t   max prise :                                          " << max;
	cout << "\n\n\n\t\t\t   max prise book name :                                " << max_name;
	cout << "\n\n\n\t\t\t   min prise :                                          " << min;
	cout << "\n\n\n\t\t\t   min prise book name :                                " << min_name;
	cout << "\n\n\n\t\t\t   the sum prie of all books =                          " << sum << endl;
	cout << "\n\n\t\t    -----------------------------------------------------------------------------\t\t\t\n\n";

	_getch();

	main_menu();

}
//###############################################################################################################################################
//prints all books with details                                                                                                       all details
void all_details()
{
	system("cls");

	fstream file;
	Book ins;
	int counter = 0;
	file.open("C:/C++/file.txt", ios::binary | ios::in);

	while (file.seekp(counter * sizeof(Book)) && file.read((char*)&ins, sizeof(Book)))
	{
		ins.PrintDetails();
		counter++;
	}

	_getch();
	main_menu();
}
//###############################################################################################################################################
//edits details of a book and writes them on file                                                                                            edit
void edit()
{
	fstream file;
	Book ins;
	int code;

	file.open("C:/C++/file.txt", ios::binary | ios::in | ios::out);

	system("cls");
	cout << "\t\t  ----------------------------------------------------------------------------\t\t\t\n\n";
	cout << "\t\t\t      Enter code of book:                          \b";
	cin >> code;

	file.seekp((code - 1) * sizeof(Book));

	file.read((char*)&ins, sizeof(Book));

	system("cls");

	cout << "\n\n\t\t\t      book code :                                  " << code;
	cout << "\n\n\t\t\t      Current details of book :                    \b";

	ins.PrintDetails();

	cout << "\n\n\t\t  ----------------------------------------------------------------------------\t\t\t\n\n";
	cout << "\n\n\t\t\t      enter new details of book :                  \n\n";
	ins.EnterDetails();

	cout << "\n\n";

	file.seekp((code - 1) * sizeof(Book));

	file.write((char*)&ins, sizeof(Book));

	file.close();

	cout << "\n\n\t\t\t      Book details are edited successfully!        \b";

	_getch();
	main_menu();
}
//###############################################################################################################################################
void delet_panel()
{
	print_delet();
	char ch = _getch();
	switch (ch)
	{
	case'1':
		system("cls");
		//cout << "\n\n\n\t\t\t   sorry this part is not available currently ! :       ";
		//_getch();
		//delet_panel();
		del();

	case'2':
	{
		system("cls");
		cout << "\n\n\n\t\t\t   all books will be deleted , are you sure ?! y/n:       ";
		ch = _getch();
		switch (ch)
		{
		case 'y':
			remove("C:/C++/file.txt");
			cout << "\n\n\n\t\t\t   all books deleted succesfully !        ";
			_getch();
		default:
			break;
		}
		delet_panel();
	}
	case'3':
		main_menu();

	default:
		break;
	}

}
//###############################################################################################################################################
void del()
{
	fstream file;
	Book ins;
	int code;

	int counter = 0;
	file.open("C:/C++/file.txt", ios::binary | ios::in);

	while (file.seekp(counter * sizeof(Book)) && file.read((char*)&ins, sizeof(Book)))
		counter++;
	file.close();

	file.open("C:/C++/file.txt", ios::binary | ios::in | ios::out);
	cout << "enter code of the book";
	cin >> code;

	code--;     //code is ok now , as the indexes of the books
	counter--;  //counter is ok now , as the indexes of the books


	for (int i = code; i <= counter; i++)
	{
		file.seekp((i + 1) * sizeof(Book));
		file.read((char*)&ins, sizeof(Book));

		file.seekp(i * sizeof(Book));
		file.write((char*)&ins, sizeof(Book));
	}



	cout << "delet seccedfully";
	_getch();
	delet_panel();
	main_menu();
}
//###############################################################################################################################################
//the first and main function that can leads to different parts like panel or search menu                                               main menu
void main_menu()
{
	Book ins;

	system("cls");

	print_main_menu();

	char ch = _getch();

	switch (ch)
	{
	case '1':
		panel();
	case'2':
		searching_panel();
		break;
	case'3':
		prise_details();
		break;
	case'4':
		all_details();
		break;
	case'5':
		edit();
		break;
	case'6':
		delet_panel();
		break;
	case'7':
		exit(0);
	default:
		main_menu();
		break;
	}
}
//***********************************************************************************************************************************************
int main()
{
	system("cls");
	main_menu();
}