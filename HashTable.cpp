/*
micah sanders-johnson
october 25 2025
HashTable
Make a HashTable
*/

#include "HashTable.h"
#include <string>
#include <iostream>
#include <exception>
#include <optional>
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
    numElements=initCapacity;

}



bool HashTable::insert(const string& key, const size_t &value) {
    return false;
}

bool HashTable::remove(const string &key) {
    return false;
}

bool HashTable::contains(const string &key) {
    return false;
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
