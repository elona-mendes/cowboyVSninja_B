#include <iostream>
#include <stdexcept>
#include <string>
#include "Point.hpp"
#include "Character.hpp"

using namespace std;

#ifndef NINJA_H
#define NINJA_H

namespace ariel{
    class Ninja: public Character{

        protected:

            string name;
            Point point;
            int speed;
            int hitPnt;

        public:

            Ninja(string nme, Point pnt, int spd, int hit): Character(pnt, nme, hit), speed(spd){
                // this->name = nme;
                // this->point = pnt;
                // this->hitPnt = hit;
                // this->speed = spd;
            } 
                  
            // Recive poiter to character and move to him the same as his speed 
            // (if speed = 6, move distance 6).
            void move(Character* chrctr) override;

            // If the Ninja is alive and distance from enemy < 1:
            // enemy -40 hitPnt, else nothing happend.
            bool slash(Character* chrctr) override;

            int getSpeed() const{
                return this->speed;
            }

            // Prints the name of the character, 
            // the number of its hit points, 
            // and the point where the character is.
            // If the character dies a number of - - hit points will not be printed, 
            // and the character's name will appear in parentheses. 
            // Before the name will appear a letter indicating the type of character: 
            // N for ninja and C for morning.
            string print() override;

            // int getHitPoint();

    };

}
#endif