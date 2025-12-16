#pragma once

#include "Player.hpp"
#include "Location.hpp"
#include <vector>

class Game {
private:
    Player* player;
    std::vector<Location*> locations;
    bool gameOver;
    std::string ending;
    bool firstTimeShow[16];
    bool locationSearched[16];
    
    void initializeLocations();
    void initializeItems();
    void processOption(LocationOption* option);
    void showEnding();
    
public:
    Game(const std::string& playerName);
    ~Game();
    
    void start();
    void run();
    bool isGameOver() const;
};