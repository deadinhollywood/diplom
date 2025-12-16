#pragma once

#include <string>

class Item {
protected:
    std::string name;
    std::string description;
    
public:
    Item(const std::string& name, const std::string& description);
    virtual ~Item();
    
    virtual void use();
    virtual Item* clone() const;
    
    std::string getName() const;
    std::string getDescription() const;
    void setDescription(const std::string& desc);
};

// Производные классы для разных типов предметов
class KeyItem : public Item {
public:
    KeyItem(const std::string& name, const std::string& description);
    void use() override;
    Item* clone() const override;
};

class ConsumableItem : public Item {
private:
    int effectValue;
    
public:
    ConsumableItem(const std::string& name, const std::string& description, int effect);
    void use() override;
    Item* clone() const override;
    
    int getEffect() const;
};