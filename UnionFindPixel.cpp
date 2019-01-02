//
// Created by nadav on 1/2/2019.
//

#include "UnionFindPixel.h"

#define ROOT -1

UnionFindPixel::UnionFindPixel(int pixels) {
    this->size=new int[pixels];
    this->parent=new int[pixels];

    for (int i = 0; i < pixels; i++) {
        this->size[i]=1;
        this->parent[i]=ROOT;
        this->labels[i]=new Map_tree<int,int>();
    }
}

int UnionFindPixel::Find(int pixel_ID) {
    return find_recurse(pixel_ID,this->parent);
}


int UnionFindPixel::find_recurse(int pixel_id, int* parent){
    if(parent[pixel_id]==ROOT)
        return pixel_id;

    int new_parent = find_recurse(parent[pixel_id], parent);
    parent[pixel_id]=new_parent;                                //shrinking routes
    return new_parent;
}

void UnionFindPixel:: Union(int pixel1, int pixel2){
    int root1=Find(pixel1);
    int root2=Find(pixel2);

    if (size[root1]>size[root2]){
        parent[root2]=root1;
        size[root1]+=size[root2];
        size[root2]=0;
    }
    else{
        parent[root1]=root2;
        size[root2]+=size[root1];
        size[root1]=0;
    }

}



Map_tree<int,int>* UnionFindPixel::merge_trees(Map_tree<int,int>* tree1, Map_tree<int,int>* tree2){
    TreeNode<int,int>** array1=tree_to_array(tree1);
    TreeNode<int,int>** array2=tree_to_array(tree2);

    


};

TreeNode<int,int>** UnionFindPixel::tree_to_array(Map_tree<int,int>* tree){
    TreeNode<int,int>** array = new TreeNode<int,int>*[tree->get_size()];

};