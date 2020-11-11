CXXFLAGS = -O3
CXXFLAGS_DEBUG = -fsanitize=address -mfpmath=sse -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Woverloaded-virtual -Wnon-virtual-dtor -Wcast-qual -Wno-suggest-attribute=format

STUDENT_PATH = ./student
TREE_PATH = $(STUDENT_PATH)/tree

all: research.out research_debug.out

%.o: %.cpp
	g++ $(CXXFLAGS) -c $< -o $@
%_debug.o: %.cpp
	g++ $(CXXFLAGS_DEBUG) -c $< -o $@

research.out: main.o $(STUDENT_PATH)/student.o $(TREE_PATH)/tree.o $(TREE_PATH)/num_ends.o $(TREE_PATH)/max_depth.o $(TREE_PATH)/list2_width.o $(TREE_PATH)/width_node.o $(TREE_PATH)/max_width.o $(TREE_PATH)/max_diff_depths.o $(TREE_PATH)/num_one_descendant.o
	g++ $(CXXFLAGS) $^ -o $@
research_debug.out: main_debug.o $(STUDENT_PATH)/student_debug.o $(TREE_PATH)/tree_debug.o $(TREE_PATH)/num_ends_debug.o $(TREE_PATH)/max_depth_debug.o $(TREE_PATH)/list2_width_debug.o $(TREE_PATH)/width_node_debug.o $(TREE_PATH)/max_width_debug.o $(TREE_PATH)/max_diff_depths_debug.o $(TREE_PATH)/num_one_descendant_debug.o
	g++ $(CXXFLAGS_DEBUG) $^ -o $@

mrproper: mrproper_current mrproper_student mrproper_tree
mrproper_current:
	rm -f *.o *.out
mrproper_student: $(STUDENT_PATH)
	rm -f $</*.o 
mrproper_tree: $(TREE_PATH)
	rm -f $</*.o
