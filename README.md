# Smooth Weighted Round Robin
Простая реализация плавного WRR.

## Установка
```bash
git clone git@github.com:Echways/cpp-weightedroundrobin.git
```

Затем в вашем коде

```bash
#include "includes/swrr/swrr.hpp"
```

# Пример использования
```markdown
SmoothWeightedRR lb;
lb.addServer("A", 5);
lb.addServer("B", 3);
lb.addServer("C", 1);

std::unordered_map<std::string,int> counts;
const int N = 8;
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
```
```markdown
0: A
1: B
2: A
3: C
4: A
5: B
6: A
7: A

Counts:
B -> 2
C -> 1
A -> 5
```
