#include <stdlib.h>
#include <valarray>
#include "Serial.hpp"

using namespace std;

int main( int arg, char **argv) {

  if( argv[1] == NULL ) {
    cout << "Usage:" << "./" << argv[0] << " <data file> \n"; 
    exit(-1);
  }
  
  Serial turtle(argv[1]);
  //turtle.printInput();  
  turtle.matMult();
  turtle.printResult();
  return 0;
}

