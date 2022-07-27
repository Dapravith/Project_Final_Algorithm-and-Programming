#include<iostream>
#include<math.h>
using namespace std;

bool isPrime(int num){
    bool flag=true;
    for(int i = 2; i <= num / 2; i++) {
       if(num % i == 0) {
          flag = false;
          break;
       }
    }
    return flag;
}

bool isPrime(int num);

bool checkPerfect(int no){
	// 3
	int i = 0;
	int sum = 0;

	// 4
	while (i++ < no)
	{
		// 5
		if (no % i == 0 && i < no)
		{
			sum += i;
		}
	}

	return sum == no;
}

int reverseNumber(int num);
int isPalindrome(int num);

int isPalindrome(int num){

    if(num == reverseNumber(num))
    {
        return 1;
    }

    return 0;
}

int reverseNumber(int num){

    // Finding number of digits in num
    int digit = (int)log10(num);


    if(num == 0)
        return 0;
    return ((num%10 * pow(10, digit)) + reverseNumber(num/10));
}

