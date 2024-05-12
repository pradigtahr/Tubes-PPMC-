#ifndef STRUCT_H
#define STRUCT_H

#define MAX_LEN_STRING 255

typedef struct Node{
  char nama_kota[MAX_LEN_STRING];
  double lintang;
  double bujur;
  struct Node* next;
}Node;

#endif
