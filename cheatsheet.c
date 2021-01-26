#include <stdio.h>

static void printNotes();
static void printTabs();

void cheatsheet()
{ 
	printNotes();
	printf("\n\n");
	printTabs();
}

void printNotes()
{
	const int notesNum = 22;
	const int downNotesOffset = 7;
	const int notesOnBarsNum = 9;
	for (int i = 0; i < notesNum; i++)
	{
		int drawBarBefore = i + notesOnBarsNum >= notesNum - downNotesOffset;
		int drawBarAfter = i <= notesNum - downNotesOffset;
		int isOnBar = i % 2 == 0;
		for (int j = 0; j < notesNum; j++) 
		{
			int cmpToNote = i - notesNum + j;
			int cmpSign = (cmpToNote > 0) - (cmpToNote < 0);
			switch (cmpSign)
			{
				case 1:
					printf (isOnBar && drawBarAfter ? "--" : "  ");
					break;
				case 0:
					printf("O%c", isOnBar ? '-' : ' ');
					break;
				case -1:
					if (!drawBarBefore && isOnBar && cmpToNote == -1) printf(" -");
					else printf(isOnBar && drawBarBefore ? "--" : "  ");
					break;
			}
		}
		printf("\n");
	}
}

void printTabs()
{
	const int notesNum = 7;
	const int totalNotesNum = 22;
	const char firstNote = 'A';

	const int noteOffsets[7] = {1, 2, 2, 2, 1, 2, 2};
	int noteDistances[totalNotesNum];
	noteDistances[0] = 0;
	for (int i = 1; i < totalNotesNum; i++)
	{
		int offsetIndex = (i - 1) % notesNum;
		noteDistances[i] = noteDistances[i - 1] + noteOffsets[offsetIndex];
	}

	const int stringsToNotes[6] = {14, 11, 9, 6, 3, 0};
	for (int stringIndex = 0; stringIndex < 6; stringIndex++)
	{
		int stringStartingIndex = stringsToNotes[stringIndex];
		int stringStartingDistance = noteDistances[stringStartingIndex];
		for (int noteIndex = 0; noteIndex < totalNotesNum; noteIndex++)
		{
			int noteDistance = noteDistances[noteIndex];
			if (noteDistance < stringStartingDistance ||
					noteDistance > stringStartingDistance + 12) 
			{
				printf("--");
			}
			else 
			{
				int difference = noteDistance - stringStartingDistance;
				printf ("%d", difference);
			}
		}
		printf("\n\n");
	}

	for(int i = 0; i < totalNotesNum; i++)
	{
		char note = firstNote + (i + 4) % notesNum;
		printf("%c ", note);
	}
}
