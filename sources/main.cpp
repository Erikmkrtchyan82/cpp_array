#include <iostream>
#include <string>
#include <vector>

#include "../headers/my_array.hpp"
#include "../headers/utils.hpp"

int main() {
    size_t n = insert("Insert count: ");
    Array arr{n};
    std::string query;
    std::vector<std::string> chunks;
    do {
        std::cout << " >>> ";
        std::getline(std::cin, query);

        if (query == "intersect") {
            intersect(arr);
            continue;
        }

        if (query == "merge") {
            merge(arr);
            continue;
        }

        chunks = split(query);

        try {
            standard(arr, chunks);
        } catch (std::string& e) {
            std::cout << "ERROR: " << e << std::endl;
        }
    } while (query != "q");
}
