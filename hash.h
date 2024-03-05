#ifndef HASH_H
#define HASH_H
#include <iostream>
#include <string>
#include <cmath>

// Defining the Node struct for chaining hash table
struct Node {
    std::string value;
    Node* next;
};

class HashTable {
private:
    int size;
    Node** table; 

    // Hash function declaration
    int customHash(const std::string& key);

public:
    HashTable(int size);
    ~HashTable();

    void insert(const std::string& key); // Inserting key into the Hash Table

    void printFirstSlots(int slotsToPrint); //Printing the key
    void printSlotLengths();
    float calculateStandardDeviation();
};

#endif /* HASH_H */

