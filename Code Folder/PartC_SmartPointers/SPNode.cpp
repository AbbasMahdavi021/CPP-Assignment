//
// Created by Abbas And Melisa
//

#include "SPNode.h"
//  Node.cpp
//  Created by Frank M. Carrano and Timothy M. Henry.
//	Updated by Duc Ta
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

//
//
// PLEASE DO NOT CHANGE THIS FILE
//
//

template<typename ItemType>
SPNode<ItemType>::SPNode() : item(), next(nullptr) {}

template<typename ItemType>
SPNode<ItemType>::SPNode(const ItemType& anItem) : item(anItem), next(nullptr) {}

template<typename ItemType>
SPNode<ItemType>::SPNode(const ItemType& anItem, SPNode<ItemType>* nextNodePtr) :
        item(anItem), next(nextNodePtr) {}

template<typename ItemType>
SPNode<ItemType>::~SPNode(){
    cout << "SPNode Destructor: " << this << ", " << this->getItem() << endl;
}

template<typename ItemType>
void SPNode<ItemType>::setItem(const ItemType& anItem) {
    item = anItem;
}

template<typename ItemType>
void SPNode<ItemType>::setNext(shared_ptr<ItemType> nextNodePtr) {
    next.swap({ nextNodePtr });
    nextNodePtr.reset();
}

template<typename ItemType>
ItemType SPNode<ItemType>::getItem() const {
    return item;
}

template<typename ItemType>
shared_ptr<ItemType> SPNode<ItemType>::getNext() const {
    return next;
}