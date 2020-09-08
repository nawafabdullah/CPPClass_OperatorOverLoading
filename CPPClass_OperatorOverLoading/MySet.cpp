#include "MySet.h"

//default constructor
MySet::MySet()
{
  arr = nullptr;
  size = 0;
}

//constructor that takes an array and its size as an int
MySet::MySet(int _size, int _arr[])
{
  if (_arr) // if the array is not empty
    {
      size = _size;
      arr = new int[size];
      for (unsigned i = 0; i < size; i++)
	arr[i] = _arr[i];
      std::sort(arr, arr + size); //calling the built in "sort" function from algorithms
    }
}

// copy Constructor
MySet::MySet(const MySet& _obj)
{
  size = _obj.size; // size of the array
  arr = new int[size];
  for (unsigned i = 0; i < size; i++)
    arr[i] = _obj.arr[i];

  std::sort(arr, arr + size);// 

}

// overloading assignment Operator
MySet& MySet::operator = (const MySet& _obj)
{
  if (this->size > 0) // checking 
    delete[]arr; // previous memory

  this->size = _obj.size;
  this->arr = new int[size];
  for (unsigned i = 0;  i < size;  i++)
    this->arr[i] = _obj.arr[i];

  return *this;
}

// destructor
MySet::~MySet()
{
  size = 0; // initializing the size to zero
  delete[]arr;
  arr = nullptr;
}

// overloading the addition operator to union
MySet MySet::operator + (const MySet& _obj)
{
  MySet temp; // making a temperary variable

  temp.size = this->size + _obj.size;

  temp.arr = new int[temp.size];

  for (unsigned i = 0; i < this->size; i++) // initializing from first array
    temp.arr[i] = this->arr[i];

  for (unsigned i = this->size,j = 0; i < temp.size; i++,j++) // initializing from the second array in this loop i value start from the last index of the first array
    temp.arr[i] = _obj.arr[j];

  std::sort(temp.arr, temp.arr + temp.size); // sorting the array

  for (unsigned i = 0; i < temp.size-1;) 
    {
      if (temp.arr[i] == temp.arr[i + 1]) // checking if the next element is equal to the current
	{
	  for (unsigned j = i; j < temp.size - 1; j++) // copying data
	    temp.arr[j] = temp.arr[j + 1];
	  temp.size--;
	}
      else
	i++;
    }
  return temp;
}

// overloading comparison operator
bool MySet::operator == (const MySet& _obj)
{
  if (this->size == _obj.size) 
    return true; // return true if they are equal
  return false; // return false if they are not equal
}

// checking if the given number is already in the set
bool MySet::compare(int _num)
{
  for (unsigned i = 0; i < size;i++)
    if (arr[i] == _num) // checking if the number existed in the list
      return true;// return true if found

  return false;// return false if not found
}

//adding a number to the list
void MySet::add(int _num)
{
  if (!compare(_num))
    {
      int * temp = arr;

      arr = new int[size + 1];

      for (unsigned i = 0; i < size; i++)
	arr[i] = temp[i];
      arr[size] = _num;
      size++;
      delete[]temp;
      std::sort(arr, arr + size);
    }
}

// overloading the output operator
ostream& operator << (ostream& out, const MySet& _obj)
{
  for (unsigned i = 0; i < _obj.size; i++)
    {
      out << _obj.arr[i] << endl;
    }
  return out;
}

// overloading the input operator
istream& operator >> (istream& in, MySet& _obj)
{
  if (_obj.size > 0)
    delete[]_obj.arr;

  in >> _obj.size; // taking the number of elements
  _obj.arr = new int[_obj.size];
  for (unsigned i = 0; i < _obj.size; i++)//loop to initialize the array
    in >> _obj.arr[i]; // taking input
  std::sort(_obj.arr, _obj.arr + _obj.size); //
  return in;
}

// printing out the set
void MySet::print()
{
  for (unsigned i = 0; i < size; i++) // loop to print the array
    {
      cout << arr[i] << endl; // printing array elements
    }
}
