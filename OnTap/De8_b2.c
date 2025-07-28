
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Request {
    int id;
    char issue[100];
    int priority;
}Rq;
typedef struct Queue {
    Rq* request;
    int front;
    int rear;
    int cap;
}Queue;
Queue* createQueue( int cap){
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->cap = cap;
    newQueue->front = 0;
    newQueue->rear= -1;
    newQueue->request = (Rq*)malloc(sizeof(Rq)*cap);

};
int isEmpty(Queue* queue) {
   return queue->rear == -1;
}
void enqueue(Queue* queue, Rq rq) {
if (queue->rear == queue->cap -1 ) {
    printf("Hang doi full\n");
    return ;
}
    queue->rear++;
    queue->request[queue->rear] = rq;

}
void displayQueue(Queue* queue,Queue* low) {
    if (queue->rear == -1) {
        printf("ko co uu cau cao");
    }else {
        for (int i =0;i<queue->rear;i++) {
            printf("%s",queue->request[i].issue);
        }
    }
    if (low->rear== -1) {
        printf("ko co yeu cau thap\n");
    }else {
        for (int i =0;i<low->rear;i++) {
            printf("%s",low->request[i].issue);
        }
    }


}
void dequeue(Queue* queue) {
    queue->front++;
}
int main() {
int choice;
Queue* high = createQueue(100);
Queue* low = createQueue(100);

    do {
        printf("1. REQUEST\n");
        printf("2. HANDEL REQUEST\n");
        printf("3. TOP REQUEST\n");
        printf("4. HIEN THI\n");
        printf("5. Thoat\n");
        printf("Moi ba nhap lua chon cua ban : ");
        scanf("%d",&choice);
        getchar();
        switch (choice) {
            case 1:
                int id,priority;
                char issue[100];
                printf("Moi ban nhap id\n ");
                scanf("%d",&id);
                getchar();
                printf("Moi ban nhap nhu cau \n");
                fgets(issue,100,stdin);
                issue[strcspn(issue,"\n")]='\0';
                printf("Moi ban nhap muc do uu tien \n");
                scanf("%d",&priority);
                getchar();
                Rq newRq;
                newRq.id=id;
                newRq.priority=priority;
                strcpy(issue,newRq.issue);
                if (newRq.priority==1) {
                    enqueue(high,newRq);
                }else if (newRq.priority==2) {
                    enqueue(low,newRq);
                }else {
                    printf("Nhap sai do uu tien \n");

                }


                break;
            case 2:
                if (!isEmpty(high)) {
                    dequeue(high);

                }else {
                    if (!isEmpty(low)) {
                        dequeue(low);
                    }

                }
                break;

        }
    }while (choice!= 5);
}