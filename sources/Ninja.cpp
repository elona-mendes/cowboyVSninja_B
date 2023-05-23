#include "Ninja.hpp"

using namespace std;
using namespace ariel; 

// Recive poiter to character and move to him the same as his speed 
// (if speed = 6, move distance 6).
void Ninja::move(Character* chrctr){
    // if(this->getLocation().distance(chrctr->getLocation()) > 1){
        this->setLocation(Point::moveTowards(this->getLocation(), chrctr->getLocation(), this->getSpeed()));
    // }
    
}

// If the Ninja is alive and distance from enemy < 1:
// enemy -40 hitPnt, else nithing happend.
bool Ninja::slash(Character* chrctr){
    if(chrctr == this){
        throw std::runtime_error("Can't attack yourself.");
    }
    if((!chrctr->isAlive()) || (!this->isAlive())){
        throw std::runtime_error("Can't attack a died enemy or attack if you died.");
    }
    if(this->distance(chrctr)<1){
            chrctr->hit(40);
            return true;
    }
    return false;
}

string Ninja::print(){
    string out = "N: "; 
    if(!this->isAlive()){
        out += "(" + this->getName() + ")"; 
    }
    else{
        out += this->getName() + ", Hit points:" + std::to_string(this->getHitPoint());
    }
    out += " Position:" + this->getLocation().print();
    return out;
}