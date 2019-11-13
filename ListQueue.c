/*
	Purpose: Enqueues at least 3 ints, traverses the queue and prints 
	out the contents of the nodes. Then dequeue each item separately 
	and print each element as it is dequeued. Finally, show the number 
	of elements that are in the queue at the different intervals.

*/

#include <stdio.h>
#include <stdlib.h>

typedef int Object;

typedef struct node{
    
    Object element;
    struct node *next;
    
} Node;

typedef struct queue{
    
    Node *head;
    Node *tail;
    int sz;
    
} Queue;

int size( Queue *Q ){
    
    return Q->sz;
    
}//end size


int isEmpty( Queue *Q ){
    
    if( Q->sz == 0 ) return 1;
    
    return 0;
    
}//end isEmpty

void enqueue( Queue *Q, Object elem ){
    
    Node *v = (Node*)malloc(sizeof(Node));
    
    if( !v ){
        printf("ERROR: Insufficient memory\n");
        return;
    }
    
    v->element = elem;
    v->next = NULL;
    
    if( isEmpty(Q) ) Q->head = v;
    else Q->tail->next = v;
    
    Q->tail = v;
    Q->sz++;
    
}//end enqueue

Object dequeue( Queue *Q ){
    
    Node *oldHead;
    
    Object temp;
    
    if( isEmpty(Q) ){
        printf("ERROR: Queue is empty\n");
        return 0;
    }
    
    oldHead = Q->head;
    temp = Q->head->element;
    
    Q->head = Q->head->next;
    free(oldHead);
    
    Q->sz--;
    
    return temp;
    
}//end dequeue

Object first( Queue *Q ){
    
    if( isEmpty(Q) ){
        printf("ERROR: Queue is empty\n");
        return 0;
    }
	
    return Q->head->element;
	
}//end first

void destroyQueue( Queue *Q ){
    
    while( !isEmpty(Q) ) dequeue(Q);
    
}//end destroyQueue

// Handles Char Datatype
void visitChar( Object elem ){
    
    printf("%c ",elem);
    
}//end visitChar

// Handles Int Datatype
void visitInt( Object elem ){
    
    printf("%d ",elem);
    
}//endvisitInt

void traverseQueue( Queue *Q, void (*visit)(Object elem) ){
    
    Node *current = Q->head;
    
    while( current ){
        
        visit(current->element);
        current = current->next;
        
    }
    
    printf("\n");
    
}//end traverseQueue

int main( int argc, char *argv[] ){
    
    
    Queue Q;
    Q.head = NULL;
    Q.tail = NULL;
    Q.sz = 0;
    
	// Prints Ints
    printf("Enqueueing three integers, 1 2 3\n");
    
    // Enqueues Ints
    enqueue(&Q,1);
    enqueue(&Q,2);
    enqueue(&Q,3);
    
    printf("Size = %d\n",size(&Q));
    printf("isEmpty = %d\n",isEmpty(&Q));
    
	printf("First = %d\n",first(&Q));
    printf("Traversing the queue: ");
    
    traverseQueue(&Q,visitInt);
    
	// Start to Dequeue Two Ints
    printf("Dequeueing two integers:\n");

    printf("%d",dequeue(&Q));

    printf("%d\n",dequeue(&Q));

    printf("Size = %d\n",size(&Q));

    printf("First = %d\n",first(&Q));

	// Dequeues One Int
    printf("Dequeueing one integer:\n");

    printf("%d\n",dequeue(&Q));

    printf("Size = %d\n",size(&Q));

	// Queue is empty
    printf("isEmpty = %d\n",isEmpty(&Q));

	//
    printf("Attempting to dequeue one integer:\n");
    
	// Dequeues
    dequeue(&Q);
	
    // Recovers memory to avoid memory leak
    destroyQueue(&Q);
    
}//end main
