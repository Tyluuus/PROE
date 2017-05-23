//
// Created by tyluus on 18.05.17.
//

#include "Wyjatek.h"

Wyjatek::Wyjatek(std::string msg) : msg(msg){}

const std::string &Wyjatek::getMsg() const {
    return msg;
};