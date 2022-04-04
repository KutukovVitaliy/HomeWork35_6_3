#include <iostream>
#include <vector>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

int main() {
    for(auto& p: fs::recursive_directory_iterator("/home/kvitadmin/gammu"))
        if(p.path().extension().compare(".txt") == 0){
            std::cout << p.path() << '\n';
        }
    return 0;
}
