#include <bits/stdc++.h>
using namespace std;
#define MAXCHAR 26
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

bool entra;
struct node
{
	int prefix_count;
	bool isEnd;
	struct node *child[MAXCHAR];
}*head;

void init()
{
	head = new node();
	head->isEnd = false;
	head->prefix_count = 0;
}

void insert(string word)
{
	node *current = head;
	current->prefix_count++;
	
	for(int i = 0 ; i < word.length(); ++i)
	{
		int letter = CHAR_TO_INDEX(word[i]);
		if(current->child[letter] == NULL)
			current->child[letter] = new node();
		current->child[letter]->prefix_count++;
		current = current->child[letter];       
	}
	current->isEnd = true;	
}

bool search(string word)
{
	node *current = head;
	for(int i = 0 ; i < word.length(); ++i)
	{
		int letter = CHAR_TO_INDEX(word[i]);
		if(current->child[letter] == NULL)
			return false;		//no esta 
		current = current->child[letter];
	}
	return current->isEnd;
}

int words_with_prefix(string prefix)
{
	node *current = head;
	for(int i = 0; i < prefix.length() ; ++i)
	{
		int letter = (int)prefix[i] - (int)'a';
		if(current->child[letter] == NULL)
			return 0;
		else
			current = current->child[letter];
	}
	return current->prefix_count;
}

int main(){
  static char s[101];
  int nCasos;
  scanf("%d",&nCasos);
  while(nCasos!=0){
  	int n=nCasos;
     init();
  	for(int i=0; i < n; i++){
       scanf("%s",s);
       insert(s);
  	}
  	scanf("%s",s);
    puts(search(s) ? "existe":"No existe");
    printf("no of words with prefix abhi are %d\n",words_with_prefix(s));
     scanf("%d",&nCasos);
  }

	return 0;
}