#include "Game.hpp"
#include <iostream>

int main() {
    // Устанавливаем русскую локаль для консоли
    setlocale(LC_ALL, "Russian");
    
    std::cout << "========================================" << std::endl;
    std::cout << "          ТЕКСТОВЫЙ КВЕСТ" << std::endl;
    std::cout << "         'ЗАЩИТА ДИПЛОМА'" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    std::cout << "Секретные команды:" << std::endl;
    std::cout << "0 - Показать инвентарь" << std::endl;
    std::cout << "77 - Использовать предмет (например, Энергетик)" << std::endl;
    std::cout << "88 - Лечение (для тестирования)" << std::endl;
    std::cout << "99 - Показать статус\n" << std::endl;
    
    std::cout << "Введите ваше имя: ";
    
    std::string playerName;
    std::getline(std::cin, playerName);
    
    if (playerName.empty()) {
        playerName = "Студент";
    }
    
        std::cout << "Ни смерть, ни душевные или физические муки не могут породить такого\n"
        "отчаяния, какое вызывает утрата собственной индивидуальности.\n"
        "Обратившись в ничто, мы обретаем забвение; но осознавать себя\n"
        "существующим, одновременно зная, что ты лишён собственного «Я» и более\n"
        "не являешься единственным и неповторимым, чем-то отличным от всех\n"
        "других, вот он, истинный апофеоз ужаса.\n" << std::endl;
    Game game(playerName);
    game.start();
    game.run();
    
    std::cout << "\nСпасибо за игру!" << std::endl;
    std::cout << "Нажмите Enter для выхода...";
    std::cin.ignore();
    std::cin.get();
    
    return 0;
}