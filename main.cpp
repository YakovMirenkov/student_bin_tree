#include <cstdio>
#include <ctime>
#include "student/tree/tree.h"

#define ERROR (-1)

int main(int argc, const char **argv)
{
	tree tr;
	int depth_print, read_res, num_ends, max_depth, max_width, max_diff_depths, num_one_descendant;
	clock_t begin, end;

	if( argc!=3 || sscanf(argv[1], "%d", &depth_print)!=1 || depth_print<0 )
	{
		fprintf(stderr, "Usage:\t%s depth_print filename\n", argv[0]);
		return ERROR;
	}

	read_res = tr.read(argv[2]);
	if( read_res!=tree::SUCCESS )
	{
		switch( read_res )
		{
		case tree::OPEN_ERROR:
			fprintf(stderr, "Can not open %s!\n", argv[2]);
			break;
		case tree::READ_ERROR:
			fprintf(stderr, "Can not read from %s!\n", argv[2]);
			break;
		case tree::ALLOC_ERROR:
			fprintf(stderr, "Can not allocate memory!\n");
			break;
		default:
			fprintf(stderr, "Unknown error with code %d!\n", read_res);
		}
		return ERROR;
	}
	tr.print(depth_print);
	if( depth_print>0 && tr.get_root()!=nullptr )
		printf("End of tree.\n\n");

	begin = clock();
	num_ends = tr.num_ends();
	end = clock();
	printf("Number of ends:\t%d\nElapsed time:\t%.2lf sec\n", num_ends, static_cast<double>(end - begin)/CLOCKS_PER_SEC);

	begin = clock();
	max_depth = tr.max_depth();
	end = clock();
	printf("\nMaximum depth:\t%d\nElapsed time:\t%.2lf sec\n", max_depth, static_cast<double>(end - begin)/CLOCKS_PER_SEC);

	begin = clock();
	max_width = tr.max_width();
	end = clock();
	printf("\nMaximum width:\t%d\nElapsed time:\t%.2lf sec\n", max_width, static_cast<double>(end - begin)/CLOCKS_PER_SEC);

	begin = clock();
	max_diff_depths = tr.max_diff_depths();
	end = clock();
	printf("\nMaximum diffrent of depths:\t%d\nElapsed time:\t%.2lf sec\n", max_diff_depths, static_cast<double>(end - begin)/CLOCKS_PER_SEC);

	begin = clock();
	num_one_descendant = tr.num_one_descendant();
	end = clock();
	printf("\nNumber of one-descendant:\t%d\nElapsed time:\t%.2lf sec\n", num_one_descendant, static_cast<double>(end - begin)/CLOCKS_PER_SEC);

	return 0;
}
