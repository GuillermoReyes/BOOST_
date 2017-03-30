#include <iostream>
#include <cmath>
template <typename T>
struct point{
  T lattitude; 
  T longitude; 
  point(double A, double B)
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
//just make it inline, right? why not.. 
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
  point<double> hello(52.373,4.8922);
  point<double> no(41.38333,2.18333);
  double answer = distance(hello, no);
  std::cout<<answer*6378.137<<std::endl; 
   
  return 0;


}
