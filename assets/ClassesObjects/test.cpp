#include <iostream>
#include <string>
using namespace std;
// Создаем класс Person для хранения информации о гражданах
class Person
{
public:
    string surname;
    string firstName;
    string middleName;
    string address;
    string gender;
    string education;
    int birthYear;
};

int main()
{
    const int arraySize = 3;    // Размер массива граждан
    Person citizens[arraySize]; // Создаем массив объектов класса Person

    // Заполняем информацию о гражданах
    for (int i = 0; i < arraySize; ++i)
    {
        cout << "Введите информацию о гражданине " << i + 1 << ":" << endl;
        cout << "Фамилия: ";
        cin >> citizens[i].surname;
        cout << "Имя: ";
        cin >> citizens[i].firstName;
        cout << "Отчество: ";
        cin >> citizens[i].middleName;
        cout << "Адрес: ";
        cin.ignore(); // Игнорируем символ новой строки во входном буфере
        getline(cin, citizens[i].address);
        cout << "Пол: ";
        cin >> citizens[i].gender;
        cout << "Образование: ";
        cin >> citizens[i].education;
        cout << "Год рождения: ";
        cin >> citizens[i].birthYear;
    }

    int ageThreshold;
    cout << "Введите пороговый возраст: ";
    cin >> ageThreshold;

    // Вывод списка граждан, возраст которых превышает заданный
    cout << "Список граждан, возраст которых превышает " << ageThreshold << ":" << endl;
    for (int i = 0; i < arraySize; ++i)
    {
        int currentYear = 2023; // Текущий год
        int age = currentYear - citizens[i].birthYear;
        if (age > ageThreshold)
        {
            cout << i + 1 << ") " << citizens[i].surname << " " << citizens[i].firstName << " " << citizens[i].middleName << endl;
        }
    }

    // Вывод списка граждан с высшим образованием
    cout << "Список граждан с высшим образованием:" << endl;
    for (int i = 0; i < arraySize; ++i)
    {
        if (citizens[i].education == "высшее" || citizens[i].education == "Высшее")
        {
            cout << i + 1 << ") " << citizens[i].surname << " " << citizens[i].firstName << " " << citizens[i].middleName << endl;
        }
    }

    // Вывод списка граждан мужского пола
    cout << "Список граждан мужского пола:" << endl;
    for (int i = 0; i < arraySize; ++i)
    {
        if (citizens[i].gender == "мужской" || citizens[i].gender == "Мужской")
        {
            cout << i + 1 << ") " << citizens[i].surname << " " << citizens[i].firstName << " " << citizens[i].middleName << endl;
        }
    }

    return 0;
}
