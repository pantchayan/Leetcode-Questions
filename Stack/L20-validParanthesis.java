class Solution {
    public boolean isValid(String s) {

        char[] str = s.toCharArray();

        LinkedList<Character> stack = new LinkedList<>();

        for (char c : str) {
            // closed bracket?
            if (c == '}' || c == ')' || c == ']') {
                if (!stack.isEmpty()) {
                    char p = stack.peekLast();
                    // check for pairs
                    if (c == '}' && p == '{') {
                        stack.removeLast();
                    } else if (c == ')' && p == '(') {
                        stack.removeLast();
                    } else if (c == ']' && p == '[') {
                        stack.removeLast();
                    } else {
                        stack.addLast(c);
                    }
                } else {
                    stack.addLast(c);
                }
            } else {
                stack.addLast(c);
            }
        }

        if (stack.isEmpty())
            return true;

        return false;

    }
}