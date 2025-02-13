#ifndef SORTEDCOLLECTION_H
#define SORTEDCOLLECTION_H

#include "Collection.h"
#include <algorithm>

template <typename T>
class SortedCollection : public Collection<T> {
public:

    SortedCollection() = default;

    SortedCollection(size_t capacity) : Collection<T>(capacity) {

    }

    SortedCollection(const SortedCollection& other) : Collection<T>(other) {

    }

    SortedCollection& operator+(const T& item) {

        add( item );

        return *this;

    }

    SortedCollection& operator<<( const T& item ) 
    {
        add( item );

        return *this;

    }

    void add(const T& item) {
        auto its = std::lower_bound( this -> items.begin(), 
                                     this -> items.end(), 
                                    item) ;

        this->items.insert(its, 
                           item);
    }

    SortedCollection& operator-(const T& item) {


        auto its = std::find(this -> items.begin(), 
                            this  -> items.end(), 
                            item);

        if (its != this->items.end()) {
            this->items.erase(its);
        }
        return *this;
    }
};

#endif