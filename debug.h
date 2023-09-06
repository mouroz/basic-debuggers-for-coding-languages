#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static int globalcounter = 0;

//----------------------------------------------------------------------
//Main debug functions - use __LINE__ for the line variable
//----------------------------------------------------------------------

void debug_int(int i, int line, const char* desc) {
    printf("debug: %d in line %d: %s\n", i, line, desc);
}

void debug_float(float f, int line, const char* desc) {
    printf("debug: %f in line %d: %s\n", f, line, desc);
}

void debug_char(char c, int line, const char* desc) {
    printf("debug: %c in line %d: %s\n", c, line, desc);
}

void debug_string(const char* str, int line, const char* desc) {
    printf("debug: %s in line %d: %s\n", str, line, desc);
}

void debug_bool(bool b, int line, const char* desc) {
    printf("debug: %s in line %d: %s\n", b ? "true" : "false", line, desc);
}

void debug_double(double d, int line, const char* desc) {
    printf("debug: %lf in line %d: %s\n", d, line, desc);
}



//----------------------------------------------------------------------
//Quick debug functions
//----------------------------------------------------------------------

void d_int(int i) {printf("quickdebug: %i\n", i);}
void d_float(float f) {printf("quickdebug: %f\n", f);}
void d_char(char c) {printf("quickdebug: %c\n", c);}
void d_string(const char* str) {printf("quickdebug: %s\n", str);}
void d_bool(bool b) {printf("quickdebug: %s\n", b ? "true" : "false");}
void d_double(double d) {printf("quickdebug: %lf\n", d);}

//----------------------------------------------------------------------
//Other utility functions
//----------------------------------------------------------------------

void endl(){printf("\n");}

//Print lines of char one at a time faster
void debug_seq_char(char c) {printf("%c",c);}

void debug_counter() {
	globalcounter++;
	if (globalcounter > 9999) {
		printf("\nCritical: Infinite Loop");
		exit(1);
	}
}

//----------------------------------------------------------------------
//FILE SECTION
//----------------------------------------------------------------------
	//At this stage the code actually outputs a bunch of outputs on a new txt, and youre supposed
	//to use a online text comparator to see if the results match

void file_createOrRewrite(const char* filename) {
	FILE *file = fopen(filename, "w");
	if (file == NULL) printf("ERROR - Failed to acess the file %s", filename);
}

void file_delete(const char* filename) {
	bool loop = true; 
	char answer;
	do{
		printf("\nAre you sure you want to delete the file %s?\n (Y/N)",filename);
		scanf(" %c", &answer);
		if (answer = 'N') return;
		if (answer = 'Y') loop = false;
		while (getchar() != '\n'); // Clear input buffer
	} while(loop);
	if (remove(filename) == 0) {
		printf("File '%s' sucessfully deleted\n", filename);
	} else {
		printf("Failure on deleting file");
	}

}
void file_addLine(const char* filename, const char* content) {
	FILE *file = fopen(filename, "a");
	if (file == NULL) {
		printf("ERROR - Failed to acess the file %s", filename);
		return;
	}
	fprintf(file,"%s",content);
}

void file_addEndl(const char* filename) {
	FILE *file = fopen(filename, "a");
	if (file == NULL) {
		printf("ERROR - Failed to acess the file %s", filename);
		return;
	}
	fprintf(file,"\n");
}

//----------------------------------------------------------------------
//Add variables to file
//----------------------------------------------------------------------


void file_addInt(const char* filename, int value) {
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        printf("ERROR - Failed to access the file %s\n", filename);
        return;
    }
    fprintf(file, "%d", value);
    fclose(file);
}

void file_addFloat(const char* filename, float value) {
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        printf("ERROR - Failed to access the file %s\n", filename);
        return;
    }
    fprintf(file, "%f", value);
    fclose(file);
}

void file_addChar(const char* filename, char value) {
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        printf("ERROR - Failed to access the file %s\n", filename);
        return;
    }
    fprintf(file, "%c", value);
    fclose(file);
}

void file_addBool(const char* filename, bool value) {
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        printf("ERROR - Failed to access the file %s\n", filename);
        return;
    }
    fprintf(file, "%s", value ? "true" : "false");
    fclose(file);
}

void file_addDouble(const char* filename, double value) {
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        printf("ERROR - Failed to access the file %s\n", filename);
        return;
    }
    fprintf(file, "%lf", value);
    fclose(file);
}

#endif
