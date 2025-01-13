//
// Created by 2021s on 9/9/2022.
//

#ifndef PROGRAM1_LOCATION_H
#define PROGRAM1_LOCATION_H
#include <string>

using namespace std;

class location {
private:
    string description;
    bool scan;
    int x_coordinate;
    int y_coordinate;
public:
    location();
    location(string d, bool s, int x, int y);

    string get_description(){return description;}
    bool get_key_piece(){return scan;}
    int get_x(){return x_coordinate;}
    int get_y(){return y_coordinate;}

    void set_description(string n){description=n;}
    void set_key_piece(bool k){scan=k;}
    void set_x(int n){x_coordinate=n;}
    void set_y(int n){y_coordinate=n;}
};

location::location() {

}

location::location(string d, bool s, int x, int y) {
    description=d;
    scan=s;
    x_coordinate=x;
    y_coordinate=y;
}
#endif //PROGRAM1_LOCATION_H
