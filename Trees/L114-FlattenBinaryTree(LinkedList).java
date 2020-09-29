
class Solution {

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    public void flatten(TreeNode root) {
        linearize02(root);
    }

    public static void linearize02(TreeNode node) {
        if (node == null)
            return;

        linearize02(node.left);
        linearize02(node.right);

        if (node.left != null) {
            TreeNode tail = node.left;
            while (tail.right != null) {
                tail = tail.right;
            }
            tail.right = node.right;
            node.right = node.left;
            node.left = null;
        }

    }
}