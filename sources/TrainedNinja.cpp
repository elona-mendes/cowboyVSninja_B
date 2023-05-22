#include "TrainedNinja.hpp"

using namespace std;
using namespace ariel; 

//constractor: hit = 120, speed = 12
TrainedNinja::TrainedNinja(string nme, Point pnt):Ninja(nme, pnt, 12, 120){
    this->name = nme;
    this->point = pnt;
    this->hitPnt = 120;
    this->speed = 12;
}