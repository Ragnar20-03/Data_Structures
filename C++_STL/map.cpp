#include<map> 
#include <iostream> 
#include<set>

using namespace std ; 

int main() 
{
    map<int , map < int , multiset <int >  >  > m ; 

    m[0][0].insert(1);
    m[0][2].insert(10);
    m[0][2].insert(9);
    m[0][4].insert(6);

    m[-2][2].insert(4);
    m[-1][1].insert(2);
    m[-1][3].insert(5);

    m[1][1].insert(3);

    m[2][2].insert(10);




     std::cout << "Elements in the map:" << std::endl;
    for (const auto& outer_pair : m) {
        int outer_key = outer_pair.first;
        std::cout << "Outer key: " << outer_key << std::endl;
        for (const auto& inner_pair : outer_pair.second) {
            int inner_key = inner_pair.first;
            std::cout << "  Inner key: " << inner_key << " -> ";
            for (const auto& value : inner_pair.second) {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0 ;
}