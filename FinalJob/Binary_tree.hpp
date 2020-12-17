//
//  Binary_tree.hpp
//  FinalJob
//
//  Created by Thomas Kristan on 15.12.20.
//

#ifndef Binary_tree_h
#define Binary_tree_h
#include "Simple_tree.hpp"
#include <queue>
using namespace std;

template <typename Type>
class Binary_tree : private Simple_tree<Type>{
public:
    Binary_tree(const Type &obj, Binary_tree* parent = nullptr) : Simple_tree<Type>(obj, parent) {}
    Binary_tree* left() const;
    Binary_tree* right() const;
    Type value() const { return Simple_tree<Type>::value(); }
    Binary_tree* parent() const { return (Binary_tree<Type>*)Simple_tree<Type>::parent(); }
    void insert(Type const&);
    void detach() { Simple_tree<Type>::detach(); }
    int degree() const { return Simple_tree<Type>::degree(); }
    bool is_root() const { return Simple_tree<Type>::is_root(); }
    bool is_leaf() const { return Simple_tree<Type>::is_leaf(); }

};

template<typename Type>
Binary_tree<Type>* Binary_tree<Type>::left() const
{
    if (this->is_leaf()) { return nullptr; }
    return (Binary_tree<Type>*)this->child(0);
}

template<typename Type>
Binary_tree<Type>* Binary_tree<Type>::right() const
{
    if (this->is_leaf() || this->degree() < 2) { return nullptr; }
    return (Binary_tree<Type>*)this->child(1);
}

template <typename Type>
void Binary_tree<Type>::insert(Type const& obj)
{
    if (this->degree() >= 2) { return; }
    Simple_tree<Type>::insert(obj);
}


#endif /* Binary_tree_h */
