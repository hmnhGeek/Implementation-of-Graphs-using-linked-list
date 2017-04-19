// Program to implement graphs data structure. //
#include <stdio.h>
#include <stdlib.h>

// Make an edge data structure //
typedef struct edge_node
{
	int vertexIndex;
	struct edge_node *next;
}edge;

// Now define structure for vertex //
typedef struct vertex_node
{
	int data;
	struct edge_node *next;
}vertex;

/*
	Now define an array instance of vertex datatype containing, say, 10 elements.
*/

vertex graph[10];
int vertexCount = 0;

void insert(int item){
	/*
		The basic principle is that you just need to update the graph index at vertexCount
		with the item being passed and then increase vertexCount by 1 so that overriding of
		the index does not happen.
	*/
	graph[vertexCount].data = item;
	graph[vertexCount].next = NULL;
	vertexCount += 1;
} // End of insert() function. //

/*
	Now we need to define a function called connect() to connect two different nodes given the
	index of the nodes.
*/

void connect(int vertex1, int vertex2){
	/*
		To traverse the linked list which we are going to create, we need to initialise the temp 
		pointer of the type edge. So we conculde that "temp has TWO variables - 1.) vertexIndex and
		2.) next pointer."

		Also we create two other pointers edge1 and edge2 of same datatype edge. They too will be having 
		the same data members 1. vertexIndex and 2. next pointer. 
	*/
	edge *temp, *edge1, *edge2;
	edge *last_temp = NULL;

	// Assign temp the next pointer the address of vertex1 //
	temp = graph[vertex1].next;

	// Now create a new node and store it in edge1. Basically we are creating an edge. //
	edge1 = (edge *)malloc(sizeof(edge));
	// Assign edge1 the vertex2 since you are trying to connect vertex2 and its next as NULL. //
	edge1 -> vertexIndex = vertex2;
	edge1 -> next = NULL;

	/*
		Now traverse the linked list for vertex1 (which we are currently on) and stop only when
		temp reaches NULL.
	*/
	while(temp != NULL){
		last_temp = temp;
		temp = temp -> next;
	}

	if(temp == NULL && last_temp == NULL){
		// This means that while loop is not executed at all. //
		/*
			This means that temp was initially NULL, i.e. this is the very first connection
			being made for this node. So here just update graph's[vertex1].next as NULL.
		*/
		graph[vertex1].next = edge1;
	}
	else{
		/*
			The other case that can only be possible would be that while loop is executed, temp
			has become NULL and last_temp contains the last non-NULL value of temp. So basically,
			temp is NULL but last_temp is not NULL. So, do this, last_temp -> next (which is currently NULL),
			assign it edge2. Basically we did the same thing as above but this time linked list was not
			empty so we traversed till last and inserted edge2 at last.
		*/
		last_temp -> next = edge1;
	}

	// Now do the same but for vertex2 and edge1 this time. //

	last_temp = NULL;
	temp = graph[vertex2].next;

	edge2 = (edge *)malloc(sizeof(edge));
	edge2 -> vertexIndex = vertex1;
	edge2 -> next = NULL;

	while(temp != NULL){
		last_temp = temp;
		temp = temp -> next;
	}

	if(temp == NULL && last_temp == NULL){
		graph[vertex2].next = edge2;
	}
	else{
		last_temp -> next = edge2;
	}
} // End of connect() function. //

/*
	Now we have created insert() and connect() function, its time to display the graph. 
*/

void print(){
	/*
		The idea is very simple, just traverse each vertex and for each vertex print its data and
		its connections.
	*/
	edge *temp;

	for (int i = 0; i < vertexCount; i+=1)
	{
		// Assign temp the current graph's vertex's address. //
		temp = graph[i].next;
		// So currently we can traverse the linked list for this node. //
		printf("%d(%d)", i, graph[i].data);

		// Now iterate the linked list and print the connections. //
		while(temp != NULL){
			printf("-> %d", temp -> vertexIndex);
			temp = temp -> next;
		}
		// Give a line break for next node. //
		printf("\n");
	}
} // End of print() function. //

// Define the main() function. //

void main(){
	int ch = 1;

	while(ch){
		printf("Enter 1 to insert in the graph.\n");
		printf("Enter 2 to connect two nodes in the graph.\n");
		printf("Enter 3 to print the graph.\n");
		printf("Enter 4 to exit.\n");

		int choice;
		printf("Enter your choice: ");
		scanf("%d", &choice);

		if(choice == 1){
			int item;
			printf("Enter item: ");
			scanf("%d", &item);

			insert(item);
		}
		else if(choice == 2){
			int v1, v2;
			
			printf("Enter vertex1 index: ");
			scanf("%d", &v1);

			printf("Enter vertex2 index: ");
			scanf("%d", &v2);

			connect(v1, v2);
		}
		else if(choice == 3){
			print();
		}
		else{
			ch = 0;
		}
	}
} // End of main() function. //

