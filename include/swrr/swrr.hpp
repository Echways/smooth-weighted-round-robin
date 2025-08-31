#include "../server/server.hpp"
#include <vector>
#include <optional>


class SmoothWeightedRR{
private:
    std::vector<Server> serverVector_;
    int32_t totalWeight_;
    size_t rrIndex_ = SIZE_MAX;

public:
    SmoothWeightedRR();
    bool addServer(const std::string&, int32_t);
    bool setWeight(size_t, int32_t);
    bool clear();

    std::optional<std::string> pick();
};

SmoothWeightedRR::SmoothWeightedRR()
    : totalWeight_(0)
    , rrIndex_(SIZE_MAX)
{}

bool SmoothWeightedRR::addServer(const std::string& id, int32_t w) {
    if (w <= 0) w = 0;
    serverVector_.emplace_back(Server(id, w));
    totalWeight_ += w;
    return 0;
}

bool SmoothWeightedRR::setWeight(size_t id, int32_t w) {
    if(id >= serverVector_.size()){
        throw std::out_of_range("Your id is out of servers id range");
    } 
    if (w <= 0) w = 0;
    totalWeight_ += (w - serverVector_[id].getStaticWeight());
    serverVector_[id].setStaticWeight(w);
    return 0;
}

bool SmoothWeightedRR::clear() {
    serverVector_.clear();
    totalWeight_ = 0;
    rrIndex_ = SIZE_MAX;
    return 0;
}

std::optional<std::string> SmoothWeightedRR::pick() {
    if (serverVector_.empty()) return std::nullopt;

    if (totalWeight_ == 0) {
        if (rrIndex_ == SIZE_MAX) rrIndex_ = 0;
        else rrIndex_ = (rrIndex_ + 1) % serverVector_.size();
        return serverVector_[rrIndex_].getId();
    }

    size_t best = 0;
    for (size_t i = 0; i < serverVector_.size(); ++i){
        serverVector_[i].incCurrentWeight(serverVector_[i].getStaticWeight());
        if (serverVector_[i].getCurrentWeight() > serverVector_[best].getCurrentWeight()) best = i;
    }
    serverVector_[best].decCurrentWeight(totalWeight_);

    rrIndex_ = SIZE_MAX;
    return serverVector_[best].getId();
}
