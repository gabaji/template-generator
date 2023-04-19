#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};
vector<int> inOrder(Node* root){
    
    if(!root) return vector<int>();
    
    stack<Node*> st;
    vector<int> ans;
    // st.push(root);
    Node* cur = root;
    
    while(cur != NULL or !st.empty()){
        
        if(cur != NULL){
            st.push(cur);
            cur = cur->left;
        }
        else{
            cur = st.top();
            ans.push_back(cur->data);
            st.pop();
            cur = cur->right;
        }
        
        
    }
    return ans;
}
vector<int> postOrder(Node* root) {
    
   vector<int> ans;
   
   stack<Node*> st;
   st.push(root);
   while(!st.empty()){
       auto cur = st.top();
       st.pop();
       ans.push_back(cur->data);
       
       if(cur->left){
           st.push(cur->left);
       }
       if(cur->right){
           st.push(cur->right);
       }
   }
   reverse(ans.begin() , ans.end());
   return ans;
}
vector<int> preOrder(Node* root){
    vector<int> ans;
   
   stack<Node*> st;
   st.push(root);
   while(!st.empty()){
       auto cur = st.top();
       st.pop();
       ans.push_back(cur->data);
       if(cur->right){
           st.push(cur->right);
       }
       if(cur->left){
           st.push(cur->left);
       }
       
   }
//   reverse(ans.begin() , ans.end());
   return ans;
}
int main(){
	return 0;
}
