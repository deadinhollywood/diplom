#include "Item.hpp"
#include <iostream>

Item::Item(const std::string& name, const std::string& description) 
    : name(name), description(description) {}

Item::~Item() {}

void Item::use() {
    std::cout << "Вы используете: " << name << std::endl;
}

Item* Item::clone() const {
    return new Item(*this);
}

std::string Item::getName() const { return name; }
std::string Item::getDescription() const { return description; }
void Item::setDescription(const std::string& desc) { description = desc; }

// Класс KeyItem
KeyItem::KeyItem(const std::string& name, const std::string& description)
    : Item(name, description) {}

void KeyItem::use() {
    std::cout << "Ключевой предмет: " << name << " - " << description << std::endl;
}

Item* KeyItem::clone() const {
    return new KeyItem(*this);
}

// Класс ConsumableItem
ConsumableItem::ConsumableItem(const std::string& name, const std::string& description, int effect)
    : Item(name, description), effectValue(effect) {}

void ConsumableItem::use() {
    std::cout << "Вы потребляете: " << name << " (эффект: " << effectValue << ")" << std::endl;
}

Item* ConsumableItem::clone() const {
    return new ConsumableItem(*this);
}

int ConsumableItem::getEffect() const { return effectValue; }