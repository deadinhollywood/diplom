#include "Player.hpp"
#include <iostream>

Player::Player(const std::string& playerName) 
    : name(playerName), health(3), maxHealth(3), currentLocation(0) {}

Player::~Player() {}

std::string Player::getName() const { return name; }
int Player::getHealth() const { return health; }
int Player::getMaxHealth() const { return maxHealth; }
int Player::getLocation() const { return currentLocation; }
Inventory& Player::getInventory() { return inventory; }

void Player::setLocation(int location) {
    currentLocation = location;
}

void Player::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
    std::cout << "Вы получили " << damage << " урона! Здоровье: " << health << "/" << maxHealth << std::endl;
}

void Player::heal(int amount) {
    health += amount;
    if (health > maxHealth) health = maxHealth;
    std::cout << "Вы восстановили " << amount << " здоровья! Здоровье: " << health << "/" << maxHealth << std::endl;
}

bool Player::isAlive() const {
    return health > 0;
}

bool Player::useEnergyDrink() {
    if (health < 5) {  // Максимум 5 здоровья
        health++;
        std::cout << "Вы использовали энергетик! Здоровье: " << health << "/5" << std::endl;
        return true;
    } else {
        std::cout << "У вас уже максимальное здоровье!" << std::endl;
        return false;
    }
}

int Player::getHealth() const {
    return health;
}

void Player::setHealth(int health) {
    this->health = health;
    if (this->health > 5) this->health = 5;
    if (this->health < 0) this->health = 0;
}
void Player::showStatus() const {
    std::cout << "\n=== СТАТУС ===" << std::endl;
    std::cout << "Имя: " << name << std::endl;
    std::cout << "Здоровье: " << health << "/" << maxHealth << std::endl;
    std::cout << "Локация: Этаж " << (currentLocation + 1) << std::endl;
    std::cout << "==============\n" << std::endl;
}

bool Player::useItem(const std::string& itemName) {
    Item* item = inventory.getItem(itemName);
    if (!item) {
        std::cout << "У вас нет предмета: " << itemName << std::endl;
        return false;
    }
        if (itemName == "Энергетик") {
        heal(1);
        inventory.removeItem("Энергетик");
        return true;
    }
    
    item->use();
    return true;
}
