# 深度优先搜索-搜索特定结点类

## _1._ N-ary Tree Level Order Traversal

Given an n-ary tree, return the level order traversal of its nodes' values.

_Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value \(See examples\)._

![Input: root = \[1,null,3,2,4,null,5,6\] Output: \[\[1\],\[3,2,4\],\[5,6\]\]](../.gitbook/assets/image.png)

题目的目的是把每一层的节点都存储在一个列表中，最后返回一个二维列表

**思路：用一个辅助队列，存储下每一层的节点，以及使用一个分割符号记录层结束时的节点，之后利用这个队列依次遍历即可**

