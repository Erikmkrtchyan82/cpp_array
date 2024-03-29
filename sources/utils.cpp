#include "../headers/utils.hpp"

#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "../headers/my_array.hpp"

std::vector<std::string> split(const std::string& input, const std::string& sep) {
    std::vector<std::string> chunks;

    auto begin = 0;
    do {
        auto sep_idx = input.find(sep, begin);
        if (sep_idx == std::string::npos) break;
        chunks.push_back(input.substr(begin, sep_idx - begin));
        begin = sep_idx + sep.size();
    } while (true);

    chunks.push_back(input.substr(begin));

    return chunks;
}

size_t insert(const std::string& prompt) {
    size_t n;
    std::cout << prompt;
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return n;
}

void standard(Array& arr, std::vector<std::string>& chunks) {
    if (chunks[0] == "get") {
        std::cout << arr.get_item(std::stoi(chunks[1])) << std::endl;
    }
    if (chunks[0] == "push") {
        std::cout << arr.push(std::stoi(chunks[1])) << std::endl;
    }
    if (chunks[0] == "insert") {
        std::cout << arr.insert(std::stoi(chunks[1]), std::stoi(chunks[2])) << std::endl;
    }
    if (chunks[0] == "remove") {
        std::cout << arr.remove(std::stoi(chunks[1]), std::stoi(chunks[2])) << std::endl;
    }
    if (chunks[0] == "p") {
        std::cout << arr << std::endl;
    }
}

void intersect(Array& arr) {
    size_t n = insert("Insert count for 2nd array: ");
    Array arr2{n};
    std::string query;
    std::vector<std::string> chunks;
    do {
        std::cout << "i >> ";
        std::getline(std::cin, query);

        chunks = split(query);

        if (chunks[0] == "i") {
            std::cout << intersect(arr, arr2) << std::endl;
        } else if (chunks[0] == "a") {
            std::cout << "arr1\n";
            std::cout << arr << std::endl;
            std::cout << "\narr2\n";
            std::cout << arr2 << std::endl;
        } else {
            standard(arr2, chunks);
        }
    } while (query != "q");
}

void merge(Array& arr) {
    size_t n = insert("Insert count for 2nd array: ");
    Array arr2{n};
    std::string query;
    std::vector<std::string> chunks;
    do {
        std::cout << "m >> ";
        std::getline(std::cin, query);

        chunks = split(query);

        if (chunks[0] == "m") {
            std::cout << merge(arr, arr2, false) << std::endl;
        } else if (chunks[0] == "mu") {
            std::cout << merge(arr, arr2, true) << std::endl;
        } else if (chunks[0] == "a") {
            std::cout << "arr1\n";
            std::cout << arr << std::endl;
            std::cout << "\narr2\n";
            std::cout << arr2 << std::endl;
        } else {
            standard(arr2, chunks);
        }
    } while (query != "q");
}
