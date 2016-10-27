#include "lab.h"

void init_table(table* Table){
  int i;
  //if the value in the key is -1, it means the position is free an can be use
  //so we initiate all the positions with a '-1'
  for(i = 0; i < M; i++){
    Table[i].key = -1;
  }
}

int hash_index(long long int key){
  //function that calculate the index based in the mod of key divide by M(who is a "cousin number")
  return key % M;
}

int hash_index2(long long int key){
  //function that calculate a second index based in one plus the mod of key divide by (M-2)(who is also a "cousin number")
  return 1+(key%(M-2));
}

int hash_insert(table* Table,long long int key, int value){
  int i = hash_index(key);
  int k = hash_index2(key);
  int count = 0;

  if(Table[i].key == key){
    Table[i].value = value;
    return 1;
  }

  while (Table[i].key != (long long int)-1) {
    if(Table[i].key == key){
      Table[i].value = value;
      return 1;
    }
    count++;
    if(count == 50000)
      return -2;
    i = (i+k)%M;
  }

  if(Table[i].key == key)
    Table[i].value = value;
  else{
    Table[i].key = key;
    Table[i].value = value;
  }
  return 1;
}

int hash_search(table* Table,long long int key){
  int i = hash_index(key);
  int k = hash_index2(key);
  int count = 0;

  while(Table[i].key != key){
    if(Table[i].key == -1)
      return -1;
    count++;
    if(count == 50000)
      return -2;
    i = (i+k)%M;
  }
  return i;
}

void hash_remove(table* Table,long long int key){

  int index = hash_search(Table,key);

  if(index >= 0){
    Table[index].key = -1;
    Table[index].value = 0;
  }
}
