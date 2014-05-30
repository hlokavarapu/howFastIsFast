#include <random>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main (int argc, char **argv) {
  if( argv[1] == NULL ) {
    cerr << "Usage: ./" << argv[0] << " <specify dimension>";
    exit(-1);
  }
  int n = atoi(argv[1]);
 
  ofstream dataFile(strcat( argv[1], "_dataFile"));
  if(!dataFile) {
    cerr << "Could not create file. Check permissions.";
    exit(-1);
  }

  dataFile << n << "\n\n";
  double uBound = 1000;
  double lBound = 0;
  double randNumber;
  uniform_real_distribution<double> bellCurve(lBound, uBound);
  default_random_engine re;
  
  int i,j;
  for(i=0; i<n; i++) {
    for(j=0; j<n; j++) {
      randNumber = bellCurve(re);
      dataFile << randNumber << " "; 
    }
    dataFile << "\n";
  }
  
  dataFile << "\n";

  for(i=0; i<n; i++) {
    randNumber = bellCurve(re);
    dataFile << randNumber << " ";
  }

  dataFile.close();
}
