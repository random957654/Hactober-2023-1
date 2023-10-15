// C program to read and print 
// all files in a zip file 
// uses library libzip 
#include <stdlib.h> 
#include <zip.h> 

// this is run from the command line with the zip file 
// passed in example usage: ./program zipfile.zip 
int main(int argc, char* argv[]) 
{ 
	// if more or less than 2 
	// command line arguments, 
	// program ends 
	if (argc > 2 || argc < 2) 
		return -1; 

	// if the file provided can't 
	// be opened/read, program 
	// ends 
	if (!fopen(argv[1], "r")) 
		return -2; 

	// stores error codes for libzip functions 
	int errorp = 0; 

	// initializes a pointer to a zip archive 
	zip_t* arch = NULL; 

	// sets that pointer to the 
	// zip file from argv[1] 
	arch = zip_open(argv[1], 0, &errorp); 

	// the zip_stat structure 
	// contains information such as 
	// file name, size, comp size 

	struct zip_stat* finfo = NULL; 

	// must be allocated enough space 
	// (not exact space here) 
	finfo = calloc(256, sizeof(int)); 

	// "initializes" the structure 
	// according to documentation 

	zip_stat_init(finfo); 

	// initialize file descriptor for 
	// zip files inside archive 
	zip_file_t* fd = NULL; 

	// initialize string pointer for 
	// reading from fd 
	char* txt = NULL; 

	// count = index of file archive 0 = 
	// first file 

	int count = 0; 

	// we open the file at the count'th index inside the 
	// archive we loop and print every file and its 
	// contents, stopping when zip_stat_index did not return 
	// 0, which means the count index is more than # of 
	// files 
	while ((zip_stat_index(arch, count, 0, finfo)) == 0) { 

		// allocate room for the entire file contents 
		txt = calloc(finfo->size + 1, sizeof(char)); 
		fd = zip_fopen_index( 
			arch, count, 0); // opens file at count index 
							// reads from fd finfo->size 
							// bytes into txt buffer 
		zip_fread(fd, txt, finfo->size); 

		printf("file #%i: %s\n\n", count + 1, 
			finfo->name); // prints filename 
		printf("%s\n\n", 
			txt); // prints entire file contents 

		// frees allocated buffer, will 
		// reallocate on next iteration of loop 
		free(txt); 

		// increase index by 1 and the loop will 
		// stop when files are not found 
		count++; 
	} 
	return 0; 
}
