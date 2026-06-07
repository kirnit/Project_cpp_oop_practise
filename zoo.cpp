#include <iostream>
#include <vector>

using namespace std;

class Animal {
public:
    string name;
    int age;

    Animal(string name, int age) {
        this->name = name;
        this->age = age;
    } 
    Animal() {
        cout << "Enter the name of the animal: \n";
        cin >> this->name;
        cout << "Enter the age of the animal: \n";
        cin >> this->age;
    }
    void printInfo() {
        cout << "Name: " << name << "; Age: " << age << endl;
    }
};

class Capybara: public Animal {
    public:
    int is_happy = 1;
    Capybara(): Animal() {
        cout << "Enter whether your Capybara is happy (1 or 0): \n";
        cin >> this->is_happy;
    }
    Capybara(string name, int age, bool is_happy): Animal(name, age) {
        this->is_happy = is_happy;
    }
    void make_sound() {
        if (is_happy) cout << "*Sounds of happiness*" << endl;
        else cout << "*Sneezing*" << endl;
    }
    
};

class Alpaka: public Animal {
    public:
    string color;
    Alpaka(): Animal() {
        cout << "Enter the color of your Alpaka: \n";
        cin >> this->color;
    }
    Alpaka(string name, int age, string color): Animal(name, age) {
        this->color = color;
    }
    void make_sound() {
        cout << "Tfu!" << endl;
    }
};

class Salamander: public Animal {
    public:
    bool is_poisonous;
    int length_of_tail;
    Salamander(): Animal() {
        cout << "Enter whether your Salamander is poisonous: \n";
        cin >> this->is_poisonous;
        cout << "Enter the length of its tail: \n";
        cin >> this->length_of_tail;
    }
    Salamander(string name, int age, bool is_poisonous, int length_of_tail): Animal(name, age) {
        this->is_poisonous = is_poisonous;
        this->length_of_tail = length_of_tail;
    }
    void make_sound() {
        cout << "Ssss!" << endl;
    }
};

class Honeybear: public Animal {
    public:
    int killed_cobras;
    Honeybear(): Animal() {
        cout << "Enter how many cobras killed your Honeybear: \n";
        cin >> this->killed_cobras;
    }
    Honeybear(string name, int age, int killed_cobras): Animal(name, age) {
        this->killed_cobras = killed_cobras;
    }
    void make_sound() {
        cout << "Raaar!" << endl;
    }
};

int main() {
    vector<Animal*> zoo;
    zoo.push_back(new Capybara("Lucy", 56, 1));
    zoo.push_back(new Capybara("Boby", 91, 0));
    zoo.push_back(new Alpaka("Dilan", 13, "red"));
    zoo.push_back(new Alpaka("Barbara", 69, "rainbow"));
    zoo.push_back(new Salamander("Malfoy", 27, false, 50));
    zoo.push_back(new Salamander("Belatrisa", 189, true, 0));
    zoo.push_back(new Honeybear("Amanda", 1, 9));
    zoo.push_back(new Honeybear("Linda", 2, 80));
    zoo.push_back(new Honeybear("Rose", 3, -7));

    for (auto t : zoo) {
        t->printInfo();
        cout << endl;
    }

    for (auto t : zoo) {
        delete t;
    }

    return 0;
}