//
// Created by nadav on 1/2/2019.
//

#ifndef EX4_UNIONFINDPIXEL_H
#define EX4_UNIONFINDPIXEL_H

//#include "SuperPixel.h"
#include "map_tree.h"
class UnionFindPixel {
    int* size;
    int* parent;
    Map_tree<int,int>** labels;

public:
    UnionFindPixel(int pixels);
    ~UnionFindPixel();

    int Find(int pixel_ID);                             //return index of the "super pixel"
    void Union(int pixel1, int pixel2);


    static int find_recurse(int pixel_id, int* parent);
    static Map_tree<int,int>* merge_trees(Map_tree<int,int>* tree1, Map_tree<int,int>* tree2);

    static TreeNode<int,int>** tree_to_array(Map_tree<int,int>* tree);          //inserting tree to array by in-order scan
    static void tree_to_array_recurse(TreeNode<int,int>* current, TreeNode<int,int>** array_to_fill, int index);
};


#endif //EX4_UNIONFINDPIXEL_H
