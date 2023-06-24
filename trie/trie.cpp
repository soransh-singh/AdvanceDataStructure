#include<bits/stdc++.h>
#include<fstream>

using namespace std;

class TrieNode{
public:
    TrieNode *children[52];
    int freq;

    TrieNode(){
        freq=0;
        for (int i = 0; i < 52; i++)
        {
            children[i] = NULL;
        }
    }
};

class Trie{

private:
    TrieNode *root;
    int totalFreq;
    int maxHeight;

public:
    
    Trie(){
        root = new TrieNode();
        totalFreq=0;
        maxHeight=0;
    }

    void insert(string word){

        TrieNode *current = root;
        int n=word.length();
        for (char c : word){
            int index = (isupper(c))?c-'A':c - 'a'+26;
            if (current->children[index] == NULL){
                current->children[index] = new TrieNode();
            }

            current = current->children[index];
        }
        // maxHeight = max(maxHeight, n);
        maxHeight = maxHeight>n?maxHeight:n;
        totalFreq+=1;
        current->freq+=1;
    }

    bool search(string word){

        TrieNode *current = root;
        cout<<current;
        cout<<"[";
        for(auto node:current->children){
                cout<<node<<" ";
        }
        cout<<"] ";
        cout<<current->freq<<endl;

        for (char c : word){
            int index = (isupper(c))?c-'A':c-'a'+26;
            if (current->children[index] == NULL){
                return 0;
            }

            current = current->children[index];
            
            cout<<current<<"[";
            for(auto node:current->children){
                cout<<node<<" ";
            }
            cout<<"] ";
            cout<<current->freq<<endl;
            
        }

        return current->freq;
    }

    int total_Freq(){
        return totalFreq;
    }

    int height(){
        return maxHeight;
    }

};

int main(){
    Trie trie;

    string filename = "";
    cout<<"Enter the name of file to insert: ";
    cin>>filename;

    ifstream file(filename);

    if (!file){
        cout << "Failed to open file"<<endl;
        return 1;
    }

    string name;
    while (!file.eof()){
        getline(file, name);
        if(regex_match(name, std::regex("^[A-Za-z]+$"))){
            trie.insert(name);
        }
    }
    cout<<"Total number of names in file: "<<trie.total_Freq()<<endl;
    cout<<"Maximum height of trie tree is: "<<trie.height()<<endl;

    string input;
    cout<<"Enter a name you want to search in a file: ";
    cin>>input;
    int isFound = trie.search(input);
    cout<<((isFound> 0)?"":"Not ")<<"found the "<<input<<endl;
    cout<<"Frequency of "<<input<<" is: "<<isFound<<endl;

    return 0;
}
