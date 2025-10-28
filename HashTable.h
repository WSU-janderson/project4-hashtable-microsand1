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

enum class BucketType {NORMAL, ESS, EAR};

class HashTableBucket {
    //constructors
    HashTableBucket();
    HashTableBucket(const std::string& key, const size_t& value);

    // the better stuff
    void load(const std::string& key, const size_t& value);
    bool isEmpty() const;
    friend ostream& operator<<(ostream& os, const HashTableBucket& bucket);

};

class HashTable {
public:

    HashTable(size_t initCapacity = 8);

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