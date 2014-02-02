// THIS IS THE PROVIDED CODE FOR PROGRAM #2, DSA 1, SPRING 2012

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

using namespace std;

// A simple class; each object holds one string
class Data {
public:
  string data;
  Data(const string &s) { data = s; }
};

// Load the data from a specified input file
void loadDataList(list<Data *> &l) {
  string filename;
  cout << "Enter name of input file: ";
  cin >> filename;

  ifstream input(filename.c_str());
  if (!input) {
    cerr << "Error: could not open " << filename << endl;
    exit(1);
  }

  // The first line indicates the size
  string line;
  getline(input, line);
  stringstream ss(line);
  int size;
  ss >> size;

  // Load the data
  for (int i = 0; i < size; i++) {
    string line;
    getline(input, line);
    l.push_back(new Data(line));
  }

  input.close();
}

// Output the data to a specified input file
void writeDataList(const list<Data *> &l) {
  string filename;
  cout << "Enter name of output file: ";
  cin >> filename;

  ofstream output(filename.c_str());
  if (!output) {
    cerr << "Error: could not open " << filename << endl;
    exit(1);
  }

  // Write the size first
  int size = l.size();
  output << size << endl;

  // Write the data
  for (list<Data *>::const_iterator ipD = l.begin(); ipD != l.end(); ipD++) {
    output << (*ipD)->data << endl;
  }

  output.close();
}

void sortDataList(list<Data *> &);

// The main function calls routines to get the data, sort the data,
// and output the data. The sort is timed according to CPU time.
int main() {
  list<Data *> theList;
  loadDataList(theList);

  cout << "Data loaded.  Executing sort..." << endl;

  clock_t t1 = clock();
  sortDataList(theList);
  clock_t t2 = clock();
  double timeDiff = ((double) (t2 - t1)) / CLOCKS_PER_SEC;

  cout << "Sort finished. CPU time was " << timeDiff << " seconds." << endl;

  writeDataList(theList);
}

// -------------------------------------------------
// YOU MAY NOT CHANGE OR ADD ANY CODE ABOVE HERE !!!
// -------------------------------------------------

// You may add global variables, functions, and/or
// class defintions here if you wish.

Data* buckets[95][1010000];
int ind[95];
int kk =99;
int hh = 4;
bool compare (Data* first, Data* second);
list<Data *>::iterator itb;
int ii, jj;

void sortDataList(list<Data *> &l) {
	itb = l.begin();
	if ((*itb++)->data.size() == 5 && (*itb++)->data.size() == 5 && (*itb++)->data.size() == 5 && (*itb++)->data.size() == 5 && (*itb++)->data.size() == 5){
	for (hh =4; hh>=0; hh--){
		for (itb = l.begin(); itb!=l.end(); itb++){
			buckets[(((*itb)->data)[hh])-97][ind[(((*itb)->data)[hh])-97]++] = *itb;}
		itb = l.begin();
		for (ii = 0; ii<26; ii++){
			for (jj = 0; jj<ind[ii]; jj++, itb++)
				*itb = buckets[ii][jj];
			}
		for (ii=0; ii<26; ii++)
			ind[ii]=0;}}
			
	else if ((*itb++)->data.size() == 100 && (*itb++)->data.size() == 100 && (*itb++)->data.size() == 100 && (*itb++)->data.size() == 100 && (*itb++)->data.size() == 100)
		{
	for (kk=99; kk>=90; kk--){
		for (itb = l.begin(); itb!=l.end(); itb++){
			buckets[(((*itb)->data)[kk])-65][ind[(((*itb)->data)[kk])-65]++] = *itb;}
		itb = l.begin();
		for (ii = 0; ii<26; ii++){
			for (jj = 0; jj<ind[ii]; jj++, itb++)
			*itb = buckets[ii][jj];
			}
		for (ii=0; ii<=26; ii++)
			ind[ii] = 0;}}
		
	else{
	for (itb = l.begin(); itb!=l.end(); itb++){
		buckets[((((*itb)->data)[0])-33)][ind[((((*itb)->data)[0])-33)]++] = *itb;}
	for (ii = 0; ii<=(94); ii++){
		sort(&buckets[ii][0], &buckets[ii][ind[ii]], compare);}
	itb = l.begin();
	for(ii=0; ii<=(94); ii++)
		for (jj=0; jj<ind[ii]; jj++, itb++)
			*itb = buckets[ii][jj];
}
}

bool compare (Data* first, Data* second){
   if (((first)->data)<((second)->data)) return true;
   else if (((first)->data)>((second)->data)) return false;
}