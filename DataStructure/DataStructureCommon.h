/** 
 * author: zzw5005
 * date: 2020/6/25 9:26 下午
*/

#ifndef SWORDTOOFFER_DATASTRUCTURECOMMON_H
#define SWORDTOOFFER_DATASTRUCTURECOMMON_H

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x){
        val = x;
    }
};

/**
 * 多了指向父节点的指针
 */
struct BinaryTreeNode{
    int val;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode *parent;

    BinaryTreeNode(int x){
        val = x;
    }
};

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x){
        val = x;
    }
};

#endif //SWORDTOOFFER_DATASTRUCTURECOMMON_H
