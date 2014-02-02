#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <time.h>

using namespace std;

void wait ( int seconds )
{
  clock_t endwait;
  endwait = clock () + seconds * CLOCKS_PER_SEC ;
  while (clock() < endwait) {}
}

/*clock_t t1 = clock();
wait (3);
clock_t t2 = clock();
wait(1);
clock_t t3 = clock();
wait(9);
clock_t t4 = clock();
wait(2);
clock_t t5 = clock();
wait(1);
clock_t t6 = clock();
wait(3);
clock_t t7 = clock();
wait(1);
clock_t t8 = clock();
wait(1)
clock_t t9 = clock();*/

//myvec[] = {t1, t2, t3, t4, t5, t6, t7, t8, t9};

int main(){
	srand(unsigned(time(NULL)));
	string filename;
	cout << "Enter name of output file: ";
	cin >> filename;
	ofstream output(filename.c_str());
	output<< "1000300"<<endl;
	for (int ii = 0; ii < 1000300; ii++){
		//srand(t10+t2+myvec[rand%9]);
		unsigned int length = (rand() % 500) + 1;
		for (int jj =1; jj <= length; jj++){
			//clock_t t10 = clock();
			//srand(t10+t2+myvec[rand%9]);
			output<<char(rand() %94 + 33);}
		output<<endl;}
		return 0;
}	
	