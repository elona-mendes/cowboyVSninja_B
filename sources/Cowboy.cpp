#include "Cowboy.hpp"
#include "Point.hpp"

using namespace std;
using namespace ariel; 

Cowboy::Cowboy(string nme, Point pnt): Character(pnt, nme, 110){
    // this->setName(nme);
    // this->setLocation(pnt);
    this->numBalls = 6;
    // this->setHitPoint(110);
}

void Cowboy::shoot(Character* chrctr){
    if(chrctr == this){
        throw std::runtime_error("Can't attack yourself.");
    }
    if((!chrctr->isAlive()) || (!this->isAlive())){
        throw std::runtime_error("Can't attack a died enemy or attack if you died.");
    }
    if(this->getNumBalls() > 0){
        chrctr->hit(10); 
        this->numBalls = this->numBalls - 1;
    }  
}

// Return true if the cowboy had Balls, else return false.
bool Cowboy::hasboolets(){
    if(this->numBalls >0) 
        return true;
    return false;
}
// Reload the cowboy balls, set them to 6.
void Cowboy::reload(){
    if(!this->isAlive()){
        throw std::runtime_error("Cowboy can't reload if he is died.");
    }
    this->numBalls = 6;
}

string Cowboy::print(){
    string out = "C: "; 
    if(!this->isAlive()){
        out += "(" + this->getName() + ")"; 
    }
    else{
        out += this->getName() + ", Hit points:" + std::to_string(this->getHitPoint());
    }
    out += " Position:" + this->getLocation().print();
    return out;
}

// int Cowboy::getHitPoint(){
//     return this->hitPnt;
// }
            