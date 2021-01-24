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
	const int offsetLen = 10;
	const int downNotesOffset = 7;
	const int totalLength = notesNum * 2 + offsetLen;
	const int barsNum = 5;

	signed char notes[notesNum];
	for (signed char i = 0; i < notesNum; i++)
	{
		notes[i] = i - downNotesOffset;
	}


	int currentPosition = notesNum - downNotesOffset - 1;
	while (currentPosition >= -downNotesOffset)
	{
		int p = 0;
		int isOnBar = currentPosition % 2 == 0;
		while(p < totalLength)
		{
			if (p < offsetLen && isOnBar)
			{
				printf("-");
				p += 1;
			}
			else
			{
				int noteIndex = (p - offsetLen) / 2;
				int isNote = notes[noteIndex] == currentPosition;
				if (isNote)
				{
					printf("O");
					if (isOnBar)
					{
						printf("-");
					}
				}
				else if (currentPosition >= 0 && currentPosition <= barsNum * 2 - 1)
				{
					printf(isOnBar ? "--" : "  ");
				}
				else 
				{
					printf("  ");
				}
				
				
				p += 2;
			}
		}

		printf("\n");
		currentPosition -= 1;
	}
}
