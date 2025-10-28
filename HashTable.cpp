/*
micah sanders-johnson
october 25 2025
HashTable
Make a HashTable
*/

#include "HashTable.h"

#include <algorithm>
#include <chrono>
#include <string>
#include <iostream>
#include <exception>
#include <optional>
#include <random>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;


// Default constructor.
HashTableBucket::HashTableBucket() : key(""), value(0), type(BucketType::ESS) {

}

//constructor.
HashTableBucket::HashTableBucket(string  key, const size_t& value) : key(std::move(key)), value(value), type(BucketType::NORMAL) {

}

//Load for the bucket parameters
void HashTableBucket::load(const string& key, const size_t& value) {
    this->key = key;
    this->value = value;
    this->type = BucketType::NORMAL;
}

bool HashTableBucket::isEmpty() const {
    return type == BucketType::ESS || type == BucketType::EAR;
}

void HashTableBucket::makeEAR() {
    this->type = BucketType::EAR;
}

ostream& operator<<(ostream& os, const HashTableBucket& bucket) {
    if (bucket.isEmpty()) {
        os << "(Empty)";
    } else {
        os << "Key: " << bucket.key << ", Value: " << bucket.value;
    }
    return os;
}




/**
* Only a single constructor that takes an initial capacity for the table is
* necessary. If no capacity is given, it defaults to 8 initially
*/
HashTable::HashTable(size_t initCapacity) {
    numElements=0;
    table.reserve(initCapacity);
    offsets.reserve(initCapacity);
    for (size_t i = 1; i <= initCapacity; ++i) {
        offsets.push_back(i);
    }
    //what did you mean by shuffle, after 20 min this is all i could find
    auto rng = std::default_random_engine {};

    shuffle(offsets.begin(), offsets.end(), rng);
}

HashTable::~HashTable() {
    delete &table;
}

bool HashTable::insert(const string& key, const size_t &value) {
    return false;
}



bool HashTable::remove(const string &key) {
    bool result = false;
    for(int i=0; i < table.size(); i++) {
        if(table[i].key==key) {
            result = true;
            table[i].makeEAR();
        }
    }
    return result;
}

bool HashTable::contains(const string &key) {
    bool result = false;
    for(int i=0; i < table.size(); i++) {
        if(table[i].key==key) {
            result = true;
        }
    }
    return result;
}


optional<size_t> HashTable::get(const string& key) {
    return nullopt;
}

size_t& HashTable::operator[](const string& key) {
    return numElements;
};


vector<string> HashTable::keys() const {
    vector<string> result;
    for(int i=0; i < table.size(); i++) {
        result.push_back(table[i].key);
    }
    return result;
}

double HashTable::alpha() const {
    return static_cast<double>(numElements)/static_cast<double>(table.size());
}

size_t HashTable::capacity() const {
    return table.size();
}

size_t HashTable::size() const {
    return numElements;
}

ostream& operator<<(ostream& os, const HashTable& hashTable) {

}
