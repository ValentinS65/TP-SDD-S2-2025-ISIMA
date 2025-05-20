#include <stdio.h>
#include <stdlib.h>
#include "avl.h"


int max(int a, int b) {
	if (a>b) {
		return a;
	}
	else {
		return b;
	}
}

struct avl * avlCreateNode(int key) {
    struct avl * new=(struct avl*)malloc(sizeof(struct avl));
    new->key=key;
    new->left=NULL;
    new->right=NULL;
    return new;
}

int avlHeight(struct avl * root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + max(avlHeight(root->left), avlHeight(root->right));
}


int avlGetBalance(struct avl * root) {
    if(root!=NULL){
        return avlHeight(root->left)-avlHeight(root->right);
    }
    else{
        return 0;
    }
}

struct avl * avlRotateRight(struct avl * x) {
    if(x->left==NULL){return x;}

    struct avl * tmp=x->left;
    x->left=x->left->right;

    tmp->right=x;
    return tmp;
}

struct avl * avlRotateLeft(struct avl * x) {
    if(x->right==NULL){return x;}
    struct avl * tmp=x->right;
        
    x->right=x->right->left;

    tmp->left=x;
    return tmp;
}

struct avl * avlRotateLeftRight(struct avl * x) {
    if(x->left==NULL){return x;}

    x->left=avlRotateLeft(x->left);
    return avlRotateRight(x);
}

struct avl * avlRotateRightLeft(struct avl * x) {
    if(x->right==NULL){return x;}

    x->right=avlRotateRight(x->right);
    return avlRotateLeft(x);
}


struct avl * balanceAVL(struct avl * root){
    int balance=avlGetBalance(root);
    //Cas où l'arbre est équilibré
    if(abs(balance) == 1 || balance==0){
        return root;
    }
    else{
        // cas ou le désiquilibre viens du fils droit
        if(balance<-1){
            if(avlGetBalance(root->right)>0){
                root=avlRotateRightLeft(root);

            }
            else{
                root=avlRotateLeft(root);
            }
        }
        //cas désiquilibre fils gauche
        else{
            if(avlGetBalance(root->left)<0){
                root=avlRotateLeftRight(root);

            }
            else{
                root=avlRotateRight(root);
            }

        }
        return root;

    }



}
struct avl * avlInsert(struct avl * root, int key) {
    if (root == NULL) {
        return avlCreateNode(key);  // Create a new node when root is NULL
    }
    
    // Insert in the right subtree if key is greater
    if (key > root->key) {
        root->right = avlInsert(root->right, key);
    } 
    // Insert in the left subtree if key is smaller or equal
    else {
        root->left = avlInsert(root->left, key);
    }
    
    return balanceAVL(root);
}

struct avl * avlMinValue(struct avl * root) {
    if(root->left==NULL){
        return root;
    }else{
        return avlMinValue(root->left);
    }}

struct avl * avlDelete(struct avl * root, int key) {
    if(root!=NULL){
        // Cas 1 : Pas d'enfant
            if (root->left == NULL && root->right == NULL) {
                free(root);
                return NULL;
            }
            // Cas 2 : Un seul enfant
            if (root->left == NULL) {
                struct avl * temp = root->right;
                free(root);
                return temp;
            } else if (root->right == NULL) {
                struct avl * temp = root->left;
                free(root);
                return temp;
            }

            // Cas 3 : Deux enfants, on récupère le minimum du sous-arbre droit
            struct avl * min = avlMinValue(root->right);

            // On copie la valeur et les pointeurs du minimum dans root
            root->key = min->key;

            // On appelle la suppression sur le sous-arbre droit pour supprimer le minimum
            root->right = avlDelete(root->right, min->key);
        } 
        else if (key > root->key) {
            root->right = avlDelete(root->right, key);
        } 
        else {
            root->left = avlDelete(root->left, key);
        }
    
    return balanceAVL(root);
}

void avlFree(struct avl * root) {
     if(root!=NULL){
        avlFree(root->left);
        avlFree(root->right);
        free(root);
    }
}

void avlDisplay(struct avl * root) {
     if(root!=NULL){
        printf("%d ",root->key);
        printf("[");
        if(root->left!=NULL){
            avlDisplay(root->left);
        }
        printf("] ");
        printf("[");
        if(root->right!=NULL){
            avlDisplay(root->right);
        }
        printf("] ");
        
    }
}


