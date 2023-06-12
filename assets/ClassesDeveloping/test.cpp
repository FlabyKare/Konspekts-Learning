#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Vector {
private:
    vector<double> elements;
    int size;

public:
    Vector() : size(0) {}

    Vector(int n) : size(n), elements(n, 0.0) {}

    Vector(const Vector& other) : size(other.size), elements(other.elements) {}

    Vector(Vector&& other) noexcept : size(other.size), elements(move(other.elements)) {}

    ~Vector() {}

    double getMagnitude() const {
        double sumOfSquares = 0.0;
        for (int i = 0; i < size; i++) {
            sumOfSquares += elements[i] * elements[i];
        }
        return sqrt(sumOfSquares);
    }

    double dotProduct(const Vector& other) const {
        double result = 0.0;
        for (int i = 0; i < size; i++) {
            result += elements[i] * other.elements[i];
        }
        return result;
    }

    Vector operator+(const Vector& other) const {
        Vector sum(size);
        for (int i = 0; i < size; i++) {
            sum.elements[i] = elements[i] + other.elements[i];
        }
        return sum;
    }

    Vector operator-(const Vector& other) const {
        Vector difference(size);
        for (int i = 0; i < size; i++) {
            difference.elements[i] = elements[i] - other.elements[i];
        }
        return difference;
    }

    Vector operator*(double scalar) const {
        Vector result(size);
        for (int i = 0; i < size; i++) {
            result.elements[i] = elements[i] * scalar;
        }
        return result;
    }

    double& operator[](int index) {
        return elements[index];
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            size = other.size;
            elements = other.elements;
        }
        return *this;
    }

    Vector& operator=(Vector&& other) noexcept {
        if (this != &other) {
            size = other.size;
            elements = move(other.elements);
        }
        return *this;
    }
};

void checkCollinearityOrthogonality(const Vector& v1, const Vector& v2) {
    double dotProduct = v1.dotProduct(v2);
    double v1Magnitude = v1.getMagnitude();
    double v2Magnitude = v2.getMagnitude();

    if (abs(dotProduct) < 1e-6) {
        cout << "Векторы являются ортогональными." << endl;
    } else if (abs(dotProduct - v1Magnitude * v2Magnitude) < 1e-6) {
        cout << "Векторы являются коллинеарными." << endl;
    } else {
        cout << "Векторы не являются ни коллинеарными, ни ортогональными." << endl;
    }
}

int main() {
    int size;
    cout << "Введите размерность векторов: ";
    cin >> size;

    Vector v1(size);
    Vector v2(size);

    cout << "Введите элементы вектора v1:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Введите элемент " << i + 1 << ": ";
        cin >> v1[i];
    }

    cout << "Введите элементы вектора v2:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Введите элемент " << i + 1 << ": ";
        cin >> v2[i];
    }

    Vector sum = v1 + v2;
    Vector difference = v1 - v2;
    Vector scaled = v1 * 2.0;

    cout << "Модуль v1: " << v1.getMagnitude() << endl;
    cout << "Скалярное произведение v1 и v2: " << v1.dotProduct(v2) << endl;

    cout << "Сумма v1 и v2: ";
    for (int i = 0; i < size; i++) {
        cout << sum[i] << " ";
    }
    cout << endl;

    cout << "Разность v1 и v2: ";
    for (int i = 0; i < size; i++) {
        cout << difference[i] << " ";
    }
    cout << endl;

    cout << "Умножение v1 на 2.0: ";
    for (int i = 0; i < size; i++) {
        cout << scaled[i] << " ";
    }
    cout << endl;

    checkCollinearityOrthogonality(v1, v2);

    return 0;
}
