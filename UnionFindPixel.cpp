//
// Created by nadav on 1/2/2019.
//

#include "UnionFindPixel.h"
#include <math.h>

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

    TreeNode<int,int>** full_array=merge_arrays(array1,tree1->get_size(),array2,tree2->get_size());
    Map_tree<int,int>* new_tree=build_complete_tree(full_array,(tree1->get_size()+tree2->get_size()));
    insert_array_to_tree(new_tree,full_array);

    return new_tree;
}

TreeNode<int,int>** UnionFindPixel::tree_to_array(Map_tree<int,int>* tree){
    TreeNode<int,int>** array = new TreeNode<int,int>*[tree->get_size()];
    tree_to_array_recurse(tree->get_root(),array,0);
    return array;
}

void UnionFindPixel::tree_to_array_recurse(TreeNode<int,int>* current,
                                           TreeNode<int,int>** array_to_fill,
                                           int index){
    if(current == nullptr)
        return;

    tree_to_array_recurse(current->get_left_son(),array_to_fill,index);
    array_to_fill[index]=current;
    index++;
    tree_to_array_recurse(current->get_right_son(),array_to_fill,index);
}

TreeNode<int,int>** UnionFindPixel::merge_arrays(TreeNode<int,int>** array1,int size1,
                                          TreeNode<int,int>** array2, int size2){
    int new_size= size1+size2;
    TreeNode<int,int>** new_array = new TreeNode<int,int>*[new_size];
    int i1, i2, i_new;
    for(i1 = i2 = i_new = 0; (i1<size1) && (i2<size2); i_new++){
        if(array1[i1]<array2[i2]){
            new_array[i_new]=array1[i1];
            i1++;
        } else{
            new_array[i_new]=array2[i2];
            i2++;
        }
    }
    for(; i1<size1; i1++, i_new++){
        new_array[i_new]=array1[i1];
    }
    for(; i2<size2; i2++, i_new++){
        new_array[i_new]=array2[i2];
    }
}

Map_tree<int,int>* UnionFindPixel::build_complete_tree(TreeNode<int,int>** array, int size){
    int height = log2(size);
    Map_tree<int,int>* empty_tree= build_recurse(empty_tree->get_root(),height);

    int num_to_delete = exp2(height)-size;
    delete_right_leaves(empty_tree,num_to_delete,height);

};

Map_tree<int,int>* UnionFindPixel::build_recurse(TreeNode<int,int>* current, int height){
    if(h<0){                        //need < or <= ??
        return nullptr;
    }
    TreeNode<int,int>* new_node= new TreeNode<int,int>*(0,0);
    current->set_left_son(build_recurse(current->get_left_son()),h-1);
    current->set_right_son(build_recurse(current->get_right_son()),h-1);
    return new_node;
};

void UnionFindPixel::delete_right_leaves(Map_tree<int,int>* tree, int num_to_delete, int height){
    TreeNode<int,int>* current=tree->get_root();
    int height = log2(tree->get_size());
    delete_right_leaves_recurse(tree->get_root(),*num_to_delete,height);

}

void UnionFindPixel::delete_right_leaves_recurse(TreeNode<int,int>* current, int* num_to_delete, int height){
    if(height==0 || *num_to_delete<=0){
        return;
    }

    delete_right_leaves_recurse(current->get_right_son(),*num_to_delete,height-1);
    if(*num_to_delete>0 && height==1){
        delete current->get_right_son();
        current->set_right_son(nullptr);
        *num_to_delete--;
    }

    delete_right_leaves_recurse(current->get_left_son(),*num_to_delete,height-1);
    if(*num_to_delete>0 && height==1){
        delete current->get_left_son();
        current->set_left_son(nullptr);
        *num_to_delete--;
    }

}

void UnionFindPixel::insert_array_to_tree(Map_tree<int,int>* tree,TreeNode<int,int>** array){

}