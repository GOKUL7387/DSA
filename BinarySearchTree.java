class BinaryTree {
    Node root;
    class Node {
        int key;
        Node left,right;
        Node(int val) {
            key=val;
            left=null;
            right=null;
        }
    }
    BinaryTree(int val) {
        root=new Node(val);
    }
    BinaryTree() {
        root=null;
    }
    public Node insert(Node root,int val) {
        if(root==null) {
            return new Node(val);
        }
        if(val<root.key) {
            root.left=insert(root.left,val);
        }
        else {
            root.right=insert(root.right,val);
        }
        return root;
    }
    public void inOrder(Node root) {
        if(root!=null) {
            inOrder(root.left);
            System.out.print(root.key+" ");
            inOrder(root.right);
        }
    }
    public void preOrder(Node root) {
        if(root!=null) {
            System.out.print(root.key+" ");
            preOrder(root.left);
            preOrder(root.right);
        }
    }
    public void postOrder(Node root) {
        if(root!=null) {
            postOrder(root.left);
            postOrder(root.right);
            System.out.print(root.key+" ");
        }
    }
    public  Node search(Node root, int val) {
        if(root==null || root.key==val) {
            return root;
        }
        if(val<root.key) {
            return search(root.left,val);
        }
        return search(root.right,val);
    }
    public Node delete(Node root, int val) {
        if(root==null) {
            return null;
        }
        if(val<root.key) {
            root.left=delete(root.left,val);
        }
        else if(val>root.key) {
            root.right=delete(root.right,val);
        }
        else {
            if(root.left==null) {
                return root.right;
            }
            else if(root.right==null) {
                return root.left;
            }
            root.key=min(root.right);
            root.right=delete(root.right,root.key);
        }
        return root;
    }
    public int min(Node root) {
        int minval=root.key;
        while(root.left!=null) {
            minval=root.left.key;
            root=root.left;
        }
        return minval;
    }
}
public class Binarytree {
    public static void main (String[] args) {
        BinaryTree bst=new BinaryTree(50);
        bst.insert(bst.root,20);
        bst.insert(bst.root,70);
        bst.insert(bst.root,10);
        bst.insert(bst.root,25);
        bst.insert(bst.root,60);
        bst.insert(bst.root,90);
        bst.inOrder(bst.root);
        System.out.println();
        bst.preOrder(bst.root);
        System.out.println();
        bst.postOrder(bst.root);
        System.out.println();
        if(bst.search(bst.root,70)==null) {
            System.out.println("Not found");
        }
        else {
            System.out.println("found");
        }
        bst.delete(bst.root,70);
        bst.inOrder(bst.root);
    }
}
