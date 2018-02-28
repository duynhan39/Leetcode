import java.util.Stack;

class Solution {

    public String removeDuplicateLetters(String s) {
        Stack<Character> answer = new Stack<>();

        for(int i=0; i<s.length(); i++) {
            if(!answer.contains(s.charAt(i))) {
                addToStack(answer, s.charAt(i), s.substring(i));
            }
        }
        String st = new String();
        for(Character c:answer)
            st+=c;
        return st;
    }

    public void addToStack(Stack<Character> answer, Character ch, String s) {
        while(!answer.empty()) {
            if(s.indexOf(answer.lastElement())<0 || answer.lastElement()<ch) {
                break;
            }
            if(answer.lastElement()>ch) {
                answer.pop();
            }
        }
        answer.add(ch);
    }
}
