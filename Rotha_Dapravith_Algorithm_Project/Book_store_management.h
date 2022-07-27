#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<iomanip>
#include<fstream>

using namespace std;

fstream file1;

struct Book{
    int ID;
    string book_ISBN;
    string title;
    string published_year;
    string author_name;
    float price;
};
Book b[100];



void storeallbooks(struct Book b[],int size){
    char ch;
    file1.open("Book.txt",ios::app);
    for(int i=0;i<size;i++){

        cout<<"Detail Book #"<<i+1<<endl;
        cout<<"Enter book ID: ";cin>>b[i].ID;
        cout<<"Enter book ISBN: ";cin>>b[i].book_ISBN;
        cout <<"Enter the book's title : ";
        getline(cin,b[i].title);getline(cin,b[i].title);
        cout<<"Enter published year: ";cin>>b[i].published_year;
        cout<<"Enter author names: ";getline(cin,b[i].author_name);getline(cin,b[i].author_name);
        cout<<"Enter book price($): ";cin>>b[i].price;
        cout << "Do you want to add another book(y/n) | (Y|N) : ";
        cin >> ch;
        file1<<left<<setw(10)<<b[i].ID<<setw(16)<<b[i].book_ISBN<<setw(25)<<b[i].title<<setw(20)<<b[i].published_year<<setw(24)<<b[i].author_name<<left<<setw(21)<<b[i].price<<endl;
    }
    while(ch == 'y' || ch == 'Y');
    file1.close();
}
void DisplayAllBookInfo(struct Book b[]){
    cout<<"\n2. Display information all of books\n";
    file1.open("Book.txt",ios::in);
    int i=0;
    while(!file1.eof()){
        file1>>b[i].ID;
        file1>>b[i].book_ISBN;
        file1>>b[i].title;
        file1>>b[i].published_year;
        file1>>b[i].author_name;
        file1>>b[i].price;
        i = i + 1;
    }
    cout<<endl;
    cout<<left<<setw(10)<<"Book ID"<<setw(16)<<"Book ISBN"<<setw(25)<<"Title"<<setw(16)<<"Published year"<<setw(24)<<"Writer"<<setw(21)<<"price($)"<<endl;
    for(int k=0;k<i-1;k++){
        cout<<left<<setw(10)<<b[k].ID;
        cout<<left<<setw(16)<<b[k].book_ISBN;
        cout<<left<<setw(25)<<b[k].title;
        cout<<left<<setw(20)<<b[k].published_year;
        cout<<left<<setw(24)<<b[k].author_name;
        cout<<left<<setw(21)<<b[k].price<<endl;
    }
    cout<<endl;
    file1.close();
}
void DisplayBookByPublished_year(struct Book b[]){
    string published_year;
    cout<<"\n3. Display a book by Published year\n";
    cout<<"\nEnter book published year to display: ";cin>>published_year;
    file1.open("Book.txt",ios::in);
    int i=0;
    while(!file1.eof()){
        file1>>b[i].ID;
        file1>>b[i].book_ISBN;
        file1>>b[i].title;
        file1>>b[i].published_year;
        file1>>b[i].author_name;
        file1>>b[i].price;
        i = i + 1;
    }
    cout<<endl;
    cout<<left<<setw(10)<<"Book ID"<<setw(16)<<"Book ISBN"<<setw(25)<<"Title"<<setw(16)<<"Published year"<<setw(24)<<"Writer"<<setw(21)<<"price($)"<<endl;
    for(int k=0;k<i-1;k++){
        if(b[k].published_year==published_year){
            cout<<left<<setw(10)<<b[k].ID;
            cout<<left<<setw(16)<<b[k].book_ISBN;
            cout<<left<<setw(25)<<b[k].title;
            cout<<left<<setw(20)<<b[k].published_year;
            cout<<left<<setw(24)<<b[k].author_name;
            cout<<left<<setw(21)<<b[k].price<<endl;
        }
    }
    cout<<endl;
    file1.close();
}
int searchByID(struct Book bk[]){
    int ID;
    cout<<"\nEnter a ID to search: ";cin>>ID;
    file1.open("Book.txt",ios::in);
    int i=0;
    while(!file1.eof()){
        file1>>b[i].ID;
        file1>>b[i].book_ISBN;
        file1>>b[i].title;
        file1>>b[i].published_year;
        file1>>b[i].author_name;
        file1>>b[i].price;
        i = i + 1;
    }
    cout<<endl;
    cout<<"The information of a book by ID\n\n";
    cout<<left<<setw(10)<<"Book ID"<<setw(16)<<"Book ISBN"<<setw(25)<<"Title"<<setw(20)<<"Published year"<<setw(24)<<"Writer"<<setw(21)<<"price($)"<<endl;
    for(int k=0;k<i-1;k++){
        if(bk[k].ID == ID){
            cout<<left<<setw(10)<<b[k].ID;
            cout<<left<<setw(16)<<b[k].book_ISBN;
            cout<<left<<setw(25)<<b[k].title;
            cout<<left<<setw(20)<<b[k].published_year;
            cout<<left<<setw(24)<<b[k].author_name;
            cout<<left<<setw(21)<<b[k].price<<endl;
        }
    }
    cout<<endl;
    file1.close();
}
void deleteByID(struct Book b[]){
    cout<<"\n5. Delete a book by ID\n";
//    int ID = searchByID(bk);
   string answer;
    int ID;
    cout<<"Enter a ID to delete this data: ";cin>>ID;
   //if(answer == "yes"){
        file1.open("Book.txt",ios::in);
        ofstream tempFile;
        tempFile.open("temp.txt");
        int i=0;
        while(!file1.eof()){
            file1>>b[i].ID;
            file1>>b[i].book_ISBN;
            file1>>b[i].title;
            file1>>b[i].published_year;
            file1>>b[i].author_name;
            file1>>b[i].price;
            i = i + 1;
        }
        for(int k=0;k<i-1;k++){
            if(b[k].ID != ID){
                tempFile<<left<<setw(10)<<b[k].ID;
                tempFile<<left<<setw(16)<<b[k].book_ISBN;
                tempFile<<left<<setw(25)<<b[k].title;
                tempFile<<left<<setw(16)<<b[k].published_year;
                tempFile<<left<<setw(24)<<b[k].author_name;
                tempFile<<left<<setw(21)<<b[k].price<<endl;
            }
        }
        file1.close();
        tempFile.close();
        remove("Book.txt");
        rename("temp.txt","Book.txt");
        cout<<"\nSuccessfully deleted!\n";
//    }else{
//        cout<<"\nThis ID does not exist in the list !!"<<endl;
//        cout<<"\nData couldn't Deleted!.\n";
    cout<<endl;
    }


void updateInFile(struct Book bk[]){
    cout<<"\n6. Update a book by ID\n";
    Book bNew;
//    int ID = searchByID(bk);
    //string answer;
    int ID;
    cout<<"Enter a ID to update this data: ";cin>>ID;
//    if(answer == "yes"){
        file1.open("Book.txt",ios::in);
        ofstream tempFile;
        tempFile.open("temp.txt");
        int i=0;
        while(!file1.eof()){
            file1>>b[i].ID;
            file1>>b[i].book_ISBN;
            file1>>b[i].title;
            file1>>b[i].published_year;
            file1>>b[i].author_name;
            file1>>b[i].price;
            i = i + 1;
        }
        for(int k=0;k<i-1;k++){
            if(b[k].ID != ID){
                tempFile<<left<<setw(10)<<b[k].ID;
                tempFile<<left<<setw(16)<<b[k].book_ISBN;
                tempFile<<left<<setw(25)<<b[k].title;
                tempFile<<left<<setw(16)<<b[k].published_year;
                tempFile<<left<<setw(24)<<b[k].author_name;
                tempFile<<left<<setw(21)<<b[k].price<<endl;
            }
        }
        cout<<"Enter book new ID: ";cin>>bNew.ID;
        cout<<"Enter book new ISBN: ";cin>>bNew.book_ISBN;
        cout<<"Enter book new title: ";cin>>bNew.title;
        cout<<"Enter published new year: ";cin>>bNew.published_year;
        cout<<"Enter author new names: ";getline(cin,bNew.author_name);
                                         getline(cin,bNew.author_name);
        cout<<"Enter book new price: ";cin>>bNew.price;

        tempFile<<left<<setw(10)<<bNew.ID;
        tempFile<<left<<setw(16)<<bNew.book_ISBN;
        tempFile<<left<<setw(25)<<bNew.title;
        tempFile<<left<<setw(16)<<bNew.published_year;
        tempFile<<left<<setw(24)<<bNew.author_name;
        tempFile<<left<<setw(21)<<bNew.price<<endl;

        file1.close();
        tempFile.close();
        remove("Book.txt");
        rename("temp.txt","Book.txt");
        cout<<"\nSuccessfuly updated!";

        cout<<"\nData which updated will be at bottom of the list.\n\n";

}
