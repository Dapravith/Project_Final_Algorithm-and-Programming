#include<iostream>
#include<iomanip>
#include<fstream>
#include<math.h>
#include<string.h>
using namespace std;

struct Date{
    int d;
    int m;
    int y;
};

struct Product{
    string ID;
    string name;
    string factory;
    Date mfd;
    Date exp;
    int Barcode;
    float price;
    string cat;
};

int Check_line_of_a_file(string fname, string ID, string ext){///check if the new ID are already created or not
    fstream f1;
    string line;
    int s=0;//get how many ID are in fname, to know the size array to create, using Queue will be harder
    f1.open(fname+ext+"..txt", ios::in);
    while(!f1.eof()){
        getline(f1, line);
        s++;
    }
    f1.close();

    string str[s];
    f1.open(fname+ext+"..txt", ios::in);
    int i=0;
    while(!f1.eof()){
            getline(f1, line);
            str[i]=line;
            i++;
    }
    f1.close();

    int m=0;
    for(int j=0;j<s;j++){
        if(str[j]==ID){///compare each ID to the all  saved  IDs
            m=1;
            break;
        }
    }
    return m;
}


Product Create_Product(){
    Product P;
    cout<<"\t    Product'sName: ";
    getline(cin>>ws, P.name);
    cout<<"\t    Product'sCompany: ";
    getline(cin>>ws,P.factory);
    cout<<"\t    Product'sBarcode:  ";
    cin>>P.Barcode;
    cout<<"\t    Manufactured date MFD: dd/mm/yy: ";
    cin>>P.mfd.d>>P.mfd.m>>P.mfd.y;
    cout<<"\t    Expire date EXP: dd/mm/yy: ";
    cin>>P.exp.d>>P.exp.m>>P.exp.y;
    cout<<"\t    Price($): ";
    cin>>P.price;
    cout<<"\t    Category: ";
    getline(cin>>ws,P.cat);

    return P;
}


void save_product(Product PD, string ext){///using ios::out so this can be used for update too
    fstream f1;

    f1.open(PD.ID+ext+".txt", ios::out);
    f1<<"\nID: "<<PD.ID<<endl;
    f1<<"Name: "<<PD.name<<endl;
    f1<<"Manufacturer's Company: "<<PD.factory<<endl;
    f1<<"Barcode: "<<PD.Barcode<<endl;
    f1<<"MFD: "<<PD.mfd.d<<" "<<PD.mfd.m<<" "<<PD.mfd.y<<endl;
    f1<<"EXP: "<<PD.exp.d<<" "<<PD.exp.m<<" "<<PD.exp.y<<endl;
    f1<<"Price($): "<<PD.price<<endl;
    f1<<"Category: "<<PD.cat;
    f1.close();
}


void delete_File(string fname, string ext){///delete file

    char c[fname.length()+ext.length()+5];
    strcpy(c, (fname+ext+".txt").c_str());

    if(remove(c)==0){
        cout<<"\t    Product has been Deleted successfully!"<<endl;
    }else cout<<"\t   Error!!!"<<endl;
}


void remove_ID_in_File(string fname, string ID, string ext){//remove a line from the file that store all ID
    fstream f1;
    string line;
    int s=0;//get how many ID are in fname, to know the size array to create, using Queue will be harder
    f1.open(fname+ext+"..txt", ios::in);
    while(!f1.eof()){
        getline(f1, line);
        s++;
    }
    f1.close();
    s=s-1;
    string str[s];
    f1.open(fname+ext+"..txt", ios::in);
    getline(f1,line);//skip 1st line
    for(int i=0;i<s;i++){
        getline(f1,line);
        str[i]=line;
    }
    f1.close();

    f1.open(fname+ext+"..txt", ios::out);
    for(int i=0;i<s;i++){///overwrite the file excluding the Deleted ID
        if(str[i]!=ID) f1<<endl<<str[i];
    }
    f1.close();
}


void save_line_to_a_file(string fname, string ID, string ext){///store all IDs/files of product or book in fname
    fstream f1;
    f1.open(fname+ext+"..txt", ios::app);
    f1<<endl<<ID;
    f1.close();
}


void display_data_from_a_file(string ID, string ext, int n=NULL){///n is to manage how to display from txt file
    fstream f1;
    string line;
    f1.open(ID+ext+".txt", ios::in);
    if(n!=NULL) getline(f1, line);//skip 1st line as n!=NULL is when the first line is...empty

    while(!f1.eof()){
        getline(f1, line);

        if(n==NULL) cout<<"\t    "<<line<<endl;
        else cout<<"    "<<line;
    }
    f1.close();
    cout<<endl;
}


void createEmpty_File(string fname, string ext){
    fstream f1;
    f1.open(fname+ext+"..txt", ios::app);
    f1<<"";
    f1.close();
}



void Display_all_data(string fname, string ext){
    fstream f1;
    fstream f2;
    string line;
    string text;

    int z=0;
    f1.open(fname+ ext+"..txt", ios::in);
    getline(f1, line);///skip 1st line
    while(!f1.eof()){
            z=1;
        getline(f1, line);
        f2.open(line+ext+".txt", ios::in);
        while(!f2.eof()){
            getline(f2, text);
            cout<<"\t    "<<text<<endl;
        }
        f2.close();
        cout<<endl;
    }
    f1.close();
    if(z==0)   cout<<"\t>>>>>>>> No record data <<<<<<<<"<<endl<<endl;
}


void display_data_by_Cat(string fname, string cat, string ext){
    fstream f1;
    fstream f2;
    string line;
    string C;
    f1.open(fname+ext+"..txt", ios::in);
    getline(f1, line);
    while(!f1.eof()){
        getline(f1, line);
        f2.open(line+ext+".txt", ios::in);
        while(!f2.eof()){
            getline(f2, C);
        }
        f2.close();
        C=C.substr(10, C.length());
        if(C==cat){
            display_data_from_a_file(line, ext);
        }
    }
    f1.close();
}

void cls();


void Product_Management(){
    ///these 2 files can not be modified from program,
    createEmpty_File("ProductID", ".p");///store all ID
    createEmpty_File("Product_Cat", ".p");///Store all catgory
    string np;
    string s;
    Product PD;

    while(1){


        cout<<"\n\n\tWelcome to product management menu"<<endl;
        cout<<"\n\t ***Product management***"<<endl<<endl;
        cout<<"\t  1. Create product"<<endl<<endl;
        cout<<"\t  2. Display all products"<<endl<<endl;
        cout<<"\t  3. Display  a product by ID"<<endl<<endl;
        cout<<"\t  4. Update a product by ID"<<endl<<endl;
        cout<<"\t  5. Delete a product by ID"<<endl<<endl;
        cout<<"\t  6. Search for a product"<<endl<<endl;
        cout<<"\t  0.Exit program"<<endl<<endl;
        cout<<"\t  Choose your option: ";
        cin>>np;
        system("cls");
        cout<<"\t  Enter an Option N.o: "<<np<<endl;

        if(np=="1"){
               cls();
                cout<<"\t  1. Create product"<<endl;
                cout<<"\t    Enter the information of product: "<<endl;
                cout<<"\t    ID: ";
                cin>>s;
                if(Check_line_of_a_file("ProductID", s,  ".p")==1){//if the ID has already existed
                cout<<"\t    This ID has already existed\n\t    ----return to main Menu."<<endl;
                }else{
                    PD=Create_Product();
                    PD.ID=s;
                        cout<<"\t    1. Save product information with its ID"<<endl;
                        cout<<"\t    Otherwise not"<<endl;
                        cout<<"\t    Enter an ID to save: ";      cin>>s;
                    if(s=="1"){
                        save_product(PD,  ".pro");//save to file, file name is the ID +.pro
                        save_line_to_a_file("ProductID", PD.ID,  ".p");//save its ID to Product_ID.pro..txt

                        if(Check_line_of_a_file("Product_Cat", PD.cat, ".p")==0){
                            save_line_to_a_file("Product_Cat", PD.cat, ".p");//save the tag/category
                        }
                        cout<<"\t    Product has been saved successfully"<<endl;
                    }
                }


        }else if(np=="2"){
               cls();
                cout<<"\t  2. Display all products"<<endl;
                Display_all_data("ProductID",  ".p");


        }else if(np=="3"){
                cls();
                cout<<"\t  3. Display  a product by ID"<<endl;
                cout<<"\t    Enter ID: ";       cin>>s;
                if(Check_line_of_a_file("ProductID", s,  ".p")==0)
                cout<<"\t    ID does not exist."<<endl<<endl;
                else    display_data_from_a_file(s,  ".p");


        }else if(np=="4"){
                cls();
                cout<<"\t  4. Update a product by ID"<<endl;
                cout<<"\t    Enter ID: ";       cin>>s;
                if(Check_line_of_a_file("ProductID", s,  ".p")==0)
                    cout<<"\t    ID does not exist."<<endl<<endl;

                else{
                    display_data_from_a_file(s,  ".p");
                    cout<<endl;
                    cout<<"\t    Enter the information of product to update: "<<endl;
                    PD=Create_Product();
                    PD.ID=s;
                    save_product(PD,  ".p");
                    cout<<"\t    Product has been updated!"<<endl;
                }

        }else if(np=="5"){
            cls();
            cout<<"\t  5. Delete a product by ID"<<endl;
            cout<<"\t    Enter ID: ";       cin>>s;
                if(Check_line_of_a_file("ProductID", s,  ".p")==0)
                    cout<<"\t    ID does not exist."<<endl<<endl;
                else{
                    delete_File(s,  ".pro");
                    remove_ID_in_File("ProductID", s,  ".p");
                }

        }else if(np=="6"){
            cls();
            cout<<"\t  6. Search for a product"<<endl;
            cout<<"\t    Product category: ";
            display_data_from_a_file("Product_Cat", ".p.", 1);
            cout<<"\t    Enter category: ";     getline(cin>>ws,s);
            if(Check_line_of_a_file("Product_Cat", s, ".p")==0){
                cout<<"\t    It's does not exist"<<endl;
            }else{
                display_data_by_Cat("ProductID", s, ".p");
            }
        }else if(np=="0"){
            cls();
            cout<<"\t  Exist"<<endl;
            break;
        }else{

          cout<<"\t   Wrong choice"<<endl;
        }
    }
}
