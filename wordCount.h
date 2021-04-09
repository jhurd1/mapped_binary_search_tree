/***********************************************************************
* Header:
*    WORD COUNT
* Summary:
*    This will contain the prototype for the wordCount()
*    function and the definition for the Count class.
* Author
*    Daniel Perez, Jamie Hurd, Benjamin Dyas
************************************************************************/

#ifndef WORD_COUNT_H
#define WORD_COUNT_H

/*****************************************************
 * WORD COUNT
 * Prompt the user for a file to read, then prompt the
 * user for words to get the count from
 *****************************************************/
void wordCount();

/*****************************************************
 * COUNT CLASS
 * Allows for zero initialization to zero of an int
 *****************************************************/
class Count
{
   public:
   Count() : count{0} {}
   Count(int countL) { this->count = countL; }

   //value holder
   int count;

   // assignment operator
   Count & operator = (const Count & rhs)
   {
      //copy internal int values
      count  = rhs.count;

      return *this; 
   }

   // constant fetchers
   const int & getCount()  const { return count;  }
   
   // compare count
   bool operator >  (const Count & rhs) const { return count >  rhs.count; }
   bool operator >= (const Count & rhs) const { return count >= rhs.count; }
   bool operator <  (const Count & rhs) const { return count <  rhs.count; }
   bool operator <= (const Count & rhs) const { return count <= rhs.count; }
   bool operator == (const Count & rhs) const { return count == rhs.count; }
   bool operator != (const Count & rhs) const { return count != rhs.count; }

   // prefix increment a
   Count & operator ++ () { count++; return *this; }
   // postfix increment
   Count   operator ++ (int postfix)
   {
      Count tempObj(count);
      count++; 
      return tempObj;
   }
   // prefix decrement
   Count & operator -- () { count--; return *this; }
   // postfix decrement
   Count   operator -- (int postfix)
   {
      Count tempObj(count);
      count--; 
      return tempObj;
   }
};
#endif // WORD_COUNT_H

