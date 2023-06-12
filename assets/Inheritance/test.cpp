#include <iostream>
#include <string>

using namespace std;

// Базовый класс "Транспортное средство"
class Transport {
protected:
    string name; // Название транспортного средства

public:
    Transport(const string& _name) : name(_name) {} // Конструктор с параметром

    virtual void show() const { // Виртуальная функция вывода информации о транспорте
        cout << "Транспортное средство: " << name << endl;
    }

    virtual float calculateTime(int distance) const = 0; // Чисто виртуальная функция подсчета времени перевозки
    virtual float calculateCost(int distance) const = 0; // Чисто виртуальная функция подсчета стоимости перевозки
};

// Производный класс "Автомобиль"
class Car : public Transport {
private:
    int passengers; // Количество пассажиров
    float speed; // Скорость автомобиля
    float costPerKm; // Стоимость перевозки за километр

public:
    Car(const string& _name, int _passengers, float _speed, float _costPerKm)
        : Transport(_name), passengers(_passengers), speed(_speed), costPerKm(_costPerKm) {} // Конструктор с параметрами

    void show() const override { // Переопределение виртуальной функции вывода информации
        Transport::show();
        cout << "Количество пассажиров: " << passengers << endl;
        cout << "Скорость: " << speed << " км/ч" << endl;
        cout << "Стоимость перевозки за километр: " << costPerKm << " руб/км" << endl;
    }

    float calculateTime(int distance) const override { // Переопределение чисто виртуальной функции подсчета времени перевозки
        return distance / speed;
    }

    float calculateCost(int distance) const override { // Переопределение чисто виртуальной функции подсчета стоимости перевозки
        return distance * costPerKm;
    }
};

// Производный класс "Велосипед"
class Bicycle : public Transport {
private:
    int passengers; // Количество пассажиров
    float speed; // Скорость велосипеда

public:
    Bicycle(const string& _name, int _passengers, float _speed)
        : Transport(_name), passengers(_passengers), speed(_speed) {} // Конструктор с параметрами

    void show() const override { // Переопределение виртуальной функции вывода информации
        Transport::show();
        cout << "Количество пассажиров: " << passengers << endl;
        cout << "Скорость: " << speed << " км/ч" << endl;
    }

    float calculateTime(int distance) const override { // Переопределение чисто виртуальной функции подсчета времени перевозки
        return distance / speed;
    }

    float calculateCost(int distance) const override { // Переопределение чисто виртуальной функции подсчета стоимости перевозки
        return 0; // Велосипед не требует дополнительной оплаты за перевозку
    }
};

// Производный класс "Повозка"
class Carriage : public Transport {
private:
    int passengers; // Количество пассажиров
    float speed; // Скорость повозки
    float costPerKm; // Стоимость перевозки за километр

public:
    Carriage(const string& _name, int _passengers, float _speed, float _costPerKm)
        : Transport(_name), passengers(_passengers), speed(_speed), costPerKm(_costPerKm) {} // Конструктор с параметрами

    void show() const override { // Переопределение виртуальной функции вывода информации
        Transport::show();
        cout << "Количество пассажиров: " << passengers << endl;
        cout << "Скорость: " << speed << " км/ч" << endl;
        cout << "Стоимость перевозки за километр: " << costPerKm << " руб/км" << endl;
    }

    float calculateTime(int distance) const override { // Переопределение чисто виртуальной функции подсчета времени перевозки
        return distance / speed;
    }

    float calculateCost(int distance) const override { // Переопределение чисто виртуальной функции подсчета стоимости перевозки
        return distance * costPerKm;
    }
};

int main() {
    const int numVehicles = 3;
    Transport* vehicles[numVehicles];

    // Ввод данных о транспортных средствах
    for (int i = 0; i < numVehicles; i++) {
        string name;
        int passengers;
        float speed;
        float costPerKm;

        cout << "Введите название транспортного средства: ";
        getline(cin, name);

        cout << "Введите количество пассажиров: ";
        cin >> passengers;

        cout << "Введите скорость (км/ч): ";
        cin >> speed;

        if (i == 0 || i == 2) {
            cout << "Введите стоимость перевозки за километр: ";
            cin >> costPerKm;
        }

        cin.ignore(); // Очищаем буфер после ввода чисел

        if (i == 0)
            vehicles[i] = new Car(name, passengers, speed, costPerKm);
        else if (i == 1)
            vehicles[i] = new Bicycle(name, passengers, speed);
        else
            vehicles[i] = new Carriage(name, passengers, speed, costPerKm);
    }

    // Вывод информации о транспортных средствах
    for (int i = 0; i < numVehicles; i++) {
        vehicles[i]->show();
        int distance = 100; // Расстояние для расчета времени и стоимости
        float time = vehicles[i]->calculateTime(distance);
        float cost = vehicles[i]->calculateCost(distance);
        cout << "Время перевозки: " << time << " часов" << endl;
        cout << "Стоимость перевозки: " << cost << " рублей" << endl;
        cout << "------------------------------------" << endl;
    }

    // Освобождение памяти, занятой объектами
    for (int i = 0; i < numVehicles; i++) {
        delete vehicles[i];
    }

    return 0;
}
