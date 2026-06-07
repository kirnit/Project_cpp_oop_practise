#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using  namespace std;

class People {
private:
    string name;
    int age;
protected:
    int HP;
public:
    People() {
        cin >> this->name >> this->age >> this->HP;
    }     
    People(string name, int age) {
        this->name = name;
        this->age = age;
        this->HP = 0;
    } string GetName() {return this->name;}
    void SetHP(int NewHP) {this->HP += NewHP;}
    bool Alive() {return HP > 0;}
    virtual void act(People* x) = 0;
    virtual void print() {cout << this->name << ' ' << this->age << ' ' << this->HP << " ";}
};

class Doc: public People {
    public:
        Doc(): People() {this->HP = 200;}
        Doc(string name, int age): People(name, age) {this->HP = 200;}
        void act(People* x) {
            cout << this->GetName() << " лечит " << x->GetName() << endl;
            this->HP -= 40;
            x->SetHP(50);
        }
};

class Granny: public People {
    public:
        Granny(): People() {this->HP = 100;}
        Granny(string name, int age): People(name, age) {this->HP = 100;}
        void act(People* x) {
            cout << this->GetName() << " печет пирожки для " << x->GetName() << endl;
            this->HP -= 20;
            x->SetHP(30);
        }
};

class Mus: public People {
    public:
        Mus(): People() {this->HP = 100;}
        Mus(string name, int age): People(name, age) {this->HP = 100;}
        void act(People* x) {
            cout << this->GetName() << " играет на скрипке для " << x->GetName() << endl;
            this->HP -= 20;
            x->SetHP(-30);
        }
};

int main() {
    srand(time(0));
    int N = 6, alive = N;
    People* city[N] = {
        new Granny("Alla", 80),
        new Granny("Baba Yaga", 100),
        new Doc("Dr. House", 70),
        new Doc("Dr. Watson", 75),
        new Mus("Bon Jovi", 63),
        new Mus("Freddie Mercury", 45)
    };

    for (int i=0; i<N; i++)
        city[i]->print();
        cout << endl;
    
    cout << endl << "The Game of Life has started!" << endl;

    while (alive > 1) {
        int citiz_1 = rand() % N;
        int citiz_2 = rand() % N;

        if (citiz_1 == citiz_2)
            continue;
        if (city[citiz_1] == nullptr)
            continue;
        if (city[citiz_2] == nullptr)
            continue;
        city[citiz_1]->act(city[citiz_2]);
        cout << endl;

        for (int i = 0; i < N; i++) {
            if (city[i] != nullptr &&
                !city[i]->Alive()) {
                city[i]->print();
                cout << " УМЕР!" << endl;

                delete city[i];
                city[i] = nullptr;
                alive--;
            }
        }
    }
}