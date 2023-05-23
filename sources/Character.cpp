#include "Character.hpp"

using namespace std;
using namespace ariel; 

int Character::getHitPoint(){
    return this->hitPnt;
}

void Character::shoot(Character* chrctr){
    return;
}
bool Character::hasboolets(){
    return 0;
}
void Character::reload(){
    return;
}
void Character::move(Character* chrctr){
    return;
}
bool Character::slash(Character* chrctr){
    return 0;
}

bool Character::isAlive(){
    if (this->hitPnt > 0){
        return 1;
    }
    return 0;
}
double Character::distance(Character* place1){
    return this->location.distance(place1->getLocation());
}

void Character::hit(int hits){
    if(hits < 0){
        throw std::invalid_argument("Can't hit and maximize hit enemy hitPoints.");
    }
    this->hitPnt = this->hitPnt - hits;
}