// file:        arrayclass.cpp
// author:      Geoff T
// date:        2017-10-13
// description: implementation of a dynamic array class for CPSC 221 PA2

#ifdef _ARRAYCLASS_H_

// default constructor
// Creates an empty ArrayClass with DEFAULTCAPACITY
template <typename T>
ArrayClass<T>::ArrayClass()
{
  arr = new T [_capacity];
  
}

// parameterized constructor
// Creates an empty ArrayClass with capacity of n
template <typename T>
ArrayClass<T>::ArrayClass(unsigned int n)
{
  // The following is stub code only.
  // Please replace with your own implementation
}

// copy constructor
// Creates an ArrayClass as a deep copy of the parameter
template <typename T>
ArrayClass<T>::ArrayClass(const ArrayClass& ac)
{
  // The following is stub code only.
  // Please replace with your own implementation
}

// destructor
template <typename T>
ArrayClass<T>::~ArrayClass()
{
  // The following is stub code only.
  // Please replace with your own implementation
}

// overloaded assignment operator
template <typename T>
ArrayClass<T>& ArrayClass<T>::operator=(const ArrayClass& ac)
{
  // The following is stub code only.
  // Please replace with your own implementation
  return *this;
}

////////////////////////
// capacity functions //
////////////////////////

// Returns the number of elements stored in the array
template <typename T>
unsigned int ArrayClass<T>::size() const
{
  // The following is stub code only.
  // Please replace with your own implementation
  return 0;
}

// Returns the maximum capacity of the array
template <typename T>
unsigned int ArrayClass<T>::capacity() const
{
  // The following is stub code only.
  // Please replace with your own implementation
  return 0;
}

// Resizes the array
// If n is smaller than the size, then only the
//   first n elements are copied to the new array
template <typename T>
void ArrayClass<T>::resize(unsigned int n)
{
  // The following is stub code only.
  // Please replace with your own implementation
}

// Check if array is empty
// return true if array is empty
template <typename T>
bool ArrayClass<T>::empty() const
{
  // The following is stub code only.
  // Please replace with your own implementation
  return true;
}

// Resizes the array to fit exactly as many items
//   as are stored in the array
template <typename T>
void ArrayClass<T>::shrinkToFit()
{
  // The following is stub code only.
  // Please replace with your own implementation
}

//////////////////////////////
// element access functions //
//////////////////////////////

// Returns a reference to the element at position i
//   in the array.
// Throws an out_of_range exception if i is outside
//   the bounds of valid elements
template <typename T>
T& ArrayClass<T>::operator[](unsigned int i)
{
  // The following is stub code only.
  // Please replace with your own implementation
  T stub;
  return stub;
}

// Returns a reference to the element at position i
//   in the array.
// Throws an out_of_range exception if i is outside
//   the bounds of valid elements
template <typename T>
T& ArrayClass<T>::at(unsigned int i)
{
  // The following is stub code only.
  // Please replace with your own implementation
  T stub;
  return stub;
}

// Returns a reference to the first element in the array
// Calling this on an empty array throws out_of_range exception
template <typename T>
T& ArrayClass<T>::front()
{
  // The following is stub code only.
  // Please replace with your own implementation
  T stub;
  return stub;
}

// Returns a reference to the last element in the array
// Calling this on an empty array throws out_of_range exception
template <typename T>
T& ArrayClass<T>::back()
{
  // The following is stub code only.
  // Please replace with your own implementation
  T stub;
  return stub;
}

//////////////////////
// modify functions //
//////////////////////

// Add an element at the end
// If array is at capacity before adding, then
//   expand the array to double its capacity and
//   then add.
template <typename T>
void ArrayClass<T>::pushBack(const T& item)
{
  // The following is stub code only.
  // Please replace with your own implementation
}

// Removes the last stored element in the array,
//   reducing container size by 1.
// No effect if called on an empty container
template <typename T>
void ArrayClass<T>::popBack()
{
  // The following is stub code only.
  // Please replace with your own implementation
}

// Inserts an element before the element at specified position
// Expands the array if necessary
// Elements to the right of position (inclusive) must be shifted
// Throws out_of_range if position is > _size
// POST: item is at position, all elements formerly at position and beyond are shifted
template <typename T>
void ArrayClass<T>::insert(unsigned int position, const T& item)
{
  // The following is stub code only.
  // Please replace with your own implementation
}

// Removes an element from the array at specified position.
// Elements to the right of position will be shifted over to fill the gap
// Throws out_of_range if position is >= _size
template <typename T>
void ArrayClass<T>::erase(unsigned int position)
{
  // The following is stub code only.
  // Please replace with your own implementation
}

// Reallocates stored items into a new array of the same size,
//   starting from specified position
// No effect if position is 0 or >= _size
// e.g. startFrom(3) on {1, 2, 3, 4, 5, 6, 7}
//   produces {4, 5, 6, 7, 1, 2, 3}
template <typename T>
void ArrayClass<T>::startFrom(unsigned int position)
{
  // The following is stub code only.
  // Please replace with your own implementation
}

//////////////////////
// helper functions //
//////////////////////

// helper method for deep copy
template <typename T>
void ArrayClass<T>::copyArray(const ArrayClass& ac)
{
  // The following is stub code only.
  // Please replace with your own implementation
}

// helper method for expanding array
template <typename T>
void ArrayClass<T>::expandArray()
{
  // The following is stub code only.
  // Please replace with your own implementation
}

#endif