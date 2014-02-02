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

int main(){
	srand(unsigned(time(NULL)));
	string uni;
	string truth;
	string final;
	unsigned long size;
	unsigned long value = 0;
	unsigned long this_guy;
	string filename;
	unsigned long Remainder[200];
	unsigned long Div[200];
	cout << "Enter name of output file: ";
	cin >> filename;
	ofstream output(filename.c_str());
	int va;
	
	output<< "1000300"<<endl;
		for (int jj =1; jj <= 100; jj++){
			va = (rand() %26 + 65);
			//cout << va<<endl;
			uni.push_back(char(va));
			//cout<<uni<<endl;
			//cout<<"done"<<endl;
			}
			//output<<uni<<endl;
			
			cout<<uni<<endl;
			//cout<<uni[0]-65;
			
		/*for (int uu = 0; uu<=99; uu++){
			value = value + (((uni[uu])-65)^(-uu+99));
			cout<<"value is"<<uni[uu]-65;}*/			
		
		for (int ii =1; ii <=1000300; ii++){
			int pp=1;
			truth.clear();
			final.clear();
			this_guy = ii + rand()%10 - 5;
			Div[0] = this_guy;
			Remainder[0] = 5;
			//cout<<"thisG:"<<this_guy<<"\t"<<Div[pp-1]/26<<endl;
			truth+= (char (65));
			if ((Div[pp-1]/26)>=1){
			while ((Div[pp-1]/26)>=1){
				//cout<<"while loop"<<endl;
				Div[pp] = (Div[pp-1]/26);
				Remainder[pp] = (Div[pp-1]%26);
				truth+= (char(Remainder[pp]+65));
				pp++;
				//cout<<pp<<endl;
				}
			truth[0] = (char (Div[pp-1]+65));
				//z++;}
			//truth.push_back (char (Div[pp-1]+65));
			/*for (int ll = (pp-1); ll>1 ; ll--){
				truth.push_back (char(Remainder[ll]+65));}*/
			//output<<truth<<endl;
			}
			else {
				truth[0] = (char (Div[pp-1]+65));
				//output<<truth<<endl;
				}
			size = truth.size();
			for (int ttt = 0; ttt<100-size; ttt++)
				final += uni[ttt];
			for (int rrr = 100 - size; rrr<100; rrr++)
				final += truth[rrr-100+size];
			output<<final<<endl;}
			cout<<"size:"<<size;
		return 0;
	
}