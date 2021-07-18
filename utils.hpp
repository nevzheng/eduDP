// Useful Template of Utility Functions for programming problems
// Created by Nevin Zheng on 7/14/21.
//
#pragma once

#include <bits/stdc++.h>
using namespace std;

template<typename T>
void printVector(const T& t) {
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, ", "));
}

template<typename T>
void printVectorInVector(const T& t) {
    std::for_each(t.cbegin(), t.cend(), printVector<typename T::value_type>);
}