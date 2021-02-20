#include <iostream>
 
using namespace std;

//TODO: Add all necessary functions and 
//Overload the '+' sign 
//To achieve the required total

class Shape 
{
    private:
      int length;     // Length of a box
      int width;
      
    public:
      // Constructor definition
      Shape(int l = 2, int w = 2) 
      {
         length = l;
         width = w;
      }
	  int GetWidth()
	  {
		  return width;
	  }
	  int GetLingth()
	  {
		  return length;
	  }
      double Area() 
      {
         return length * width;
      }
	  //operator overloading
	  int operator +(Shape sh)
	  {
		  return ( (width + sh.GetWidth() ) * (length + sh.GetLingth() ));
	  }
		
};
