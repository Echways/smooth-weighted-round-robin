#pragma once

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
