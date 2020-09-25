import java.util.ArrayList;
import java.util.LinkedList;
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

    public List<List<Integer>> levelOrder(TreeNode root) {

        List<List<Integer>> ans = new ArrayList<>();
        if (root == null)
            return ans;
        LinkedList<TreeNode> que = new LinkedList<TreeNode>();

        que.addLast(root);

        while (que.size() != 0) {
            int size = que.size();
            List<Integer> smallAns = new ArrayList<>();
            while (size-- > 0) {
                TreeNode curr = que.getFirst();
                que.removeFirst();

                smallAns.add(curr.val);

                if (curr.left != null)
                    que.addLast(curr.left);

                if (curr.right != null)
                    que.addLast(curr.right);

            }
            ans.add(smallAns);
        }
        return ans;
    }
}