#include <iostream>
#include <stdexcept>
#include <string>
#include "Point.hpp"

using namespace std;

#ifndef CHARACTER_H
#define CHARACTER_H

namespace ariel{
    class Character{
      
        private:
            Point location;
            string name;
            int hitPnt;
            bool inTeam;
                   
        public:

            Character(Point lctin, string nme, int hit):name(std::move( nme)), location(lctin), hitPnt(hit), inTeam(false){
            }

            // From here to destructor - take from chatGPT
            // Copy constructor
            Character(const Character& other) : location(other.location), name(other.name), hitPnt(other.hitPnt), inTeam(other.inTeam) {}

            // Copy assignment operator
            Character& operator=(const Character& other) {
                if (this != &other) {
                    location = other.location;
                    name = other.name;
                    hitPnt = other.hitPnt;
                    inTeam = other.inTeam;
                }
                return *this;
            }

            // Move constructor
            Character(Character&& other) noexcept : location(other.location), name(std::move(other.name)), hitPnt(other.hitPnt), inTeam(other.inTeam) {}

            // Move assignment operator
            Character& operator=(Character&& other) noexcept {
                if (this != &other) {
                    location = other.location;
                    name = std::move(other.name);
                    hitPnt = other.hitPnt;
                    inTeam = other.inTeam;
                }
                return *this;
            }

            // Destructor
            virtual ~Character() {}

            //Getters
            string getName(){
                return this->name;
            }
            Point getLocation(){
                return this->location;
            }
            int getHitPoint();

            //Setters
            void setName(string& nme){
                this->name = nme;
            }
            void setLocation(Point loca){
                this->location = loca;
            }
            void setHitPoint(int hit){
                this->hitPnt = hit;
            }

            bool isInTeam() const{
                return this->inTeam;
            }
            void setInTeam(bool flag){
                this->inTeam = flag;
            }

            // Prints the name of the character, 
            // the number of its hit points, 
            // and the point where the character is.
            // If the character dies a number of - - hit points will not be printed, 
            // and the character's name will appear in parentheses. 
            // Before the name will appear a letter indicating the type of character: 
            // N for ninja and C for morning.
            virtual string print() =0;
            bool isAlive();
            double distance(Character* place1);
            void hit(int hits);

            virtual void shoot(Character* chrctr);
            virtual bool hasboolets();
            virtual void reload();
            virtual void move(Character* chrctr);
            virtual bool slash(Character* chrctr);

    };
}
#endif