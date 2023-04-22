#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Trie
{
    int flag;
    struct Trie *children[26];
}Trie;

void insert(struct Trie **ppTrie, char *word);
int numberOfOccurances(struct Trie *pTrie, char *word);
struct Trie *deallocateTrie(struct Trie *pTrie);
int main(void)
{
    // read the number of the words in the dictionary
    //  parse line  by line, and insert each word to the trie data structure
    struct Trie *trie = NULL;
    char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
    for (int i = 0; i < 5; i++)
    {
        printf("\t%s : %d\n", pWords[i], numberOfOccurances(trie, pWords[i]));
    }
    trie = deallocateTrie(trie);
    if (trie != NULL)
        printf("There is an error in this program\n");
    return 0;
}
void insert(struct Trie **ppTrie, char *word)
{
    if (ppTrie == NULL)
    {
        return;
    }
    struct Trie *temp = *ppTrie;
    int length = strlen(word);
    for (int i = 0; i < length; i++)
    {
        int index = word[i] - 'a';
        if (temp->children[index] == NULL)
        {
            temp->children[index] = calloc(1, sizeof(Trie));
        }
        temp = temp->children[index];
    }
    temp->flag++;
}
int numberOfOccurances(struct Trie *pTrie, char *word)
{
    if (pTrie == NULL)
    {
        return 0;
    }
    struct Trie *pNode = pTrie;
    for (int i = 0; word[i] != '\0'; i++)
    {
        int index = word[i] - 'a';
        if (pNode->children[index] == NULL)
        {
            return 0;
        }
        pNode = pNode->children[index];
    }
    return pNode->flag;
}
struct Trie *deallocateTrie(struct Trie *pTrie)
{
    int i;
    for (i = 0; i < 26; i++)
    {
        if (pTrie->children[i] != NULL)
        {
            deallocateTrie(pTrie->children[i]);
        }
    }
    free(pTrie);
    return NULL;
}