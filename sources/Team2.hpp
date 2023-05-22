#include <iostream>
#include <stdexcept>
#include <string>
#include "Team.hpp"

using namespace std;

#ifndef TEAM2_H
#define TEAM2_H

namespace ariel{
    class Team2: public Team{


//Going over all members of the group (for attacking, printing, or comparing) 
//will always be done in the following order: 
//The transition will be made according to the order in which the characters were added.
                      
        public:
            Team2(Character* chrctr);

            void add(Character* chrctr) override;
    };

}
#endif