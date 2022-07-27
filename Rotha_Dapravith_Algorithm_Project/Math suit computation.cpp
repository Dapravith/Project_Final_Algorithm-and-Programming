#include<iostream>

using namespace std;

int add(int n){

     if(n != 0)
        return n + add(n - 1);
    return 0;

}

void sumOfSeries (int number){ //1^2 + 2^2 + ... + n^2
	int sum = 0;

	sum = (number * (number + 1) * (2 * number + 1 )) / 6;

	cout << "\n\n\tThe Sum of the Series of " << number << " \n\n\tnumber = " << sum << "\n\n";

	for(int i = 1; i <= number; i++){

		if (i != number){
			cout << i << "^2 + ";
    	}else{
       		cout << i << "^2 = " << sum;
	}
}

}

int sumSquare(int n){ //1+2+3+...+n

     if(n==1){
          return 1;
     }else{
          return n*n+ sumSquare(n-1);
     }

}

void sumPrime(int x){

     int pn; //primary number
     int sum=0;
     for(int i=x;i>0;i--){
          bool not_prime = false;
          for(int j=2; j< i; j++){

               if(i%j == 0){
                    not_prime = true;
                    j = i;
               }
          }
          if(not_prime == false){
               cout<<"\n\n\tPrimary number: "<<i<<" ";
               sum = sum + i;
          }
     }
     cout<<endl<<"\n\n\tThe sum of all primary number between 1 to  "<<pn<<" is : "<<sum;
}

void sumPrime(int x);

 main(){

     system("color F1");
	int number=0;
	int n,x;
     int sum=0,i=1;
     int num,count;

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



}
