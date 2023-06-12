#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Структура, представляющая информацию о поезде
struct Train {
int number;
string destination;
string departureTime;
};

// Класс для работы с динамической структурой данных - списком поездов
class TrainList {
private:
vector<Train> trains; // Вектор поездов

public:
void addTrain(const Train& train) {
trains.push_back(train); // Добавление нового поезда в конец вектора
}void printAllTrains() {
    for (const auto& train : trains) {
        cout << "Номер поезда: " << train.number << endl;
        cout << "Направление: " << train.destination << endl;
        cout << "Время отправления: " << train.departureTime << endl;
        cout << endl;
    }
}

void findTrainByNumber(int trainNumber) {
    for (const auto& train : trains) {
        if (train.number == trainNumber) {
            cout << "Номер поезда: " << train.number << endl;
            cout << "Направление: " << train.destination << endl;
            cout << "Время отправления: " << train.departureTime << endl;
            return;
        }
    }

    cout << "Поезд с номером " << trainNumber << " не найден." << endl;
}

void findTrainsByDestination(const string& destination) {
    for (const auto& train : trains) {
        if (train.destination == destination) {
            cout << "Номер поезда: " << train.number << endl;
            cout << "Направление: " << train.destination << endl;
            cout << "Время отправления: " << train.departureTime << endl;
            cout << endl;
        }
    }
}
};

int main() {
TrainList trainList;cout << "Введите информацию о поезде (0 для выхода):" << endl;

while (true) {
    int trainNumber;
    string destination;
    string departureTime;

    cout << "Номер поезда: ";
    cin >> trainNumber;

    if (trainNumber == 0) {
        break;
    }

    cout << "Направление: ";
    cin >> destination;

    cout << "Время отправления: ";
    cin >> departureTime;

    Train train;
    train.number = trainNumber;
    train.destination = destination;
    train.departureTime = departureTime;

    trainList.addTrain(train);
}

cout << endl << "Все поезда:" << endl;
trainList.printAllTrains();

int trainNumber;
cout << endl << "Введите номер поезда для поиска: ";
cin >> trainNumber;
trainList.findTrainByNumber(trainNumber);

string destination;
cout << endl << "Введите направление для поиска поездов: ";
cin >> destination;
trainList.findTrainsByDestination(destination);

return 0;
}