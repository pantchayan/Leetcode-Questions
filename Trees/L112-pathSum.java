
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

    public boolean hasPathSum(TreeNode root, int sum) {

        if (root == null)
            return false;
        sum = sum - root.val;
        if (sum == 0) {
            if (root.left == null && root.right == null)
                return true;

        }

        boolean res = false;
        res = res || hasPathSum(root.left, sum) || hasPathSum(root.right, sum);

        return res;
    }
}