#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <arpa/inet.h>

struct node{
	
	unsigned int ip;
	unsigned int mask;
	bool isGoal;
	bool entry;
	struct node *leaf[1];
};

typedef struct node *treeNode;

treeNode *head = NULL;


unsigned int createPath(treeNode currentNode,treeNode insertNode, unsigned int numBits);
unsigned int getNodeBit(treeNode node, unsigned int bitPosition);
unsigned int getNumBits(unsigned int num, unsigned numBitsPositions);

int insertPrefix(treeNode node){
	//int maxMask=31;
	int i=1;
	treeNode currentNode = *head;
	if(node == NULL){
		return 1;
	}
	node->mask;
	while(i <= node->mask){
		
	if(createPath(currentNode,node,i) == 0){
		
			currentNode = currentNode->leaf[0];
	}
	else{
			currentNode = currentNode->leaf[1];
	}


	i++;
	}
		
}

unsigned int createPath(treeNode currentNode,treeNode insertNode, unsigned int numBits){
	treeNode temp;
	
	if(getNodeBit(insertNode,numBits)==0){
	temp = currentNode->leaf[0];
	
		if(temp == NULL){
			treeNode node = malloc(sizeof(struct node));
			node->ip = getNumBits(insertNode->ip,numBits);
		
			node->mask = numBits;
			node->leaf[0] = NULL;
			node->leaf[1] = NULL;
			currentNode->leaf[0] = node;
			
			return 0;
		}
		
		return 0;
		
	}
	else if (getNodeBit(insertNode,numBits)==1){
	temp = currentNode->leaf[1];
	
		if(temp == NULL){
			treeNode node = malloc(sizeof(struct node));
			node->ip = getNumBits(insertNode->ip,numBits);
		
			node->mask =  numBits;
			node->leaf[0] = NULL;
			node->leaf[1] = NULL;
			currentNode->leaf[1] = node;
			
			return 1;
		}
	
		return 1;
	

			
	}
	


}

unsigned int getNumBits(unsigned int num, unsigned numBitsPositions){
	
	if(numBitsPositions == 1){ return  (num & 0x80000000); }
	if(numBitsPositions == 2){ return  (num & 0xC0000000); }
	if(numBitsPositions == 3){ return  (num & 0xE0000000); }
	if(numBitsPositions == 4){ return  (num & 0xF0000000); }
	if(numBitsPositions == 5){ return  (num & 0xF0000000); }
	if(numBitsPositions == 6){ return  (num & 0xF8000000); }
	if(numBitsPositions == 7){ return  (num &  0xFC000000); }
	if(numBitsPositions == 8){ return  (num &  0xFE000000); }
	if(numBitsPositions == 9){ return  (num &  0xFF000000); }
	if(numBitsPositions == 10){ return  (num & 0xFF800000); }
	if(numBitsPositions == 11){ return  (num & 0xFFC00000); }
	if(numBitsPositions == 12){ return  (num & 0xFFE00000); }
	if(numBitsPositions == 13){ return  (num & 0xFFF00000); }
	if(numBitsPositions == 14){ return  (num & 0xFFF80000); }
	if(numBitsPositions == 15){ return  (num & 0xFFFC0000); }
	if(numBitsPositions == 16){ return  (num & 0xFFFE0000); }
	if(numBitsPositions == 16){ return  (num & 0xFFFF0000); }
	if(numBitsPositions == 17){ return  (num & 0xFFFF8000); }
	if(numBitsPositions == 18){ return  (num & 0xFFFFC000); }
	if(numBitsPositions == 19){ return  (num & 0xFFFFE000); }
	if(numBitsPositions == 20){ return  (num & 0xFFFFF000); }
	if(numBitsPositions == 21){ return  (num & 0xFFFFF800); }
	if(numBitsPositions == 22){ return  (num & 0xFFFFFC00); }
	if(numBitsPositions == 23){ return  (num & 0xFFFFFE00); }
	if(numBitsPositions == 24){ return  (num & 0xFFFFFF00); }
	if(numBitsPositions == 25){ return  (num & 0xFFFFFF80); }
	if(numBitsPositions == 26){ return  (num & 0xFFFFFFC0); }
	if(numBitsPositions == 27){ return  (num & 0xFFFFFFE0); }
	if(numBitsPositions == 28){ return  (num & 0xFFFFFFF0); }
	if(numBitsPositions == 29){ return  (num & 0xFFFFFFF8); }
	if(numBitsPositions == 30){ return  (num & 0xFFFFFFFC); }
	if(numBitsPositions == 31){ return  (num & 0xFFFFFFFE); }
	if(numBitsPositions == 32){ return  (num & 0xFFFFFFFF); }
	
	//result = (num >> numBitsPositions) & ((1 << numBitsPositions) - 1);
		
		
}

unsigned int getNodeBit(treeNode node, unsigned int bitPosition){
	
	int position = (32 - bitPosition);
	return ((node->ip >> position) & 1);
	
	
}
void printTrie(treeNode node){
	treeNode temp = node;
	
	if(temp == NULL){
		
		return;
		
	}
	
	printf("%u.",(node->ip  >> 24) & 0x000000FF);
	printf("%u.",(node->ip  >> 16) & 0x000000FF);
	printf("%u.",(node->ip  >> 8) & 0x000000FF);
	printf("%u", node->ip  & 0x000000FF);
	printf("/%u \n",node->mask); 
			
	printTrie(temp->leaf[0]);
	printTrie(temp->leaf[1]);
		
}




int main(){
	head = malloc(sizeof(treeNode));
	treeNode head_node = malloc(sizeof(struct node));
	head_node->ip = 0;
	head_node->mask = 0;
	head_node->leaf[0] = NULL;
	head_node->leaf[1] = NULL;
	*head = head_node;
	
	treeNode node1 = malloc(sizeof(struct node));
	node1->ip = 3232238080; // 192.168.0.0
	node1->mask = 24;
	node1->leaf[0] = NULL;
	node1->leaf[1] = NULL;
	node1->entry = true;
	
	treeNode node2 = malloc(sizeof(struct node));
	node2->ip = 167772160; //10.0.0.0
	node2->mask = 8;
	node2->leaf[0] = NULL;
	node2->leaf[1] = NULL;
	node2->entry = true;
	
	treeNode node3 = malloc(sizeof(struct node));
	node3->ip = 2886729728; //172.16.0.0
	node3->mask = 16;
	node3->leaf[0] = NULL;
	node3->leaf[1] = NULL;
	node3->entry = true;

	insertPrefix(node1);
	insertPrefix(node3);
	insertPrefix(node1);

	printTrie(*head);

	//printf("Test of GetNumBits = %u\n",getNumBits(node1->ip,2));
	//printf("Test of GetNodeBit = %u\n",getNodeBit(node1,3));
	
	
	
	
}