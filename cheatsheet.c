#include <stdio.h>

static const int MAIN_SLOTS = 9;

static void printNotes();

void cheatsheet()
{ 
	printNotes();
}

void printNotes()
{
	const int notesNum = 22;
	const int downNotesOffset = 7;
	const int notesOnBarsNum = 9;
	for (int i = 0; i < notesNum; i++)
	{
		for (int j = 0; j < notesNum; j++) 
		{
			int drawBarBefore = i + notesOnBarsNum >= notesNum - downNotesOffset;
			int drawBarAfter = i <= notesNum - downNotesOffset;
			int isOnBar = i % 2 == 0;
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
