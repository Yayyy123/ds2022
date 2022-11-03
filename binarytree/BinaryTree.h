
#include <iostream>
using namespace std;

template<typename Comparable>
class TreeNode//classNode

{
private:
    Comparable element;
    //Node里面的元素值
    TreeNode *left;
    //指向左子树的指针
    TreeNode *right;
    //指向右子树的指针
public:
    virtual Comparable getElement() const {return element;}
    //获取节点元素值
    virtual void setElement(Comparable _val){element = _val;}
    //给节点赋值
    virtual void setleft(Comparable _val){element = _val;}
    //给左子树 传递 值
    virtual void setright(Comparable _val){element = _val;}
    //给右子树 传递 值
    virtual TreeNode* getleftNode() const = 0;
    //获取左子树根节点
    virtual TreeNode* getrightNode() const = 0;
    //获取右子树根节点
};

    
template<typename Comparable>
class BinaryTree
{
private:
    class BinaryTreeNode : public TreeNode<Comparable>{;};
    
public:
    ~BinaryTree();
    //构造BinaryTree
    virtual BinaryTree & operator=( const BinaryTree & rhs);
    //rhs BinarysTree的左值
    virtual BinaryTree & operator=( BinaryTree && rhs );
    //rhs BinaryTree的右值
    virtual Comparable & findMin() const;
    //寻找树的最小值
    virtual Comparable & findMax() const;
    //寻找树的最大值
    virtual bool contains( const Comparable & _val) const;
    //判断树是否存在_val 的元素
    virtual bool isEmpty() const;
    //判断树是否是空的
    virtual void printTree();
    //打印出来
    virtual void makeEmpty();
    //清空整个树
    virtual void insert( const Comparable & _val);
    //插入节点的左值
    virtual void insert( const Comparable && _val);
    //插入节点的右值
    virtual void remove( const Comparable & _val);
    //删除指定节点的值
};

template<typename Comparable>
class BinarySearchTree : public BinaryTree<Comparable>
{
private:
    class BinarySearchTreeNode : public TreeNode<Comparable>{};
public:
    virtual BinarySearchTreeNode * clone( BinarySearchTreeNode *t ) const;
    //克隆子树的内部方法
};

template<typename Comparable>
class AvlTree : public BinaryTree<Comparable>
{
private:
    class AvlTreeNode : public TreeNode<Comparable>
    {
    private:
        int height;
        //多增加一个高度
    };
public:
    ~AvlTree();
    
    virtual void balance (AvlTreeNode * & t);
    //保持Avl树平衡
    virtual void rotateWithLeftChild( AvlTreeNode * & k2 );
    //Avl树case 1 旋转
    virtual void rotateWithRightChild( AvlTreeNode * & k1 );
    //Avl树case 2 旋转
    virtual void doubleWithLeftChild( AvlTreeNode * & k3 );
    //Avl树case 3 旋转
    virtual void doubleWithRightChild( AvlTreeNode * & k1 );
    //Avl树case 4 旋转
};

template<typename Comparable>
class SplayTree : public BinaryTree<Comparable>
{
private:
    class SplayTreeNode : public TreeNode<Comparable>{};
public:
    virtual void splay( const Comparable & x, SplayTreeNode * & t );
    //展开数的代码
};


