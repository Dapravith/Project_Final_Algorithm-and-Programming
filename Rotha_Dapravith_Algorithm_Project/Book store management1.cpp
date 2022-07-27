#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
using namespace std;
class book{

    public:
    void control_panel();
    void add_book();
    void show_books();
    void check_book();
    void update_book();
    void del_book();

    public :
     book(){

     id = 0;
     strcpy(title, "no title");
     price = 0;
     published_year = 0;

     int return_id()
		{
			return id;
		}
		char* return_title(){
			return title;
		}
     }

};

book b;

  void book::control_panel(){
      system("cls");
      cout<<"\n\n\t\t\t\tControl Panel";
      cout<<"\n\n 1. Add New Book";
      cout<<"\n 2. Display Books";
      cout<<"\n 3. Check Specific Book";
      cout<<"\n 4. Update Book";
      cout<<"\n 5. Delete Book";
      cout<<"\n 6. Exit";
  }
  void book::add_book(){

      system("cls");
      fstream file;
      char title[50];
      string id,firstname,lastname,ISBN;
      int published_year;
      float price;

          cout << "\n\tEnter the book's' id : ";
		cin >> b.id;
		cout << "\n\tEnter the book's title : ";
		cin.ignore();
		cin.getline(b.title, 49);
		cout << "\n\tEnter the book's writer : ";
		getline(cin,b.firstname);getline(cin,b.lastname);

		cout<<"\n\tEnter the book's ISBN: ";
		cin>>b.ISBN;
		cout<<"\n\tEnter the book's Published year: ";
		cin>>b.published_year;
		cout << "\n\tEnter the book's price : ";
		cin >> b.price;
		cout<<"\n";
		store_data();
		cout << "Do you want to add another book(y/n) | (Y|N) : ";
		cin >> ch;
	}
	while(ch == 'y' || ch == 'Y');
      file.open("book.txt",ios::out|ios::app);
      file<<""<<b.id<<"\t"<< b.firstname<<"\t"<<b.lastname<<"\t"<<b.ISBN<<"\t"<<b.published_year<<"\t"<<b.price<<"\n";
      file.close();
  }

  void bookshop::show_books()
  {
      system("cls");
      fstream file;
      int no_copy;
      string b_id, b_name, a_name;
      cout<<"\n\n\t\t\tShow All Books";
      file.open("D://book.txt",ios::in);
      if(!file)

          cout<<"\n\n File Opening Error...";

      else
      {
        cout<<"\n\nBook ID    BName    AName    NoOfCopy\n\n";
        file>>b_id>>b_name>>a_name>>no_copy;
        while(!file.eof())
        {
            cout<<"     "<<b_id<<"\t   "<<b_name<<"\t    "<<a_name<<"\t"<<no_copy<<"\n\n";
            file>>b_id>>b_name>>a_name>>no_copy;
        }
        file.close();
      }
  }

  void bookshop::check_book()
  {
      system("cls");
      fstream file;
      int no_copy, count=0;
      string b_id, b_name, a_name, b_idd;
      cout<<"\n\n\t\t\t\tCheck Specific Book";
      file.open("D://book.txt",ios::in);
      if(!file)
      cout<<"\n\n File Opening Error...";
      else
      {
         cout<<"\n\n Book ID: ";
         cin>>b_idd;
         file>>b_id>>b_name>>a_name>>no_copy;
         while (!file.eof())
         {
            if(b_idd == b_id)
            {
             system("cls");
             cout<<"\n\n\t\t\t\t\t Check Specific Book";
             cout<<"\n\n Book ID: "<<b_id;
             cout<<"\n\n\t\t\tName:  "<<b_name;
             cout<<"\n\nAuthor:  "<<a_name;
             cout<<"\n\n\t\t\t No.Of Copies:"<<no_copy;
             count++;
             break;
            }
            file>>b_id>>b_name>>a_name>>no_copy;
         }
         file.close();
         if(count ==0)
         cout<<"\n\n Your Book Not Found...";

      }

  }

  void bookshop::update_book()
	{
		system("cls");
		fstream file, file1;
		int no_copy,no_co,count=0;
		string b_name,b_na,a_name,a_na,b_idd,b_id;
		cout<<"\n\n\t\t\t\tUpdate Book Record";
		file1.open("D://book1.txt",ios::app|ios::out);
		file.open("D://book.txt",ios::in);
		if(!file)
		cout<<"\n\n File Openning Error...";
		else
		{
			cout<<"\n\n Book ID : ";
			cin>>b_id;
			file>>b_idd>>b_name>>a_name>>no_copy;
			while(!file.eof())
			{
				if(b_id == b_idd)
				{
					system("cls");
					cout<<"\n\n\t\t\t\tUpdate Book Record";
					cout<<"\n\n New Book Name : ";
					cin>>b_na;
					cout<<"\n\n\t\t\tAuthor Name : ";
					cin>>a_na;
					cout<<"\n\n No. of Copies : ";
					cin>>no_co;
					file1<<" "<<b_id<<" "<<b_na<<" "<<a_na<<" "<<no_co<<"\n";
					count++;
				}
				else
				file1<<" "<<b_idd<<" "<<b_name<<" "<<a_name<<" "<<no_copy<<"\n";
				file>>b_idd>>b_name>>a_name>>no_copy;
			}
			if(count == 0)
			cout<<"\n\n Book ID Not Found...";
		}
		file.close();
		file1.close();
		remove("D://book.txt");
		rename("D://book1.txt","D://book.txt");
	}
  void bookshop::del_book()
	{
		system("cls");
		fstream file,file1;
		int no_copy,count=0;
		string b_id,b_idd,b_name,a_name;
		cout<<"\n\n\t\t\t\tDelete Book Record";
		file1.open("D://book1.txt",ios::app|ios::out);
		file.open("D://book.txt",ios::in);
		if(!file)
		cout<<"\n\n File Openning Error...";
		else
		{
			cout<<"\n\n Book ID : ";
			cin>>b_id;
			file>>b_idd>>b_name>>a_name>>no_copy;
			while(!file.eof())
			{
				if(b_id == b_idd)
				{
					system("cls");
					cout<<"\n\n\t\t\t\tDelete Book Record";
					cout<<"\n\n One Book is Deleted Successfully...";
					count++;
				}
				else
				file1<<" "<<b_idd<<" "<<b_name<<" "<<a_name<<" "<<no_copy<<"\n";
				file>>b_idd>>b_name>>a_name>>no_copy;
			}
			if(count == 0)
			cout<<"\n\n Book ID Not Found...";
		}
		file.close();
		file1.close();
		remove("D://book.txt");
		rename("D://book1.txt","D://book.txt");
	}

main()
{
    int choice;
    char x;
    bookshop b;
    p:
    b.control_panel();
    cout<<"\n\n Your Choice:";
    cin>>choice;
    switch (choice)
    {
    case 1:
        do
        {
        b.add_book();
        cout<<"\n\n Do you want to Add Another Book (Y/N):";
        cin>>x;
        } while (x == 'Y');

         break;

    case 2:
          b.show_books();

        break;

    case 3:
         b.check_book();
        break;

    case 4:
         b.update_book();
        break;

    case 5:
         b.del_book();
        break;

    case 6:
         exit(0);
    default:
         cout<<"\n\n Invalid Value...Please try again";

    }
    getch();
    goto p ;
}
