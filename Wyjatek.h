//
// Created by tyluus on 18.05.17.
//

#ifndef PROE2_WYJATEK_H
#define PROE2_WYJATEK_H

#include <iostream>

class Wyjatek
    : public std::exception
{
    private:
        std::string msg;
    public:
        Wyjatek(std::string msg);

        const std::string &getMsg() const;
};

#endif //PROE2_WYJATEK_H
