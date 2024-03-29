#ifndef __my_array_hpp__
#define __my_array_hpp__

#include <cstddef>
#include <ostream>

class Array {
   public:
    Array() = delete;
    Array(size_t);
    Array(const Array& other);
    ~Array();
    int get_item(size_t);
    bool insert(int, size_t);
    bool remove(int, int);
    size_t find(int);
    size_t push(int);

    friend std::ostream& operator<<(std::ostream&, const Array&);
    friend Array intersect(const Array& arr1, const Array& arr2);
    friend Array merge(const Array&, const Array&, bool unique);

   private:
    bool _alloc(size_t);
    void _check_bounds(size_t);

   private:
    size_t _size;
    size_t _count;
    int* _buf;
};

#endif  // __my_array_hpp__
