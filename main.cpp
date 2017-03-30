#include "boostlib.hpp"


int main(){
  //can use typedefs to make this a little clearer.
  point<double> hello(.914,0.08538);
  point<double> no(0.72227,0.038106);
  double answer = distance(hello, no);
  std::cout<<answer*6378.137<<std::endl; 
   
  return 0;


}
