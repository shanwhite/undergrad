// CS211 LAB 5
// Binary Trees

package BinaryTrees;

public class BinaryTrees {
    Node root;

    // inserting a node
    public void insert(int data) {
        Node newNode = new Node(data);    // make new node
        if(root==null) {              // no node in root
            root = newNode;
        } else {                      // root occupied
            Node current = root;      // start at root
            Node parent;
        
            while(true) {                 // (exits internally)
                parent = current;
                if (data<current.data) {    // go left?
                    current = current.leftChild;   
                    if (current==null) {                // if end of the line,
                        parent.leftChild = newNode;     // insert on left
                        return;
                    } 
                } else {                  // or go right?
                    current = current.rightChild;
                    if (current==null) {                  // if end of the line,
                        parent.rightChild = newNode;     // insert on right
                        return;
                    } 
                }
            }
        }
    }

    public int maxDepth(Node node) {
        if (node==null) {
            return 0;
        } else {
            int leftDepth = maxDepth(node.leftChild);
            int rightDepth = maxDepth(node.rightChild);
            return Math.max(leftDepth, rightDepth) + 1;    // recursively counts # of levels
        }
    }
}