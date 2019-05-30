#include "arithmeticExpression.h"


arithmeticExpression::arithmeticExpression(const string & sentence){
    root = new TreeNode('a', 'a');
    infixExpression = sentence;
}

bool arithmeticExpression::isOperator(char val ){
    if( val == '*' || val == '+' || val == '/' || val == '-' ){
        return true;
    }

    return false;
}

void arithmeticExpression::buildTree(){
    stack<TreeNode* > tree;
    string Expression = infix_to_postfix();

    delete root;
    char counterKey = 'a';

    for( unsigned int i = 0; i < Expression.size() ; ++i){
        if( isOperator( Expression.at(i) ) ){
            TreeNode* newNode = new TreeNode( Expression.at(i) , counterKey);
            counterKey++;

            newNode->right = tree.top();
            tree.pop();
            newNode->left = tree.top();
            tree.pop();

            tree.push(newNode);
            
        }

        else{
            TreeNode* newNode = new TreeNode( Expression.at(i), counterKey);
            counterKey++;

            tree.push(newNode);
        }
       
    }
  

    root = tree.top();
    
}

void arithmeticExpression::infix(){
    infix(root);
}
void arithmeticExpression::prefix(){
    prefix(root);
}
void arithmeticExpression::postfix(){
    postfix(root);
}
void arithmeticExpression::infix(TreeNode * node){

     if( node->left  && node->right ){
        cout << "(";

        infix(node->left);
        cout << node->data;
        
        infix( node->right);
        cout << ")";
       
    }

    else {
        cout << node->data;
    }
    
   // cout << node ->data << " " << node->key << node->right->data << endl;
}
void arithmeticExpression::prefix(TreeNode * node){
    if( node){
        cout << node->data;
        prefix(node->left);
        prefix( node->right);
    }
}
void arithmeticExpression::postfix(TreeNode * node){
    if( node){
        postfix(node->left);
        postfix( node->right);
        cout << node->data;
    }
}

int arithmeticExpression::priority(char op){
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream oss;
    char c;

    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}
void  arithmeticExpression::visualizeTree(ofstream & OS, TreeNode * node){
   if (node) {
         OS << node->key << " [ label=\"" << node->data << "\"];" << endl;
        visualizeTree(OS, node->left);
        visualizeTree(OS, node->right);
        if(node->right) {
            OS << node->key << " -> " << node->right->key << ";" << endl;
        }
        if(node->left) {
            OS << node->key << " -> " << node->left->key << ";" << endl;
        }
    }
}

void arithmeticExpression::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}