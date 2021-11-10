/* 
 * =====================================================================================
 *    Description:  Exercise 1
 *//
 *        Created:  12/08/1400 12:03
 *       Compiler:  gcc
 *         Author:  Alireza Tomari - alireza.tomari1043@gmail.com
 *   Organization:  SRTTU
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;
//--------------------------------//define type for most used types in code
using listType=vector<string>;
using size=int;
//--------------------------------//header of functions
void inputList(listType &listOfWords);
void printList(const listType &listOfWords);
//--------------------------------
int main()
{
    listType listOfWords;
    inputList(listOfWords);
    printList(listOfWords);
    return 0;
}
void inputList(listType &listOfWords)
{
    string word;
    while(cin>>word)// get word as long as you don't enter (ctrl+z)
    {
        listOfWords.push_back(word);
    }
}

bool comma(const int index , const size length)//return false if index is for last word std list -> [...,...,...]
{
    return ( index == length-1 ) ? false : true ;
}
void printList(const listType &listOfWords)
{
    size len=listOfWords.size();
    cout<<"[";
    for(size i=0;i<len;i++)
    {
        cout<<listOfWords[i];
        if(comma(i,len))
        {
            cout<<",";
        }
    }
    cout<<"]"<<endl;
}
