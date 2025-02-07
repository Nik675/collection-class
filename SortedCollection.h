#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

template<typename Item>
class Collection {

public:

  Collection();
  Collection(int size);
  Collection(Collection<Item>& a);
  
  virtual int size();
  virtual Item get(int ndx) const;
  virtual void add(Item e);
  virtual void removeEnd();
  
  friend ostream& operator<<(ostream& out, const Collection& c){

    for (int i = 0; i < c.curSize; ++i) {

      out << c.items[i] << " ";

    }

    return out;

  }

  Item& operator[](int index) {
    return items.at(index);
  }

  const Item& operator[](int index) const {

    return items.at(index);

  }

  void operator-(int index) {

    if (index >= 0 && index < curSize) {

      items.erase(items.begin() + index);

      curSize--;

    } else {

      throw out_of_range("this is out of range");

    }

  }

protected:
  int capacity;
  int curSize;
  static const int INITIAL_CAPACITY = 8;

  void expand();


  vector<Item> items;

};

template<typename Item>
Collection<Item>::Collection() : capacity(INITIAL_CAPACITY), curSize(0), items(vector<Item>(INITIAL_CAPACITY)) {

}

template<typename Item>
Collection<Item>::Collection(int size) : capacity(size), curSize(0), items(vector<Item>(size)) {

}

template<typename Item>
Collection<Item>::Collection(Collection<Item>& a) : capacity(a.capacity), curSize(a.curSize), items(a.items) {

}

template<typename Item>
int Collection<Item>::size() {

   return curSize;
   
}

template<typename Item>
Item Collection<Item>::get(int ndx) const {

  if (ndx >= 0 && ndx < curSize) {

    return items[ndx];

  }

  throw out_of_range("Index out of range");
  
}

template<typename Item>

void Collection<Item>::add(Item e) {

    if (curSize == capacity) {

      expand();

    }

    items[curSize++] = e;
}

template<typename Item>
void Collection<Item>::removeEnd() {

    if (curSize > 0) {
        curSize--;
    }

}

template<typename Item>
void Collection<Item>::expand() {

    capacity *= 2;
    items.resize(capacity);

}