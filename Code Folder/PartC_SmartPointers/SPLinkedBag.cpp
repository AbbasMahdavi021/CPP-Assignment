//
// Created by Abbas And Melisa
//

//  LinkedBag.cpp
//  Created by Frank M. Carrano and Timothy M. Henry.
//	Updated by Duc Ta
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include <cstddef>
#include "SPNode.h"
#include "SPLinkedBag.h"

//
//
// PLEASE DO NOT CHANGE THIS FILE
//
//

template<typename ItemType>
SPLinkedBag<ItemType>::SPLinkedBag() : headPtr(nullptr), itemCount(0) {}

template<typename ItemType>
SPLinkedBag<ItemType>::SPLinkedBag(const SPLinkedBag<ItemType>& aBag) {
    itemCount = aBag.itemCount;
    //Node<ItemType>* origChainPtr = aBag.headPtr;
    shared_ptr<SPNode<ItemType>> origChainPtr{aBag.headPtr};

    if (origChainPtr == nullptr) {
        headPtr = { nullptr };
    }
    else {
        headPtr = new SPNode<ItemType>();
        headPtr->setItem(origChainPtr->getItem());

        //Node<ItemType>* newChainPtr = headPtr;
        shared_ptr<SPNode<ItemType>> newChainPtr{ headPtr };
        origChainPtr = { origChainPtr->getNext() };

        while (origChainPtr.get() != nullptr)
        {
            ItemType nextItem = origChainPtr->getItem();
            //Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
            shared_ptr<SPNode<ItemType>> newNodePtr{nextItem, nullptr};
            newChainPtr->setNext({ newNodePtr });
            newChainPtr = {newChainPtr->getNext()};
            origChainPtr = {origChainPtr->getNext()};
        }

        newChainPtr->setNext({ nullptr });
    }
}

template<typename ItemType>
SPLinkedBag<ItemType>::~SPLinkedBag() {
    clear();
}

template<typename ItemType>
bool SPLinkedBag<ItemType>::isEmpty() const {
    return itemCount == 0;
}

template<typename ItemType>
int SPLinkedBag<ItemType>::getCurrentSize() const {
    return itemCount;
}

template<typename ItemType>
bool SPLinkedBag<ItemType>::add(const ItemType& newEntry) {
    //Node<ItemType>* nextNodePtr = new Node<ItemType>();
    shared_ptr<SPNode<ItemType>> nextNodePtr{ make_shared<SPNode<ItemType>>(newEntry, headPtr)};
    //nextNodePtr->setItem(newEntry);
    //nextNodePtr->setNext(headPtr);
    headPtr = {nextNodePtr};
    itemCount++;
    return true;
}

template<typename ItemType>
std::vector<ItemType> SPLinkedBag<ItemType>::toVector() const {
    std::vector<ItemType> bagContents;
    //Node<ItemType>* curPtr = headPtr;
    shared_ptr<SPNode<ItemType>> curPtr{ headPtr };
    int counter = 0;

    while ((curPtr.get() != nullptr) && (counter < itemCount)) {
        bagContents.push_back(curPtr->getItem());
        curPtr = { curPtr->getNext() };
        counter++;
    }

    return bagContents;
}

template<typename ItemType>
bool SPLinkedBag<ItemType>::remove(const ItemType& anEntry) {
    //Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
    shared_ptr<SPNode<ItemType>> entryNodePtr = getPointerTo(anEntry);
    bool canRemoveItem = !isEmpty() && (entryNodePtr.get() != nullptr);

    if (canRemoveItem) {
        entryNodePtr->setItem({headPtr->getItem()});
        //Node<ItemType>* nodeToDeletePtr = headPtr;
        shared_ptr<SPNode<ItemType>> nodeToDeletePtr{ headPtr };
        headPtr = {headPtr->getNext()};

        nodeToDeletePtr->setNext({nullptr});
        //delete nodeToDeletePtr;
        nodeToDeletePtr.reset();
        //nodeToDeletePtr = nullptr;

        itemCount--;
    }

    return canRemoveItem;
}

template<typename ItemType>
void SPLinkedBag<ItemType>::clear() {
    //Node<ItemType>* nodeToDeletePtr = headPtr;
    shared_ptr<SPNode<ItemType>> nodeToDeletePtr{ headPtr };

    while (headPtr.get() != nullptr) {
        headPtr = { headPtr->getNext() };
        nodeToDeletePtr->setNext(nullptr);
        nodeToDeletePtr.reset();
        nodeToDeletePtr = headPtr;
    }

    itemCount = 0;
}

template<typename ItemType>
int SPLinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const {
    int frequency = 0;
    int counter = 0;
    //Node<ItemType>* curPtr = headPtr;
    shared_ptr<SPNode<ItemType>> curPtr{ headPtr };

    while ((curPtr.get() != nullptr) && (counter < itemCount)) {
        if (anEntry == curPtr->getItem()) {
            frequency++;
        }
        counter++;
        curPtr = { curPtr->getNext() };
    }

    return frequency;
}

template<typename ItemType>
bool SPLinkedBag<ItemType>::contains(const ItemType& anEntry) const {
    return (getPointerTo(anEntry) != nullptr);
}

template<typename ItemType>
shared_ptr<SPNode<ItemType>> SPLinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const {
    bool found = false;
    //Node<ItemType>* curPtr = headPtr;
    shared_ptr<SPNode<ItemType>> curPtr{ headPtr };

    while (!found && (curPtr.get() != nullptr)) {
        if (anEntry == curPtr->getItem()) {
            found = true;
        }
        else {
            curPtr = { curPtr->getNext() };
        }
    }

    return curPtr;
}
