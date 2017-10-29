/**
	Trie data structure
*/

#define MAXCHAR 26
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

struct node
{
	int prefix_count;
	bool isEnd;
	struct node *child[MAXCHAR];
}*head;

/**
	Build Trie 
*/
void init()
{
	head = new node();
	head->isEnd = false;
	head->prefix_count = 0;
}

/**
	insert word in trie
*/

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

/**
	Search word in trie
*/

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