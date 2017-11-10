// file:        arrayclass.cpp
// author:      Geoff T
// date:        2017-10-13
// description: implementation of a dynamic array class for CPSC 221 PA2

#ifdef _ARRAYCLASS_H_
using namespace std;
// default constructor
// Creates an empty ArrayClass with DEFAULTCAPACITY
template <typename T>
ArrayClass<T>::ArrayClass()
{
	_capacity=DEFAULTCAPACITY;
  arr = new T [_capacity];
  _size=0;
}

// parameterized constructor
// Creates an empty ArrayClass with capacity of n
template <typename T>
ArrayClass<T>::ArrayClass(unsigned int n)
{
	_capacity = n;
arr = new T [_capacity];
              _size = 0;
}

// copy constructor
// Creates an ArrayClass as a deep copy of the parameter
template <typename T>
ArrayClass<T>::ArrayClass(const ArrayClass& ac)
{
          copyArray(ac);
}

// destructor
template <typename T>
ArrayClass<T>::~ArrayClass()
{
delete [] arr;
}

// overloaded assignment operator
template <typename T>
ArrayClass<T>& ArrayClass<T>::operator=(const ArrayClass& ac)
{
	if(this!=&ac){
  		delete[] arr;
  		arr = NULL;
  		copyArray(ac);
  		return *this;
  	}
}

////////////////////////
// capacity functions //
////////////////////////

// Returns the number of elements stored in the array
template <typename T>
unsigned int ArrayClass<T>::size() const
{
  return _size;
}

// Returns the maximum capacity of the array
template <typename T>
unsigned int ArrayClass<T>::capacity() const
{
  return _capacity;
}

// Resizes the array
// If n is smaller than the size, then only the
//   first n elements are copied to the new array
template <typename T>
void ArrayClass<T>::resize(unsigned int n)
{
	//ArrayClass<T>* ac;

	T* ac = new T[n];
	if(n<_size&&n>=1){
		//ac = new ArrayClass<T>(n);
		//ac->_size = n;
		_capacity = n;
		_size = n;
		for(unsigned int i=0; i<n;i++){
			ac[i] = arr[i];
		}
	}else{
		//ac = new ArrayClass<T>(n);
		//ac->_size = _size;
		_capacity = n;
		for(unsigned int i=0; i<_size;i++){
			ac[i] = arr[i];
		}
	}
	arr = ac;
	ac = NULL;
}

// Check if array is empty
// return true if array is empty
template <typename T>
bool ArrayClass<T>::empty() const
{
  return (_size==0);
}

// Resizes the array to fit exactly as many items
//   as are stored in the array
template <typename T>
void ArrayClass<T>::shrinkToFit()
{
	resize(_size);
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
	//
 if( i>_size-1|| i<0||empty()){
 	throw std::out_of_range ("the index is out of range");
 }
  //T t;
 // t = arr[i];
 //T* stub = &arr[i];
  // return *stub;
 return arr[i];
}

// Returns a reference to the element at position i
//   in the array.
// Throws an out_of_range exception if i is outside
//   the bounds of valid elements
template <typename T>
T& ArrayClass<T>::at(unsigned int i)
{
 if(i>_size-1|| i<0||empty() ){
 	throw std::out_of_range ("the index is out of range");
 }
  //T stub;
  //stub = arr[i];
  return  arr[i];
}

// Returns a reference to the first element in the array
// Calling this on an empty array throws out_of_range exception
template <typename T>
T& ArrayClass<T>::front()
{
	if(_size<=0){
		throw std::out_of_range ("the array is empty");
	}
 // T stub;
 // stub = arr[0];
  return arr[0];
}

// Returns a reference to the last element in the array
// Calling this on an empty array throws out_of_range exception
template <typename T>
T& ArrayClass<T>::back()
{
	if(_size<=0){
		throw std::out_of_range ("the array is empty");
	}
  //T stub;
 // stub = arr[_size-1];
  return arr[_size-1];
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
 if(_size>=_capacity){
 	expandArray();
 }
 arr[_size] = item;
 _size++;
}

// Removes the last stored element in the array,
//   reducing container size by 1.
// No effect if called on an empty container
template <typename T>
void ArrayClass<T>::popBack()
{
	if(!empty()){
//	arr[_size-1]==NULL;
		_size--;
	}
}

// Inserts an element before the element at specified position
// Expands the array if necessary
// Elements to the right of position (inclusive) must be shifted
// Throws out_of_range if position is > _size
// POST: item is at position, all elements formerly at position and beyond are shifted
template <typename T>
void ArrayClass<T>::insert(unsigned int position, const T& item)
{
	if(position>_size){
		throw std::out_of_range ("the index is out of range");
	}
	if(_size==_capacity)expandArray();

           T* newArray = new T[_size + 1];
  for (int i=0; i<=_size; ++i)
  {
    if (i < position)
    {
       newArray[i] = arr[i];
    }
  
    if (i == position)
    {
      newArray[i] = item;
    }
 
    if (i > position)
    {
      newArray[i] = arr[i-1];
    }
  }
   arr= newArray;
   _size++;
   newArray =NULL;
}

// Removes an element from the array at specified position.
// Elements to the right of position will be shifted over to fill the gap
// Throws out_of_range if position is >= _size
template <typename T>
void ArrayClass<T>::erase(unsigned int position)
{
	if(position>=_size){
		throw std::out_of_range ("the index is out of range");
	}
	 if(position==_size-1) {
		popBack();
	}else{
		for(int i=position; i<_size; ++i){
			arr[i]=arr[i+1];
		}
		_size--;
	}

}

// Reallocates stored items into a new array of the same size,
//   starting from specified position
// No effect if position is 0 or >= _size
// e.g. startFrom(3) on {1, 2, 3, 4, 5, 6, 7}
//   produces {4, 5, 6, 7, 1, 2, 3}
template <typename T>
void ArrayClass<T>::startFrom(unsigned int position)
{
	if(position==0|| position>=_size) return;
	 T* newArray = new T[_size ];
	     int j =0;
    for(unsigned i =0;i<_size;++i){
    	//newArray[i] = arr[position];
    	if(position==_size){
    		
    		newArray[i]=arr[j];
    		j++;

    	}else{
    		newArray[i] = arr[position];
    		position++;
    	}
    }
    arr = newArray;
    newArray = NULL;
}

//////////////////////
// helper functions //
//////////////////////

// helper method for deep copy
template <typename T>
void ArrayClass<T>::copyArray(const ArrayClass& ac)
{
	arr= new T [ ac._capacity];
  for (int i = 0; i < ac.size(); ++i)
          {
          	arr [i] = ac.arr [i];
          }
          _size = ac._size;
          _capacity = ac._capacity;
}

// helper method for expanding array
template <typename T>
void ArrayClass<T>::expandArray()
{
	_capacity= _capacity*EXPANSIONFACTOR;
	T* newArray = new T[_capacity];
	for(int i=0; i<size();i++){
		newArray[i] = arr[i];
	}
	arr = newArray;
}

#endif
