#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int val;
    struct node *next;
};

void printlist(struct node *head, struct node *end){
  struct node* p;
  p = head->next;
  while(p->next != NULL){
    printf("%d ",p->val);
    p = p->next;
  }
}

void printlist_reverse(struct node *head,struct node *end){
  struct node* p;
  p = end->prev;
  while(p->prev != NULL){
    printf("%d ",p->val);
    p = p->prev;
  }
}

int list_size(struct node *head, struct node *end){
  struct node* p;
  int s=0;
  p = head->next;
  while(p->next != NULL){
    p = p->next;
    s++;
  }
  return s;
}

void make_list(struct node *head, struct node *end){
    head -> prev = NULL;
    head -> next = end;

    end -> prev = head;
    end -> next = NULL;
}

void insert_list_bottom(struct node *head, struct node *end,int n){
  struct node *p;
  struct node *before_end;
  before_end = end->prev;
  p = (struct node*)malloc(sizeof(struct node));
  p->val = n;
  p->next = end;
  p->prev = before_end;

  end->prev = p;
  before_end->next = p;
}

void insert_list_top(struct node *head, struct node *end,int x){
  struct node *p;
  struct node *after_head;
  after_head = head->next;
  p = (struct node*)malloc(sizeof(struct node));
  p->val = x;
  p->next = after_head;
  p->prev = head;

  head->next = p;
  after_head->prev = p;
}



void insert_list_anyplace(struct node *head, struct node *end,int x,int n){
  struct node *p;
  struct node *now;
  now = head->next;
  
  for(int i = 0 ; i < n ; i++){
    now = now->next;
    if(now == NULL ){
      printf("ERROR ");
      return;
    }
  }
  if(now == head->next){
    insert_list_top(head,end,x);
    return;
  }
  if(now == end){
    insert_list_bottom(head,end,x);
    return;
  }
  p = (struct node*)malloc(sizeof(struct node));
  p->val = x;
  p->prev = now->prev;
  p->next = now;

  now->prev->next = p;
  now->prev = p;
}

int main(void){

    struct node *head;
    struct node *end;
    head = (struct node*)malloc(sizeof(struct node));
    end = (struct node*)malloc(sizeof(struct node));

    int x;

    make_list(head,end);

    insert_list_anyplace(head,end,2000,0);
    insert_list_bottom(head,end,10);    
    insert_list_bottom(head,end,28);
    insert_list_bottom(head,end,100);
    insert_list_top(head,end,40);
    
    insert_list_anyplace(head,end,200,0);

    insert_list_anyplace(head,end,400,1);
    insert_list_anyplace(head,end,800,7);
    printlist(head,end);
    printf("\n");
    printlist_reverse(head,end);
    printf("\n%d\n",list_size(head,end));
    
    return 0;
}
