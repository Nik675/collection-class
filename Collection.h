#ifndef COLLECTION_H
#define COLLECTION_H

#include <vector>

template <typename T>
class Collection {
public:
    Collection() = default;

    Collection(size_t capacity) {
        items.reserve(capacity);
    }

    Collection(const Collection& other) : items(other.items) {}

    void add(const T& item) {
        items.push_back(item);
    }

    size_t size() const {
        return items.size();
    }

    const T& operator[](size_t index) const {
        if (index >= items.size()) {
            throw std::out_of_range("Index out of range");
        }
        return items[index];
    }

protected:
    std::vector<T> items;
};

#endif // COLLECTION_H