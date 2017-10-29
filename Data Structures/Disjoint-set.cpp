/**
* Union-Find Disjoint set data structure
*/

typedef vector<int> vi;

class DisjointSet
{

private :
	/** Parent, rank and set size auxiliary arrays for the structure*/
    vi parent,ran,sizeSet;
    /** Number of disjoint sets into the structure */
    int sets;


public :
    DisjointSet(int n){
    	/** Every element is disjoint set, with rank 0 and is its own parent */
        sets = n;
        ran.assign(n,0);
        sizeSet.assign(n,1);
        parent.resize(n);
        for(int i = 0; i<n; i++) parent[i] = i;
    }

    /** Find set of a given element */
    int findSet(int i) { return (parent[i] == i) ? i : (parent[i] = findSet(parent[i])); }

    /** Return if two elements are in the same set */
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    /** Make the union of two sets */
    void unionSet(int i, int j){

        if(!isSameSet(i,j)){
            int x = findSet(i), y = findSet(j);

            if(ran[x]>ran[y]) { parent[y] = x , sizeSet[x]+=sizeSet[y]; }

            else{
                parent[x] = y , sizeSet[y]+=sizeSet[x];
                if(ran[x] == ran[y]) ran[y]++;
            }

            sets--;
        }

    }

    /** Return the number of disjoint sets into the structure */
    int numSets(){ return sets; }

    /** Return the cardinality of the set who has a given element */
    int sizeOfSet(int i){ return sizeSet[findSet(i)]; }

};