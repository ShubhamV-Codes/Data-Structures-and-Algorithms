#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    unordered_map<string, string> Country;

    Country["India"] = "Most Populated Country in the World";
    Country["USA"] = "Most Rich Country in the World";
    Country["Russia"] = "Most Land Area Country in the World";
    Country["Japan"] = "Most Hardworking Country in the World";
    Country["UK"] = "Most Developed Country in the World {Colonization Effect}";
    Country["Germany"] = "Most Technological Country in the World {Cars}";

    cout << "Country Details: " << endl;
    
    for(pair<string, string>Countries:Country){
        cout<<Countries.first << "-> " << Countries.second <<"\n";
        cout<<endl;
    }
    
    if (Country.count("India"))
    {
        cout << "India Exists: " << Country["India"] << endl;
    }
    return 0;
}

// Steps to Run and Code-

// compile- g++ -std=c++11 unorderedMap.cpp -o x
// Execute- ./x