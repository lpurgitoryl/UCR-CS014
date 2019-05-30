#include "AVLTree.h"
//using psuedo code from zybooks week 6 
Node* AVLTree::search(Node* node, string & word){//used for testing
    Node* curr = node;

    while (curr){
        if(word == curr->data){
            return curr;
        }
        else if( word < curr->data){
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }

    return nullptr;
}

void AVLTree::updateHeight(Node* node){
    if(node == nullptr){
        return;
    }
    int leftH = -1;
    if(node->left != nullptr){
        leftH = node->left->hieght;
    }
    int rightH = -1;
    if(node->right != nullptr){
        rightH = node->right->hieght;
    }

    int max = 0;
    if(leftH >= rightH){
        max = leftH;
    }
    else{
        max = rightH;
    }

    node->hieght = max + 1;
}
int AVLTree::getBalance(Node* node){
    
    int leftH = -1;
    if(node->left != nullptr){
        leftH = node->left->hieght;
    }
    int rightH = -1;
    if(node->right != nullptr){
        rightH = node->right->hieght;
    }

    return leftH - rightH;
}
int AVLTree::balanceFactor(Node* node){
    return getBalance(node);
}
Node* AVLTree::findUnbalancedNode(Node* node ){
   Node* curr = node;
   while(curr != nullptr){
       int bF = getBalance(node);
       if( bF <= -2 || bF >= 2){
           return node;
       }
       curr = node->parent;
   }
    return nullptr;
}
void AVLTree::insert( const string & word){
    if(!root){
        Node* newNode = new Node(word);
        root = newNode;
       // updateHeight(root);
        return;
    }
    else{
        Node* curr = root;
        Node* copyCurr = nullptr;
        while (curr != nullptr){
            if(curr->data == word){
                curr->count += 1;
                curr = nullptr;
            }
            else if( word < curr->data ){
                if((curr->left) == nullptr){
                    curr->left = new Node(word);
                   // updateHeight(curr);
                    copyCurr = curr;
                    curr->left->parent = curr;
                    curr = nullptr;
                }
                else{
                    curr = curr->left;
                }
            }
            else{
                if((curr->right) == nullptr){
                   curr->right = new Node(word);
                  // updateHeight(curr);
                    copyCurr = curr;
                    curr->right->parent = curr;
                    curr = nullptr;
                }
                else{
                    curr = curr->right;
                }
            }

        }
        while(copyCurr != nullptr){
            updateHeight(copyCurr);
            copyCurr = copyCurr->parent;
        }
        updateHeight(root);

    }

}
void AVLTree::printTester(){
    printTester(root);
}
void AVLTree::printTester(Node * node){

     if(node){
         cout << node->data << " " << node->hieght;
         printTester(node->left);
         printTester(node->right);
     }
    
   // cout << node ->data << " " << node->key << node->right->data << endl;
}