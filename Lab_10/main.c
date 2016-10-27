#include "lab.h"

int main(int argc, char const *argv[]){

  //variables declaration, we initialize "entry" with an 'a' to make sure that we will get in the loop
  char entry;
  long long int key;
  int value;
  int ver;
  table *Table;
  Table = malloc(M * sizeof(table));

  init_table(Table);

  do{
    scanf("%c",&entry);

    if(entry =='i'){
        scanf("%lld%d",&key,&value);
        hash_insert(Table,key,value);
    }

    if(entry =='b'){
        scanf("%lld",&key);
        ver = hash_search(Table,key);
        if(ver == -1 || ver == -2)
          printf("%lld nao existe\n",key);
        else
          printf("valor para %lld: %d\n",Table[ver].key,Table[ver].value);
      }

    if(entry =='r'){
        scanf("%lld",&key);
        hash_remove(Table,key);
    }
  }while(entry !='f');

  if(Table)
    free(Table);

  return 0;

}
