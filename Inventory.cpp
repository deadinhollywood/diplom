#include "Inventory.hpp"
#include <iostream>

Inventory::Inventory() {}

Inventory::~Inventory() {
    for (auto item : items) {
        delete item;
    }
}

bool Inventory::addItem(Item* item) {
    items.push_back(item->clone());
    std::cout << "Добавлен предмет: " << item->getName() << std::endl;
    return true;
}

bool Inventory::removeItem(const std::string& itemName) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it) && (*it)->getName() == itemName) {
            delete *it;
            items.erase(it);
            return true;
        }
    }
    return false;
}

Item* Inventory::getItem(const std::string& itemName) const {
    for (auto item : items) {
        if (item && item->getName() == itemName) {
            return item;
        }
    }
    return nullptr;
}

void Inventory::showInventory() const {
    if (items.empty()) {
        std::cout << "Инвентарь пуст." << std::endl;
        return;
    }
    
    std::cout << "\n=== ИНВЕНТАРЬ ===" << std::endl;
    for (size_t i = 0; i < items.size(); i++) {
        std::cout << (i + 1) << ". " << items[i]->getName() 
                  << " - " << items[i]->getDescription() << std::endl;
    }
    std::cout << "=================" << std::endl;
}

bool Inventory::hasItem(const std::string& itemName) const {
    return getItem(itemName) != nullptr;
}

int Inventory::getItemCount() const {
    return items.size();
}