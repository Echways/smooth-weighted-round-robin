#include "include/swrr/swrr.hpp"
#include <unordered_map>

int main(){
    SmoothWeightedRR lb;
    lb.addServer("A", 5);
    lb.addServer("B", 3);
    lb.addServer("C", 1);

    std::unordered_map<std::string,int> counts;
    const int N = 14;
    for (int i = 0; i < N; ++i) {
        auto s = lb.pick();
        if (s) {
            ++counts[*s];
            std::cout << i << ": " << *s << "\n";
        }
    }

    std::cout << "\nCounts:\n";
    for (auto &p : counts) {
        std::cout << p.first << " -> " << p.second << "\n";
    }
    return 0;
}