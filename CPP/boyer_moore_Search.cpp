#include <iostream>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    string in = "lorem djsf sdjak cpin pisci fsvd vjdfdmv";
    string needle = "pisci";

    auto it = search(in.begin(),in.end(),std::boyer_moore_horspol_searcher(needle.begin(),needle.end()));

    if(it!=end(in))
        cout<,"The string "<<needle<<"found at offset "<<distance(in.begin(),it)<<endl;
    else
        cout<<"The string " <<needle<<"was not found"<<endl;

    return 0;

}
