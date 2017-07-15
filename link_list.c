#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

print(struct node *head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
}

void insertion_b(struct node *insert,struct node *previous,struct node *after){
    previous->next=insert;
    insert->data=25;
    insert->next=after;
}

void insertion_first(struct node *insert2,struct node** head){
    insert2->data=10;
    insert2->next=(*head);
    (*head)=insert2;
}

void insertion_last(int new_data,struct node* tail){
    struct node* insert=(struct node*)malloc(sizeof(struct node));

    insert->data=new_data;
    insert->next=NULL;
    tail->next=insert;
}

int main(){
    struct node* head=NULL;
    struct node* second=NULL;
    struct node* third=NULL;
    struct node* tail=NULL;
    struct node* insert=NULL;
    struct node* insert2=NULL;

    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    tail=(struct node*)malloc(sizeof(struct node));
    insert=(struct node*)malloc(sizeof(struct node));
    insert2=(struct node*)malloc(sizeof(struct node));

    head->data=11;
    head->next=second;

    second->data=22;
    second->next=third;

    third->data=33;
    third->next=tail;

    tail->data=44;
    tail->next=NULL;

    insertion_first(insert2,&head);
    insertion_b(insert,second,third);
    insertion_last(50,tail);
    print(head);
}
