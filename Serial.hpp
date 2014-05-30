#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Serial {

  vector< vector<double> > A;
  vector< double > x; 
  vector< double > b; 

    double vecXvec(vector<double> a, vector<double> b);
  public: 
    int n; //dimension of matrixA
    Serial(string fileName);
  //  ~Serial();
    void printInput();
    void printResult();
    void matMult();
};

Serial::Serial(string fileName) {
  ifstream dataFile(fileName.c_str());
  if(!dataFile) cerr << "Cannot open file" << fileName;
   
  dataFile >> n;
  int i,j;
  double tmp;
  vector< double > vtmp;
  //reading n*n data values into tmpA 
  
  for(i=0; i<n; i++) {
    for(j=0; j<n; ++j) {
      dataFile >> tmp;
      vtmp.push_back(tmp);
    } 
    A.push_back(vtmp);
    vtmp.clear();
  }
   
  for(i=0; i<n; i++) {
    dataFile >> tmp;
    x.push_back(tmp); 
  }

  dataFile.close();
  
}

void Serial::printInput() {
  for(int i=0; i<A.size(); i++) {
    for(int j=0; j<A[i].size(); j++) cout << A[i][j] << "\t";
    cout << "\n";
  }
  cout << '\n'; 
  for(int k=0; k<x.size(); k++) cout << x[k] << "\t";
  cout << '\n';
}

void Serial::matMult() {
  for(int i=0; i<A.size(); i++) {
    b.push_back(vecXvec(A[i],x));
  }
}

double Serial::vecXvec(vector<double> a, vector<double> b) {
  //assuming that the two vectors are dimensionally compatible
  double counter = 0; 
  for(int i=0; i<a.size(); i++) {
    counter += a[i]*b[i];
  }

  return counter;
} 
void Serial::printResult() {
  for(int k=0; k<b.size(); k++) cout << b[k] << "\t";
  cout << '\n';
}
