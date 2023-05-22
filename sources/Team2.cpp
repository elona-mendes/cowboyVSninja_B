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

// void Team2::attack(Team2* tEnemy){
//     int ourSize = this->players.size();
//     unsigned int i = 0;
//     while ((tEnemy->stillAlive() > 0) && i<ourSize){
//         //attack
//         if(!(tEnemy->getLeader()->isAlive())){
//             double dist = std::numeric_limits<double>::max();
//             double newdist;
//             unsigned int vecSize = tEnemy->players.size();
//             for(unsigned int i = 0; i < vecSize; i++)
//             {
//                 if (tEnemy->players[i]->isAlive()){
//                     if(tEnemy->getLeader()->distance(tEnemy->players[i]) < dist){
//                         dist = tEnemy->getLeader()->distance(tEnemy->players[i]);
//                         tEnemy->setLeader(tEnemy->players[i]);
//                     }
//                 }
//             }
//         }
//         if(this->players[i]->isAlive()){
//             char type = (this->players[i]->print())[0];
//             if(type == 'N'){
//                 bool ans = this->players[i]->slash(tEnemy->getLeader());
//                 if(!ans){
//                     this->players[i]->move(tEnemy->getLeader());
//                 }
//             }
//             else if(type == 'C'){
//                 if(this->players[i]->hasboolets()){
//                     this->players[i]->shoot(tEnemy->getLeader());
//                 }
//                 else{
//                     this->players[i]->reload();
//                 }
//             }
//         }
//         i += 1;
//     }
// }   

// // Print all character details.
// void Team2::print(){
//     unsigned int vecSize = this->players.size();

//     for(unsigned int i = 0; i < vecSize; i++)
//     {
//         cout<<this->players[i]->print()<<endl;
//     }
// }

// int Team2::stillAlive(){
//     int count =0;

//     unsigned int vecSize = this->players.size();
//     for(unsigned int i = 0; i < vecSize; i++)
//     {
//         if (this->players[i]->isAlive()){
//             count += 1;
//         }
//     }
//     return count;
// }