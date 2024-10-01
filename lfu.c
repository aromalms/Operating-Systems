#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// Maximum number of pages that can be held in memory
#define MAX_PAGES 100
// Structure to represent a page
typedef struct {
    int pageNumber;
    int frequency;
} Page;
// Function to find the page with the lowest frequency in the dictionary
int findLowestFrequency(Page *pages, int numPages) {
    int lowestFrequency = INT_MAX;
    int lowestIndex = -1;
    for (int i = 0; i < numPages; i++) {
        if (pages[i].frequency < lowestFrequency) {
            lowestFrequency = pages[i].frequency;
            lowestIndex = i;
        }
    }
    return lowestIndex;
}

int main() {
    int numReferences, numPages, pageFaults = 0;
    int pagesInMemory = 0;
    Page memory[MAX_PAGES];
    int pageReferences[MAX_PAGES];
    int frequency[MAX_PAGES] = {0};

    printf("Enter the number of page references: ");
    scanf("%d", &numReferences);

    printf("Enter the number of pages: ");
    scanf("%d", &numPages);

    printf("Enter the page reference string: ");
    for (int i = 0; i < numReferences; i++) {
        scanf("%d", &pageReferences[i]);
    }

    for (int i = 0; i < numReferences; i++) {
        int page = pageReferences[i];
        int found = 0;
        for (int j = 0; j < pagesInMemory; j++) {
            if (memory[j].pageNumber == page) {
                frequency[j]++;
                found = 1;
                break;
            }
        }

        if (!found) {
            pageFaults++;
            if (pagesInMemory < numPages) {
                memory[pagesInMemory].pageNumber = page;
                memory[pagesInMemory].frequency = 1;
                frequency[pagesInMemory] = 1;
                pagesInMemory++;
            } else {
                int lowestIndex = findLowestFrequency(memory, pagesInMemory);
                memory[lowestIndex].pageNumber = page;
                memory[lowestIndex].frequency = 1;
                frequency[lowestIndex] = 1;
            }
        }
    }

    printf("Total page faults: %d\n", pageFaults);

    return 0;
}
