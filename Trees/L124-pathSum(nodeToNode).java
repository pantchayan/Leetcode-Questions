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

    int Sum = Integer.MIN_VALUE;

    public int maxPathSum(TreeNode root) {
        Sum = Integer.MIN_VALUE;
        maxPathSum_(root);
        return Sum;
    }

    public int maxPathSum_(TreeNode node) {
        if (node == null)
            return 0;

        int lm = maxPathSum_(node.left);
        int rm = maxPathSum_(node.right);

        int f = Math.max(lm + node.val, rm + node.val);
        int f2 = Math.max(f, node.val);
        int p = Math.max(lm + rm + node.val, f2);
        Sum = Math.max(Sum, p);

        return f2;
    }
}