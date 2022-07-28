#include <bits/stdc++.h>
using namespace std;
template<typename K>
using MapIterator = typename std::map<K,vector<K>>::const_iterator;

template<typename K>
void PrintMap(const std::map<K,vector<K>>& m) {
    for (MapIterator<K, vector<K>> iter = m.begin(); iter != m.end(); iter++) {
        std::cout << "Key: " << iter->first << " "
              << "Values: " << iter->second << std::endl;
    }
}

int main() {
    std::map<int, int> x = {{5, 7}, {8, 2}};
    PrintMap(x);
    return 0;
}