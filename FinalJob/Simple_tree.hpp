//
//  adt.h
//  FinalJob
//
//  Created by Thomas Kristan on 15.12.20.
//

#include <iostream>
#include <vector>
#include <algorithm>

template <typename Type>
class Simple_tree {
private:
    Type node_value;
    Simple_tree *parent_node;
    std::vector<Simple_tree*> children;
public:
    Simple_tree( Type const &obj = Type(), Simple_tree *p = nullptr ) : node_value(obj), parent_node(p) {}
    Type value() const{return node_value;}
    Simple_tree *parent() const {return parent_node;}
    int degree() const { return (int)children.size(); }
    bool is_root() const { return (parent() == nullptr); }
    bool is_leaf() const { return (degree() == 0); };
    Simple_tree *child( int n ) const;
    int height() const;
    int size() const;

    void insert( Type const &);
    void attach( Simple_tree *);
    void detach();
};

template <typename Type>
Simple_tree<Type> *Simple_tree<Type>::child( int n ) const {
    if ( n < 0 || n >= degree() ) {
        return nullptr;
    }
    return children[n];
}

template <typename Type>
void Simple_tree<Type>::insert( Type const &obj )
{
    children.push_back( new Simple_tree( obj, this ));
}

template <typename Type>
void Simple_tree<Type>::detach() {
   if ( is_root() ) {
       return;
    }
    auto tmp = std::find(parent()->children.begin(), parent()->children.end(), this);
    parent()->children.erase( tmp );
    parent_node = nullptr;
    
}

template <typename Type>
void Simple_tree<Type>::attach( Simple_tree<Type> *tree ) {
    if ( !tree->is_root() ) {
        tree->detach();
    }
    tree->parent_node = this;
    children.push_back( tree );
}

template <typename Type>
int Simple_tree<Type>::size() const {
    if ( this == nullptr ) {
        return 0;
    }
    int tree_size = 1;
    for ( auto child : children){
        tree_size += child->size();
    }
    return tree_size ;
}

template <typename Type>
int Simple_tree<Type>::height() const {
    if ( this == nullptr ) {
        return -1;
    }
    int tree_height = 0;
    for ( auto child : children){
        tree_height = std::max(tree_height, (1 + child->height()));
    }
    return tree_height;
}
