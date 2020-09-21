import java.util.ArrayList;
import java.util.List;

class Solution {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    static ArrayList<Integer> ans;

    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        ans = new ArrayList<>();

        ArrayList<TreeNode> path = new ArrayList<>();
        rootToNodePath(root, target, path);

        ArrayList<Integer> dis = new ArrayList<>();

        for (int i = 0; i < path.size(); i++) {
            dis.add(K);
            K--;
            if (K < 0)
                break;
        }
        for (int i = 0; i < dis.size(); i++) {
            if (i > 0)
                kDown(path.get(i), dis.get(i), path.get(i - 1).val);
            else
                kDown(path.get(i), dis.get(i), -1);
        }
        return ans;
    }

    public static boolean rootToNodePath(TreeNode node, TreeNode target, ArrayList<TreeNode> path) {
        if (node == null)
            return false;
        if (node.val == target.val) {
            path.add(node);
            return true;
        }
        boolean res = false;
        res = res || rootToNodePath(node.left, target, path) || rootToNodePath(node.right, target, path);
        if (res)
            path.add(node);
        return res;
    }

    public static void kDown(TreeNode node, int K, int noGo) {
        if (node == null)
            return;
        if (node.val == noGo)
            return;
        if (K < 0)
            return;

        if (K == 0)
            ans.add(node.val);
        K--;
        kDown(node.left, K, noGo);
        kDown(node.right, K, noGo);
    }
}
