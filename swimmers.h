//
// Created by Sg on 08.08.2022.
//
#include <string>
#include <map>
#include <mutex>
#include <limits>
#pragma once
static std::mutex result_access;
extern std::multimap<int, std::string> result;
typedef std::pair <int, std::string> Int_Pair;
struct Swimmer {
    std::string name;
    int speed;
};
void swim (const Swimmer& myS, int distance);
//template<typename T>
//void enterValue(T &n, T min = std::numeric_limits<T>::min(), T max = std::numeric_limits<T>::max());