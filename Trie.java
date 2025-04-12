public class SimpleTrie {
    // Node class for each character
    class TrieNode {
        TrieNode[] children = new TrieNode[26]; // Only lowercase English letters
        boolean isEndOfWord = false;
    }
    private TrieNode root;
    // Constructor
    public SimpleTrie() {
        root = new TrieNode();
    }

    // Insert a word into the trie
    public void insert(String word) {
        TrieNode current = root;
        for (char ch : word.toCharArray()) {
            int index = ch - 'a'; // Get index 0-25
            if (current.children[index] == null) {
                current.children[index] = new TrieNode();
            }
            current = current.children[index];
        }
        current.isEndOfWord = true;
    }

    // Search for a complete word
    public boolean search(String word) {
        TrieNode current = root;
        for (char ch : word.toCharArray()) {
            int index = ch - 'a';
            if (current.children[index] == null) {
                return false;
            }
            current = current.children[index];
        }
        return current.isEndOfWord;
    }

    // Main method to test the Trie
    public static void main(String[] args) {
        SimpleTrie trie = new SimpleTrie();

        trie.insert("apple");
        trie.insert("app");
        trie.insert("bat");

        System.out.println(trie.search("apple"));    // true
        System.out.println(trie.search("app"));      // true
        System.out.println(trie.search("appl"));     // false
    }
}
