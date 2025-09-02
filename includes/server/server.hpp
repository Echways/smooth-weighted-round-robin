#pragma once

#include <iostream>

class Server{
private:
    std::string id_;
    int32_t staticWeight_;
    int32_t currentWeight_;

public:
    Server();
    Server(const std::string&, int32_t);
    int32_t getStaticWeight() const;
    int32_t getCurrentWeight() const;
    std::string getId() const;
    bool setStaticWeight(int32_t);
    bool setCurrentWeight(int32_t);
    bool incCurrentWeight(int32_t);
    bool decCurrentWeight(int32_t);
};
