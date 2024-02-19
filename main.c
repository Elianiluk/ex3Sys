#include "StrList.h"
#include <stdio.h>

int main()
{
    //char* data=(char *)malloc(sizeof(char *));
    char *data1="lol";
    char *data2="ll";
    char *data3="olo";
    StrList *list=StrList_alloc();
    StrList_insertLast(list,data1);
    StrList_insertLast(list,data2);
    StrList_insertAt(list,data3,3);
    StrList *list2=StrList_alloc();
    StrList_insertLast(list2,data1);
    StrList_insertLast(list2,data1);
    StrList_insertAt(list2,data1,3);
    printf("%s\n",list->_head->word);
    printf("%s\n",list->_head->_next->word);
    printf("%s\n",list->_head->_next->_next->word);
    printf("%s\n",StrList_firstData(list));
    StrList_print(list);
    StrList_printAt(list,2);
    printf("numbers of chars: %d\n",StrList_printLen(list));
    printf("number of times lol is in the list is: %d\n",StrList_count(list,"lol"));
    if(StrList_isEqual(list,list2)==1)
        printf("The lists are equal\n");
    else
        printf("The lists arent equal\n"); 
    printf("%ld\n",list->size);   
    StrList *list3=StrList_clone(list);
    StrList_print(list3);
    StrList_reverse(list);
    StrList_print(list);
    //StrList_remove(list,"lol");
    //StrList_print(list);
    //StrList_removeAt(list,1);
    //StrList_print(list);
    /*char c;
    while ((c=getchar())!='0')
    {
        if(c=='1')
    }*/
    
    return 0;
}

/*git add .
  git commit -m "message"
  git push  */