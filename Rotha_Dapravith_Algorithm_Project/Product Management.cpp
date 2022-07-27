#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<iomanip>
#include<fstream>
using namespace std;

fstream file;

struct Date{
    int dd;
    int mm;
    int yy;
};

struct Product{
    int ID;
    string category;
    string name;
    string bar_code;
    int quantity;
    Date Product_date;
    Date Expired_date;
    float price;
};

Product p[100];

void createProduct(struct Product p[],int size){
    file.open("Product.txt",ios::app);
    for(int i=0;i<size;i++){
        cout<<"Products info #"<<i+1<<endl;
        cout<<"Enter product ID: ";cin>>p[i].ID;
        cout<<"Enter category of product: ";cin>>p[i].category;
        cout<<"Enter product name: ";cin>>p[i].name;
        cout<<"Enter bar code of product: ";cin>>p[i].bar_code;
        cout<<"Enter quantity of product: ";cin>>p[i].quantity;
        cout<<"Enter product date( day month year ): ";cin>>p[i].Product_date.dd>>p[i].Product_date.mm>>p[i].Product_date.yy;
        cout<<"Enter expired date( day month year ): ";cin>>p[i].Expired_date.dd>>p[i].Expired_date.mm>>p[i].Expired_date.yy;
        cout<<"Enter product price($): ";cin>>p[i].price;

        file<<left<<setw(15)<<p[i].ID;
        file<<left<<setw(15)<<p[i].category;
        file<<left<<setw(15)<<p[i].name;
        file<<left<<setw(15)<<p[i].bar_code;
        file<<left<<setw(15)<<p[i].quantity;
        file<<p[i].Product_date.dd<<" \t ";
        file<<p[i].Product_date.mm<<" \t ";
        file<<left<<setw(20)<<p[i].Product_date.yy;
        file<<p[i].Expired_date.dd<<" \t ";
        file<<p[i].Expired_date.mm<<" \t ";
        file<<left<<setw(20)<<p[i].Expired_date.yy;
        file<<left<<setw(15)<<p[i].price<<endl;
    }
    file.close();
    cout<<"Successfully Created!";
    cout<<endl;
}
void displayAllProducts(struct Product p[]){
    cout<<"\n2. Display information all products\n";
    file.open("Product.txt",ios::in);
    int i=0;
    while(!file.eof()){
        file>>p[i].ID;
        file>>p[i].category;
        file>>p[i].name;
        file>>p[i].bar_code;
        file>>p[i].quantity;
        file>>p[i].Product_date.dd;
        file>>p[i].Product_date.mm;
        file>>p[i].Product_date.yy;
        file>>p[i].Expired_date.dd;
        file>>p[i].Expired_date.mm;
        file>>p[i].Expired_date.yy;
        file>>p[i].price;
        i = i + 1;
    }
    cout<<endl;
    cout<<left<<setw(15)<<"ID"<<left<<setw(15)<<"Category"<<left<<setw(15)<<"Name"<<left<<setw(15)<<"Bar Code"<<left<<setw(15)<<"Quantity"<<left<<setw(35)<<"Product Date(dd mm yyyy)"<<left<<setw(40)<<
    "Expired Date(dd mm yyyy)"<<left<<setw(20)<<"Price($)/1unit"<<endl;
    for(int k=0;k<i-1;k++){
        cout<<left<<setw(15)<<p[k].ID;
        cout<<left<<setw(15)<<p[k].category;
        cout<<left<<setw(15)<<p[k].name;
        cout<<left<<setw(15)<<p[k].bar_code;
        cout<<left<<setw(15)<<p[k].quantity;
        cout<<p[k].Product_date.dd<<" \t ";
        cout<<p[k].Product_date.mm<<" \t ";
        cout<<left<<setw(20)<<p[k].Product_date.yy;
        cout<<p[k].Expired_date.dd<<" \t ";
        cout<<p[k].Expired_date.mm<<" \t ";
        cout<<left<<setw(20)<<p[k].Expired_date.yy;
        cout<<left<<setw(15)<<p[k].price<<endl;
    }
    cout<<endl;
    file.close();
}
void displayProductByID(struct Product p[]){
    int ID;
    cout<<"\n3. Display information a product by ID\n";
    cout<<"\nEnter product ID to display: ";cin>>ID;
    file.open("Product.txt",ios::in);
    int i=0;
    while(!file.eof()){
        file>>p[i].ID;
        file>>p[i].category;
        file>>p[i].name;
        file>>p[i].bar_code;
        file>>p[i].quantity;
        file>>p[i].Product_date.dd;
        file>>p[i].Product_date.mm;
        file>>p[i].Product_date.yy;
        file>>p[i].Expired_date.dd;
        file>>p[i].Expired_date.mm;
        file>>p[i].Expired_date.yy;
        file>>p[i].price;
        i = i + 1;
    }
    cout<<endl;
    cout<<left<<setw(15)<<"ID"<<left<<setw(15)<<"Category"<<left<<setw(15)<<"Name"<<left<<setw(15)<<"Bar Code"<<left<<setw(15)<<"Quantity"<<left<<setw(35)<<"Product Date(dd mm yyyy)"<<left<<setw(40)<<
    "Expired Date(dd mm yyyy)"<<left<<setw(20)<<"Price($)/1unit"<<endl;
    for(int k=0;k<i-1;k++){
        if(p[k].ID == ID){
            cout<<left<<setw(15)<<p[k].ID;
            cout<<left<<setw(15)<<p[k].category;
            cout<<left<<setw(15)<<p[k].name;
            cout<<left<<setw(15)<<p[k].bar_code;
            cout<<left<<setw(15)<<p[k].quantity;
            cout<<p[k].Product_date.dd<<" \t ";
            cout<<p[k].Product_date.mm<<" \t ";
            cout<<left<<setw(20)<<p[k].Product_date.yy;
            cout<<p[k].Expired_date.dd<<" \t ";
            cout<<p[k].Expired_date.mm<<" \t ";
            cout<<left<<setw(20)<<p[k].Expired_date.yy;
            cout<<left<<setw(15)<<p[k].price<<endl;
        }
    }
    cout<<endl;
    file.close();
}
void deleteProductByID(struct Product p[]){
    int ID;
    cout<<"\n4. Delete a product by ID\n";
    cout<<"\nEnter product ID to delete: ";cin>>ID;
    file.open("Product.txt",ios::in);
    ofstream file2;
    file2.open("Product2.txt");
    int i=0;
    while(!file.eof()){
        file>>p[i].ID;
        file>>p[i].category;
        file>>p[i].name;
        file>>p[i].bar_code;
        file>>p[i].quantity;
        file>>p[i].Product_date.dd;
        file>>p[i].Product_date.mm;
        file>>p[i].Product_date.yy;
        file>>p[i].Expired_date.dd;
        file>>p[i].Expired_date.mm;
        file>>p[i].Expired_date.yy;
        file>>p[i].price;
        i = i + 1;
    }
    for(int k=0;k<i-1;k++){
        if(p[k].ID != ID){
            file2<<left<<setw(15)<<p[k].ID;
            file2<<left<<setw(15)<<p[k].category;
            file2<<left<<setw(15)<<p[k].name;
            file2<<left<<setw(15)<<p[k].bar_code;
            file2<<left<<setw(15)<<p[k].quantity;
            file2<<p[k].Product_date.dd<<" \t ";
            file2<<p[k].Product_date.mm<<" \t ";
            file2<<left<<setw(20)<<p[k].Product_date.yy;
            file2<<p[k].Expired_date.dd<<" \t ";
            file2<<p[k].Expired_date.mm<<" \t ";
            file2<<left<<setw(20)<<p[k].Expired_date.yy;
            file2<<left<<setw(15)<<p[k].price<<endl;
        }
    }
    file.close();
    file2.close();
    remove("Product.txt");
    rename("Product2.txt","Product.txt");
    cout<<"\nSuccessfully deleted!\n";
    cout<<endl;
}

void updateProductByID(struct Product p[]){
    Product proNew;
    int ID;
    cout<<"\n5. Update a product by ID";
    cout<<"\nEnter product ID to update: ";cin>>ID;
    file.open("Product.txt",ios::in);
    ofstream file2;
    file2.open("Product2.txt");
    int i=0;
    while(!file.eof()){
        file>>p[i].ID;
        file>>p[i].category;
        file>>p[i].name;
        file>>p[i].bar_code;
        file>>p[i].quantity;
        file>>p[i].Product_date.dd;
        file>>p[i].Product_date.mm;
        file>>p[i].Product_date.yy;
        file>>p[i].Expired_date.dd;
        file>>p[i].Expired_date.mm;
        file>>p[i].Expired_date.yy;
        file>>p[i].price;
        i = i + 1;
    }
    for(int k=0;k<i-1;k++){
        if(p[k].ID != ID){
            file2<<left<<setw(15)<<p[k].ID;
            file2<<left<<setw(15)<<p[k].category;
            file2<<left<<setw(15)<<p[k].name;
            file2<<left<<setw(15)<<p[k].bar_code;
            file2<<left<<setw(15)<<p[k].quantity;
            file2<<p[k].Product_date.dd<<" \t ";
            file2<<p[k].Product_date.mm<<" \t ";
            file2<<left<<setw(20)<<p[k].Product_date.yy;
            file2<<p[k].Expired_date.dd<<" \t ";
            file2<<p[k].Expired_date.mm<<" \t ";
            file2<<left<<setw(20)<<p[k].Expired_date.yy;
            file2<<left<<setw(15)<<p[k].price<<endl;
        }
    }

    cout<<"Enter new product ID: ";cin>>proNew.ID;
    cout<<"Enter new category of product: ";cin>>proNew.category;
    cout<<"Enter new product name: ";cin>>proNew.name;
    cout<<"Enter new bar code of product: ";cin>>proNew.bar_code;
    cout<<"Enter new quantity of product: ";cin>>proNew.quantity;
    cout<<"Enter new product date( day month year ): ";cin>>proNew.Product_date.dd>>proNew.Product_date.mm>>proNew.Product_date.yy;
    cout<<"Enter new expired date( day month year ): ";cin>>proNew.Expired_date.dd>>proNew.Expired_date.mm>>proNew.Expired_date.yy;
    cout<<"Enter new product price($): ";cin>>proNew.price;

    file2<<left<<setw(15)<<proNew.ID;
    file2<<left<<setw(15)<<proNew.category;
    file2<<left<<setw(15)<<proNew.name;
    file2<<left<<setw(15)<<proNew.bar_code;
    file2<<left<<setw(15)<<proNew.quantity;
    file2<<proNew.Product_date.dd<<" \t ";
    file2<<proNew.Product_date.mm<<" \t ";
    file2<<left<<setw(20)<<proNew.Product_date.yy;
    file2<<proNew.Expired_date.dd<<" \t ";
    file2<<proNew.Expired_date.mm<<" \t ";
    file2<<left<<setw(20)<<proNew.Expired_date.yy;
    file2<<left<<setw(15)<<proNew.price<<endl;

    file.close();
    file2.close();
    remove("Product.txt");
    rename("Product2.txt","Product.txt");
    cout<<"\nSuccessfully updated!\n";
    cout<<endl;
}
void searchProductByID(struct Product p[]){
    int ID;
    cout<<"\n3. Display information a product by ID\n";
    cout<<"\nEnter product ID to display: ";cin>>ID;
    file.open("Product.txt",ios::in);
    int i=0;
    while(!file.eof()){
        file>>p[i].ID;
        file>>p[i].category;
        file>>p[i].name;
        file>>p[i].bar_code;
        file>>p[i].quantity;
        file>>p[i].Product_date.dd;
        file>>p[i].Product_date.mm;
        file>>p[i].Product_date.yy;
        file>>p[i].Expired_date.dd;
        file>>p[i].Expired_date.mm;
        file>>p[i].Expired_date.yy;
        file>>p[i].price;
        i = i + 1;
    }
    cout<<endl;
    cout<<left<<setw(15)<<"ID"<<left<<setw(15)<<"Category"<<left<<setw(15)<<"Name"<<left<<setw(15)<<"Bar Code"<<left<<setw(15)<<"Quantity"<<left<<setw(35)<<"Product Date(dd mm yyyy)"<<left<<setw(40)<<
    "Expired Date(dd mm yyyy)"<<left<<setw(20)<<"Price($)/1unit"<<endl;
    for(int k=0;k<i-1;k++){
        if(p[k].ID == ID){
            cout<<left<<setw(15)<<p[k].ID;
            cout<<left<<setw(15)<<p[k].category;
            cout<<left<<setw(15)<<p[k].name;
            cout<<left<<setw(15)<<p[k].bar_code;
            cout<<left<<setw(15)<<p[k].quantity;
            cout<<p[k].Product_date.dd<<" \t ";
            cout<<p[k].Product_date.mm<<" \t ";
            cout<<left<<setw(20)<<p[k].Product_date.yy;
            cout<<p[k].Expired_date.dd<<" \t ";
            cout<<p[k].Expired_date.mm<<" \t ";
            cout<<left<<setw(20)<<p[k].Expired_date.yy;
            cout<<left<<setw(15)<<p[k].price;
        }
    }
    cout<<endl<<endl;
    file.close();
}

void cls(){
     system("cls");

}

void intro(){

 cout <<"\n\n\t\t***Product Management***";
}

main(){

          int size;
          int option;
          system("Color 03");
          system("Color 9F");
          system("cls");
       while(true){
        intro();
        cout<<"\n\n\t\t1. Create products";
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
            break;
        }
    }
}
