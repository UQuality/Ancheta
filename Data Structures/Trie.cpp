/**
	Trie data structure
*/
#include <bits/stdc++.h>
using namespace std;
#define MAXCHAR 26
#define CHAR_TO_INDEX(c) ((int) c - (int)'a')

struct Trie{
    struct node{
    	int prefix;
    	bool fin;
    	struct node *child[MAXCHAR];
    }*head;
    
    
    void init(){
    	head=new node();
    	head->prefix=0;
    	head->fin=false;
    }

    void insert(string a){
    	node *curr=head;
    	curr->prefix++;
        int i,letra;
    	for(i=0; i < a.size(); i++){
    		letra=CHAR_TO_INDEX(a[i]);
    		if(curr->child[letra]==NULL){
    			curr->child[letra]=new node();
    		}
    		curr->child[letra]->prefix++;
    		curr=curr->child[letra];
    	}
    	curr->fin=true;
    }

    int search(string a){
    	node *curr=head;
    	int i,letra;
    	for(i=0; i < a.size(); i++){
    		letra=CHAR_TO_INDEX(a[i]);
    		if(curr->child[letra]==NULL){
    			return -1;
    		}
    		curr=curr->child[letra];
    	}
     return curr->prefix;
    }
};
