import java.util.ArrayList;
import java.util.List;

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

    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> smallAns = new ArrayList<>();

        pathSum_(root, sum, smallAns, res);

        return res;
    }

    public static void pathSum_(TreeNode root, int sum, List<Integer> smallAns, List<List<Integer>> res) {
        if (root == null)
            return;

        sum = sum - root.val;
        if (sum == 0) {
            if (root.left == null && root.right == null) {
                List<Integer> base = new ArrayList<>(smallAns);
                base.add(root.val);
                res.add(base);
                return;
            }
        }

        smallAns.add(root.val);
        pathSum_(root.left, sum, smallAns, res);
        pathSum_(root.right, sum, smallAns, res);
        smallAns.remove(smallAns.size() - 1);

    }

}