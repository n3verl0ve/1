#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
class Room {
private:
    string name;
    double width;
    double height;
    bool ceilingToCover;

public:
    Room(const string& n, double w, double h, bool ceiling)
        : name(n), width(w), height(h), ceilingToCover(ceiling) {}

    double calculateWallArea() const {
        if (ceilingToCover) {
            return 2 * (width + height) * height;
        }
        else {
            return 2 * (width + height) * height + (width * height);
        }
    }
};

class WallpaperRoll {
private:
    string name;
    double width;
    double length;
    double price;

public:
    WallpaperRoll(const string& n, double w, double l, double p)
        : name(n), width(w), length(l), price(p) {}

    int calculateNeededRolls(double totalArea) const {
        return ceil(totalArea / (width * length));
    }

    double calculateTotalCost(int rolls) const {
        return rolls * price;
    }
};

class Apartment {
private:
    vector<Room> rooms;

public:
    void addRoom(const string& name, double width, double height, bool ceiling) {
        Room newRoom(name, width, height, ceiling);
        rooms.push_back(newRoom);
    }

    void calculateWallpaperNeeded(const vector<WallpaperRoll>& rolls) const {
        for (const auto& room : rooms) {
            double roomArea = room.calculateWallArea();
            cout << "Room: " << roomArea << " sq.m" << endl;
            for (const auto& roll : rolls) {
                int neededRolls = roll.calculateNeededRolls(roomArea);
                double totalCost = roll.calculateTotalCost(neededRolls);
                cout << "Wallpaper: " << roll.name << ", Needed Rolls: " << neededRolls << ", Total Cost: " << totalCost <<  endl;
            }
            cout << endl;
        }
    }
};

int main() {
    Apartment apartment;

    apartment.addRoom("Living Room", 5.5, 3.2, true);
    apartment.addRoom("Bedroom", 4.8, 3.0, false);

    vector<WallpaperRoll> rolls;
    rolls.push_back(WallpaperRoll("Design1", 1.06, 10, 20.5));
    rolls.push_back(WallpaperRoll("Design2", 1.06, 15, 30.5));

    apartment.calculateWallpaperNeeded(rolls);

    return 0;
}