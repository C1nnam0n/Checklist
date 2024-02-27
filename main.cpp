//
// Created by Miki on 13.02.2024.
//
/*oppsy bedą obiektami dzięki temu wpierdole im name i tatus(czy zajebani) dopierdole jeszcze że wszystko do pliku się zapisuje i będe mógł odczytać z pliku
 * w mainie będzie opcja [0] dodaj bossa, [1] usun bossa(i guess ?) [2] wyświetl całą liste*/
#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>

struct Boss {
public:
    std::string name;
    std::string is_alive{};
};


int main() {
    int action_num;
    std::cout << "Welcome to boss menager, what you want to do? " << '\n' << "[1] Create boss list " << '\n'
              << "[2] Add boss to existing list "
              << '\n' << "[3] Delete boss from the existing list" << '\n' << "[4] Delete list" << '\n'
              << "[5] Check existing lists" << '\n';

    std::cin >> action_num;
    std::string boss_list_name;
    switch (action_num) {
        case 1: {

            std::cout << " Please enter a name of your boss list" << '\n';
            std::cin >> boss_list_name;
            std::ofstream boss_list(boss_list_name);

            std::vector<Boss> bosses;
            std::cout << "Enter names of the bosses and state is he dead or alive, press 's' and then enter to stop"
                      << '\n';
            for (int i = 0; i < sizeof bosses; i++) {
                Boss boss;
                std::cin >> boss.name >> boss.is_alive;
                if (boss.name == "s") {
                    boss_list.close();
                    break;
                }
                boss_list << boss.name << " " << boss.is_alive;
                boss_list << '\n';
            }
            break;
        }
        case 2: {
            std::cout << "choose to which list you want to add a boss: ";
            std::cin >> boss_list_name;
            break;
        }
        default: throw std::runtime_error("Cannot do");
    }
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        std::cout << "Aktualny katalog roboczy: " << cwd << std::endl;
    } else {
        std::cerr << "Błąd pobierania aktualnego katalogu roboczego" << std::endl;
    }
}