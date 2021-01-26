#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <signal.h>
#include <getopt.h>

const int NUM_NOTES = 7;
const int NUM_STRINGS = 6;

const unsigned int INTERVAL = 3;

static volatile int keepRunning = 1;

void drawFretboard(char* letters, int stringIndex, int noteIndex);
void interruptHandler(int arg);
void cheatsheet();

int main (int argc, char** argv)
{
	char letters[NUM_NOTES];

	int optIndex;
	unsigned char strings = ~0;
	unsigned int period = INTERVAL;
	unsigned int numStrings = NUM_STRINGS;
	int opt;

	struct option options[] = 
	{
		{"cheatsheet", no_argument, 0, 'c'},
		{0, 0, 0, 0}
	};

	while ((opt = getopt_long(argc, argv, "s:p:", options, &optIndex)) != -1)
	{
		switch(opt)
		{
			case 'p':
				period = atoi(optarg);
				break;
			case 's':
				numStrings = strlen(optarg);
				strings = 0;
				for (int i = 0; i < numStrings; i++)
				{
					int stringIndex = (int)optarg[i] - 49;
					if (stringIndex >= 0)
					{
						strings |= (1 << stringIndex);
					}
				}
				break;
			case 'c':
				cheatsheet();
				return 0;
		}
	}

	for(int i = 0; i < NUM_NOTES; i++)
	{
		letters[i] = 'A' + i;
	}

	srand(time(NULL));
	setbuf(stdout, NULL); // Disable buffering for stdout. Makes it flush immediately without \n
	signal(SIGINT, interruptHandler);

	while (keepRunning)
	{
		int noteIndex = rand() % NUM_NOTES;
		int stringIndex = rand() % NUM_STRINGS;

		if ((strings & (1 << stringIndex)) != 0)
		{
			drawFretboard(letters, stringIndex, noteIndex);
			sleep(period);
		}
	}

	return 0;
}

void drawFretboard(char* letters, int stringIndex, int noteIndex)
{
	const int fretboardLength = 20;
	for (int string = 0; string < NUM_STRINGS; string++)
	{
		printf("%c[2K\r", 27); //Clear the current line
		printf("%c", stringIndex == string ? letters[noteIndex] : ' ');
		printf(" ");
		for (int i = 0; i < fretboardLength; i++)
		{
			printf("-");
		}
		printf("\n");
	}

	printf("%c[%dA", 27, NUM_STRINGS); //Move cursor up NUM_STRINGS lines
}

void interruptHandler(int arg)
{
	printf("%c[%dB", 27, NUM_STRINGS); //Move cursor down NUM_STRINGS lines
	keepRunning = 0;
}
