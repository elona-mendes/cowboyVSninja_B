#include "SmartTeam.hpp"

using namespace std;
using namespace ariel; 

SmartTeam::SmartTeam(Character* chrctr): Team(chrctr){}

void SmartTeam::attack(Team* tEnemy){
    if(tEnemy == nullptr){
         throw std::invalid_argument("A Team pointer can't be null.");
    }
    if(tEnemy->stillAlive() == 0 || this->stillAlive() ==0 ){
        throw std::runtime_error("A Team (or you) you want to attack is died.");
    }
    unsigned int ourSize = this->getPlayersZise();
    unsigned int j = 0;
    while ((tEnemy->stillAlive() > 0) && j<ourSize){
        //attack
        //If the leader is died
        if(!(this->getLeader()->isAlive())){
            Point position = this->getLeader()->getLocation();
            double dist = std::numeric_limits<double>::max();
            for(unsigned int i = 0; i < ourSize; i++)
            {
                if (this->getPlayerIn(i)->isAlive()){
                    if(this->getPlayerIn(i)->getLocation().distance(position) < dist){
                        dist = this->getPlayerIn(i)->getLocation().distance(position);
                        this->setLeader(this->getPlayerIn(i));
                    }
                }
            }
        }
        if(this->getPlayerIn(j)->isAlive()){
            Character* attackEnemy;
            char type = (this->getPlayerIn(j)->print())[0];
            unsigned int vecSize = tEnemy->getPlayersZise();
            //If its ninja - find the closest enemy.
            //If its cowboy - shoot the enemy whith the minimum points
            if(type == 'N'){  
                char EnemyType = (tEnemy->getPlayerIn(0)->print())[0];
                double dist = std::numeric_limits<double>::max();
                for(unsigned int i = 0; i < vecSize; i++)
                {
                    if (tEnemy->getPlayerIn(i)->isAlive()){
                        if(this->getPlayerIn(j)->distance(tEnemy->getPlayerIn(i)) < dist){
                            dist = this->getPlayerIn(j)->distance(tEnemy->getPlayerIn(i));
                            attackEnemy = tEnemy->getPlayerIn(i);
                        }
                    }
                }
                bool ans = this->getPlayerIn(j)->slash(attackEnemy);
                if(!ans){
                    this->getPlayerIn(j)->move(attackEnemy);
                }
            }
            else if(type == 'C'){
                int minHit = std::numeric_limits<int>::max();
                for(unsigned int i = 0; i < vecSize; i++)
                {
                    if (tEnemy->getPlayerIn(i)->getHitPoint() < minHit){
                            minHit = tEnemy->getPlayerIn(i)->getHitPoint();
                            attackEnemy = tEnemy->getPlayerIn(i);
                        }
                    }
                }
                if(this->getPlayerIn(j)->hasboolets()){
                    this->getPlayerIn(j)->shoot(attackEnemy);
                }
                else{
                    this->getPlayerIn(j)->reload();
                }
        }
        j += 1;
    }
    
}