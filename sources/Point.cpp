#include "Point.hpp"

using namespace std;
using namespace ariel; 


Point::Point(double xPnt, double yPnt): xPoint(xPnt), yPoint(yPnt){
    this->xPoint = xPnt;
    this->yPoint = yPnt;
}

string Point::print(){
    // take from chatGPT:
    std::stringstream ss;
    ss << "(" << this->xPoint << ", " << this->yPoint << ")";
    std::string str = ss.str();
    return str;
}

double Point::distance(Point pntB){
    double distx = pow((pntB.getX() - this->xPoint), 2);
    double disty = pow((pntB.getY() - this->yPoint), 2);
    return sqrt(distx + disty);
}

Point Point::moveTowards(Point src, Point dest, double dist){
    if (dist <0)
    {
        throw std::invalid_argument("Can't move, negative distance.");
    }
    
     // take from chatGPT:
    double currentDistance = src.distance(dest);

    if ((currentDistance <= dist) || (currentDistance<1) ) {
        // If the current distance is less than or equal to the desired distance,
        // the destination point will be reached. Return the destination point.
        return dest;
    }

    double ratio = dist / currentDistance;
    double dx = dest.getX() - src.getX();
    double dy = dest.getY() - src.getY();

    Point newPosition(src.getX() + dx * ratio, src.getY() + dy * ratio);
    return newPosition;
}
