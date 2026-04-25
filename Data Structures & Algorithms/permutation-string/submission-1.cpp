// Corrected version of my initial/first approach: (correct brute force)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // 🔥 Edge case fix
        if(s1.length() > s2.length()) return false;
        unordered_map<char,int> freq;
        for(char c : s1) {
            freq[c]++;
        }
        // Step 2: check each window of size s1
        for(int i = 0; i <= s2.length() - s1.length(); i++) {

            unordered_map<char,int> temp = freq; // copy original freq
            int count = 0;

            // check window
            for(int j = 0; j < s1.length(); j++) {
                char c = s2[i + j];

                if(temp[c] > 0) {
                    temp[c]--;
                    count++;
                } else {
                    break;
                }
            }

            // if full match
            if(count == s1.length()) {
                return true;
            }
        }
        return false;
    }
};


// Raw initial/unsuccessful approach/thinking: (incorrect brute force)
/*
#include <iostream>

int main() {
    string s1 = "abc";
    string s2 = "lecabee";
    unordered_map<char, int> freq;

    for (int i = 0; i <= s2.length() - s1.length(); i++) {
        for (char c : s2) {
            freq[c++];
        }

        for (int j = 0; j < s1.length(); j++) {
            if (s2[i] == s1[j] && freq[s2[j]] != 0) {
                freq[s2[j]]--;
                break;
            }
        }
    }

    return 0;
}

*/

// Correct thinking logic for incorrect to correct brute force:

/*
🧠 Refined Notes: Permutation in String

🔴 My Initial Thinking (Flawed Approach)

- Compare each character of s2 with each character of s1
- While matching:
  - Check if the character exists in s1 using unordered_map
  - If present and count > 0 → decrement frequency
- Try to match characters one by one and make frequency zero

❌ Problems in this logic:
- Comparing characters individually does NOT guarantee a valid permutation
- Order doesn’t matter in permutation → but I was implicitly depending on order
- I was mixing:
  - Position-based matching ❌
  - Frequency-based validation ✔️
- This leads to incorrect matches and unnecessary complexity


✅ Key Realization (Turning Point)

Instead of comparing characters directly, convert the problem into a frequency matching problem

👉 Treat characters as counts (numbers) rather than positions


🟢 Corrected Logic (Improved Thinking)

Step 1: Frequency Setup
- Store frequency of s1 in unordered_map

  Example:
  a → 1, b → 1, c → 1


Step 2: Process s2 using a window of size s1.length()

- For each character in the window:
  
  if(freq[c] > 0)
  
  - If true:
    - Decrease frequency
    - Increase match count


💡 Important Insight Used

- If a character is NOT present in unordered_map
  → its value is 0 by default

- So:
  
  freq[c] > 0
  
  ensures:
  - Character exists
  - AND is still needed


Step 3: Match Condition

- If:
  
  count == s1.length()
  
  → permutation found ✅


🔁 Mental Model Shift

Old Thinking ❌                 | New Thinking ✅
------------------------------|-------------------------------
Compare characters one-by-one | Compare frequency distributions
Focus on positions            | Ignore order
Nested matching loops         | Window + frequency check
Direct equality               | Count-based validation


⚡ One-Line Summary (for revision)

"Permutation check = match frequency of s1 with any window of s2, not character positions."


🔥 Final Intuition

- You don’t care about where characters are
- You only care about:

👉 "Do I have the exact same count of characters?"
*/




