#ifndef SORTEDCOLLECTION_H
#define SORTEDCOLLECTION_H

#include <vector>
#include <algorithm>
#include <stdexcept>

template <typename T>

class SortedCollection {

public:

    SortedCollection() = default;

    SortedCollection(size_t capacity) {

        this_collection.reserve(capacity);

    }
    SortedCollection (const SortedCollection& other) : this_collection(other.this_collection) {

    }

    SortedCollection& operator+( const T& value ) {

        this_collection.push_back(value);

        std::sort(this_collection.begin(), 
                    this_collection.end());
        return *this;

    }


    SortedCollection& operator-( const T& value) {

        auto its = std::find( this_collection.begin(), 
                            this_collection.end(), 
                            value);

        if (its != this_collection.end()) {


            this_collection.erase(its);


        } else {

            throw std::runtime_error("not found");
        }

        return *this;
    }

    SortedCollection& operator<<( const T& value ) {

        this_collection.push_back(value);

        std::sort(this_collection.begin(), 
                 this_collection.end());

        return *this;
        
    }


    T operator[](size_t index) const 
    {

        if (index >= this_collection.size()) {

            throw std::out_of_range("out of range");

        }

        return this_collection[ index ];

    }


    size_t size() 

    const {

        return this_collection.size();

    }

private:

    std::vector<T> this_collection;


};

#endif