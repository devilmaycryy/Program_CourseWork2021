#pragma once
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


class Exception {
private:
    int error_number;
public:
    Exception(int err);
    Text show();
};