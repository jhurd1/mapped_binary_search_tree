/***********************************************************************
 * Component:
 *    Assignment 10, Word Count
 *    Brother Kirby, CS235
 * Author:
 *    Daniel Perez, Jamie Hurd, Benjamin Dyas
 * Summary:
 *    Implementation of the map data structure and supporting classes
 ************************************************************************/

#ifndef MAP_H
#define MAP_H

#include "bst.h"
#include "pair.h"

namespace custom
{
   /************************************************
    * MAP
    * An associative container formed with a key
    * value and a data value
    ***********************************************/
   template <class K, class V> // key, value pair
   class map {
      public:
         // constructors and destructor
         map() {}
         map (const map<K,V> &rhs);
         ~map() { clear(); };

         //overloaded operators
         map & operator = (const map<K,V> &rhs); // assignment
         V & operator[] (const K &k);
         V   operator[] (const K &k) const;
         
         // standard MAP interfaces
         int  size() const { return bst.size(); }
         bool empty() const { return bst.empty(); }
         void clear() { bst.clear(); }
         
         // nested classes
         class iterator;
         
         // iterator interfaces
         iterator  begin()
         {
            iterator itBegin(bst.begin());
            return itBegin;
         }

         iterator  end()
         {
            iterator itEnd(bst.end());
            return itEnd;
         }

         iterator  find(const K & element)
         {
            //bst.find searched pairs so we firs create a pair
            custom::pair<K,V> searchPair;
            //only need to update first element
            searchPair.first = element;

            iterator itFind(bst.find(searchPair));
            return itFind;
         }
      
      private:
         BST< pair<K, V> > bst; // T will be a pair of k and v
         
   };

   /********************************************
    * FUNCTION:  COPY CONSTRUCTOR
    * RETURNS:   N/A
    * PARAMETER: N/A
    ********************************************/
   template <class K, class V>
   map<K,V>::map(const map<K,V> & rhs)
   {
      //leverage the assignment operator from bst
      this->bst = rhs.bst;
   }

   /********************************************
    * FUNCTION:  ASSIGNMENT OPERATOR OVERLOAD
    * RETURNS:   N/A
    * PARAMETER: N/A
    ********************************************/
   template <class K, class V>
   map<K,V> & map<K,V>::operator=(const map<K,V> & rhs)
   {
      //leverage the assignment operator from bst
      this->bst = rhs.bst;

      return *this;
   }

   /********************************************
    * FUNCTION:  OVERLOADED ACCESS OPERATOR
    * RETURNS:   template var of type V
    * PARAMETER: const template var of type K
    ********************************************/
   template <class K, class V>
   V & map<K,V>::operator[] (const K& k) //this IS the access operator
   {
      //search using bst.find which takes a pair
      custom::pair<K,V> searchPair;
      searchPair.first = k;
      typename BST<pair<K, V>>::iterator it;
      it = this->bst.find(searchPair);

      //it will be bst.end() if not found, in which
      //   case a new node should be created per
      //   requirement
      if (it == bst.end())
      {
         bst.insert(searchPair);

         //after it is inserted we need something to
         //   return. a reference to the newly created
         //   value is returned.
         typename BST<pair<K, V>>::iterator itSecond;
         itSecond = bst.find(searchPair);
         return (*itSecond).second;
      }
      else
      {
         //if it is found, send the value from it.
         return (*it).second;
      }
      
   }

   /********************************************
    * FUNCTION:  OVERLOADED ACCESS OPERATOR
    * RETURNS:   template var of type V
    * PARAMETER: const template var of type K
    ********************************************/
   template <class K, class V>
   V map<K,V>::operator[] (const K& k) const
   {
      //search using bst.find which takes a pair
      custom::pair<K,V> searchPair;
      searchPair.first = k;
      typename BST<pair<K, V>>::iterator it;
      it = this->bst.find(searchPair);

      //if found, return its value by copy
      if (it != bst.end())
      {
         return (*it).second;
      }
      else
      {  
         //else return nullptr
         return NULL;
      }
   }

   /********************************************
    * FUNCTION:  MAP ITERATOR CLASS
    * RETURNS:   template var of type V
    * PARAMETER: const template var of type K
    ********************************************/
   template <class K, class V>
   class map<K,V>::iterator
   {
      public:
      // constructors, destructors, and assignment operator
      iterator() : itBST(nullptr) {}
      iterator( typename custom::BST<pair<K,V>>::iterator rhs)
      {
         this->itBST = rhs;
      }
      iterator(const iterator & rhs) { *this = rhs; }

      //assignment operator
      iterator & operator = (const iterator & rhs)
      {
         //trivial thanks to the underlying BST
         this->itBST = rhs.itBST;
         return *this;
      }

      // equals, not equals operator
      bool operator != (const iterator & rhs) const { return rhs.itBST != this->itBST; }
      bool operator == (const iterator & rhs) const { return rhs.itBST == this->itBST; }

      // dereference operator
            pair<K,V> & operator * ()       { return *itBST; }
      const pair<K,V> & operator * () const { return *itBST; }

      // prefix increment a
      iterator   operator ++ ()            {return ++itBST;}
      // postfix increment
      iterator   operator ++ (int postfix)
      {
         //trivial thanks to the underlying BST
         typename custom::BST< pair<K,V> >::iterator tempIt;
         tempIt = itBST;

         itBST++;

         return tempIt;
      }

      // prefix decrement
      iterator  operator -- ()            { return --itBST; }
      // postfix decrement
      iterator   operator -- (int postfix)
      {
         //trivial thanks to the underlying BST
         typename custom::BST< pair<K,V> >::iterator tempIt;
         tempIt = itBST;

         itBST--;

         return tempIt;
      }

      private:
      typename custom::BST< pair<K,V> >::iterator itBST;

   };

} //end namespace custom
#endif // MAP_H