#include "Team.hpp"

using namespace std;
using namespace ariel; 

Team::Team(Character* chrctr){
    this->players.push_back(chrctr);
    if(chrctr->isInTeam()){
         throw std::runtime_error("Character is already in another team.");
    }
    this->leader = chrctr;
    this->leader->setInTeam(true);
}
// Add character to your group
void Team::add(Character* chrctr){
    if(this->players.size() >= 10){
        throw std::runtime_error("Error: There is already a maximum number of participants in the team (10).");
    }
    if(chrctr->isInTeam()){
         throw std::runtime_error("Character is already in another team.");
    }
    chrctr->setInTeam(true);

    char type = (chrctr->print())[0];
    if(type == 'N'){
        this->players.push_back(chrctr);
    }
    else if(type == 'C'){
        players.insert(players.begin(), chrctr);
    }
}

void Team::attack(Team* tEnemy){
    if(tEnemy == nullptr){
         throw std::invalid_argument("A Team pointer can't be null.");
    }
    if(tEnemy->stillAlive() == 0){
        throw std::runtime_error("A Team you want to attack is died.");
    }
    int ourSize = this->players.size();
    unsigned int j = 0;
    while ((tEnemy->stillAlive() > 0) && j<ourSize){
        //attack
        //If the leader is died
        if(!(tEnemy->getLeader()->isAlive())){
            double dist = std::numeric_limits<double>::max();
            unsigned int vecSize = tEnemy->players.size();
            for(unsigned int i = 0; i < vecSize; i++)
            {
                if (tEnemy->players[i]->isAlive()){
                    if(tEnemy->getLeader()->distance(tEnemy->players[i]) < dist){
                        dist = tEnemy->getLeader()->distance(tEnemy->players[i]);
                        tEnemy->setLeader(tEnemy->players[i]);
                    }
                }
            }
        }
        if(this->players[j]->isAlive()){
            char type = (this->players[j]->print())[0];
            if(type == 'N'){
                bool ans = this->players[j]->slash(tEnemy->getLeader());
                if(!ans){
                    this->players[j]->move(tEnemy->getLeader());
                }
            }
            else if(type == 'C'){
                if(this->players[j]->hasboolets()){
                    this->players[j]->shoot(tEnemy->getLeader());
                }
                else{
                    this->players[j]->reload();
                }
            }
        }
        j += 1;
    }
}

// Return the number of team character that alive.       
int Team::stillAlive(){
    int count =0;

    unsigned int vecSize = this->players.size();

    for(unsigned int i = 0; i < vecSize; i++)
    {
        if (this->players[i]->isAlive()){
            count += 1;
        }
    }
    
    return count;
}
// Print all character details.
void Team::print(){
    unsigned int vecSize = this->players.size();

    for(unsigned int i = 0; i < vecSize; i++)
    {
        cout<<this->players[i]->print()<<endl;
    }
}