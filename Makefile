CXXFLAGS = -O3
CXXFLAGS_DEBUG = -fsanitize=address -mfpmath=sse -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Woverloaded-virtual -Wnon-virtual-dtor -Wcast-qual -Wno-suggest-attribute=format

STUDENT_PATH = ./student
BIN_TREE_PATH = $(STUDENT_PATH)/bin_tree

all: research.out research_debug.out

%.o: %.cpp
	g++ $(CXXFLAGS) -c $< -o $@
%_debug.o: %.cpp
	g++ $(CXXFLAGS_DEBUG) -c $< -o $@

research.out: main.o $(STUDENT_PATH)/student.o $(BIN_TREE_PATH)/bin_tree.o $(BIN_TREE_PATH)/num_ends.o $(BIN_TREE_PATH)/max_depth.o $(BIN_TREE_PATH)/list2_width.o $(BIN_TREE_PATH)/width_node.o $(BIN_TREE_PATH)/max_width.o $(BIN_TREE_PATH)/max_diff_depths.o $(BIN_TREE_PATH)/num_one_descendant.o $(BIN_TREE_PATH)/num_sbtrs_nng.o $(BIN_TREE_PATH)/num_nodes_sbtrs_nng.o $(BIN_TREE_PATH)/num_sbtrs_depth_ng.o $(BIN_TREE_PATH)/num_sbtrs_width_ng.o $(BIN_TREE_PATH)/num_nodes_depth.o
	g++ $(CXXFLAGS) $^ -o $@
research_debug.out: main_debug.o $(STUDENT_PATH)/student_debug.o $(BIN_TREE_PATH)/bin_tree_debug.o $(BIN_TREE_PATH)/num_ends_debug.o $(BIN_TREE_PATH)/max_depth_debug.o $(BIN_TREE_PATH)/list2_width_debug.o $(BIN_TREE_PATH)/width_node_debug.o $(BIN_TREE_PATH)/max_width_debug.o $(BIN_TREE_PATH)/max_diff_depths_debug.o $(BIN_TREE_PATH)/num_one_descendant_debug.o $(BIN_TREE_PATH)/num_sbtrs_nng_debug.o $(BIN_TREE_PATH)/num_nodes_sbtrs_nng_debug.o $(BIN_TREE_PATH)/num_sbtrs_depth_ng_debug.o $(BIN_TREE_PATH)/num_sbtrs_width_ng_debug.o $(BIN_TREE_PATH)/num_nodes_depth_debug.o
	g++ $(CXXFLAGS_DEBUG) $^ -o $@

mrproper: mrproper_current mrproper_student mrproper_bin_tree
mrproper_current:
	rm -f *.o *.out
mrproper_student: $(STUDENT_PATH)
	rm -f $</*.o 
mrproper_bin_tree: $(BIN_TREE_PATH)
	rm -f $</*.o
