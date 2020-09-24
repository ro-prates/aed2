#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node {
    int data{};
    node* left = nullptr;
    node* right = nullptr;
    node* parent = nullptr;
    string color;
};

 class RB_TREE {

    node* root;

    public:
        RB_TREE() : root(nullptr) {}

        node* GetRoot(){ return root; }

         void InsertNode(int stuff) {
           if(root == nullptr){
               root = new node();
               root->data = stuff;
               root->parent = nullptr;
               root->color = "N";
               
           }
           else {
               auto linker = GetRoot();
               node* newnode = new node();
               newnode->data = stuff;

               while(linker != nullptr){
                   if(linker->data > stuff){
                       if(linker->left == nullptr){
                           linker->left = newnode;
                           newnode->color = "R";
                           newnode->parent = linker;
                            break; }
                       else { linker = linker->left; }
                   } else {
                       if(linker->right == nullptr){
                           linker->right = newnode;
                           newnode->color = "R";
                           newnode->parent = linker;
                            break; }
                       else {  linker = linker->right; }
                   }
               }
            RB_Insert_Fixup(newnode);
           }
        }

        void RB_Insert_Fixup(node* z) {
            while(z->parent->color == "R") {
                auto grandparent = z->parent->parent;
                auto uncle = GetRoot();
                if(z->parent == grandparent->left) {
                    if(grandparent->right) { uncle = grandparent->right; }
                    if(uncle->color == "R"){
                        z->parent->color = "N";
                        uncle->color = "N";
                        grandparent->color = "R";
                        if(grandparent->data != root->data){ z = grandparent; }
                        else { break; }
                    }
                    else if(z == grandparent->left->right) {
                       LeftRotate(z->parent);
                    }
                    else {
                        z->parent->color = "N";
                        grandparent->color = "R";
                        RightRotate(grandparent);
                        if(grandparent->data != root->data){ z = grandparent; }
                        else { break; }
                    }
                }
                else {
                    if(grandparent->left) { uncle = grandparent->left; }
                    if(uncle->color == "R"){
                        z->parent->color = "N";
                        uncle->color = "N";
                        grandparent->color = "R";
                        if(grandparent->data != root->data){ z = grandparent; }
                        else { break; }
                    }
                    else if(z == grandparent->right->left){
                        RightRotate(z->parent);
                    }
                    else {
                        z->parent->color = "N";
                        grandparent->color = "R";
                        LeftRotate(grandparent);
                        if(grandparent->data != root->data){ z = grandparent; }
                        else { break; }
                    }
                }
            }
            root->color = "N";
        }


        void RemoveNode(node* parent, node* curr, int stuff) {
            if(curr == nullptr) { return; }
            if(curr->data == stuff) {
                //CASE -- 1
                if(curr->left == nullptr && curr->right == nullptr) {
                    if(parent->data == curr->data){ root = nullptr; }
                    else if(parent->right == curr) {
                        RB_Delete_Fixup(curr);
                        parent->right = nullptr;
                    } 
                    else { 
                        RB_Delete_Fixup(curr);
                        parent->left = nullptr;
                    }
                }
                //CASE -- 2
                else if(curr->left != nullptr && curr->right == nullptr) {
                    int swap = curr->data;
                    curr->data = curr->left->data;
                    curr->left->data = swap;
                    RemoveNode(curr, curr->right, stuff);
                }
                else if(curr->left == nullptr && curr->right != nullptr) {
                    int swap = curr->data;
                    curr->data = curr->right->data;
                    curr->right->data = swap;
                    RemoveNode(curr, curr->right, stuff);
                }
                //CASE -- 3
                else {
                    bool flag = false;
                    node* temp = curr->right;
                    while(temp->left) { flag = true; parent = temp; temp = temp->left; }
                    if(!flag) { parent = curr; }
                    int swap = curr->data;
                    curr->data = temp->data;
                    temp->data = swap;
                    RemoveNode(parent, temp, swap);
                }
            }
        }

        void Remove(int stuff) {
            auto temp = root;
            auto parent = temp;
            bool flag = false;
            if(!temp) { RemoveNode(nullptr, nullptr, stuff); }

            while(temp) {
                if(stuff == temp->data) { flag = true; RemoveNode(parent, temp, stuff); break; }
                else if(stuff < temp->data) { parent = temp ; temp = temp->left; }
                else { parent = temp ; temp = temp->right; }
            }

            if(!flag) { cout << "\nElement doesn't exist in the table"; }
        }

        void RB_Delete_Fixup(node* z) { 
            while(z->data != root->data && z->color == "N") {
                auto sibling = GetRoot();
                if(z->parent->left == z) {
                    if(z->parent->right){ sibling = z->parent->right; }
                    if(sibling) {
                        //CASE -- 1
                        if(sibling->color == "R") {
                            sibling->color = "N";
                            z->parent->color = "R";
                            LeftRotate(z->parent);
                            sibling = z->parent->right;
                        }
                         //CASE -- 2
                        if(sibling->left == nullptr && sibling->right == nullptr) {
                            sibling->color = "R";
                            z = z->parent;
                        }
                        else if(sibling->left->color == "N" && sibling->right->color == "N") {
                            sibling->color = "R";
                            z = z->parent;
                        }
                        //CASE -- 3
                        else if(sibling->right->color == "N") {
                            sibling->left->color = "N";
                            sibling->color = "R";
                            RightRotate(sibling);
                            sibling = z->parent->right;
                        } else {
                            sibling->color = z->parent->color;
                            z->parent->color = "N";
                            if(sibling->right){ sibling->right->color = "N"; }
                            LeftRotate(z->parent);
                            z = root;
                        }
                    } 
                } else {
                    if(z->parent->right == z){
                        if(z->parent->left){ sibling = z->parent->left; }
                        if(sibling) {
                            //CASE -- 1
                            if(sibling->color == "R"){
                                sibling->color = "N";
                                z->parent->color = "R";
                                RightRotate(z->parent);
                                sibling = z->parent->left;
                            }
                            //CASE -- 2
                             if(sibling->left == nullptr && sibling->right == nullptr) {
                                sibling->color = "R";
                                z = z->parent;
                            }
                            else if(sibling->left->color == "N" && sibling->right->color == "N") {
                                sibling->color = "R";
                                z = z->parent;
                            }
                            //CASE -- 3 
                            else if(sibling->left->color == "N") {
                                sibling->right->color = "N";
                                sibling->color = "R";
                                RightRotate(sibling);
                                sibling = z->parent->left;
                            } else {
                                sibling->color = z->parent->color;
                                z->parent->color = "N";
                                if(sibling->left){ sibling->left->color = "N"; }
                                LeftRotate(z->parent);
                                z = root;
                            }
                        } 
                    }

                }
            }
            z->color = "N";
        }

        node* TreeSearch(int stuff) {
            auto temp = GetRoot();
            if(temp == nullptr) { return nullptr; }

            while(temp) {
                if(stuff == temp->data){ return temp; }
                else if(stuff < temp->data){ temp = temp->left; }
                else { temp = temp->right; }
            }
            return nullptr;
        }

         void LeftRotate(node* x) {
            node* nw_node = new node();
            if(x->right->left) { nw_node->right = x->right->left; }
            nw_node->left = x->left;
            nw_node->data = x->data;
            nw_node->color = x->color;
            x->data = x->right->data;

            x->left = nw_node;
            if(nw_node->left){ nw_node->left->parent = nw_node; }
            if(nw_node->right){ nw_node->right->parent = nw_node; }
            nw_node->parent = x;

            if(x->right->right){ x->right = x->right->right; }
            else { x->right = nullptr; }

            if(x->right){ x->right->parent = x; }
        }

        void RightRotate(node* x) {
            node* nw_node = new node();
            if(x->left->right){ nw_node->left = x->left->right; }
            nw_node->right = x->right;
            nw_node->data = x->data;
            nw_node->color = x->color;

            x->data = x->left->data;
            x->color = x->left->color;

            x->right = nw_node;
            if(nw_node->left){ nw_node->left->parent = nw_node; }
            if(nw_node->right){ nw_node->right->parent = nw_node; }
            nw_node->parent = x;

            if(x->left->left){ x->left = x->left->left; }
            else { x->left = nullptr; }

            if(x->left){ x->left->parent = x; }
        }

        void PreorderTraversal(node* temp) {
            if(!temp){ return; }
            cout << "--> " << temp->color << "<" << temp->data << ">";
            PreorderTraversal(temp->left);
            PreorderTraversal(temp->right);
        }

        void PostorderTraversal(node *temp) {
            if(!temp){ return; }
            PostorderTraversal(temp->left);
            PostorderTraversal(temp->right);
            cout << "--> " << temp->color << "<" << temp->data << ">";
        }
 };

int altura_ArvAVL(node *temp){
    if(temp == NULL)
        return 0;
 
    int alt_esq = altura_ArvAVL((temp->left));
    int alt_dir = altura_ArvAVL((temp->right));
    if(alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return (alt_dir + 1);
}

void preOrdem_ArvAVL(node *temp){
    if(temp != NULL){
        cout << "(" << temp->color << temp->data;
        preOrdem_ArvAVL(temp->left);
        preOrdem_ArvAVL(temp->right);
        cout << ")";
    }else{
        cout << "()";
    }
}

 int main(){
    RB_TREE demo;
        int info, input, quantidade, i, altura, remover;

        cin >> quantidade;

        for(i=0; i<quantidade; i++){
            cin >> input; demo.InsertNode(input);
        }

        cin >> remover;

        altura = altura_ArvAVL(demo.GetRoot());

        if(altura > 1){
            altura = altura - 1;
        }

        cout << altura;
        cout << "\n";

        preOrdem_ArvAVL(demo.GetRoot());

        demo.Remove(remover);

        altura = altura_ArvAVL(demo.GetRoot());
        if(altura > 1){
            altura = altura - 1;
        }

        cout << "\n";

        cout << altura;
        cout << "\n";

        preOrdem_ArvAVL(demo.GetRoot());

    return 0;
 }