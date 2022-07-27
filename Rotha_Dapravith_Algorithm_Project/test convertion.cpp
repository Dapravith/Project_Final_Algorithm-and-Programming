#include<iostream>
#include<cmath>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<time.h>
#include<fstream>

using namespace std;

void binaryToDecimal(){

     int a[20],i,j,temp,flag=0,sum=0;
     long num;

     cout<<"\n\tEnter Binary Number :";
     cin>>num;
     i=0;
     while(num){
     temp=num%10;
     num=num/10;
     flag++;
     a[i]=temp;
     i++;
     }
     for(i=0;i<flag;i++){
     sum+=(pow(2,i)*a[i]);
     }
 cout<<"\n\tDecimal Number of Entered Binary is :"<<sum;

}

void decimalToBinary(){
     int num,temp,i=0,bin[20];
     cout<<"\n\tEnter Decimal Number :";
     cin>>num;
     while(num>0){
     temp=num%2;
     bin[i++]=temp;
     num=num/2;
     }
     cout<<"\n\tBinary Number of Given Decimal Number :";

     for(int j=i-1;j>=0;j--){
     cout<<bin[j];
     }
}

void octalToDecimal(){
     char num[30];
     int i,sum=0,temp=0;
     cout<<"\n\tEnter Octal Number :";
     cin>>num;
     int len=strlen(num);

     for(i=len-1;i>=0;i--){
     sum+=(pow(8,temp))*(((int)num[i])-48);
     temp++;
     }
     cout<<"\n\tDecimal Number of given Octal number is "<<sum;

}


void decimalToOctal(){
     int num,temp,i=0,octal[20];
     cout<<"\n\tEnter Decimal Number :";
     cin>>num;
     while(num>0){
     temp=num%8;
     num=num/8;
     octal[i]=temp;
     i++;
     }
     cout<<"\n\tOctal Number of Entered Decimal Number is ";

     for(int j=i-1;j>=0;j--){
     cout<<octal[j];
     }
}


void decimaltoHexaDecimal(){

      int num,temp,i=0;
      char hexadecimal[20];
      cout<<"\n\tEnter Decimal Number :";
      cin>>num;

      while(num>0){
       temp=num%16;
       num=num/16;

       if(temp==10){
        hexadecimal[i]='A';
       }
       else if(temp==11){
        hexadecimal[i]='B';
       }
       else if(temp==12){

        hexadecimal[i]='C';
       }
       else if(temp==13){
        hexadecimal[i]='D';
       }
       else if(temp==14){
        hexadecimal[i]='E';
       }
       else if(temp==15){
        hexadecimal[i]='F';
       }
       else{
        hexadecimal[i]=(char(temp))+48;
       }
       i++;
      }
      hexadecimal[i]='\0';
      int len=strlen(hexadecimal);
      cout<<"\n\tOctal Number of Entered Decimal Number is ";

      for(i=len-1;i>=0;i--){
       cout<<hexadecimal[i];
      }
      cout<<"\n\n";
}


void cls(){
     system("cls");
}

void displaymenu(){

      cout<<"\n\n";
      cout<<"\n\t============================="<<endl;
      cout<<" \n\t | ** NUMBER CONVERSIONS ** |"<<endl;
      cout<<"\n\t============================="<<endl;
      cout<<"\n\t1.  Binary to Decimal"<<endl;
      cout<<"\n\t2.  Decimal to Binary"<<endl;
      cout<<"\n\t3.  Octal to Decimal"<<endl;
      cout<<"\n\t4.  Decimal to Octal"<<endl;
      cout<<"\n\t5.  Decimal to HexaDecimal"<<endl;
      cout<<"\n\t0.  quit program"<<endl;
      cout<<"\n\t**************************"<<endl;
      cout<<"\n\tPlease input Your Choice : ";

}

main(){

     system("color F9");
     system("color 0");
     int choice;
     fstream f1;
     f1.open("MainData1.txt",ios::in);
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
   default:
    cout<<"\n\tInvalid Input! Please check number choice in menu";
    cout<<"\n\n";
    system("\n\tpause");
  }

  getch();
 }

 while(choice>0);

 f1.close();


}



