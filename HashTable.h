/*
micah sanders-johnson
october 25 2025
HashTable
Make a HashTable
*/

#ifndef CLASSES_HASHTABLE_H
#define CLASSES_HASHTABLE_H

#include <string>
#include <iostream>
#include <exception>

using namespace std;

class HashTable {
public:



    bool insert(const std::string$ key, const size_t& value);
    bool remove(const std::string& key);
    bool contains(const string& key);

    std::optional<size_t> get(const string& key);
    size_t& operator[](const string& key);
    std::vector<std::string> keys() const;


    double alpha() const;
    size_t capacity() const;
    size_t size() const;

    friend ostream& operator<<(ostream& os, const HashTable& hashTable);
    };

#endif