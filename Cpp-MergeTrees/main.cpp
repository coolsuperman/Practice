#include<iostream>
using namespace std

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x),left(NULL), right(NULL) {}
};
class Solution {
  public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
              if(!t1){return t2;}
                      else if(!t2){return t1;}
              else{
                            fun(t1,t2,t1,start);
                                        return t1;
                                                
              }
                  
    }
  private:
        enum LR{start,left,right};
        void fun(TreeNode* t1, TreeNode* t2,TreeNode* pre,LR lr){
          if(t1==NULL&&t2==NULL){
                        return ;
                                
          }
          else if(t1==NULL){
            if(lr==left){
                              pre->left = t2;
                                          
            }
            else if(lr==right){
                              pre->right = t2;
                                          
            }
                        return;
                                
          }
          else if(t2==NULL){
            if(lr==left){
                              pre->left = t1;
                                          
            }
            else if(lr==right){
                              pre->right = t1;
                                          
            }
                       return;
                               
          }
          else{
                        t1->val = t1->val+t2->val;
                                
          }
                  fun(t1->left,t2->left,t1,left);
                          fun(t1->right,t2->right,t1,right);
                              
        }
            

};
