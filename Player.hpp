#pragma once

#include "Inventory.hpp"
#include <string>

class Player {
private:
    std::string name;
    int health;
    int maxHealth;
    Inventory inventory;
    int currentLocation;
    
public:
    Player(const std::string& playerName);
    ~Player();
    
    // Геттеры и сеттеры
    std::string getName() const;
    int getHealth() const;
    int getMaxHealth() const;
    int getLocation() const;
    Inventory& getInventory();
    
    void setLocation(int location);
    void takeDamage(int damage);
    void heal(int amount);
    bool isAlive() const;
    bool useItem(const std::string& itemName); // Новый метод
    
    void showStatus() const;
};