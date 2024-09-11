import java.util.*;


class Solution {
  public boolean wordBreak(String s, List<String> wordDict) {
    return helper(s, wordDict, new HashMap<String, Boolean>());
  }

  private boolean helper(String s, List<String> wordDict, HashMap<String, Boolean> tracker) {

    if (s.length() == 0) return true;

    if (tracker.containsKey(s)) return tracker.get(s);

    for (String word : wordDict) {
      
      if (s.length() >= word.length() && s.startsWith(word)) {

        boolean result = helper(s.substring(word.length()), wordDict, tracker);
        tracker.put(s, true);
        if (result) return true;
      }
    }

    tracker.put(s, false);
    return false;
  }
}

// class Solution {
//   public boolean wordBreak(String s, List<String> wordDict) {
//     return helper(s, wordDict);
//   }

//   private boolean helper(String s, List<String> wordDict) {

//     if (s.length() == 0) return true;

//     for (String word : wordDict) {
      
//       if (s.length() >= word.length() && s.startsWith(word)) {
//         boolean result = helper(s.substring(word.length()), wordDict);
//         if (result) return true;
//       }
//     }

//     return false;
//   }
// }