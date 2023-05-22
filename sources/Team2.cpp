#include "Team2.hpp"

using namespace std;
using namespace ariel; 

Team2::Team2(Character* chrctr): Team(chrctr){}

void Team2::add(Character* chrctr){
    if(this->players.size() >= 10){
        throw std::runtime_error("Error: There is already a maximum number of participants in the team (10).");
    }
    if(chrctr->isInTeam()){
         throw std::runtime_error("Character is already in another team.");
    }
    chrctr->setInTeam(true);
    this->players.push_back(chrctr);
}