#pragma once

#include <string>
#include <vector>

struct LocationOption {
    int id;
    std::string description;
    std::string result;
    std::string requiredItem;
    std::string itemReward;
    int damage;
    int nextLocation;
    bool isAvailable;
};

class Location {
private:
    int id;
    std::string name;
    std::string description;
    std::vector<LocationOption> options;
    
public:
    Location(int locId, const std::string& locName, const std::string& locDesc);
    
    void addOption(const LocationOption& option);
    void showDescription() const;
    void showOptions() const;
    LocationOption* getOption(int optionId);
    int getId() const;
    std::string getName() const;
    
    void setOptionAvailable(int optionId, bool available);
};