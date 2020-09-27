

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

    static int leftMin = Integer.MAX_VALUE;
    static int rightMax = Integer.MIN_VALUE;

    public static void width(TreeNode node, int lev) {
        if (node == null)
            return;

        leftMin = Math.min(leftMin, lev);
        rightMax = Math.max(rightMax, lev);

        width(node.left, lev - 1);
        width(node.right, lev + 1);

    }

    public static class pairVO {
        TreeNode node;
        int vl = 0;

        pairVO(TreeNode node, int vl) {
            this.node = node;
            this.vl = vl;
        }
    }

    public List<List<Integer>> verticalTraversal(TreeNode root) {
        leftMin = Integer.MAX_VALUE;
        rightMax = Integer.MIN_VALUE;
        width(root, 0);
        int n = rightMax - leftMin + 1;

        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            ans.add(new ArrayList<Integer>());
        }

        LinkedList<pairVO> que = new LinkedList<>();

        que.addLast(new pairVO(root, -leftMin));

        while (que.size() != 0) {
            int size = que.size();
            while (size-- > 0) {
                pairVO curr = que.getFirst();
                que.removeFirst();

                ans.get(curr.vl).add(curr.node.val);

                if (curr.node.left != null)
                    que.addLast(new pairVO(curr.node.left, curr.vl - 1));

                if (curr.node.right != null)
                    que.addLast(new pairVO(curr.node.right, curr.vl + 1));

            }
        }

        return ans;
    }

}