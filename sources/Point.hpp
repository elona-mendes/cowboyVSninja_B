#include <iostream>
#include <stdexcept>
#include <cmath>
#include <sstream>

#ifndef POINT_H
#define POINT_H

namespace ariel{
    class Point{
      
        private:
            double xPoint;
            double yPoint;
                   
        public:

            //Constructor
            Point(double xPnt = 0, double yPnt = 0);

            //Getters
            double getX() const{
                return this->xPoint;
            }
            double getY() const{
                return this->yPoint;
            }

            //Setters
            void setX(double newx){
                this->xPoint = newx;
            }
            void setY(double newy){
                this->yPoint = newy;
            }

            std::string print();
            double distance(Point pntB);
            static Point moveTowards(Point src, Point dest, double dist);

    };

}
#endif