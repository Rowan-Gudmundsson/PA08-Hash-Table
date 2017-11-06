#include "HashTable.h"

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(int initTableSize) {

    tableSize = initTableSize;

    dataTable = new BSTree<DataType, KeyType>[initTableSize];
}

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(const HashTable& other) {

    (*this) = other;
}

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>& HashTable<DataType, KeyType>::operator = (const HashTable& other) {

    if(this = &other) return (*this);

    clear();

    tableSize = other.tableSize;

    dataTable = new BSTree<DataType, KeyType>[tableSize];

    for(int i = 0; i < tableSize; ++i) {

        dataTable[i] = other.dataTable[i];
    }

    return(*this);
}

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::~HashTable() {

    clear();
}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::insert(const DataType& newDataItem) {

    dataTable[newDataItem.hash(newDataItem.getKey())].insert(newDataItem);
    ++tableSize;
}

template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::remove(const KeyType& deleteKey) {

    --tableSize;
    return dataTable[deleteKey].remove(deleteKey);
}

template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::retrieve(const KeyType& searchKey, DataType& returnItem) const {

    return dataTable[searchKey].retrieve(searchKey, returnItem);
}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::clear() {

    delete [] dataTable;

    tableSize = 0;
}

template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::isEmpty() const {

    if(tableSize == 0) return true;
    else return false;
}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::showStructure() const {

    for (int i = 0; i < tableSize; ++i) {
        
        cout << i << ": ";
        dataTable[i].writeKeys();
    }
}

template <typename DataType, typename KeyType>
double HashTable<DataType, KeyType>::standardDeviation() const {

    return 0;
}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::copyTable(const HashTable& source) {


}