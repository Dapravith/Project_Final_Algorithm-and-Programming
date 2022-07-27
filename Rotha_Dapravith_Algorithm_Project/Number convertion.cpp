#include<iostream>
#include<cmath>
#include<string.h>

#define BASE_16 16
using namespace std;

long binaryToDecimal(long n);
long decimalToBinary(long n);
long octalToDecimal(long n);
long decimalToOctal(long n);


// Function to convert a binary number to decimal number
long binaryToDecimal(long n) {
    int remainder;
    long decimal = 0, i=0;
    while(n != 0) {
        remainder = n%10;
        n = n/10;
        decimal = decimal + (remainder*pow(2,i));
        ++i;
    }
    return decimal;
}

long decimalToBinary(long n) {
    int remainder;
    long binary = 0, i = 1;

    while(n != 0) {
        remainder = n%2;
        n = n/2;
        binary= binary + (remainder*i);
        i = i*10;
    }
    return binary;
}

long octalToDecimal(long n) {
 int remainder;
    long decimal = 0, i=0;
    while(n != 0) {
        remainder = n%10;
        n = n/10;
        decimal = decimal + (remainder*pow(8,i));
        ++i;
    }
    return decimal;
}

long decimalToOctal(long n) {
    int remainder;
    long octal = 0, i = 1;

    while(n != 0) {
        remainder = n%8;
        n = n/8;
        octal = octal + (remainder*i);
        i = i*10;
    }
    return octal;
}

void menu(){

     int ch;
      cout<<"==============================="<<endl;
      cout<<" MENU OF NUMBER CONVERSIONS    "<<endl;
      cout<<"==============================="<<endl;
      cout<<"1.  Binary to Decimal"<<endl;
      cout<<"2.  Decimal to Binary"<<endl;
      cout<<"3.  Octal to Decimal"<<endl;
      cout<<"4.  Decimal to Octal"<<endl;
      cout<<"5.  Decimal to HexaDecimal"<<endl;
      cout<<"0.  Exit"<<endl;
      cout<<"=============================="<<endl;
      cout<<"Enter Your Choice :";cin>>ch;


}

 main() {

     //do{

  menu();

//
//  switch(ch){
//   case 0: exit(0);
//   case 1: binaryToDecimal(); break;
//   case 2: decimalToBinary(); break;
//   case 3: octalToDecimal(); break;
//   case 4: decimalToOctal();break;
//   case 5: hexadecimal(); break;
//   default:
//    cout<<"Wrong Input";
//  }
//  getch();
// }while(ch>0);

    while(1>0){

    long binary;
    long decimal;
    long octal;
    char hexadecimal[40];
    int index, remaindar;
     int ch;
    if(ch==1){
    cout << "\n\n\tEnter a binary number: ";
    cin >> binary;

    cout << "\n\n\tDecimal number = " << binaryToDecimal(binary);
    }else if(ch==2){

    cout <<"\n\n\tEnter a decimal number: ";
    cin >> decimal;
    cout << "\n\n\tBinary number = " << decimalToBinary(decimal);
    }
    else if(ch==3){
    cout << "\n\n\tEnter an octal number: ";
    cin >> octal;
    cout << "\n\n\tDecimal number : " << octalToDecimal(octal);
    }
    else if(ch==4){
    cout << "\n\n\tEnter a decimal number: ";
    cin >> decimal;
    cout << "\n\n\tOctal number : " << decimalToOctal(decimal);
    }
    else if(ch==5){
     char hexDigits[] = "0123456789ABCDEF";

    // Take a Decimal Number as input form user
    cout << "\n\n\tEnter a Decimal Number: ";
    cin >> decimal;

    index = 0;

    // Convert Decimal Number to Hexadecimal Numbers
    while(decimal != 0) {
        remaindar = decimal % BASE_16;
        hexadecimal[index] = hexDigits[remaindar];
        decimal /= BASE_16;
        index++;
    }
    hexadecimal[index] = '\0';

    strrev(hexadecimal);

    cout << "\n\n\tHexadecimal Number : " << hexadecimal;
    }

//}
}


}


