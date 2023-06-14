//
// Created by Abbas And Melisa
//

#ifndef ASSIGNMENT_04_CODE_SPNODE_H
#define ASSIGNMENT_04_CODE_SPNODE_H


//	Node.h
//  Created by Frank M. Carrano and Timothy M. Henry.
//	Updated by Duc Ta
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#pragma once
#include <memory>
#include <iostream>
using namespace std;
//
//
// PLEASE DO NOT CHANGE THIS FILE
//
//

template<typename ItemType>
class SPNode {
public:
    SPNode();
    SPNode(const ItemType&);

    ~SPNode();

    SPNode(const ItemType&, SPNode<ItemType>*);
    void setItem(const ItemType&);
    //void setNext(SPNode<ItemType>*);
    void setNext(shared_ptr<ItemType>);
    ItemType getItem() const;
    //SPNode<ItemType>* getNext() const;
    shared_ptr<ItemType> getNext() const;

private:
    ItemType        item{};			 // A data item
    //SPNode<ItemType>* next{ nullptr }; // Pointer to next node
    shared_ptr<ItemType> next{ nullptr };
};

#endif //ASSIGNMENT_04_CODE_SPNODE_H
