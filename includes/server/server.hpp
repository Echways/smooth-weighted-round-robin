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



Server::Server()
    : id_("a")
    , staticWeight_(0)
    , currentWeight_(0)
{}

Server::Server(const std::string& id, int32_t w)
    : id_(id)
    , staticWeight_(w)
    , currentWeight_(0)
{}


int32_t Server::getStaticWeight() const {
    return staticWeight_;
}

int32_t Server::getCurrentWeight() const {
    return currentWeight_;
}

std::string Server::getId() const {
    return id_;
}

bool Server::setStaticWeight(int32_t num) {
    staticWeight_ = num;
    return 0;
}

bool Server::setCurrentWeight(int32_t num) {
    currentWeight_ = num;
    return 0;
}

bool Server::incCurrentWeight(int32_t num) {
    currentWeight_ += num;
    return 0;
}
bool Server::decCurrentWeight(int32_t num) {
    currentWeight_ -= num;
    return 0;
}