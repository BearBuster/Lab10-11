#include "Func.h"

pNode makeTree(char data[] , int first , int last){
    int minPrt, i, k , prt ;
    int nets = 0;
    pNode tree = new node;
    if(first == last){
        tree->key = data[first];
        tree->right = nullptr;
        tree->left = nullptr;
        return tree;
    }
    minPrt = 100;
    for(i = first ; i <= last ; i++){
        if(data[i] == '('){ nets++ ; continue; }
        if(data[i] == ')'){ nets-- ; continue; }
        if(nets > 0 ) continue ;
        prt = priority(data[i]);
        if(prt <= minPrt){
            minPrt = prt;
            k = i;
        }
    }
    if ( minPrt == 100 && data[first]== '(' && data[last]==')' ) {
        delete tree;
        return makeTree(data, first+1, last-1);
    }
    tree->key = data[k];
    tree->left = makeTree(data , first , k-1);
    tree->right = makeTree(data , k+1 , last);
    return tree;
}

int calcTree( pNode tree ){
    int num1 , num2;
    if(!tree->left)
        return tree->key - '0';
    num1 = calcTree(tree->left);
    num2= calcTree(tree->right);
    switch (tree->key){
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return num1 / num2;
    }
    return 32767;
}

int priority( char c ){
    switch(c){
        case '+':case '-':return 1;
        case '*':case '/':return 2;
    }
    return 100;
}

void printKLP( pNode tree ){
    if( !tree ) return;
    cout << tree->key << ' ';
    printKLP( tree->left );
    printKLP(tree->right);
}
//При правильном построение , выводит по убыванию
void printPKL( pNode tree ){
    if( !tree ) return;
    printPKL(tree->right);
    cout << tree->key << ' ';
    printPKL( tree->left );
}
//При правильном построение , выводит по возрастанию
void printLKP( pNode tree ){
    if( !tree ) return;
    printLKP( tree->left );
    cout << tree->key << ' ';
    printLKP(tree->right);
}

void printLPK( pNode tree ) {
    if (!tree) return;
    printLPK(tree->left);
    printLPK(tree->right);
    cout << tree->key << ' ';
}
/*void addToTree( pNode &tree , int data ){
    if(!tree){
        tree = new node;
        tree->right = nullptr;
        tree->left = nullptr;
        tree->key = data;
        return;
    }
    if( data < tree->key )
        addToTree(tree->left , data);
    else
        addToTree(tree->right , data);
}

pNode search (pNode tree, int what){
    if(!tree) return nullptr;
    if(what == tree->key) return tree;
    if(what < tree->key) return search(tree->left , what);
    else return search(tree->right , what);
}
*/