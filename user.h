//
// Created by 2021s on 9/9/2022.
//

#ifndef PROGRAM1_USER_H
#define PROGRAM1_USER_H

#include <string>
#include <algorithm>
#include <vector> //used vector instead of dynamic array; found it easier to use

using namespace std;

class user {
private:
    string name;
    vector<string> Inventory; //made string vector called Inventory
    int x=4;//where user starts on map (4,2)
    int y=2;
    int score=0; //starting score
public:
    user();

    string get_name(){return name;}
    vector<string> get_Inventory();
    int get_x(){return x;}
    int get_y(){return y;}
    int get_score(){return score;}
    int get_size(){return Inventory.size();}

    void set_name(string c){name=c;}
    void display_Inventory();
    void set_x(int c){x=c;}
    void set_y(int c){y=c;}
    void set_score(int s){score=score+s;}
    void addItem(string item);
    bool dropItem(string item);
};

user::user() {

}

vector<string> user::get_Inventory() {
    return Inventory;
}

void user::display_Inventory() { //to display inventory
    for (int i=0; i<Inventory.size(); i++){
        cout << Inventory.at(i)<<", ";
    }
    cout << endl;
}

void user::addItem(string item) { //to add item to inventory
    Inventory.push_back(item);
}

bool user::dropItem(string item) { //to drop item from inventory
    for (int i=0; i<Inventory.size(); i++) {
        if (Inventory.at(i) == item) {
            Inventory.erase(Inventory.begin()+i); //looks through list to find item user wants to drop and erases it
            return true;
        }
    }
    return false;
}

#endif //PROGRAM1_USER_H
