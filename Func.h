#ifndef LAB10_11_FUNC_H
#define LAB10_11_FUNC_H
#include <iostream>
using namespace std;

struct node{
    char key;
    node *left , *right;
};
typedef node *pNode;

pNode makeTree( char[] , int , int );
int priority( char );
int calcTree( pNode );
void printKLP( pNode );
void printPKL( pNode );
void printLPK( pNode );
void printLKP( pNode );
/*void addToTree( pNode& , int );
pNode search ( pNode , int );*/
#endif
