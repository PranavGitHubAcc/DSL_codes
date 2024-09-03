class Node {
    Node[] charactersNodes;
    boolean eow;
    
    public Node() {
        charactersNodes = new Node[26];
        for (int i = 0; i < 26; i++) {
            charactersNodes[i] = null;
        }
        eow = false; 
    }
}

public class TrieDataStructure {
    static Node node = new Node();
    
    public static void insert(String s) {
        Node currNode = node;
        for (int i = 0; i < s.length(); i++) {
            int index = s.charAt(i) - 'a';
            if (currNode.charactersNodes[index] == null) {
                currNode.charactersNodes[index] = new Node();
            }
            currNode = currNode.charactersNodes[index];
        }
        currNode.eow = true;
    }
    
    public static boolean find(String s) {
        Node currNode = node;
        for (int i = 0; i < s.length(); i++) {
            int index = s.charAt(i) - 'a';
            if (currNode.charactersNodes[index] == null) {
                return false;
            }
            currNode = currNode.charactersNodes[index];
        }
        return currNode.eow;
    }
    
    public static void main(String[] args) {
    	String words[] = {"the", "a", "there", "their", "any", "thee"};
        for (String word : words) {
            insert(word);
            System.out.println("inserted " + word);
        }

        System.out.println("thee -> " + find("thee"));
        System.out.println("thor -> " + find("thor"));



    }
}
