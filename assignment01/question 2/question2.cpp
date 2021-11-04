
/*
 * =====================================================================================
 *    Description:  Exercise 2
 *
 *        Created:  13/08/1400 18:10
 *       Compiler:  gcc
 *         Author:  Alireza Tomari - alireza.tomari1043@gmail.com
 *   Organization:  SRTTU
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;
int main()
{
    int number;
    long long int ans;
    cin>>number;
    ans=(~((number<<9))+1)+((number<<2)+(number<<1));//    multiply number by -506
    cout<<ans;
    return 0;
}
