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
    if(tEnemy->stillAlive() == 0 || this->stillAlive() ==0 ){
        throw std::runtime_error("A Team (or you) you want to attack is died.");
    }
    int ourSize = this->players.size();
    unsigned int j = 0;
    while ((tEnemy->stillAlive() > 0) && j<ourSize){
        //attack
        //If the leader is died
        if(!(this->getLeader()->isAlive())){
            Point position = this->getLeader()->getLocation();
            double dist = std::numeric_limits<double>::max();
            for(unsigned int i = 0; i < ourSize; i++)
            {
                if (this->players[i]->isAlive()){
                    if(this->players[i]->getLocation().distance(position) < dist){
                        dist = this->players[i]->getLocation().distance(position);
                        this->setLeader(this->players[i]);
                    }
                }
            }
        }
        Character* attackEnemy;
        double dist = std::numeric_limits<double>::max();
        unsigned int vecSize = tEnemy->players.size();
        for(unsigned int i = 0; i < vecSize; i++)
        {
            if (tEnemy->players[i]->isAlive()){
                if(this->getLeader()->distance(tEnemy->players[i]) < dist){
                    dist = this->getLeader()->distance(tEnemy->players[i]);
                    attackEnemy = tEnemy->players[i];
                }
            }
        }
        //Start the attack
        if(this->players[j]->isAlive()){
            char type = (this->players[j]->print())[0];
            if(type == 'N'){
                bool ans = this->players[j]->slash(attackEnemy);
                if(!ans){
                    this->players[j]->move(attackEnemy);
                }
            }
            else if(type == 'C'){
                if(this->players[j]->hasboolets()){
                    this->players[j]->shoot(attackEnemy);
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