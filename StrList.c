#include <stdio.h>
#include "StrList.h"

int stringLength(const char *str);
int compareStrings(const char *str1, const char *str2);
/*
 * StrList represents a StrList data structure.
 */
struct _StrList;
typedef struct _StrList StrList;

/*
 * Allocates a new empty StrList.
 * It's the user responsibility to free it with StrList_free.
 */
StrList* StrList_alloc()
{
    StrList *list=(StrList*)malloc(sizeof(StrList));
    if(list==NULL)
    {
        printf("couldnt allocate memory");
        exit(1);
    }
    list->size=0;
    list->_head=NULL;
    return list;
}

/*
 * Frees the memory and resources allocated to StrList.
 * If StrList==NULL does nothing (same as free).
 */
void StrList_free(StrList* StrList)
{
    if(StrList==NULL)
        return;
    Node *head=StrList->_head;
    Node *h;
    while (head!=NULL)
    {
        h=head;
        head=head->_next;
        free(head);
    }
    free(StrList);
}

/*
 * Returns the number of elements in the StrList.
 */
size_t StrList_size(const StrList* StrList)
{
    return StrList->size;
}

/*
 * Inserts an element in the end of the StrList.
 */
void StrList_insertLast(StrList* StrList,const char* data)
{
    //char* d=(char*)malloc(sizeof(data));
    Node* temp=(Node*)malloc(sizeof(Node));
    if(data==NULL || temp==NULL)
    {
        printf("couldnt allocate memory");
        exit(1);
    }
    temp->word=data;
    temp->_next=NULL;
    
    if (StrList->_head==NULL)
    {
        StrList->_head=temp;
        StrList->size++;
        return;
    }
    Node* last=StrList->_head;
    while (last->_next!=NULL)
    {
        last=last->_next;
    }
    
    last->_next=temp;
    StrList->size++;
    //free(temp);
}

/*
* Inserts an element at given index
*/
void StrList_insertAt(StrList* StrList,const char* data,int index)
{
    if(index>(StrList->size)+1)
        printf("you cant add in this index");
    if (StrList->_head==NULL)
    {
        return;
    }
    int count=1;
    Node* nodeIndex=StrList->_head;
    while (count!=index-1)
    {
        nodeIndex=nodeIndex->_next;
        count++;
    }
    Node* temp=(Node*)malloc(sizeof(Node));
    if(data==NULL || temp==NULL)
    {
        printf("couldnt allocate memory");
        exit(1);
    }
    temp->word=data;
    temp->_next=NULL;
    Node *nodenext=nodeIndex->_next;
    nodeIndex->_next=temp;
    temp->_next=nodenext;
    StrList->size++;
}

/*
 * Returns the StrList first data.
 */
char* StrList_firstData(const StrList* StrList)
{
    return StrList->_head->word;
}

/*
 * Prints the StrList to the standard output.
 */
void StrList_print(const StrList* StrList)
{
    Node *temp=StrList->_head;
    while(temp!=NULL)
    {
        printf("%s,",temp->word);
        temp=temp->_next;
    }
    printf("\n");
}

/*
 Prints the word at the given index to the standard output.
*/
void StrList_printAt(const StrList* Strlist,int index)
{
    Node *temp=Strlist->_head;
    int count=1;
    while (count!=index)
    {
        temp=temp->_next;
        count+=1;
    }
    printf("%s\n",temp->word);
}

/*
 * Return the amount of chars in the list.
*/
int StrList_printLen(const StrList* Strlist)
{
    Node *temp=Strlist->_head;
    int count=0;
    while(temp!=NULL)
    {
        count+=stringLength(temp->word);
        temp=temp->_next;
    }
    return count;
}

int stringLength(const char *str) {
    int length = 0;
    // Iterate over the string until the null terminator is encountered
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

/*
Given a string, return the number of times it exists in the list.
*/
int StrList_count(StrList* StrList, const char* data)
{
    int count=0;
    Node *temp=StrList->_head;
    while (temp!=NULL)
    {
        if(compareStrings(data,temp->word)==1)
            count+=1;
        temp=temp->_next;    
    }
    return count;
}

int compareStrings(const char *str1, const char *str2) {
    // Iterate over both strings simultaneously until either a difference is found or both strings end
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            // If characters at the same position are different, strings are not the same
            return 0;
        }
        str1++;
        str2++;
    }
    // If both strings have ended at the same position, they are the same
    return (*str1 == '\0' && *str2 == '\0');
}

/*
	Given a string and a list, remove all the appearences of this string in the list.
*/
void StrList_remove(StrList* StrList, const char* data)
{
    /*Node *temp=StrList->_head;
    if(compareStrings(data,temp->word)==1)
        temp->_next=NULL;
    Node *next=StrList->_head->_next; 
    while(next!=NULL)
    {
        if(compareStrings(next->word,data)==1)
            {
                temp->_next=next->_next;
                Node *temp1=next;
                next=next->_next;
                temp1=NULL;
            }
        temp=temp->_next;
    }*/

    Node* current = StrList->_head;
    Node* prev = NULL;

    // Traverse the list
    while (current != NULL) {
        // Check if the current node's data matches the given value
        if (compareStrings(data,current->word)) {
            // If it matches, remove the node
            if (prev == NULL) {
                StrList->_head = current->_next; // Update the head if the first node is to be removed
            } else {
                prev->_next = current->_next; // Update the previous node's next pointer
            }
            free(current); // Free the memory allocated for the node
            current = prev == NULL ? StrList->_head : prev->_next; // Move to the next node
        } else {
            // If it doesn't match, move to the next node
            prev = current;
            current = current->_next;
        }
    }
}

/*
	Given an index and a list, remove the string at that index.
*/
void StrList_removeAt(StrList* StrList, int index)
{
    Node* current = StrList->_head;
    Node* prev = NULL;
    int count=1;
    while(count!=index)
    {
        count++;
        prev = current;
        current = current->_next; 
    }  
    if (prev == NULL) {
                StrList->_head = current->_next; // Update the head if the first node is to be removed
            } else {
                prev->_next = current->_next; // Update the previous node's next pointer
            }
}

/*
 * Checks if two StrLists have the same elements
 * returns 0 if not and any other number if yes
 */
int StrList_isEqual(const StrList* StrList1, const StrList* StrList2)
{
    if(StrList1->size!=StrList2->size)
        return 0;
    Node* p1 = StrList1->_head;
    Node* p2 = StrList2->_head;  
    while(p1==NULL)
    {
        if(compareStrings(p1->word,p2->word)==0)
            return 0;
        p1=p1->_next;
        p2=p2->_next;    
    } 
    return 1;
}

/*
 * Clones the given StrList. 
 * It's the user responsibility to free it with StrList_free.
 */
StrList* StrList_clone(const StrList* Strlist)
{
    StrList *list=StrList_alloc();
    Node* p = Strlist->_head; 
    while(p!=NULL)
    {
        StrList_insertLast(list,p->word);
        p=p->_next;
    }
    return list;
}

/*
 * Reverces the given StrList. 
 */
void StrList_reverse( StrList* Strlist)
{
    Node* prev = NULL;
    Node* current = Strlist->_head;
    Node* nextNode = NULL;

    // Traverse the list, changing the direction of pointers
    while (current != NULL) {
        nextNode = current->_next; // Store the next node
        current->_next = prev; // Reverse the link
        prev = current; // Move pointers forward
        current = nextNode;
    }
    Strlist->_head=prev;
}

/*
 * Sort the given list in lexicographical order 
 */
void StrList_sort( StrList* StrList);

/*
 * Checks if the given list is sorted in lexicographical order
 * returns 1 for sorted,   0 otherwise
 */
int StrList_isSorted(StrList* StrList);