#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 50000 // Hash table size

// Structure for hash table nodes
typedef struct HashNode {
    int key;                
    int value;              
    struct HashNode* next;  
} HashNode;

// Hash table
HashNode* hashTable[HASH_SIZE] = {0};

// Hash function
int hash(int key) {
    return abs(key) % HASH_SIZE;
}

// Insert into hash table
void hashInsert(int key, int value) {
    int hashIndex = hash(key);
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[hashIndex];
    hashTable[hashIndex] = newNode;
}

// Search in hash table
int hashSearch(int key) {
    int hashIndex = hash(key);
    HashNode* node = hashTable[hashIndex];
    while (node != NULL) {
        if (node->key == key) return node->value;
        node = node->next;
    }
    return -1;
}

// Free hash table memory
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
    int* result = (int*)malloc(2 * sizeof(int));
    if (!result) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int index = hashSearch(complement);
        if (index != -1) {
            result[0] = index;
            result[1] = i;
            *returnSize = 2;
            hashFree();
            return result;
        }
        hashInsert(nums[i], i);
    }

    free(result);
    hashFree();
    return NULL;
}

// Main function to test Two Sum
int main() {
    int nums1[] = {2, 7, 11, 15};
    int target1 = 9;
    int returnSize1;
    int* result1 = twoSum(nums1, 4, target1, &returnSize1);

    if (result1 != NULL) {
        printf("Test Case 1: nums = {2, 7, 11, 15}, target = 9\n");
        printf("Output: [%d, %d]\n\n", result1[0], result1[1]);
        free(result1);
    } else {
        printf("Test Case 1 failed!\n\n");
    }

    int nums2[] = {3, 2, 4};
    int target2 = 6;
    int returnSize2;
    int* result2 = twoSum(nums2, 3, target2, &returnSize2);

    if (result2 != NULL) {
        printf("Test Case 2: nums = {3, 2, 4}, target = 6\n");
        printf("Output: [%d, %d]\n\n", result2[0], result2[1]);
        free(result2);
    } else {
        printf("Test Case 2 failed!\n\n");
    }

    int nums3[] = {3, 3};
    int target3 = 6;
    int returnSize3;
    int* result3 = twoSum(nums3, 2, target3, &returnSize3);

    if (result3 != NULL) {
        printf("Test Case 3: nums = {3, 3}, target = 6\n");
        printf("Output: [%d, %d]\n", result3[0], result3[1]);
        free(result3);
    } else {
        printf("Test Case 3 failed!\n");
    }

    return 0;
}
