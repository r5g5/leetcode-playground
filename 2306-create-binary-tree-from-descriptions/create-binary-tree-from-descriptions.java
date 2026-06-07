/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    // private class TreeNodeDesc {
    //     public TreeNode Node;
    //     public int parent;
    //     TreeNodeDesc(TreeNode node, int guardian) {
    //         Node = node;
    //         parent = guardian;
    //     }
    // };
    public TreeNode createBinaryTree(int[][] descriptions) {
        // var root = new TreeNode();
        var map = new HashMap<Integer, TreeNode>();
        var parentMap = new HashMap<Integer, Integer>();
        for (var desc : descriptions) {
            int parent = desc[0];
            int child = desc[1];
            boolean isLeftChild = desc[2] == 1 ? true : false;
            if (map.containsKey(parent) && map.containsKey(child)) {
                // case 1: both the nodes already exists
                var parentNode = map.get(parent);
                var childNode = map.get(child);
                // just link them
                if (isLeftChild) {
                    parentNode.left = childNode;
                } else {
                    parentNode.right = childNode;
                }
            } else if (map.containsKey(parent)) {
                // case 2: child node doesn't exists
                var parentNode = map.get(parent);
                var childNode = new TreeNode(child);
                map.put(child, childNode);
                if (isLeftChild) {
                    parentNode.left = childNode;
                } else {
                    parentNode.right = childNode;
                }
            } else if (map.containsKey(child)) {
                // case 3: parent doesn't exists
                var parentNode = new TreeNode(parent);
                var childNode = map.get(child);
                map.put(parent, parentNode);
                if (isLeftChild) {
                    parentNode.left = childNode;
                } else {
                    parentNode.right = childNode;
                }
            } else {
                // case 4: both doesn't exists
                var parentNode = new TreeNode(parent);
                var childNode = new TreeNode(child);
                if (isLeftChild) {
                    parentNode.left = childNode;
                } else {
                    parentNode.right = childNode;
                }
                map.put(child, childNode);
                map.put(parent, parentNode);
            }
            parentMap.put(child, parent);
        }
        // int top = -1;
        // int randomParent = descriptions[0][0];
        // while (map.containsKey(randomParent)) {
        //     var p = map.get(randomParent);
        //     root = p;
        //     randomParent = p.val;
        // }
        
        int randomParent = descriptions[0][0];
        while (parentMap.containsKey(randomParent)) {
            randomParent = parentMap.get(randomParent);
        }
        return map.get(randomParent);
    }
}