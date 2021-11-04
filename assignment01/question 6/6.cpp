
bool isPalindrome(string str)
{
    if( (str.size() <= 1) ) { return true; }
    if( (str[0] != str[str.size()-1]) ) { return false; }
    return isPalindrome(str.substr(1,str.size()-2));
}
