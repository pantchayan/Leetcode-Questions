

class Solution {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
    
        TreeNode(int x) {
            val = x;
        }
    }
    static TreeNode LCANode = null;

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        LCANode = null;
        LCA02(root, p, q);
        return LCANode;
    }

    public static boolean LCA02(TreeNode node, TreeNode p, TreeNode q) {
        boolean SelfDone = false;
        if (node == null)
            return false;
        if ((node.val == p.val) || (node.val == q.val)) {
            SelfDone = true;
        }
        boolean Left = LCA02(node.left, p, q);
        if (LCANode != null)
            return true;

        boolean Right = LCA02(node.right, p, q);
        if (LCANode != null)
            return true;

        if ((SelfDone && Left) || (SelfDone && Right) || (Right && Left)) {
            LCANode = node;
        }

        return SelfDone || Right || Left;
    }
}