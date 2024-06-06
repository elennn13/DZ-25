#include <iostream>
#include <string>
#include <algorithm> // Для std::transform
#include <cctype>

bool isPalindrome(std::string word) {
    // Преобразуем все символы в нижний регистр
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);

    // Удаляем все нелатинские символы
    word.erase(std::remove_if(word.begin(), word.end(), [](char c) {
        return !std::isalpha(c);
        }), word.end());

    // Сравниваем начало и конец строки, двигаясь к середине
    for (int i = 0; i < word.length() / 2; i++) {
        if (word[i] != word[word.length() - 1 - i]) {
            return false;
        }
    }

    return true;
}

int countSpecialChars(std::string str) {
    int count = 0;
    for (char c : str) {
        if (c == ' ' || c == '.' || c == ',' || c == '!' || c == '?') {
            count++;
        }
    }
    return count;
}
std::string func(const std::string& str, char sym) {
    // Находим последнее вхождение символа в строке
    size_t pos = str.rfind(sym);

    // Если символ не найден, возвращаем пустую строку
    if (pos == std::string::npos) {
        return "";
    }

    // Возвращаем подстроку, начинающуюся с найденного символа и заканчивающуюся концом строки
    return str.substr(pos);
}


int main(){
    setlocale(LC_ALL, "ru");
    // Задача 1
      // Дана строка str. Пользователь вводит символ sym.
      // Программа создаёт новую строку, которая состоит из символа
      // sym. Длина новой строки равна количеству совпадений
      // введённого символа с элементами изначальной строки str.

    std::string str = "Hello World!";
    std::cout << "Введите символ -> ";
    char sym;
    std::cin >> sym;
    std::string result;

    for (int i = 0; i < str.length(); i++)
        if (str[i] == sym)
            result += sym;
    std::cout << result << std::endl;

    // Задача 2
    // Создайте функцию, которая принимает слово и возвращает
    // true, если оно является палиндромом. В противном случае
    // возвращается false. Функция должна быть
    // нерегистрозависимой.


     // Пример использования функции
    std::cout << "Является ли слово 'Пап' палиндромом? " << isPalindrome("Пап") << std::endl;
    std::cout << "Является ли слово 'Hello' палиндромом? " << isPalindrome("Hello") << std::endl;


   // Задача 3    
   // Создайте функцию, которая принимает строку. Функция
   // считает все пробелы, точки, запятые, восклицательные и
   // вопросительные знаки, которые есть в переданной строке и
   // возвращает их общее количество.

    std::string input = "Hello, world! How are you?";
    int result = countSpecialChars(input);
    std::cout << "Количество символов в строке равно: " << result << std::endl;


    // Задача 4
    // Создайте функцию, которая принимает строку и символ.
    // Функция ищет последнее вхождение символа в переданную
    // строку и возвращает подстроку, начинающуюся с этого символа
    // и заканчивающуюся концом строки.Если символа в строке нет,
    // то функция возвращает пустую строку.
    
    std::string str = "Hello world!";
    char sym = 'o';
    std::cout << func(str, sym) << std::endl;



    return 0;
}