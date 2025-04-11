// Class representing a node in an AVL tree
class AVLNode {
    int key;
    AVLNode left, right;
    int height;

    public AVLNode(int key) {
        this.key = key;
        this.height = 1;
    }
}

// Class representing an AVL tree
class AVLTree {

    // Method to get the height of the tree
    int height(AVLNode node) {
        if (node == null) {
            return 0;
        }
        return node.height;
    }

    // Method to perform a right rotation
    AVLNode rightRotate(AVLNode y) {
        AVLNode x = y.left;
        AVLNode T2 = x.right;

        // Perform rotation
        x.right = y;
        y.left = T2;

        // Update heights
        y.height = Math.max(height(y.left), height(y.right)) + 1;
        x.height = Math.max(height(x.left), height(x.right)) + 1;

        // Return new root
        return x;
    }

    // Method to perform a left rotation
    AVLNode leftRotate(AVLNode x) {
        AVLNode y = x.right;
        AVLNode T2 = y.left;

        // Perform rotation
        y.left = x;
        x.right = T2;

        // Update heights
        x.height = Math.max(height(x.left), height(x.right)) + 1;
        y.height = Math.max(height(y.left), height(y.right)) + 1;

        // Return new root
        return y;
    }

    // Method to get the balance factor of a node
    int getBalance(AVLNode node) {
        if (node == null) {
            return 0;
        }
        return height(node.left) - height(node.right);
    }

    // Method to insert a node into the AVL tree and maintain its balance
    AVLNode insert(AVLNode node, int key) {
        // Perform the normal BST insertion
        if (node == null) {
            return new AVLNode(key);
        }

        if (key < node.key) {
            node.left = insert(node.left, key);
        } else if (key > node.key) {
            node.right = insert(node.right, key);
        } else {
            return node; // Duplicate keys are not allowed in BST
        }

        // Update the height of this ancestor node
        node.height = 1 + Math.max(height(node.left), height(node.right));

        // Get the balance factor of this ancestor node to check if it became unbalanced
        int balance = getBalance(node);

        // If the node becomes unbalanced, then there are 4 cases:
        // Left Left Case
        if (balance > 1 && key < node.left.key) {
            return rightRotate(node);
        }
        // Right Right Case
        if (balance < -1 && key > node.right.key) {
            return leftRotate(node);
        }
        // Left Right Case
        if (balance > 1 && key > node.left.key) {
            node.left = leftRotate(node.left);
            return rightRotate(node);
        }
        // Right Left Case
        if (balance < -1 && key < node.right.key) {
            node.right = rightRotate(node.right);
            return leftRotate(node);
        }
        // Return the (unchanged) node pointer
        return node;
    }
    // Method to perform pre-order traversal of the tree
    void preOrder(AVLNode node) {
        if (node != null) {
            System.out.print(node.key + " ");
            preOrder(node.left);
            preOrder(node.right);
        }
    }

    public static void main(String[] args) {
        AVLTree tree = new AVLTree();
        AVLNode root = null;
        // Insert nodes
        int[] nodes = {10, 20, 30, 40, 50, 25};
        for (int key : nodes) {
            root = tree.insert(root, key);
        }
        // Pre-order traversal to check the structure
        System.out.println("Pre-order traversal of the constructed AVL tree is:");
        tree.preOrder(root);
    }
}
