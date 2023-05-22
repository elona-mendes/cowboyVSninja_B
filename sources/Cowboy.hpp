#include <iostream>
#include <stdexcept>
#include <string>
#include "Character.hpp"

using namespace std;

#ifndef COWBOY_H
#define COWBOY_H

namespace ariel{
    // class Cowboy{
    class Cowboy: public Character{
      
        private:
            int numBalls;
                
        public:

            Cowboy(string name, Point pnt);

            int getNumBalls(){
                return this->numBalls;
            }

            // If the cowboy is alive: "shoot" the enemy, 
            //-10 to enemy "hitPnt" and -1 to "numBalls". 
            void shoot(Character* chrctr);
            // Return true if the cowboy had Balls, else return false.
            bool hasboolets();
            // Reload the cowboy balls, set them to 6.
            void reload();

            // Prints the name of the character, 
            // the number of its hit points, 
            // and the point where the character is.
            // If the character dies a number of - - hit points will not be printed, 
            // and the character's name will appear in parentheses. 
            // Before the name will appear a letter indicating the type of character: 
            // N for ninja and C for morning.
            string print();

            int getHitPoint();

    };

}
#endif