#include <stdlib.h>

#define HASH_SIZE 50000 // Hash table size, adjustable as needed

// Structure for hash table nodes
typedef struct HashNode {
    int key;                // Store the value from the array
    int value;              // Store the index of the value
    struct HashNode* next;  // Pointer to the next hash node (chaining)
} HashNode;

// Hash table, an array storing pointers to hash nodes
HashNode* hashTable[HASH_SIZE] = {0};

// Hash function using modulo operation
int hash(int key) {
    return abs(key) % HASH_SIZE;
}

// Insert a key-value pair into the hash table
void hashInsert(int key, int value) {
    int hashIndex = hash(key);
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;          // Store value
    newNode->value = value;      // Store index
    newNode->next = hashTable[hashIndex]; // Insert at the head of the linked list
    hashTable[hashIndex] = newNode;
}

// Search for a key in the hash table, return the index if found, otherwise return -1
int hashSearch(int key) {
    int hashIndex = hash(key);
    HashNode* node = hashTable[hashIndex];
    while (node != NULL) {
        if (node->key == key) {
            return node->value; // Return the index
        }
        node = node->next;
    }
    return -1; // Not found
}

// Free memory allocated for the hash table
void hashFree() {
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode* node = hashTable[i];
        while (node != NULL) {
            HashNode* temp = node;
            node = node->next;
            free(temp);
        }
        hashTable[i] = NULL;
    }
}

// Two Sum function
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Dynamically allocate memory for the result array
    int* result = (int*)malloc(2 * sizeof(int));
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // Initialize return size
    *returnSize = 0;

    // Iterate through the array
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int index = hashSearch(complement);
        if (index != -1) {
            // If a valid pair is found
            result[0] = index;
            result[1] = i;
            *returnSize = 2;
            hashFree(); // Free hash table memory
            return result;
        }
        // Insert the current element into the hash table
        hashInsert(nums[i], i);
    }

    // If no valid pair is found
    free(result);
    hashFree(); // Free hash table memory
    return NULL;
}

