#include <cstdio>
#include <ctime>
#include "student/bin_tree/bin_tree.h"

#define ERROR (-1)

int main(int argc, const char **argv)
{
	bin_tree tr;
	int depth_print, param, read_res, num_ends, max_depth, max_width, max_diff_depths, num_one_descendant, num_sbtrs_nng, num_nodes_sbtrs_nng, num_sbtrs_depth_ng, num_sbtrs_width_ng, num_nodes_depth;
	const char *name;
	clock_t begin, end;

	if( (argc!=3 || sscanf(argv[1], "%d", &depth_print)!=1) && (argc!=4 || sscanf(argv[1], "%d", &depth_print)!=1 || sscanf(argv[3], "%d", &param)!=1) )
	{
		fprintf(stderr, "Usage:\t%s depth_print filename [parameter]\n", argv[0]);
		return ERROR;
	}
	name = argv[2];

	begin = clock();
	read_res = tr.read(name);
	end = clock();
	if( read_res!=bin_tree::SUCCESS )
	{
		switch( read_res )
		{
		case bin_tree::OPEN_ERROR:
			fprintf(stderr, "Can not open %s!\n", name);
			break;
		case bin_tree::READ_ERROR:
			fprintf(stderr, "Can not read from %s!\n", name);
			break;
		case bin_tree::ALLOC_ERROR:
			fprintf(stderr, "Can not allocate memory!\n");
			break;
		default:
			fprintf(stderr, "Unknown error with code %d!\n", read_res);
		}
		return ERROR;
	}
	printf("Reading completed.\nResult:\n");
	tr.print(depth_print);
	printf("Elapsed: %.2lf sec\n", static_cast<double>(end - begin)/CLOCKS_PER_SEC);

	begin = clock();
	num_ends = tr.num_ends();
	end = clock();
	printf("\nNumber of ends calculated.\nResult: %d\nElapsed: %.2lf sec\n", num_ends, static_cast<double>(end - begin)/CLOCKS_PER_SEC);

	if( tr.get_root()!=nullptr )
	{
		begin = clock();
		max_depth = tr.max_depth();
		end = clock();
		printf("\nMaximum depth calculated.\nResult: %d\nElapsed: %.2lf sec\n", max_depth, static_cast<double>(end - begin)/CLOCKS_PER_SEC);

		begin = clock();
		max_width = tr.max_width();
		end = clock();
		printf("\nMaximum width calculated.\nResult: %d\nElapsed: %.2lf sec\n", max_width, static_cast<double>(end - begin)/CLOCKS_PER_SEC);

		begin = clock();
		max_diff_depths = tr.max_diff_depths();
		end = clock();
		printf("\nMaximum diffrent of depths left and right subtrees calculated.\n");
		if( max_diff_depths<0 )
			printf("Result: no two subtrees\n");
		else
			printf("Result: %d\n", max_diff_depths);
		printf("Elapsed: %.2lf sec\n", static_cast<double>(end - begin)/CLOCKS_PER_SEC);
	}

	begin = clock();
	num_one_descendant = tr.num_one_descendant();
	end = clock();
	printf("\nNumber of one-descendant nodes calculated\nResult: %d\nElapsed: %.2lf sec\n", num_one_descendant, static_cast<double>(end - begin)/CLOCKS_PER_SEC);

	if( argc!=4 )
		return 0;

	begin = clock();
	num_sbtrs_nng = tr.num_sbtrs_nng(param);
	end = clock();
	printf("\nNumber of subtrees with number of nodes not greater-than parameter calculated.\nResult: %d\nElapsed: %.2lf sec\n", num_sbtrs_nng, static_cast<double>(end - begin)/CLOCKS_PER_SEC);

	begin = clock();
	num_nodes_sbtrs_nng = tr.num_nodes_sbtrs_nng(param);
	end = clock();
	printf("\nNumber of nodes subtrees with number of nodes not greater-than parameter calculated.\nResult: %d\nElapsed: %.2lf sec\n", num_nodes_sbtrs_nng, static_cast<double>(end - begin)/CLOCKS_PER_SEC);

	begin = clock();
	num_sbtrs_depth_ng = tr.num_sbtrs_depth_ng(param);
	end = clock();
	printf("\nNumber of subtrees with max depth not greater-than parameter calculcated.\nResult: %d\nElapsed: %.2lf sec\n", num_sbtrs_depth_ng, static_cast<double>(end - begin)/CLOCKS_PER_SEC);

	begin = clock();
	num_sbtrs_width_ng = tr.num_sbtrs_width_ng(param);
	end = clock();
	printf("\nNumber of subtrees with max width not greater-than parameter calculated.\nResult: %d\nElapsed: %.2lf sec\n", num_sbtrs_width_ng, static_cast<double>(end - begin)/CLOCKS_PER_SEC);

	begin = clock();
	num_nodes_depth = tr.num_nodes_depth(param);
	end = clock();
	printf("\nNumber of nodes on depth parameter calculated.\nResult: %d\nElapsed: %.2lf sec\n", num_nodes_depth, static_cast<double>(end - begin)/CLOCKS_PER_SEC);

	return 0;
}
