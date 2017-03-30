#include <iostream>
#include <cmath>
//earth point representation
template <typename T>
struct point{
  T lattitude; 
  T longitude; 
  point(T A, T B)
    :lattitude(A) , longitude(B)
  {
  }
};
namespace traits
{
  template <typename P, int D>
  struct access {};

}
namespace traits
{
  template <typename T>
  struct access<point<T>, 0>
  {
    static T get(point<T> const& p)
    {
      return p.lattitude; 
    }


  };
  template <typename T>
  struct access<point<T>, 1>
  {
    static T get(point<T> const& p)
    {
      return p.longitude;
    }


  };
}
 
template <int D, typename P>
inline double get(P const& p)
{
  return traits::access<P,D>::get(p);
}
template <typename P1, typename P2>
double distance(P1 const& a, P2 const& b)
{
  
  double dx = std::abs(get<0>(a) - get<0>(b));
  //for small distance we can use this formula
  double dy = std::abs(get<1>(a) - get<1>(b)); 
  //can make the following segment multithreaded ? 
  double t1 = std::sin(dx/2)*std::sin(dx/2); 
  double t2 = std::cos(get<0>(a))*std::cos(get<0>(b))*std::sin(dy/2.0)*std::sin(dy/2.0);
  double t3 = std::sqrt(t1 + t2); 
  
  return 2.0*std::asin(t3);  



}

int main(){
  //can use typedefs to make this a little clearer.
  point<double> hello(.914,0.08538);
  point<double> no(0.72227,0.038106);
  double answer = distance(hello, no);
  std::cout<<answer*6378.137<<std::endl; 
   
  return 0;


}
