#pragma once

#include "Item.hpp"
#include <vector>

class Inventory {
private:
    std::vector<Item*> items; 
    
public:
    Inventory();
    ~Inventory();
    
    bool addItem(Item* item);
    bool removeItem(const std::string& itemName);
    Item* getItem(const std::string& itemName) const;
    void showInventory() const;
    bool hasItem(const std::string& itemName) const;
    int getItemCount() const;
    
    Inventory(const Inventory&) = delete;
    Inventory& operator=(const Inventory&) = delete;
};