#include "Location.hpp"
#include <iostream>

Location::Location(int locId, const std::string& locName, const std::string& locDesc)
    : id(locId), name(locName), description(locDesc) {}

void Location::addOption(const LocationOption& option) {
    options.push_back(option);
}

void Location::showDescription() const {
    std::cout << "\n=== " << name << " ===" << std::endl;
    std::cout << description << std::endl;
    std::cout << "====================\n" << std::endl;
}

void Location::showOptions() const {
    std::cout << "Доступные действия:" << std::endl;
    for (const auto& option : options) {
        if (option.isAvailable) {
            std::cout << option.id << ". " << option.description << std::endl;
        }
    }
    std::cout << "0. Показать инвентарь" << std::endl;
    std::cout << "99. Показать статус" << std::endl;
}

LocationOption* Location::getOption(int optionId) {
    for (auto& option : options) {
        if (option.id == optionId && option.isAvailable) {
            return &option;
        }
    }
    return nullptr;
}

int Location::getId() const { return id; }
std::string Location::getName() const { return name; }

void Location::setOptionAvailable(int optionId, bool available) {
    for (auto& option : options) {
        if (option.id == optionId) {
            option.isAvailable = available;
            break;
        }
    }
}