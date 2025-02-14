#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <functional>
#include <fstream>
#include <sstream>
#include <iostream>



void clearWindow();


template <typename T>
std::vector<T> loadfiles( std::string &filePath, std::function<T( std::stringstream&)> createEntity) {
    std::vector<T> entities;
    std::ifstream file(filePath);
    if (!file) {
        std::cout << "无法打开文件" << std::endl;
        return entities;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        T entity = createEntity(ss);
        if (entity) { entities.push_back(entity); }
    }
    return entities;
}
template <typename T>
T randomSelect(std::vector<T> &entities) {
    T entity = entities[rand() % entities.size()];
    return entity;
}


#endif // UTILS_H
