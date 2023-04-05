#include "iostream"
#include "vector"
#include "string"
#include "algorithm"



template <typename T, typename F>
std::vector<std::invoke_result_t<F,T>> mapped(const std::vector<T>& initialVector, F mappingFunc){
    std::vector<std::invoke_result_t<F,T>> toReturn;
    for (const auto& elem: initialVector) {
        toReturn.push_back(mappingFunc(elem));
    }
    return toReturn;
}

int main() {
    auto strings = std::vector<std::string>{"abc", "defghi", "jk", "lmno"};
    auto chars = mapped(
            strings,
            [](std::string s)  { return s.front(); }
    );
    for (auto elem:chars) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    auto sizes = mapped(
            strings,
            [](std::string s) { return s.size(); }
    );
    for (auto elem:sizes) {
        std::cout << elem << " ";
    }
    return 0;
}



