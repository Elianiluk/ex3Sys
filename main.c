#include "StrList.h"
#include <stdio.h>

int main()
{
    /*char* data=(char *)malloc(sizeof(char *));
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
    StrList_insertAt(list2,"sol",3);
    printf("%s\n",list->_head->word);
    printf("%s\n",list->_head->_next->word);
    printf("%s\n",list->_head->_next->_next->word);
    printf("%s\n",StrList_firstData(list));
    StrList_print(list);
    StrList_print(list2);
    //printf("")
    StrList_printAt(list,2);
    printf("numbers of chars: %d\n",StrList_printLen(list));
    printf("number of times lol is in the list is: %d\n",StrList_count(list,"lol"));
    if(StrList_isEqual(list,list2)==1)
        printf("The lists are equal\n");
    else
        printf("The lists arent equal\n"); 
    printf("%ld\n",list->size); 
    printf("%ld\n",list2->size);     
    StrList *list3=StrList_clone(list);
    StrList_print(list3);
    StrList_reverse(list);
    StrList_print(list);
    StrList_free(list);
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
    
    StrList* list=NULL;
    int c;
    while(1)
    {
         scanf(" %d", &c);
        switch (c)
        {
        case 0:
            if(list!=NULL)
                StrList_free(list);
            return 0;    
        case 1:
            list=StrList_alloc();
            int n;
            scanf("%d",&n);
            int count=0;
            while(count<n)
            {
                char *data=(char *)malloc(sizeof(char)*100);
                //char *data;
                scanf("%s",data);
                StrList_insertLast(list,data);
                count++;
            }
            if(count>n){
                printf("too many words");
                return 0;
            }
            break;
        case 2:
            int index;
            scanf("%d",&index);
            char *data4=(char *)malloc(sizeof(char)*100);
            scanf("%s",data4);
            StrList_insertAt(list,data4,index);
            break;
        case 3:
            StrList_print(list);
            break;
        case 4:
            printf("%d\n",StrList_size(list));   
            break;
        case 5:
            int n1;
            scanf("%d",&n1);
            StrList_printAt(list,n1);
            break; 
        case 6:
            printf("%d\n",StrList_printLen(list));
            break;
        case 7:
            char *data1=(char *)malloc(sizeof(char)*100);
            scanf("%s",data1);  
            printf("%d\n",StrList_count(list,data1));  
            break;
        case 8:
            char *data2=(char *)malloc(sizeof(char)*100);
            scanf("%s",data2);  
            StrList_remove(list,data2);
            break;
        case 9:
            int index2;
            scanf("%d",&index2);
            StrList_removeAt(list,index2);   
            break;
        case 10:
            StrList_reverse(list);
            break;
        case 11:
            //StrList_removeAll(list);
            StrList_free(list);
            break;
        case 12:
            StrList_sort(list);
            break;
        case 13:
            if(StrList_isSorted(list)==1)
                printf("True\n");
            else    
                printf("False\n");  
            break;          
        default:
            printf("command not found\n");
            break;
        }
    }
    return 0;
}

/*git add .
  git commit -m "message"
  git push  */