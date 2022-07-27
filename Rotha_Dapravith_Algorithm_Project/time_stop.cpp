#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

main(){

     time_t * rawtime = new time_t;
     struct tm * timeinfo;
     time(rawtime);
     timeinfo = localtime(rawtime);

     ofstream file("Time.txt"); // File output stream, the file that we'll write to it
     if(!file) { // if can't open file
     cout << "Error while creating file!";
     cin.get(); // pause
     return 1;
     }

     file << asctime(timeinfo);
     file.close();

     cout << "Time wrote successfully!" << endl;
     time_t date = time(0);
    char * dt = ctime(&date);

    cout<<"The date is: "<<dt;
     return 0;

}
