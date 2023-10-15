 #include<bits/stdc++.h>
  using namespace std;

  //Huffman tree node
  struct MinHeapNode{
      char data;
      int freq;

      MinHeapNode *left,*right;

      MinHeapNode(char data,int freq){
          left=right=NULL;
          this->data=data;
          this->freq=freq;
     }
};

//For comparison of two nodes.
struct compare{

    bool operator()(MinHeapNode *l,MinHeapNode *r)
    {
        return (l->freq>r->freq);
    }
};

//Print Huffman Codes
void printCodes(struct MinHeapNode* root,string str){
   //If root is Null then return.
   if(!root){
       return;
   }
   //If the node's data is not '$' that means it's not an internal node and print the string.
   if(root->data!='$'){
       cout<<root->data<<": "<<str<<endl;
   }

   printCodes(root->left,str+"0");
   printCodes(root->right,str+"1");
}

//Build Huffman Tree
void HuffmanCodes(char data[],int freq[],int size){

struct MinHeapNode *left,*right,*top;

//create a min heap.
priority_queue<MinHeapNode*,vector<MinHeapNode*>,compare> minheap;

// For each character create a leaf node and insert each leaf node in the heap.
for(int i=0;i<size;i++){
    minheap.push(new MinHeapNode(data[i],freq[i]));
 }

 //Iterate while size of min heap doesn't become 1
 while(minheap.size()!=1){
     //Extract two nodes from the heap.
     left = minheap.top();
     minheap.pop();

     right = minheap.top();
     minheap.pop();

     //Create a new internal node having frequency equal to the sum of 
     two extracted nodes.Assign '$' to this node and make the two extracted 
     node as left and right children of this new node.Add this node to the 
     heap.

     tmp = new MinHeapNode('$',left->freq+right->freq);
     tmp->left = left;
     tmp->right = right;

     minheap.push(tmp);
 }
 //Calling function to print the codes.
 printCodes(minheap.top()," ");
}

int main(){

  char arr[] = {'a','b','c','d','e'};
  int freq[] = {10,5,2,14,15};

  int size=5;
  HuffmanCodes(arr,freq,size);

return 0;
}
