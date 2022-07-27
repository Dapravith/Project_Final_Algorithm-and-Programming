#include<iostream>
#include<fstream>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<cmath>
#include<ctime>
#include"Product_Management.h"
#include"Book_store_management.h"
#include"Number_testing.h"
#include"Math_suit_computation.h"
#include"Number_convertion_system.h"
using namespace std;


time_t mytime = time(0);
char *load = ctime(&mytime);

fstream history;

void SetColor(int ForgC){

     WORD wColor;
     //This handle is needed to get the current background attribute

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //csbi is used for wAttributes word

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;


}

int GetFontSize(HANDLE windowHandle, COORD *size){

    CONSOLE_FONT_INFOEX font = { sizeof(CONSOLE_FONT_INFOEX) };

    if (!GetCurrentConsoleFontEx(windowHandle, 0, &font))
        {
        return 0;
        }

    *size = font.dwFontSize;

    return 1;
    }

int SetFontSize(HANDLE windowHandle, COORD size){

    CONSOLE_FONT_INFOEX font = { sizeof(CONSOLE_FONT_INFOEX) };

    if (!GetCurrentConsoleFontEx(windowHandle, 0, &font)){
        return 0;
        }

    font.dwFontSize = size;

    if (!SetCurrentConsoleFontEx(windowHandle, 0, &font)){
        return 0;
        }

    return 1;
}

void intro(){

	cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\tFinal Algo.Project\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout<<"\n\n\t\t\t\tMade By: Rotha Dapravith\n\t\t\t\t-------------------------";
	cout<<"\n\n\t\t\t\tID: e20190915\n\t\t\t\t-----------------------------------";
	cout<<"\n\n\t\t\t\tGroup: I3 GIC(C)\n\t\t\t\t---------------------------------";
	getch();
}

void loading(){

    SetColor(9);
    printf("\n\n\t\t\t\t\t\t\tLoading.....\n");
    printf("\t\t\t\t\t\t  ");

    for(int i=0; i<=20; i++){
        SetColor(9);
        Sleep(50);
        printf("%c",219);
        SetColor(9);
    }
    printf("\n\n\n\t\t\t\t       ");
    system("pause");
}

void welcome(){

	system("cls");
	cls();
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\tWelcome to Algo.Project ";
	getch();
}



main(){


     int choice;
//     time_t now = time(0);
//     tm*ltm = localtime(&now);
     system("Color 5");

    intro();
    welcome();
    loading();
    cls();
     HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD size;

    if (GetFontSize(h, &size)){
        /* Grow by 50% */
        size.X += (SHORT)(size.X * .6);
        size.Y += (SHORT)(size.Y * .6);
        SetFontSize(h, size);
    }

    cout<<"\t\t\t\t\t\t\tHistory Data of each feature 1-6"<<endl<<endl;


     SetColor(2);
     cls();
     cout<<"\n\t\t======================================================="<<endl;
     cout<<"\t\t\t*** Algorithm and Programming Project Menu ***"<<endl;
     cout<<"\t\t======================================================="<<endl<<endl;
     cout<<"\t\t\t\t1.Product Management"<<endl<<endl;
     cout<<"\t\t\t\t2.Book store Management"<<endl<<endl;
     cout<<"\t\t\t\t3.Number testing"<<endl<<endl;
     cout<<"\t\t\t\t4.Basic Math"<<endl<<endl;
     cout<<"\t\t\t\t5.Math suit computation"<<endl<<endl;
     cout<<"\t\t\t\t6.Number conversion"<<endl<<endl;
     cout<<"\t\t\t\t0.Exit program"<<endl<<endl;
     cout<<"\n\t\t\t\tPlease Input your choice: ";cin>>choice;

     if(choice==0){
          exit(0);
     }else if(choice == 1){
          cls();
          int size;
          int option;
          history.open("HistoryData.txt",ios::app);
          history<<"\nUser used feature product Management on "<<load;
          history.close();

          cout<<endl;
          system("Color 03");
          system("Color 9F");

      while(1){
        cout<<"\n\n\t\t1. Create or Insert a product";
        cout<<"\n\n\t\t2. Display information all products";
        cout<<"\n\n\t\t3. Display information a product by ID";
        cout<<"\n\n\t\t4. Delete a product by ID";
        cout<<"\n\n\t\t5. Update a product by ID";
        cout<<"\n\n\t\t6. Search a product ";
        cout<<"\n\n\t\t0. Exit program\n";
        cout<<"\n\n\t\tEnter a number to choose a option: ";cin>>option;
        cls();
        if(option == 1){

            cout<<"\n1. Create products";
            cout<<"\nEnter a number which you want to add:";cin>>size;
            createProduct(p,size);
        }
        else if(option == 2){
            displayAllProducts(p);
        }
        else if(option == 3){
            displayProductByID(p);
        }
        else if(option == 4){
            deleteProductByID(p);
        }
        else if(option == 5){
            updateProductByID(p);
        }
        else if(option == 6){
            searchProductByID(p);
        }
        else if(option == 0){
            exit(0);
            system("pause");
            break;
        }
    }

     }else if(choice == 2){

          int size;
          int choice;
         char ch;
          history.open("HistoryData.txt",ios::app);
          history<<"\nUser used feature Book store Management on "<<load;
          history.close();
    //cls();
    do{
          system("cls");
          cout<<"\n\n\t\t ***Book Store Management ***"<<endl;
          cout << "\n\n\t\t=== Menu ===";
		cout << "\n\n\t1. Create new book";
		cout << "\n\t2. Show book by ID";
		cout << "\n\t3. Display books by published year";
		cout << "\n\t4. Search book by ID";
		cout << "\n\t5. Update book by ID";
		cout << "\n\t6. Delete book by ID";
          cout << "\n\t0. Exit program";
          cout<<"\nChoose your option number: ";cin>>choice;

        switch(choice){
            case 1:
            cout<<"\n1. Create information of books";
            cout<<"\nEnter a number of Book you want to create: ";cin>>size;
            storeallbooks(b,size);
            break;
            case 2:
            DisplayAllBookInfo(b);
            system("pause");
            break;
            case 3:
            DisplayBookByPublished_year(b);
            system("pause");
            break;
            case 4:
            cout<<"\n4. Search & display a book info by ID\n";
            searchByID(b);
            system("pause");
            break;
            case 5:
            updateInFile(b);
            system("pause");
            break;
            case 6:
            deleteByID(b);
            system("pause");
            break;

            case 0:
            exit(0);
            system("pause");
            break;

     }

     }while(choice!=0);

     }else if(choice == 3){

        int num;
        bool flag;
         history.open("HistoryData.txt",ios::app);
          history<<"\nUser used feature Number testing on"<<load;
          history.close();

           cout<<"\n\n\t1. Check primary number";
           cout<<"\n\n\tEnter any number : ";
          cin>>num;
          flag = isPrime(num);
          if (flag==true){
          cout<<"\t"<<num<<" is a primary number";
        }else{
          cout<<"\t"<<num<<" is not a primary number";
        }
        cout<<"\n\n\t2. Check perfect number";
        cout << "\n\n\tEnter a number : "; cin >> num;

	if (checkPerfect(num)){
		cout << "\tIt is a perfect number";
	}
	else{
		cout << "\tIt is not a perfect number";
	}
     cout<<"\n\n\t3. Check palindrome number";
	cout<<"\n\n\tEnter any number: ";
    cin>>num;

    if(isPalindrome(num) == 1){
        cout<<"\t"<<num<<" \n\tIt is palindrome number";
    }
    else{
        cout<<"\t"<<num<<" \n\tIt is not palindrome number";
        cout<<endl<<endl;
        system("\n\n\tpause");
    }

     }else if(choice == 4){ //*basic Math
           int a, b;
          history.open("HistoryData.txt",ios::app);
          history<<"\nUser used feature Basic Math on "<<load;
          history.close();
    // printing the sum of a and b
    cout<<"\n\n\tEnter value of a: ";cin>>a;
    cout<<"\n\n\tEnter value of b: ";cin>>b;

    cout << "\n\n\tSummation a + b = " << (a + b) << endl;

    // printing the difference of a and b
    cout << "\n\n\tSubtraction a - b = " << (a - b) << endl;

    // printing the product of a and b
    cout << "\n\n\tMultiplication a * b = " << (a * b) << endl;

    // printing the division of a by b
    cout << "\n\n\tDivision a / b = " << (a / b) << endl;
    cout<<endl<<endl;
    system("\n\tpause");

     }else if(choice == 5){
     int number=0;
	int n,x;
     int sum=0,i=1;
     int num,count;

      history.open("HistoryData.txt",ios::app);
          history<<"\nUser used feature Math suit Computation on "<<load;
          history.close();

     cout<<"\n\n\t1. 1+2+3+...+n";
     cout << "\n\n\tEnter a number: ";
     cin >> n;

     cout << "\n\n\tSummation of 1+2+3+...+n =  " << sumSquare(n);

     cout<<"\n\n\t2. 1+3+5+...+n";
     cout<<"\n\n\tEnter a number: ";
     cin>>n;

    while(i<=n){
        sum+=i;
        i+=2;
    }
    cout<<"\n\n\tThe sum of the series 1+3+5+...+n = "<<sum;

     cout<<"\n\n\t3. 1^2+2^2+...+n^2";
	cout << "\n\n\tEnter the Number to find sum of Series 1^2 + 2^2 + n^2 =  ";
	cin >> number;

	sumOfSeries (number);

	cout<<"\n\n\t4. Sum all primary numbers in between 1 to n";

     cout<<"\n\n\tEnter a number:  ";cin>>number;
     sumPrime(number);
     cout<<endl<<endl;
     system("\n\n\tpause");
     }else if(choice == 6){
          int choice;
           history.open("HistoryData.txt",ios::app);
          history<<"\nUser used feature Number convertion system on "<<load;
          history.close();
          cls();
     do{
     displaymenu();
     cin>>choice;

     switch(choice){
        case 0: exit(0);
        cls();
        case 1: binaryToDecimal(); break;
        cls();
        case 2: decimalToBinary(); break;
        cls();
        case 3: octalToDecimal(); break;
        cls();
        case 4: decimalToOctal();break;
        cls();
        case 5: decimaltoHexaDecimal(); break;
        cls();
        default:
         cout<<"\n\tInvalid Input! Please check number choice in menu";
         cout<<"\n\n";
         cout<<endl<<endl;

       }

       getch();
      }

      while(choice>0);

     }
     else{
          cout<<"\n\n\t\tInvalid choice!!";

     }





}
