#include <iostream>
#include <string>
#include <clocale>

using namespace std;

// Docstring: Выводит 32-битное представление целого числа на экран.
void printBits(int number) {
    cout << "Биты числа " << number << ": ";

    // Проходим от старшего бита (31) до младшего (0)
    for (int i = 31; i >= 0; --i) {
        // Сдвигаем число вправо на i позиций и проверяем младший бит
        int bit = (number >> i) & 1;
        cout << bit;

        // Для удобства чтения добавляем пробел каждые 8 бит (через 4 бита от конца)
        if (i % 8 == 0 && i != 0) {
            cout << " ";
        }
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    // Установка русской кодировки для консоли
    setlocale(LC_ALL, "Russian");

    // Проверяем, передан ли аргумент командной строки
    if (argc < 2) {
        cout << "Ошибка: не передано число!" << endl;
        cout << "Использование: " << argv[0] << " <число>" << endl;
        return 1;
    }

    try {
        // Преобразуем переданный аргумент из строки в целое число
        string arg = argv[1];
        int number = stoi(arg);

        // Выводим результат
        printBits(number);

    } catch (const invalid_argument& e) {
        cout << "Ошибка: аргумент '" << argv[1] << "' не является числом." << endl;
        return 1;
    } catch (const out_of_range& e) {
        cout << "Ошибка: число выходит за пределы допустимого диапазона типа int." << endl;
        return 1;
    }

    return 0;
}
