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
    this->key = "";
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
    if (initCapacity < 8) {
        initCapacity = 8;
    }
    numElements = 0;
    table.resize(initCapacity);
    offsets.resize(initCapacity);

    for (size_t i = 0; i < initCapacity; ++i) {
        offsets[i] = i;
    }

    // Shuffle offsets to define random probing order
    std::shuffle(offsets.begin(), offsets.end(), std::default_random_engine(
        std::chrono::system_clock::now().time_since_epoch().count()
    ));
}



size_t HashTable::hash(const string& key) const {
    std::hash<string> hasher;
    return hasher(key) % table.size();
}


bool HashTable::insert(const string& key, const size_t &value) {
    if (contains(key)) {
        return false;
    }
    bool result = false;
    for(int i=0; i < table.size(); i++) {
        if((table[i].type == BucketType::EAR || table[i].type == BucketType::ESS)) {
            table[i].load(key,value);
            result = true;
            i = table.size();
        }
    }
    if (0.5 <= alpha()) {
        size_t cardinality = table.size()*2;
        offsets.reserve(table.size()*2);
        table.reserve(table.size()*2);
        for (size_t i = 0; i < cardinality; ++i) {
            offsets[i] = i+1;
            if(table[i].isEmpty()&&(i>cardinality/2)) {
                table[i]=HashTableBucket();
            }
        }
    }

    return result;

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
    bool gate = false;
    size_t result;
    for(int i=0; i < table.size(); i++) {
        if(table[i].key==key) {
            result = table[i].value;
            gate = true;
        }
    }
    if (gate) {
        return result;
    }
    return nullopt;
}

size_t& HashTable::operator[](const string& key) {
    size_t result;
    for(int i=0; i < table.size(); i++) {
        if(table[i].key==key) {
            result = table[i].value;
        }
    }
    return result;
};


vector<string> HashTable::keys() const {
    vector<string> result;
    for(int i=0; i < table.size(); i++) {
        if (!(table[i].isEmpty())) {
            result.push_back(table[i].key);
        }
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
    os << "HashTable (size=" << hashTable.size()
   << ", capacity=" << hashTable.capacity()
   << ", alpha=" << hashTable.alpha() << ")\n";

    for (size_t i = 0; i < hashTable.table.size(); ++i)
        os << "[" << i << "]: " << hashTable.table[i] << "\n";

    return os;
}
