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

    public int diameterOfBinaryTree(TreeNode root) {
        diameter = 0;
        diameter_03(root);
        return diameter;
    }


    
    // Method 1 -- O(n**2) ==============================================================================================


    public static int height(TreeNode node) {
        if (node == null)
            return -1;
        return Math.max(height(node.left), height(node.right)) + 1;
    }

    public static int diameter01(TreeNode node) {
        if (node == null)
            return 0;

        int lh = height(node.left);
        int rh = height(node.right);

        int ld = diameter01(node.left);
        int rd = diameter01(node.right);

        int currDia = lh + rh + 2;

        return Math.max(currDia, Math.max(ld, rd));

    }


    // Method 2 -- O(n) with class (more intiutive) ==============================================================================================




    public static class diaPair {
        int dia = 0;
        int hei = 0;

        diaPair(int dia, int hei) {
            this.dia = dia;
            this.hei = hei;
        }
    }

    public static diaPair diameter02(TreeNode node) {
        if (node == null)
            return new diaPair(0, -1);

        diaPair lr = diameter02(node.left); // left result
        diaPair rr = diameter02(node.right); // right result

        diaPair myRes = new diaPair(0, -1);
        myRes.dia = Math.max(Math.max(lr.dia, rr.dia), (lr.hei + rr.hei + 2));
        myRes.hei = Math.max(lr.hei, rr.hei) + 1;

        return myRes;
    }



    // Method 3 -- O(n) with static ==============================================================================================





    static int diameter = 0;

    public static int diameter_03(TreeNode node) {
        if (node == null)
            return -1;

        int lh = diameter_03(node.left); // left height
        int rh = diameter_03(node.right); // right height

        diameter = Math.max(diameter, lh + rh + 2);
        return Math.max(lh, rh) + 1;
    }




}