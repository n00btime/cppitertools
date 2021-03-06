#include <sorted.hpp>

#include <iostream>
#include <vector>
#include <string>

using iter::sorted;

int main()
{
    std::vector<int> vec = {19, 3, 45, 32, 10, 0, 90, 15, 1, 7, 5, 6, 69};
    for (auto i : sorted(vec)) {
        std::cout << i << '\n';
    }

    const std::vector<int> cvec(vec);
    for (auto i : sorted(cvec)) {
        std::cout << i << '\n';
    }

    std::vector<std::string> svec = {"hello", "everyone", "thanks", "for",
                                     "having", "me", "here", "today"};
    for (auto s : sorted(svec,
                [] (const std::string & s1, const std::string & s2) {
                    return s1[1] < s2[1]; })) {
        std::cout << s << '\n';
    }
        

    return 0;
}
