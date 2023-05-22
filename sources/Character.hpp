#include <iostream>
#include <stdexcept>
#include <string>
#include "Point.hpp"

using namespace std;

#ifndef CHARACTER_H
#define CHARACTER_H

namespace ariel{
    class Character{
      
        protected:
            Point location;
            string name;
            int hitPnt;
            bool inTeam;
                   
        public:

            Character(Point lctin, string nme, int hit):name(nme), location(lctin), hitPnt(hit){
                this->name = nme;
                this->location = lctin;
                this->hitPnt = hit;
                this->inTeam = false;
            }
            //Getters
            string getName(){
                return this->name;
            }
            Point getLocation(){
                return this->location;
            }
            int getHitPoint();

            bool isInTeam(){
                return this->inTeam;
            }
            void setInTeam(bool fl){
                this->inTeam = fl;
            }

            // Prints the name of the character, 
            // the number of its hit points, 
            // and the point where the character is.
            // If the character dies a number of - - hit points will not be printed, 
            // and the character's name will appear in parentheses. 
            // Before the name will appear a letter indicating the type of character: 
            // N for ninja and C for morning.
            virtual string print();
            bool isAlive();
            double distance(Character* place1);
            void hit(int hits);

            virtual void shoot(Character* chrctr);
            // Return true if the cowboy had Balls, else return false.
            virtual bool hasboolets();
            // Reload the cowboy balls, set them to 6.
            virtual void reload();
            virtual void move(Character* chrctr);
            // If the Ninja is alive and distance from enemy < 1:
            // enemy -40 hitPnt, else nothing happend.
            virtual bool slash(Character* chrctr);

    };
}
#endif