#include<stdio.h>
#include<stdlib.h>

struct Node{
    int id;
    struct Node *next;
};

struct Node *create_track(int n, struct Node *head){
    struct Node *temp = NULL;
    struct Node *prev = NULL;

    for(int i=0; i<=n; i++){
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->id = i;
        temp->next = NULL;

        if(head == NULL){
            head = temp;
        }else{
            prev->next = temp;
        }
        prev = temp;
    }
    temp->next = head;
    return head;
}

int simulate_Race(int k, struct Node *head){
    struct Node *Dom = head;
    struct Node *Steph = head;
    int laps = 0;

    while(k > laps){
        Dom = Dom->next;
        Steph = Steph->next->next;

        if(Dom == Steph){
            printf("Dominic won the race!");
            return 0;
        }
        if(Steph->id == 0){
            laps++;
        }
    }
    printf("Stephano won the Race!");
}

int main(){
    int nodes;
    int dom_laps;

    printf("Enter the number of track segments:");
    scanf("%d", &nodes);

    printf("Enter the number of laps Dom has to finish:");
    scanf("%d", &dom_laps);

    struct Node *head = NULL;
    head = create_track(nodes, head);

    simulate_Race(dom_laps, head);

    return 0;
}