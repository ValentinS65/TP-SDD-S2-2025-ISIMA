#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

struct bst * bstCreateNode(int key) {
    struct bst * new=(struct bst*)malloc(sizeof(struct bst));
    new->key=key;
    new->left=NULL;
    new->right=NULL;
    return new;
}

void bstInorderTraversal(struct bst * root) {
    if(root!=NULL){
    bstInorderTraversal(root->left);
   
    printf("(%d)\n",root->key);
    bstInorderTraversal(root->right);
    }
}


struct bst * bstInsert(struct bst * root, int key) {
    if (root == NULL) {
        return bstCreateNode(key);  // Create a new node when root is NULL
    }
    
    // Insert in the right subtree if key is greater
    if (key > root->key) {
        root->right = bstInsert(root->right, key);
    } 
    // Insert in the left subtree if key is smaller or equal
    else {
        root->left = bstInsert(root->left, key);
    }
    
    return root;  // Return the (potentially new) root
}
struct bst *bstMinValue(struct bst *root) {
    if(root->left==NULL){
        return root;
    }else{
        return bstMinValue(root->left);
    }
}

struct bst * bstDelete(struct bst * root, int key) {
    if (root != NULL) {
        if (key == root->key) {
            if (root->left == NULL && root->right == NULL) {
                free(root);
                return NULL;
            }
            if (root->left == NULL) {
                struct bst * temp = root->right;
                free(root);
                return temp;
            } else if (root->right == NULL) {
                struct bst * temp = root->left;
                free(root);
                return temp;
            }

            // Cas 3 : deux enfants
            struct bst * min = bstMinValue(root->right);
            root->key = min->key;
            root->right = bstDelete(root->right, min->key);  // Supprimer le minimum
        } 
        else if (key > root->key) {
            root->right = bstDelete(root->right, key);
        } 
        else {
            root->left = bstDelete(root->left, key);
        }
    }
    return root;
}

void bstFree(struct bst * root) { 
    if(root!=NULL){
        bstFree(root->left);
        bstFree(root->right);
        free(root);
    }

}

void bstDisplay(struct bst * root) {
    if(root!=NULL){
        printf("%d ",root->key);
        printf("[");
        if(root->left!=NULL){
            bstDisplay(root->left);
        }
        printf("] ");
        printf("[");
        if(root->right!=NULL){
            bstDisplay(root->right);
        }
        printf("] ");
        
    }
}

