#include <iostream>
#include <stdexcept>
#include <string>
#include "Character.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Cowboy.hpp"
#include <vector>

using namespace std;

#ifndef TEAM_H
#define TEAM_H

namespace ariel{
    class Team{

//Going over all members of the group (for attacking, printing, or comparing) 
//will always be done in the following order: 
//first go over all the cowboys, then go over all the ninjas. 
//Within each group, the transition will be made according to the order in which the characters were added.
// public:
        private:
            vector<Character*> players;
            Character* leader;
            
        public:
            // Constructor
            Team(Character* chrctr);

            //From here to destructor - take from chatGPT
            // Copy constructor
                Team(const Team& other) : players(other.players.size()), leader(nullptr) {
                    for (size_t i = 0; i < other.players.size(); ++i) {
                        players[i] = other.players[i];
                        if (other.players[i] == other.leader){
                            leader = players[i];
                        }
                            
                    }
                }

                // Copy assignment operator
                Team& operator=(const Team& other) {
                    if (this != &other) {
                        // Clear current players
                        for (Character* player : players) {
                            player->setInTeam(false);
                        }
                        players.clear();

                        // Copy new players
                        players.resize(other.players.size());
                        for (size_t i = 0; i < other.players.size(); ++i) {
                            players[i] = other.players[i];
                            if (other.players[i] == other.leader){
                                leader = players[i];
                            }
                            
                        }
                    }
                    return *this;
                }

                // Move constructor
                Team(Team&& other) noexcept : players(std::move(other.players)), leader(other.leader) {
                    other.leader = nullptr;
                }

                // Move assignment operator
                Team& operator=(Team&& other) noexcept {
                    if (this != &other) {
                        // Clear current players
                        for (Character* player : players) {
                            player->setInTeam(false);
                        }
                        players.clear();

                        // Move new players
                        players = std::move(other.players);
                        leader = other.leader;

                        // Reset other
                        other.leader = nullptr;
                    }
                    return *this;
                }

            // Destructor
            virtual ~Team(){}       
        
            // Add character to your group
            virtual void add(Character* chrctr);

            void addInRow(Character* chrctr){
                this->players.push_back(chrctr);
            }

            Character* getLeader(){
                return this->leader;
            }

            unsigned int getPlayersZise(){
                return this->players.size();
            }

            Character* getPlayerIn(unsigned int index){
                return this->players[index];
            }

            void setLeader(Character* lead){
                this->leader = lead;
            }
    
            // Verify if enemy leader is alive: 
            // if alive, attack him
            // else, a new leader must be chosen, who is the living character closest (in terms of location) to the dead leader.
            // All the team that alive attacks the leader.
            // Cowboy that have balls shoot the leader, and cowboy that havn't balls reload theme.
            // Ninja that are close to the leader slash him, and approach otherwise. 
            // If the leader died in the attack - choose another one like the begining.
            // If there no alive person in our team, or enemy team: stop.
            virtual void attack(Team* tEnemy);
            // Return the number of team character that alive.       
            int stillAlive();
            // Print all character details.
            void print();  

    };

}
#endif