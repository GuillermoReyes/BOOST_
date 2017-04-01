//
//  main.cpp
//  boost-test
//
//  Created by Guillermo Reyes on 3/30/17.
//  Copyright © 2017 Guillermo Reyes. All rights reserved.
//
#include <boost/geometry.hpp>
#include <boost/geometry/geometries/geometries.hpp>


#include <boost/geometry/geometries/point_xy.hpp>

#include "boostlib.hpp"




#include <iostream>

int main(int argc, const char * argv[]) {
    
    // insert code here...
    typedef boost::geometry::model::d2::point_xy<double> point_type;
    typedef boost::geometry::model::point<float, 2, boost::geometry::cs::spherical_equatorial<boost::geometry::degree> > P;
    boost::geometry::model::linestring<P> line;
    line.push_back(P(52.373056,4.89222));
    line.push_back(P(41.2833, 2.1833));
    double const mean_radius = 6371.0;
    std::cout << "length is "
    << length(line, boost::geometry::strategy::distance::haversine<float>(mean_radius) )
    << " kilometers " << std::endl;
    
    point_type q(10.0,12);
    point_type s(45.0,13.0);
    // this is the code used by boost
    //TODO: time the code 
    point<double> x1(.914,0.08538);
    point<double> x2(0.72227, 0.038106);
    //std::cout << boost::geometry::distance(q,s) << std::endl;
    
    //this is my code
    std::cout<<" length with my code is : "<<distance(x1,x2)*6371.0<<std::endl;
    return 0;
}
