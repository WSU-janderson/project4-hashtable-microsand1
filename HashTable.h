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
#include <optional>
#include <vector>

using namespace std;

enum class BucketType {NORMAL, ESS, EAR};

class HashTableBucket {
    //constructors
    HashTableBucket();
    HashTableBucket(string  key, const size_t& value);

    // the better stuff
    void load(const string& key, const size_t& value);
    bool isEmpty() const;
    friend ostream& operator<<(ostream& os, const HashTableBucket& bucket);
    void makeEAR();


private:
    string key;
    size_t value;
    BucketType type;

};

class HashTable {
public:

    HashTable(size_t initCapacity = 8);

    bool insert(const string& key, const size_t& value);
    bool remove(const string& key);
    bool contains(const string& key);

    optional<size_t> get(const string& key);
    size_t& operator[](const string& key);
    vector<std::string> keys() const;


    double alpha() const;
    size_t capacity() const;
    size_t size() const;

    friend ostream& operator<<(ostream& os, const HashTable& hashTable);

private:
    size_t numElements;
    vector<HashTableBucket> table;
};

#endif