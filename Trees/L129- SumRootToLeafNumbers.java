class Solution {

    static int ans = 0;

    public int sumNumbers(TreeNode root) {
        ans = 0;
        ArrayList<Integer> smallAns = new ArrayList<>();

        if (root == null)
            return ans;

        rootToLeaves(root, smallAns);

        return ans;
    }

    public static void rootToLeaves(TreeNode node, ArrayList<Integer> smallAns) {
        if (node == null)
            return;

        if (node.left == null && node.right == null) {
            int x = 0;
            int fac = 10;
            x += node.val;
            for (int i = smallAns.size() - 1; i >= 0; i--) {
                x += smallAns.get(i) * fac;
                fac = fac * 10;
            }
            ans = ans + x;
        }

        smallAns.add(node.val);
        rootToLeaves(node.left, smallAns);
        rootToLeaves(node.right, smallAns);
        smallAns.remove(smallAns.size() - 1);

    }
}