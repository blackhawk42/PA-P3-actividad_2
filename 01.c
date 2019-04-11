#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void *sleepy_storyteller(char *original_story) {
    size_t buffsize = strlen(original_story);

    char *buffer = (char *)malloc(sizeof(char)*buffsize + 1);
    strcpy(buffer, original_story);

    char *token = strtok(buffer, " ");
    while(token != NULL){
        printf("%s\n", token);
        token = strtok(NULL, " ");

        sleep(1);
    }

    free(buffer);
    return NULL;
}

int main(int arg, char *argv) {

    // "The Destruction of Sennacherib", by Lord Byron
    char story[] = "The Assyrian came down like the wolf on the fold, And his cohorts were gleaming in purple and gold; And the sheen of their spears was like stars on the sea, When the blue wave rolls nightly on deep Galilee. Like the leaves of the forest when Summer is green, That host with their banners at sunset were seen: Like the leaves of the forest when Autumn hath blown, That host on the morrow lay withered and strown. For the Angel of Death spread his wings on the blast, And breathed in the face of the foe as he passed; And the eyes of the sleepers waxed deadly and chill, And their hearts but once heaved, and for ever grew still! And there lay the steed with his nostril all wide, But through it there rolled not the breath of his pride; And the foam of his gasping lay white on the turf, And cold as the spray of the rock-beating surf. And there lay the rider distorted and pale, With the dew on his brow, and the rust on his mail: And the tents were all silent, the banners alone, The lances unlifted, the trumpet unblown. And the widows of Ashur are loud in their wail, And the idols are broke in the temple of Baal; And the might of the Gentile, unsmote by the sword, Hath melted like snow in the glance of the Lord!"
    sleepy_storyteller(story);

    return 0;
}