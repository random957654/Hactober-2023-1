#include<iostream>
#include<string>
using namespace std;

class trieNode{
public:
char data;
trieNode* children[26];
bool isTreminal;

trieNode(char ch){
    data= ch;
    for (int i=0;i<26;i++)
    {
        children[i]=NULL;
    }
    isTreminal=false;
    
}

};


class trie{

public:
trieNode* root;
trie(){
root = new trieNode('\0');
// cout<<root->data<<endl;
}
void insertutil(trieNode* root, string word){
    if(word.length()==0){
        root->isTreminal=true;

        return;
    }
    int index = word[0]-'A';
    trieNode* child;
    if(root->children[index]!=NULL){

child= root->children[index];


    }

    else{
child = new trieNode(word[0]);

root->children[index] = child;

    }
    insertutil(child, word.substr(1));
}

void insertword(string word){
    insertutil(root,word);
}

bool searchutil(trieNode* root, string word){
     if(word.length()==0){
       return root->isTreminal;
    }
     int index = word[0]-'A';
    trieNode* child;
    if(root->children[index]!=NULL){
child= root->children[index];
    }else{
        return false;}
   return  searchutil(child, word.substr(1));

}

bool searchword(string word){
  return  searchutil(root,word);
}


};


int main(){

    cout<<"asdsda0"<<endl;
    trie *t = new trie();
  
    cout<<"asdsda1"<<endl;
    t->insertword("TIME");
    cout<<"asdsda2"<<endl;
  cout<<"prest " <<  t->searchword("TIM");
//     cout<<"asdsda3"<<endl;
return 0;
}
