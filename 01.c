#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <omp.h>

typedef struct Node_s {
	struct Node_s *next;
	char *str;
} Node_s, *Node;

Node new_node(Node prev, Node next, char *str) {
	Node node = (Node)malloc(sizeof(Node_s));
	if(prev != NULL) {
		prev->next = node;
	}

	node->next = next;

	node->str = (char *)malloc(sizeof(char)*strlen(str) + 1);
	strcpy(node->str, str);

	return node;
}

void destroy_list(Node head) {
	Node temp;

	while(head->next != NULL) {
		temp = head->next;
		free(head->str);
		free(head);
		head = temp;
	}
}

void *sleepy_storyteller(char *original_story) {
    size_t buffsize = strlen(original_story);

    char *buffer = (char *)malloc(sizeof(char)*buffsize + 1);
    strcpy(buffer, original_story);

	Node token_list_head, token_list_current;

    char *token = strtok(buffer, " ");
	token_list_head = new_node(NULL, NULL, token);
	token_list_current = token_list_head;
    while(token != NULL){
        //printf("%s\n", token);
        token_list_current = new_node(token_list_current, NULL, token);
		token = strtok(NULL, " ");

        //sleep(1);
    }

    free(buffer);
	
	#pragma omp parallel
	for(token_list_current = token_list_head; token_list_current != NULL; token_list_current = token_list_current = token_list_current->next) {
		printf("%s\n", token_list_current->str);
	}

	destroy_list(token_list_head);

    return NULL;
}

int main(int arg, char *argv) {

    // "The Destruction of Sennacherib", by Lord Byron
    char story[] = "The Assyrian came down like the wolf on the fold, And his cohorts were gleaming in purple and gold; And the sheen of their spears was like stars on the sea, When the blue wave rolls nightly on deep Galilee. Like the leaves of the forest when Summer is green, That host with their banners at sunset were seen: Like the leaves of the forest when Autumn hath blown, That host on the morrow lay withered and strown. For the Angel of Death spread his wings on the blast, And breathed in the face of the foe as he passed; And the eyes of the sleepers waxed deadly and chill, And their hearts but once heaved, and for ever grew still! And there lay the steed with his nostril all wide, But through it there rolled not the breath of his pride; And the foam of his gasping lay white on the turf, And cold as the spray of the rock-beating surf. And there lay the rider distorted and pale, With the dew on his brow, and the rust on his mail: And the tents were all silent, the banners alone, The lances unlifted, the trumpet unblown. And the widows of Ashur are loud in their wail, And the idols are broke in the temple of Baal; And the might of the Gentile, unsmote by the sword, Hath melted like snow in the glance of the Lord!";

    sleepy_storyteller(story);

    return 0;
}
