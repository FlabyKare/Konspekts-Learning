#include <iostream>  // Подключение библиотеки для работы с вводом/выводом
using namespace std;

template <typename T>  // Определение шаблона класса Vector
class Vector {
private:
    T* elements;  // Указатель на массив элементов
    int size;     // Размерность вектора

public:
    Vector(int n) {            // Конструктор класса Vector
        size = n;
        elements = new T[size];  // Выделение памяти для массива элементов
    }

    ~Vector() {             // Деструктор класса Vector
        delete[] elements;  // Освобождение памяти, выделенной для массива элементов
    }

    T& operator[](int i) {  // Перегрузка оператора доступа к элементам вектора
        return elements[i];
    }

    int getSize() {    // Метод для получения размерности вектора
        return size;
    }
};

int main() {
    int n;
    cout << "Введите размерность вектора: ";
    cin >> n;

    Vector<int> myVector(n);  // Создание объекта класса Vector с заданной размерностью

    cout << "Введите элементы вектора:" << endl;
    for (int i = 0; i < myVector.getSize(); i++) {
        cin >> myVector[i];  // Ввод элементов вектора
    }

    cout << "Вектор: ";
    for (int i = 0; i < myVector.getSize(); i++) {
        cout << myVector[i] << " ";  // Вывод элементов вектора
    }
    cout << endl;

    return 0;
}
