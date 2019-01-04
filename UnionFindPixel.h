//
// Created by nadav on 1/2/2019.
//

#ifndef EX4_UNIONFINDPIXEL_H
#define EX4_UNIONFINDPIXEL_H

//#include "SuperPixel.h"
#include "map_tree.h"
class UnionFindPixel {
    int num_of_pixels;      //needs only for printing function
    int* size;
    int* parent;
    Map_tree<int,int>** labels;             //array of trees?

public:
    UnionFindPixel(int pixels);
    ~UnionFindPixel();

    int find(int pixel_ID);                             //return index of the "super pixel"
    void Union(int pixel1, int pixel2);


    static int find_recurse(int pixel_id, int* parent);
    Map_tree<int,int>* merge_trees(Map_tree<int,int>* tree1, Map_tree<int,int>* tree2);
    static TreeNode<int,int>** merge_arrays(TreeNode<int,int>** array1,int size1,
                                              TreeNode<int,int>** array2, int size2);
    Map_tree<int,int>* build_complete_tree(TreeNode<int,int>** array, int size);
    static TreeNode<int,int>* build_recurse(TreeNode<int,int>* current, int height);
    void delete_right_leaves(Map_tree<int,int>* tree, int num_to_delete, int height);
    void delete_right_leaves_recurse(TreeNode<int,int>* current, int* num_to_delete, int height);
    void insert_array_to_tree(Map_tree<int,int>* tree,TreeNode<int,int>** array);
    void insert_array_to_tree_recurse(TreeNode<int,int>* current,TreeNode<int,int>** array, int index, int height);
    void update_max_score_recurse(TreeNode<int,int>* current);
    ;

    static TreeNode<int,int>** tree_to_array(Map_tree<int,int>* tree);          //inserting tree to array by in-order scan
    static void tree_to_array_recurse(TreeNode<int,int>* current, TreeNode<int,int>** array_to_fill, int index);

    bool set_score_to_label(int pixel, int label, int score);//return true if label exist, else return false
    bool delete_label(int pixel, int label);//return true if label exist, else return false

    ostream& printUnionFind(ostream& os);



    };


#endif //EX4_UNIONFINDPIXEL_H
