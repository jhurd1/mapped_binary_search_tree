/***********************************************************************
 * Module:
 *    Week 10, WORD COUNT
 *    Brother Kirby, CS 235
 * Author:
 *    Daniel Perez, Jamie Hurd, Benjamin Dyas
 * Summary:
 *    This program will implement the wordCount() function. It also 
 *    implements the readFile support function. 
 ************************************************************************/
#include <fstream>  
#include <iostream>  
#include "map.h"       // for MAP
#include "wordCount.h" // for wordCount() prototype
using namespace custom;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
void readFile(map <string, Count> & counts, const string & fileName);

/*****************************************************
 * WORD COUNT
 * Prompt the user for a file to read, then prompt the
 * user for words to get the count from
 *****************************************************/
void wordCount()
{
   //working variables/objects
   std::string fileName;
   map <string, Count> counts;

   //prompt for filename
   std::cout << "What is the filename to be counted? ";
   std::cin >> fileName;

   //read file into map object
   readFile(counts, fileName);
   
   //prompt for word to be searched
   cin.ignore();
   string search;
   cout << "What word whose frequency is to be found. Type ! when done\n";
   
   //output loop
   do
   {
      //per testBed requirement
      cout << "> ";

      //receive user input
      cin >> search;

      //if user is done, no need to even search
      if(search != "!")
      {
         //working iterator
         map<string, Count>::iterator it;
         //find the word requested
         it = counts.find(search);

         //if the word is found
         if (it != counts.end())
         {
            //output the word and the value related
            cout << "\t" << search << " : " << (*it).second.getCount() << endl;
         }
         else
         {
            //don't attempt to dereference null iterator if not found
            cout << "\t" << search << " : " << 0 << endl;
         }
      }
   } while (search != "!");
   

}

/*****************************************************
 * readFile
 * Prompt the user for a file to read, then prompt the
 * user for words to get the count from
 *****************************************************/
void readFile(map <string, Count> & counts, const string & fileName)
{
   //open file
   ifstream file;
   file.open(fileName.c_str());
   //file.open("/mnt/c/00cs235/bom.txt"); // for local testing
   //file.open("/mnt/c/00cs235/D_C_121.txt"); // for local testing

   if ( file.fail() )
   {
      cout << "Unable to read file\n";
      return;
   }

   //values to create pair
   string key;

   //While it can read from file AND is not the end of the file
   while (file >> key && !file.eof() )
   {
      Count tempIncrease;

      //workaround to not have to overload operator +=
      tempIncrease = counts[key];
      tempIncrease++;
      counts[key] = tempIncrease;

   }

   //always remember to close the file
   file.close();
}