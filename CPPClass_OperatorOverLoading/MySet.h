#include <iostream> // calling library to use cin,cout
#include <algorithm> // caling library to use the sort function

using namespace std;

class MySet
{
 public:
  MySet(); // default Constructor
  MySet(int,int[]);// Constructor with an array and number of elements in array
  MySet(const MySet&); // Copy Constructor
  ~MySet();// default Destructor
  MySet& operator = (const MySet&); // overloading assignment Operator
  MySet operator + (const MySet&); // overloading addition Operator
  bool operator == (const MySet&); // overloading equality Operator
  bool compare(int); // Function Used To Compare Whether a Number 
  void add(int); // insert a number to the list if it does not exisit 
  void print(); // print function to print the array
  friend ostream& operator << (ostream& , const MySet&); // Output operator 
  friend istream& operator >> (istream&, MySet&); // Input operator 

 private:
  int* nullptr; //declaring a pointer to int
  int* arr; // pointer to an integer array
  unsigned size; // number of elements in the array 
};
