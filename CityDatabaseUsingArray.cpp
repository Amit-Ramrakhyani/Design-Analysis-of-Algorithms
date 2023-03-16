#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

struct City {
    string name;
    int x;
    int y;
};

class CityDatabaseArrayList {
    private:
        City* cities;
        int capacity;
        int size;

    public:
        CityDatabaseArrayList(int capacity) {
            this->capacity = capacity;
            cities = new City[capacity];
            size = 0;
        }

        ~CityDatabaseArrayList() {
            delete[] cities;
        }

        void insert(City city) {
            cities[size] = city;
            size++;
        }

        void deleteByName(string name) {
            for (int i = 0; i < size; i++) {
                if (cities[i].name == name) {
                    cities[i] = cities[size-1];
                    size--;
                    return;
                }
            }
        }

        void deleteByCoordinate(int x, int y) {
            for (int i = 0; i < size; i++) {
                if (cities[i].x == x && cities[i].y == y) {
                    cities[i] = cities[size-1];
                    size--;
                    return;
                }
            }
        }

        City* searchByName(string name) {
            for (int i = 0; i < size; i++) {
                if (cities[i].name == name) {
                    return &cities[i];
                }
            }
            return nullptr;
        }

        City* searchByCoordinate(int x, int y) {
            for (int i = 0; i < size; i++) {
                if (cities[i].x == x && cities[i].y == y) {
                    return &cities[i];
                }
            }
            return nullptr;
        }

        void printWithinDistance(int x, int y, double distance) {
            for (int i = 0; i < size; i++) {
                double dx = x - cities[i].x;
                double dy = y - cities[i].y;
                double dist = sqrt(dx*dx + dy*dy);
                if (dist <= distance) {
                    cout << cities[i].name << " (" << cities[i].x << ", " << cities[i].y << ")" << endl;
                }
            }
        }

        void print() {
            for (int i = 0; i < size; i++) {
                cout << cities[i].name << " (" << cities[i].x << ", " << cities[i].y << ")" << endl;
            }
        }
};

int main() {
    CityDatabaseArrayList database(10);

    database.insert({"Delhi", 28, 77});
    database.insert({"Mumbai", 19, 72});
    database.insert({"Kolkata", 22, 88});
    database.insert({"Chennai", 13, 80});
    database.insert({"Bangalore", 15, 77});
    database.insert({"Hyderabad", 17, 78});
    database.insert({"Ahmedabad", 23, 72});
    database.insert({"Pune", 18, 73});
    database.insert({"Jaipur", 26, 75});

    cout << "All cities:" << endl;
    database.print();
    cout << endl;

    cout << "Search results for Mumbai and (15, 77): " << endl;
    City* city = database.searchByName("Mumbai");
    if (city != nullptr) {
        cout << city->name << " (" << city->x << ", " << city->y << ")" << endl;
    }

    city = database.searchByCoordinate(15, 77);
    if (city != nullptr) {
        cout << city->name << " (" << city->x << ", " << city->y << ")" << endl;
    }
    cout << endl;

    cout << "Records after deleting Delhi and (18, 73): " << endl;
    database.deleteByName("Delhi");
    database.deleteByCoordinate(18, 73);
    database.print();
    cout << endl;

    cout << "Cities within 10 units of (20, 80): " << endl;
    database.printWithinDistance(20, 80, 10);
    cout << endl;

    return 0;

}

