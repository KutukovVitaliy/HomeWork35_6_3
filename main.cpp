#include <iostream>
#include <vector>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

int main() {
    auto lambdaFunction([](std::string& inPath, std::string& extensionToFind){
        std::vector<std::string > list;
        for(auto& p: fs::recursive_directory_iterator(inPath))
            if(is_regular_file(p.path())) {
                if (p.path().extension().compare(extensionToFind) == 0) {
                    //std::cout << p.path() << '\n';
                    list.emplace_back(p.path());
                }
            }
        return list;
    });
    std::string path{"/home/kvit/Modbus"};
    std::string extension{".txt"};
    auto extensionList = lambdaFunction(path, extension);
    for(auto& el : extensionList){
        std::cout << el << std::endl;
    }
    return 0;
}
