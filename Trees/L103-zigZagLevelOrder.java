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

    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        if (root == null)
            return ans;

        LinkedList<TreeNode> que = new LinkedList<>();

        que.addLast(root);

        boolean flag = false;

        while (que.size() != 0) {
            ArrayList<Integer> smallAns = new ArrayList<>();
            int size = que.size();
            while (size-- > 0) {
                TreeNode curr = que.getFirst();
                que.removeFirst();

                smallAns.add(curr.val);

                if (curr.left != null)
                    que.addLast(curr.left);
                if (curr.right != null)
                    que.addLast(curr.right);
            }
            if (!flag) {
                ans.add(smallAns);
            } else {
                Collections.reverse(smallAns);
                ans.add(smallAns);
            }
            flag = !flag;
        }
        return ans;
    }
}