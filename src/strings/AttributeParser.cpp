#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

string cleanUp(string dirty){
    
    string cleanString = "";

    if(dirty.rfind("<",0) == 0){
        cleanString = dirty.substr(1);
    } else if(dirty.rfind("\"",0) == 0){
        cleanString = dirty.erase(0,1);
        cleanString = cleanString.erase(cleanString.find("\""));
    } else {
        cleanString = dirty;
    }
    return cleanString;

}

 map<string, string> processLine(string line){

    stringstream ss;
    ss.str(line);

    string temp;
    vector<string> attributes;
    while(ss >> temp){
        string value = cleanUp(temp);
        if(value!=""){
            attributes.push_back(value);
        }
    }
    string tag;
    map<string, string> keyPairs;
    for(int i=0;i<attributes.size();i++){
        if(attributes[i]=="=") keyPairs[attributes[i-1]] = attributes[i+1];
    }

    return keyPairs;

}

string extractTagName(string line){

    string tagName = "";
    int firstSpace = line.find_first_of(" ");
    int firstCloseTag = line.find_first_of(">");
    if(firstSpace>0) tagName=line.substr(1, firstSpace -1);
    else tagName=line.substr(1, firstCloseTag -1);
    return tagName;

}

int main() {
    int tags, queries; 
    string line;
    stringstream ss;

    getline(cin, line);
    ss.str(line);
    ss >> tags >> queries;
    
    map<string, map<string, string>> tagLines;
    string prefix = "";
    for(int i=0;i<tags;i++){
        string tagLine;
        getline(cin, tagLine);

        map<string, string> tagAttributes = processLine(tagLine);
        if(tagLine.rfind("</", 1)!=0 ){
            if(prefix!=""){
                prefix+=("."+extractTagName(tagLine));
            } else {
                prefix = extractTagName(tagLine);
            }
            
            tagLines[prefix] = tagAttributes;
        } else {
            int lastDotPosition = prefix.find_last_of(".");
            if(lastDotPosition<0) lastDotPosition = 0;
            prefix = prefix.erase(lastDotPosition);
        }
        
    }

    for(int i=0;i<queries;i++){
        string query;
        getline(cin, query);

        int tilPosition = query.find("~");
        string value = query.substr(tilPosition+1);
        string key = query.erase(tilPosition);

        string queryResult = tagLines[key][value];
        if(queryResult==""){
            cout << "Not Found!" << endl;
        } else {
            cout << queryResult << endl;
        }
    }

    return 0;
}

