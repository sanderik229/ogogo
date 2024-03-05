#include <iostream>
#include <string>
#include <algorithm>
#include <random>

// Функция для переворота слова задом наперед
std::string reverse(const std::string& word) {
    std::string reversedWord = word;
    std::reverse(reversedWord.begin(), reversedWord.end());
    return reversedWord;
}

// Функция для удаления гласных букв из слова
std::string removeVowels(const std::string& word) {
    std::string result = "";
    for (char c : word) {
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
            result += c;
        }
    }
    return result;
}

// Функция для удаления согласных букв из слова
std::string removeConsonants(const std::string& word) {
    std::string result = "";
    for (char c : word) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            result += c;
        }
    }
    return result;
}

// Функция для перемешивания букв в слове
std::string shuffle(const std::string& word) {
    std::string shuffledWord = word;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(shuffledWord.begin(), shuffledWord.end(), g);
    return shuffledWord;
}

int main() {
    std::string word;

    // Получаем слово от пользователя
    std::cout << "Введите слово: ";
    std::cin >> word;

    int choice;

    // Основной цикл меню
    while (true) {
        // Выводим доступные действия
        std::cout << "\nМеню:"
                  << "\n1. Слово задом наперед"
                  << "\n2. Вывести слово без гласных"
                  << "\n3. Вывести слово без согласных"
                  << "\n4. Рандомно раскидывать буквы заданного слова"
                  << "\n0. Выход"
                  << "\nВыберите действие: ";
        std::cin >> choice;

        std::string result;

        // Выполняем выбранное действие
        switch (choice) {
        case 1:
            result = reverse(word);
            break;
        case 2:
            result = removeVowels(word);
            break;
        case 3:
            result = removeConsonants(word);
            break;
        case 4:
            result = shuffle(word);
            break;
        case 0:
            return 0;
        default:
            std::cout << "Некорректный выбор действия.";
            continue;
        }

        // Выводим результат
        std::cout << "Результат: " << result << std::endl;
    }

    return 0;
}
