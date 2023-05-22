#include <iostream>
#include <stdexcept>
#include <string>
#include "Team.hpp"

using namespace std;

#ifndef SMARTTEAM_H
#define SMARTTEAM_H

namespace ariel{
    class SmartTeam: public Team{

// The same as the team, the transition to the characters will be by choice in whatever order you want. 
// It is permissible and desirable at this stage to "ask" the other group 
// about the positions of their forces and their status 
// as well as consider the situation of the attacking group in order to maximize damage.
                      
        public:
            SmartTeam(Character* chrctr);

            void attack(Team* tEnemy) override;
            
    };

}
#endif