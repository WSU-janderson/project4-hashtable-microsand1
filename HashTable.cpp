/*
micah sanders-johnson
october 25 2025
HashTable
Make a HashTable
*/

#include "HashTable.h"
#include <iostream>
#include <exception>

using namespace std;


// Default constructor.
HashTableBucket::HashTableBucket() : key(""), value(0), type(BucketType::ESS) {

}

//constructor.
HashTableBucket::HashTableBucket(const std::string& key, const size_t& value) : key(key), value(value), type(BucketType::NORMAL) {

}

//Load for the bucket parameters
void HashTableBucket::load(const std::string& key, const size_t& value) {
    this->key = key;
    this->value = value;
    this->type = BucketType::NORMAL;
}

bool HashTableBucket::isEmpty() const {
    return type == BucketType::ESS || type == BucketType::EAR;
}



/**
* Only a single constructor that takes an initial capacity for the table is
* necessary. If no capacity is given, it defaults to 8 initially
*/
HashTable::HashTable(size_t initCapacity) {

}

bool HashTable::insert(const std::string$ key, const size_t &value) {

}

bool HashTable::remove(const std::string &key) {

}

bool HashTable::contains(const string &key) {

}

