#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX_LEN_STRING 255

typedef struct Node{
  char nama_kota[MAX_LEN_STRING];
  double lintang;
  double bujur;
  struct Node* next;
}Node;

int add(Node **head, double data_lintang, double data_bujur, char nama[]){
    Node *temp;
    temp = (Node*)malloc(sizeof(Node));

    temp->bujur = data_bujur;
    temp->lintang = data_lintang;
    strcpy(temp->nama_kota, nama);

    //cek head kosong?
    if(*head == NULL){
        temp->next = NULL;
        *head = temp;
    }
    else{
        temp->next = *head;
        *head = temp;
    }
    return(0);
}

void print(Node* hasil){
    Node* display;
    display = (Node*) malloc(sizeof(Node));
    display = hasil;
    while(display != NULL){
        printf("%s \t: %f\t|| %f\n", display->nama_kota, display->lintang, display->bujur);
        display = display->next;
    }
}

Node* input_file(){
    Node *Linked_list_kota = (Node*)malloc(sizeof(Node));
    Linked_list_kota = NULL;

    char file_name[MAX_LEN_STRING];
    printf("Masukkan File Map: ");
    scanf("%s", file_name);

    FILE* stream = fopen(file_name, "r");

    if (stream == NULL){
        printf("File tidak ditemukan");
        return NULL;
    }

    char line[MAX_LEN_STRING];
    char tempLine[MAX_LEN_STRING];
    char token_bujur[MAX_LEN_STRING];
    char token_lintang[MAX_LEN_STRING];
    char kota_temp[MAX_LEN_STRING];
    double lintang, bujur;

    //pisahkan koordinat dan masuukan ke struct food position
    while(fgets(line, MAX_LEN_STRING, stream)){
        strcpy(tempLine, line);
        strcpy(kota_temp, strtok(tempLine, ","));
        strcpy(token_lintang, strtok(NULL, ","));
        strcpy(token_bujur, strtok(NULL, "\n"));
        sscanf(token_bujur, "%lf", &bujur);
        sscanf(token_lintang, "%lf", &lintang);
        add(&Linked_list_kota, lintang, bujur, kota_temp);
    }

    return (Linked_list_kota);
} 

int main(){
    Node *daftar_kota = input_file();

    if(daftar_kota != NULL){
        print(daftar_kota);
    }
    else{printf("NO data\n");}
    return(0);

}