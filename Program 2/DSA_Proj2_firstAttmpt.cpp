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

Data* buckets[11][26][1010000];
int ind[11][33];
int kk =99;
int hh = 4;
bool compare (Data* first, Data* second);
void T1_2sort(list<Data *> &l);
void T3sort(list<Data *> &l);
void T4sort(list<Data *> &l);
void identify(list<Data *> &l);
Data* newvec[11][1010000];
unsigned long n;
int here=0;
string temp;
list<Data *>::iterator i_1;
list<Data *>::iterator i;
list<Data *>::iterator it;
list<Data *>::iterator itb;
int ii, jj, ww, newn, tot, yy;
bool swapped;
int id [7] = {0, 0, 0, 0, 0, 0, 0};

void sortDataList(list<Data *> &l) {
	if (l.size() < 200000){
		//cout<<"This guy is T1"<<endl;
		T1_2sort(l);}
	else identify(l);
}

bool compare (Data* first, Data* second){
   if (((first)->data)<((second)->data)) return true;
   else if (((first)->data)>((second)->data)) return false;
}

void identify(list<Data *> &l) {
	itb = l.begin();
	if ((((*itb)->data)[0])<65){
		//cout<<"This guy is T2"<<endl;
		T1_2sort(l);}
	else{
	for (itb = l.begin(), yy=0; yy<6; itb++, yy++){
		if ((((*itb)->data)[0])>64 && (((*itb)->data)[0])<91){
			id[yy] = 1;}
		else if ((((*itb)->data)[0])>96 && (((*itb)->data)[0])<123){
			id [yy] = 2;}
		else id[yy] =3;}
	if (id[0] == 1 && id[1] ==1 && id[2] ==1 && id[3] ==1 && id[4] ==1 && id[5] ==1){
		//cout<<"This guy is T4"<<endl;
		T4sort(l);}
	else if (id[0] == 2 && id[1] ==2 && id[2] ==2 && id[3] ==2 && id[4] ==2 && id[5] ==2){
		//cout<<"This guy is T3"<<endl;
		T3sort(l);}
	else{
		//cout<<"This guy is T2"<<endl;
		T1_2sort(l);}
		}}

void T1_2sort(list<Data *> &l) {
	for (itb = l.begin(); itb!=l.end(); itb++){
		buckets[0][((((*itb)->data)[0])/10)-3][ind[0][((((*itb)->data)[0])/10)-3]++] = *itb;}
	//tot=0;
	for (ii = 0; ii<13; ii++){
		if (ind[0][ii]!=0){
			sort(&buckets[0][ii][0], &buckets[0][ii][ind[0][ii]], compare);
			/*for (jj = 0; jj<ind[0][ii]; jj++, tot++)
			newvec[0][tot] = buckets[0][ii][jj];*/
			}}
	itb = l.begin();
	for(ii=0; ii<13; ii++)
		for (jj=0; jj<ind[0][ii]; jj++, itb++)
			*itb = buckets[0][ii][jj];
			//l.assign(newvec[0], newvec[0]+l.size());
}

void T3sort(list<Data *> &l) {
	it = l.begin();
	for (itb = l.begin(); itb!=l.end(); itb++){
		buckets[here][(((*itb)->data)[hh])-97][ind[here][(((*itb)->data)[hh])-97]++] = *itb;}
	tot=0;
	for (ii = 0; ii<26; ii++){
			if (ind[here][ii]!=0){
				for (jj = 0; jj<ind[here][ii]; jj++, tot++)
				newvec[here][tot] = buckets[here][ii][jj];
			}}
			l.assign(newvec[here], newvec[here]+l.size());
			hh--;
			
			if (hh>=0){
				here++;
				T3sort(l);}}
				
void T4sort(list<Data *> &l) {
	it = l.begin();
	for (itb = l.begin(); itb!=l.end(); itb++){
		buckets[here][(((*itb)->data)[kk])-65][ind[here][(((*itb)->data)[kk])-65]++] = *itb;}
	tot=0;
	for (ii = 0; ii<26; ii++){
			if (ind[here][ii]!=0){
				for (jj = 0; jj<ind[here][ii]; jj++, tot++)
				newvec[here][tot] = buckets[here][ii][jj];
			}}
			l.assign(newvec[here], newvec[here]+l.size());
			kk--;
			
			if (kk>=90){
				here++;
				T4sort(l);}
			else{
			
			n =l.size();
			newn = 0;
			swapped = true;
			while(n!=0){
			while (swapped ==true){
				for (ww =1; ww < n ; ww++){
					i_1 = it;
					i = ++it;
					if ((*i_1)->data > (*i)->data){
						temp = (*i_1)->data;
						(*i_1)->data = (*i)->data;
						(*i)->data = (*i_1)->data;
						newn = ww;
						swapped = true;}
					else swapped = false;}
			n = newn;}}
}}