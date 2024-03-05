#include <iostream>
#include <string>
#include "hash.h"
#include <cmath>

using namespace std;

HashTable::HashTable(int size) {
    // Initializing the hash table with given size
    this->size = size;
    table = new Node*[size];
    for (int i = 0; i < size; ++i)
        table[i] = nullptr;
}

HashTable::~HashTable() {
    // Destructor 
    for (int i = 0; i < size; ++i) {
        Node* current = table[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] table;
}
// Custom Hash Function, this decides if I'll be the top5 or not :P
int HashTable::customHash(const std::string& key) {
    unsigned long hash = 5381;
    for (size_t i = 0; i < key.length(); ++i) {
        hash = ((hash << 5) + hash) + key[i]; 
    }
    return hash % size;
}

// Inserting keys into 'slots'
void HashTable::insert(const std::string& key) {
    int index = customHash(key);
    Node* newNode = new Node;
    newNode->value = key;
    newNode->next = nullptr;    
    if (table[index] == nullptr) {
        table[index] = newNode;
    } else {
        Node* current = table[index];
        while (current->next != nullptr)
            current = current->next;
        current->next = newNode;
    }
}

// Printing the contents of the first 'slotsToPrint' slots
void HashTable::printFirstSlots(int slotsToPrint) {
    for (int i = 0; i < slotsToPrint && i < size; ++i) {
        std::cout << "Slot " << i << ": ";
        Node* current = table[i];
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
}

// Printing the lengths of all slots in the hash table
void HashTable::printSlotLengths() {
    for (int i = 0; i < size; ++i) {
        int count = 0;
        Node* current = table[i];
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        std::cout << "Slot " << i << ": " << count << std::endl;
    }
}

// Calculating the standard deviation of slot lengths

float HashTable::calculateStandardDeviation() {
    float mean = 0;
    for (int i = 0; i < size; ++i) {
        int count = 0;
        Node* current = table[i];
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        mean += count;
    }
    mean /= size;

// I hope the math is correct 

    float variance = 0;
    for (int i = 0; i < size; ++i) {
        int count = 0;
        Node* current = table[i];
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        variance += (count - mean) * (count - mean);
    }
    variance /= size;

    return sqrt(variance);
}